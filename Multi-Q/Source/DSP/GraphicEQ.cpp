#include "GraphicEQ.h"

template <typename SampleType>
GraphicEQ<SampleType>::GraphicEQ() :
mGlobalBypass(false)
{
}

template <typename SampleType>
void GraphicEQ<SampleType>::prepare(const juce::dsp::ProcessSpec& spec)
{
    mCurrentSampleRate = spec.sampleRate;
    
    mGainDB.reset(mCurrentSampleRate, 0.02);
    mGainDB.setTargetValue(0.0);
    
    mRawGain.reset(mCurrentSampleRate, 0.02);
    mRawGain.setTargetValue(0.0);
    
    int i = 0;
    
    for (auto& filter : filters)
    {
        filter.prepare(spec);
        filter.setParameter(viator_dsp::SVFilter<float>::ParameterId::kType, viator_dsp::SVFilter<float>::FilterType::kBandShelf);
        filter.setParameter(viator_dsp::SVFilter<float>::ParameterId::kCutoff, cutoffs[i]);
        ++i;
    }
}

template <typename SampleType>
void GraphicEQ<SampleType>::setParameter(ParameterId parameter, SampleType parameterValue)
{
    using f = viator_dsp::SVFilter<float>::ParameterId;
    switch (parameter)
    {
        case ParameterId::kFilter1Gain: filter1.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kFilter2Gain: filter1.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kFilter3Gain: filter1.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kFilter4Gain: filter1.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kFilter5Gain: filter1.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kFilter6Gain: filter1.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kFilter7Gain: filter1.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kFilter8Gain: filter1.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kFilter9Gain: filter1.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kFilter10Gain: filter1.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kSampleRate: mCurrentSampleRate = parameterValue; break;
        case ParameterId::kBypass: mGlobalBypass = static_cast<bool>(parameterValue);
    }
}

template class GraphicEQ<float>;
template class GraphicEQ<double>;
