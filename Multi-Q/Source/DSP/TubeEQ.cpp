
#include "TubeEQ.h"

template <typename SampleType>
TubeEQ<SampleType>::TubeEQ() :
mGlobalBypass(false)
{
}

template <typename SampleType>
void TubeEQ<SampleType>::prepare(const juce::dsp::ProcessSpec& spec)
{
    mCurrentSampleRate = spec.sampleRate;
    
    mGainDB.reset(mCurrentSampleRate, 0.02);
    mGainDB.setTargetValue(0.0);
    
    mRawGain.reset(mCurrentSampleRate, 0.02);
    mRawGain.setTargetValue(0.0);
    
    lowBoostFilter.prepare(spec);
    lowBoostFilter.setStereoType(viator_dsp::SVFilter<float>::StereoId::kStereo);
    lowBoostFilter.setParameter(viator_dsp::SVFilter<float>::ParameterId::kType, viator_dsp::SVFilter<float>::FilterType::kBandShelf);
    lowBoostFilter.setParameter(viator_dsp::SVFilter<float>::ParameterId::kCutoff, 20);
    lowBoostFilter.setParameter(viator_dsp::SVFilter<float>::ParameterId::kQType, viator_dsp::SVFilter<float>::QType::kProportional);
    
    lowCutFilter.prepare(spec);
    lowCutFilter.setStereoType(viator_dsp::SVFilter<float>::StereoId::kStereo);
    lowCutFilter.setParameter(viator_dsp::SVFilter<float>::ParameterId::kType, viator_dsp::SVFilter<float>::FilterType::kBandShelf);
    lowCutFilter.setParameter(viator_dsp::SVFilter<float>::ParameterId::kCutoff, 40);
    lowCutFilter.setParameter(viator_dsp::SVFilter<float>::ParameterId::kQType, viator_dsp::SVFilter<float>::QType::kProportional);
    
    highBoostFilter.prepare(spec);
    highBoostFilter.setStereoType(viator_dsp::SVFilter<float>::StereoId::kStereo);
    highBoostFilter.setParameter(viator_dsp::SVFilter<float>::ParameterId::kType, viator_dsp::SVFilter<float>::FilterType::kBandShelf);
    highBoostFilter.setParameter(viator_dsp::SVFilter<float>::ParameterId::kCutoff, 1000);
    highBoostFilter.setParameter(viator_dsp::SVFilter<float>::ParameterId::kQType, viator_dsp::SVFilter<float>::QType::kProportional);
    
    highCutFilter.prepare(spec);
    highCutFilter.setStereoType(viator_dsp::SVFilter<float>::StereoId::kStereo);
    highCutFilter.setParameter(viator_dsp::SVFilter<float>::ParameterId::kType, viator_dsp::SVFilter<float>::FilterType::kBandShelf);
    highCutFilter.setParameter(viator_dsp::SVFilter<float>::ParameterId::kCutoff, 2000);
    highCutFilter.setParameter(viator_dsp::SVFilter<float>::ParameterId::kQType, viator_dsp::SVFilter<float>::QType::kProportional);
}

template <typename SampleType>
void TubeEQ<SampleType>::setParameter(ParameterId parameter, SampleType parameterValue)
{
    using f = viator_dsp::SVFilter<float>::ParameterId;
    switch (parameter)
    {
        case ParameterId::kLowBoostGain: lowBoostFilter.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kLowCutGain: lowCutFilter.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kHighBoostGain: highBoostFilter.setParameter(f::kGain, parameterValue); break;
        case ParameterId::kHighCutGain: highCutFilter.setParameter(f::kGain, parameterValue); break;
            
        case ParameterId::kLowFilterFreq:
        {
            lowBoostFilter.setParameter(f::kCutoff, parameterValue);
            lowCutFilter.setParameter(f::kCutoff, parameterValue * 2.0);
            break;
        }
            
        case ParameterId::kHighFilterFreq:
        {
            highBoostFilter.setParameter(f::kCutoff, parameterValue);
            highCutFilter.setParameter(f::kCutoff, parameterValue * 0.5);
            break;
        }
            
        case ParameterId::kDrive:
        {
            mGainDB.setTargetValue(parameterValue);
            mRawGain.setTargetValue(viator_utils::utils::dbToGain(parameterValue));
            break;
        }
            
        case ParameterId::kSampleRate: mCurrentSampleRate = parameterValue; break;
        case ParameterId::kBypass: mGlobalBypass = static_cast<bool>(parameterValue);
    }
}

template <typename SampleType>
void TubeEQ<SampleType>::setStereoType(int newStereoID)
{
    switch (newStereoID)
    {
        case 0:
        {
            lowBoostFilter.setStereoType(viator_dsp::SVFilter<float>::StereoId::kStereo);
            lowCutFilter.setStereoType(viator_dsp::SVFilter<float>::StereoId::kStereo);
            highBoostFilter.setStereoType(viator_dsp::SVFilter<float>::StereoId::kStereo);
            highCutFilter.setStereoType(viator_dsp::SVFilter<float>::StereoId::kStereo);
            break;
        }
            
        case 1:
        {
            lowBoostFilter.setStereoType(viator_dsp::SVFilter<float>::StereoId::kMids);
            lowCutFilter.setStereoType(viator_dsp::SVFilter<float>::StereoId::kMids);
            highBoostFilter.setStereoType(viator_dsp::SVFilter<float>::StereoId::kStereo);
            highCutFilter.setStereoType(viator_dsp::SVFilter<float>::StereoId::kStereo);
            break;
        }
            
        case 2:
        {
            lowBoostFilter.setStereoType(viator_dsp::SVFilter<float>::StereoId::kSides);
            lowCutFilter.setStereoType(viator_dsp::SVFilter<float>::StereoId::kSides);
            highBoostFilter.setStereoType(viator_dsp::SVFilter<float>::StereoId::kStereo);
            highCutFilter.setStereoType(viator_dsp::SVFilter<float>::StereoId::kStereo);
            break;
        }
    }
    

}

template class TubeEQ<float>;
template class TubeEQ<double>;
