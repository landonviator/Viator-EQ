/*
  ==============================================================================

    TubeEQ.cpp
    Created: 16 Apr 2022 11:23:25am
    Author:  Landon Viator

  ==============================================================================
*/

#include "../PluginProcessor.h"

void MultiQAudioProcessor::updateTubeEQParameters()
{
    tubeEQModule.setStereoType(static_cast<int>(treeState.getRawParameterValue(msID)->load()));
    tubeEQModule.setParameter(TubeEQ<float>::ParameterId::kLowBoostGain, treeState.getRawParameterValue(tubeLowBoostID)->load());
    tubeEQModule.setParameter(TubeEQ<float>::ParameterId::kLowCutGain, treeState.getRawParameterValue(tubeLowCutID)->load() * -1.0);
    tubeEQModule.setParameter(TubeEQ<float>::ParameterId::kHighBoostGain, treeState.getRawParameterValue(tubeHighBoostID)->load());
    tubeEQModule.setParameter(TubeEQ<float>::ParameterId::kHighCutGain, treeState.getRawParameterValue(tubeHighCutID)->load() * -1.0);
    tubeEQModule.setParameter(TubeEQ<float>::ParameterId::kLowFilterFreq, treeState.getRawParameterValue(tubeLowFreqID)->load());
    tubeEQModule.setParameter(TubeEQ<float>::ParameterId::kHighFilterFreq, treeState.getRawParameterValue(tubeHighFreqID)->load());
    tubeEQModule.setParameter(TubeEQ<float>::ParameterId::kBandWidth, treeState.getRawParameterValue(tubeFilterBWID)->load());
    tubeEQModule.setParameter(TubeEQ<float>::ParameterId::kDrive, treeState.getRawParameterValue(driveID)->load());
    //tubeEQModule.setParameter(TubeEQ<float>::ParameterId::kBypass, !treeState.getRawParameterValue(tubeEQONID)->load());
}
