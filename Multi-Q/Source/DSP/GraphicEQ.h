#ifndef GraphicEQ_h
#define GraphicEQ_h

#pragma once
#include <JuceHeader.h>

template <typename SampleType>
class GraphicEQ
{
public:
    
    GraphicEQ();
    
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

        for (size_t channel = 0; channel < numChannels; ++channel)
        {
            auto* input = inBlock.getChannelPointer (channel);
            auto* output = outBlock.getChannelPointer (channel);
            
            for (size_t sample = 0; sample < len; ++sample)
            {
                output[sample] = processSample(input[sample], channel);
            }
        }
    }
    
    /** Process an individual sample */
    SampleType processSample(SampleType input, SampleType channel) noexcept
    {
        input = filter1.processSample(input, channel);
        input = filter2.processSample(input, channel);
        input = filter3.processSample(input, channel);
        input = filter4.processSample(input, channel);
        input = filter5.processSample(input, channel);
        input = filter6.processSample(input, channel);
        input = filter7.processSample(input, channel);
        input = filter8.processSample(input, channel);
        input = filter9.processSample(input, channel);
        input = filter10.processSample(input, channel);
        
        return input;
    }
    
    /** Soft Clip */
    SampleType softClipData(SampleType dataToClip)
    {
        // Preamp
        dataToClip *= mRawGain.getNextValue();
        
        // Soft clipper
        dataToClip = mPiDivisor * std::atan(dataToClip);
        
        // Compensation
        dataToClip *= 2.0;
        
        // Hard clip output
        if (std::abs(dataToClip) >= 1.0)
        {
            dataToClip = std::copysign(1.0, dataToClip);
        }
        
        // Output
        return dataToClip;
    }

    /** The parameters of this module. */
    enum class ParameterId
    {
        kFilter1Gain,
        kFilter2Gain,
        kFilter3Gain,
        kFilter4Gain,
        kFilter5Gain,
        kFilter6Gain,
        kFilter7Gain,
        kFilter8Gain,
        kFilter9Gain,
        kFilter10Gain,
        kSampleRate,
        kBypass
    };
    
    void setParameter(ParameterId parameter, SampleType parameterValue);
    
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
    viator_dsp::SVFilter<float> filter5;
    viator_dsp::SVFilter<float> filter6;
    viator_dsp::SVFilter<float> filter7;
    viator_dsp::SVFilter<float> filter8;
    viator_dsp::SVFilter<float> filter9;
    viator_dsp::SVFilter<float> filter10;
};

#endif /* Distortion_h */
