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
}
