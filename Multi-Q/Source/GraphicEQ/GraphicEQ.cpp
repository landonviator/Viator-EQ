/*
  ==============================================================================

    GraphicEQ.cpp
    Created: 16 Apr 2022 11:23:11am
    Author:  Landon Viator

  ==============================================================================
*/

#include "../PluginProcessor.h"

void MultiQAudioProcessor::updateGraphicParameters()
{
    graphicEQModule.setStereoType(static_cast<int>(treeState.getRawParameterValue(msID)->load()));
    graphicEQModule.setParameter(GraphicEQ<float>::ParameterId::kFilter1Gain, treeState.getRawParameterValue(graphicFilter1GainID)->load());
    graphicEQModule.setParameter(GraphicEQ<float>::ParameterId::kFilter2Gain, treeState.getRawParameterValue(graphicFilter2GainID)->load());
    graphicEQModule.setParameter(GraphicEQ<float>::ParameterId::kFilter3Gain, treeState.getRawParameterValue(graphicFilter3GainID)->load());
    graphicEQModule.setParameter(GraphicEQ<float>::ParameterId::kFilter4Gain, treeState.getRawParameterValue(graphicFilter4GainID)->load());
    graphicEQModule.setParameter(GraphicEQ<float>::ParameterId::kFilter5Gain, treeState.getRawParameterValue(graphicFilter5GainID)->load());
    graphicEQModule.setParameter(GraphicEQ<float>::ParameterId::kFilter6Gain, treeState.getRawParameterValue(graphicFilter6GainID)->load());
    graphicEQModule.setParameter(GraphicEQ<float>::ParameterId::kFilter7Gain, treeState.getRawParameterValue(graphicFilter7GainID)->load());
    graphicEQModule.setParameter(GraphicEQ<float>::ParameterId::kFilter8Gain, treeState.getRawParameterValue(graphicFilter8GainID)->load());
    graphicEQModule.setParameter(GraphicEQ<float>::ParameterId::kFilter9Gain, treeState.getRawParameterValue(graphicFilter9GainID)->load());
    graphicEQModule.setParameter(GraphicEQ<float>::ParameterId::kFilter10Gain, treeState.getRawParameterValue(graphicFilter10GainID)->load());
}
