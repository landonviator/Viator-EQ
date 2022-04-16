/*
  ==============================================================================

    ParametricEQ.cpp
    Created: 16 Apr 2022 11:23:19am
    Author:  Landon Viator

  ==============================================================================
*/

#include "../PluginProcessor.h"

void MultiQAudioProcessor::updateParametricParameters()
{
    parametricEQModule.setStereoType(static_cast<int>(treeState.getRawParameterValue(msID)->load()));
    parametricEQModule.setParameter(ParametricEQ<float>::ParameterId::kFilter1Gain, treeState.getRawParameterValue(graphicFilter1GainID)->load());
    parametricEQModule.setParameter(ParametricEQ<float>::ParameterId::kFilter2Gain, treeState.getRawParameterValue(graphicFilter2GainID)->load());
    parametricEQModule.setParameter(ParametricEQ<float>::ParameterId::kFilter3Gain, treeState.getRawParameterValue(graphicFilter3GainID)->load());
    parametricEQModule.setParameter(ParametricEQ<float>::ParameterId::kFilter4Gain, treeState.getRawParameterValue(graphicFilter4GainID)->load());
    parametricEQModule.setParameter(ParametricEQ<float>::ParameterId::kFilter1Freq, treeState.getRawParameterValue(graphicFilter5GainID)->load());
    parametricEQModule.setParameter(ParametricEQ<float>::ParameterId::kFilter2Freq, treeState.getRawParameterValue(graphicFilter6GainID)->load());
    parametricEQModule.setParameter(ParametricEQ<float>::ParameterId::kFilter3Freq, treeState.getRawParameterValue(graphicFilter7GainID)->load());
    parametricEQModule.setParameter(ParametricEQ<float>::ParameterId::kFilter4Freq, treeState.getRawParameterValue(graphicFilter8GainID)->load());
    parametricEQModule.setParameter(ParametricEQ<float>::ParameterId::kBypass, !treeState.getRawParameterValue(paraEQONID)->load());
}
