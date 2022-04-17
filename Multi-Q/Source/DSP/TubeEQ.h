#ifndef TubeEQ_h
#define TubeEQ_h

#pragma once
#include <JuceHeader.h>

template <typename SampleType>
class TubeEQ
{
public:
    
    TubeEQ();
    
    /** Initialises the clipper. */
    void prepare(const juce::dsp::ProcessSpec& spec);
    
    /** Processes the input and output buffers supplied in the processing context. */
    template <typename ProcessContext>
    void process (const ProcessContext& context) noexcept
    {
        
        auto&& inBlock  = context.getInputBlock();
        auto&& outBlock = context.getOutputBlock();

        jassert (inBlock.getNumChannels() == outBlock.getNumChannels());
        jassert (inBlock.getNumSamples() == outBlock.getNumSamples());

        auto len         = inBlock.getNumSamples();
        auto numChannels = inBlock.getNumChannels();

        if (mGlobalBypass)
        {
            return;
        }

        lowBoostFilter.process(context);
        lowCutFilter.process(context);
        highBoostFilter.process(context);
        highCutFilter.process(context);
        
        for (int ch = 0; ch < numChannels; ++ch)
        {
            auto* input = inBlock.getChannelPointer(ch);
            auto* output = outBlock.getChannelPointer (ch);
                    
            for (int sample = 0; sample < len; ++sample)
            {
                output[sample] = softClipData(input[sample]) * viator_utils::utils::dbToGain(2.0f);
            }
        }
    }
    
    /** Soft Clip */
    SampleType softClipData(SampleType dataToClip)
    {
        // Preamp
        dataToClip *= mRawGain.getNextValue();
        
        // Soft clipper
        dataToClip = mPiDivisor * std::atan(dataToClip);
        
        // Compensation
        dataToClip *= 1.5;
        
        // Hard clip output
        if (std::abs(dataToClip) >= 0.99)
        {
            dataToClip = std::copysign(0.99, dataToClip);
        }
        
        // Output
        return dataToClip *= viator_utils::utils::dbToGain(-mGainDB.getNextValue() * 0.75);
    }

    /** The parameters of this module. */
    enum class ParameterId
    {
        kLowBoostGain,
        kLowCutGain,
        kHighBoostGain,
        kHighCutGain,
        kLowFilterFreq,
        kHighFilterFreq,
        kDrive,
        kSampleRate,
        kBypass
    };
    
    void setParameter(ParameterId parameter, SampleType parameterValue);
    void setStereoType(int newStereoType);
    
private:
    
    // Member variables
    bool mGlobalBypass;
    juce::SmoothedValue<float> mGainDB;
    juce::SmoothedValue<float> mRawGain;
    float mCurrentSampleRate {44100.0f};
    
    // Expressions
    static constexpr float mPiDivisor = 2.0 / juce::MathConstants<float>::pi;
    
    // Filters
    viator_dsp::SVFilter<float> lowBoostFilter;
    viator_dsp::SVFilter<float> lowCutFilter;
    viator_dsp::SVFilter<float> highBoostFilter;
    viator_dsp::SVFilter<float> highCutFilter;
};

#endif /* TubeEQ_h */
