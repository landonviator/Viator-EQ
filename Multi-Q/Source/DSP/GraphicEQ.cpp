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
    
    filter1.prepare(spec);
    filter1.setParameter(viator_dsp::SVFilter<float>::ParameterId::kType, viator_dsp::SVFilter<float>::FilterType::kBandShelf);
    filter1.setParameter(viator_dsp::SVFilter<float>::ParameterId::kCutoff, 31);
    
    filter2.prepare(spec);
    filter2.setParameter(viator_dsp::SVFilter<float>::ParameterId::kType, viator_dsp::SVFilter<float>::FilterType::kBandShelf);
    filter2.setParameter(viator_dsp::SVFilter<float>::ParameterId::kCutoff, 63);
    
    filter3.prepare(spec);
    filter3.setParameter(viator_dsp::SVFilter<float>::ParameterId::kType, viator_dsp::SVFilter<float>::FilterType::kBandShelf);
    filter3.setParameter(viator_dsp::SVFilter<float>::ParameterId::kCutoff, 125);
    
    filter4.prepare(spec);
    filter4.setParameter(viator_dsp::SVFilter<float>::ParameterId::kType, viator_dsp::SVFilter<float>::FilterType::kBandShelf);
    filter4.setParameter(viator_dsp::SVFilter<float>::ParameterId::kCutoff, 250);
    
    filter5.prepare(spec);
    filter5.setParameter(viator_dsp::SVFilter<float>::ParameterId::kType, viator_dsp::SVFilter<float>::FilterType::kBandShelf);
    filter5.setParameter(viator_dsp::SVFilter<float>::ParameterId::kCutoff, 500);
    
    filter6.prepare(spec);
    filter6.setParameter(viator_dsp::SVFilter<float>::ParameterId::kType, viator_dsp::SVFilter<float>::FilterType::kBandShelf);
    filter6.setParameter(viator_dsp::SVFilter<float>::ParameterId::kCutoff, 1000);
    
    filter7.prepare(spec);
    filter7.setParameter(viator_dsp::SVFilter<float>::ParameterId::kType, viator_dsp::SVFilter<float>::FilterType::kBandShelf);
    filter7.setParameter(viator_dsp::SVFilter<float>::ParameterId::kCutoff, 2000);
    
    filter8.prepare(spec);
    filter8.setParameter(viator_dsp::SVFilter<float>::ParameterId::kType, viator_dsp::SVFilter<float>::FilterType::kBandShelf);
    filter8.setParameter(viator_dsp::SVFilter<float>::ParameterId::kCutoff, 4000);
    
    filter9.prepare(spec);
    filter9.setParameter(viator_dsp::SVFilter<float>::ParameterId::kType, viator_dsp::SVFilter<float>::FilterType::kBandShelf);
    filter9.setParameter(viator_dsp::SVFilter<float>::ParameterId::kCutoff, 8000);
    
    filter10.prepare(spec);
    filter10.setParameter(viator_dsp::SVFilter<float>::ParameterId::kType, viator_dsp::SVFilter<float>::FilterType::kBandShelf);
    filter10.setParameter(viator_dsp::SVFilter<float>::ParameterId::kCutoff, 15000);
    
}

template <typename SampleType>
void GraphicEQ<SampleType>::setParameter(ParameterId parameter, SampleType parameterValue)
{
    using f = viator_dsp::SVFilter<float>::ParameterId;
    switch (parameter)
    {
        case ParameterId::kFilter1Gain: filter1.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kFilter2Gain: filter2.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kFilter3Gain: filter3.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kFilter4Gain: filter4.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kFilter5Gain: filter5.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kFilter6Gain: filter6.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kFilter7Gain: filter7.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kFilter8Gain: filter8.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kFilter9Gain: filter9.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kFilter10Gain: filter10.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kSampleRate: mCurrentSampleRate = parameterValue; break;
        case ParameterId::kBypass: mGlobalBypass = static_cast<bool>(parameterValue);
    }
}

template class GraphicEQ<float>;
template class GraphicEQ<double>;
