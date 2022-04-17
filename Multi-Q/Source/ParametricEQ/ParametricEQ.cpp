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
    parametricEQModule.setParameter(ParametricEQ<float>::ParameterId::kFilter1Gain, treeState.getRawParameterValue(parametricFilter1GainID)->load());
    parametricEQModule.setParameter(ParametricEQ<float>::ParameterId::kFilter2Gain, treeState.getRawParameterValue(parametricFilter2GainID)->load());
    parametricEQModule.setParameter(ParametricEQ<float>::ParameterId::kFilter3Gain, treeState.getRawParameterValue(parametricFilter3GainID)->load());
    parametricEQModule.setParameter(ParametricEQ<float>::ParameterId::kFilter4Gain, treeState.getRawParameterValue(parametricFilter4GainID)->load());
    parametricEQModule.setParameter(ParametricEQ<float>::ParameterId::kFilter1Freq, treeState.getRawParameterValue(parametricFilter1FreqID)->load());
    parametricEQModule.setParameter(ParametricEQ<float>::ParameterId::kFilter2Freq, treeState.getRawParameterValue(parametricFilter2FreqID)->load());
    parametricEQModule.setParameter(ParametricEQ<float>::ParameterId::kFilter3Freq, treeState.getRawParameterValue(parametricFilter3FreqID)->load());
    parametricEQModule.setParameter(ParametricEQ<float>::ParameterId::kFilter4Freq, treeState.getRawParameterValue(parametricFilter4FreqID)->load());
}
