/*
  ==============================================================================

    Parameters.cpp
    Created: 16 Apr 2022 1:45:51pm
    Author:  Landon Viator

  ==============================================================================
*/

#include "../PluginProcessor.h"

void MultiQAudioProcessor::updateCommonParameters()
{
    osToggle = static_cast<bool>(treeState.getRawParameterValue(qualityID)->load());
    phaseToggle = static_cast<bool>(treeState.getRawParameterValue(phaseID)->load());
    hpFilter.setParameter(viator_dsp::SVFilter<float>::ParameterId::kCutoff, treeState.getRawParameterValue(highpassID)->load());
    lpFilter.setParameter(viator_dsp::SVFilter<float>::ParameterId::kCutoff, treeState.getRawParameterValue(lowpassID)->load());
    gainModule.setGainDecibels(treeState.getRawParameterValue(trimID)->load());
}
