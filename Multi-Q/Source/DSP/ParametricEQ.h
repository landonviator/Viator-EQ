#ifndef ParametricEQ_h
#define ParametricEQ_h

#pragma once
#include <JuceHeader.h>

template <typename SampleType>
class ParametricEQ
{
public:
    
    ParametricEQ();
    
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

        filter1.process(context);
        filter2.process(context);
        filter3.process(context);
        filter4.process(context);
        
        for (int ch = 0; ch < numChannels; ++ch)
        {
            auto* input = inBlock.getChannelPointer(ch);
            auto* output = outBlock.getChannelPointer (ch);

            for (int sample = 0; sample < len; ++sample)
            {
                output[sample] = saturateData(input[sample]);
            }
        }
    }
    
    SampleType saturateData(SampleType dataToSaturate)
    {
        auto x = dataToSaturate * mRawGain.getNextValue();

        auto saturation = x - ((x * x * x) / 6.75);
        
        // Hard clip output
        if (std::abs(saturation) >= 0.99)
        {
            saturation = std::copysign(0.99, saturation);
        }

        return saturation *= viator_utils::utils::dbToGain(-mGainDB.getNextValue());
    }
    
    /** The parameters of this module. */
    enum class ParameterId
    {
        kFilter1Gain,
        kFilter2Gain,
        kFilter3Gain,
        kFilter4Gain,
        kFilter1Freq,
        kFilter2Freq,
        kFilter3Freq,
        kFilter4Freq,
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
    viator_dsp::SVFilter<float> filter1;
    viator_dsp::SVFilter<float> filter2;
    viator_dsp::SVFilter<float> filter3;
    viator_dsp::SVFilter<float> filter4;
};

#endif /* Distortion_h */
