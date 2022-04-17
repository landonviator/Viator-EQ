/*
  ==============================================================================

    UI-Constructor.cpp
    Created: 24 Oct 2021 1:40:44am
    Author:  Landon Viator

  ==============================================================================
*/

#include "../PluginEditor.h"

void MultiQAudioProcessorEditor::uiConstructor()
{
    // Window
    initWindow();
    addAndMakeVisible(windowComponent);
    
    // Output
    addAndMakeVisible(hpFader);
    hpFaderAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, highpassID, hpFader);

    addAndMakeVisible(lpFader);
    lpFaderAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, lowpassID, lpFader);

    addAndMakeVisible(driveFader);
    driveFaderAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, driveID, driveFader);

    addAndMakeVisible(trimFader);
    trimFaderAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, trimID, trimFader);

    addAndMakeVisible(phaseToggle);
    
    // Choice buttons
    addAndMakeVisible(graphicEQButton);
    graphicButtonAttach = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, graphicEQONID, graphicEQButton);
    graphicEQButton.setButtonText("Graphic");
    graphicEQButton.setRadioGroupId(1);
    graphicEQButton.onClick = [this]()
    {
        graphicEQComponent.setVisible(graphicEQButton.getToggleState());
        graphicEQComponent.setEnabled(graphicEQButton.getToggleState());
    };
    
    addAndMakeVisible(paraEQButton);
    parametricButtonAttach = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, paraEQONID, paraEQButton);
    paraEQButton.setButtonText("Parametric");
    paraEQButton.setRadioGroupId(1);
    paraEQButton.onClick = [this]()
    {
        parametricEQComponent.setVisible(paraEQButton.getToggleState());
        parametricEQComponent.setEnabled(paraEQButton.getToggleState());
    };
    
    addAndMakeVisible(tubeEQButton);
    tubeButtonAttach = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, tubeEQONID, tubeEQButton);
    tubeEQButton.setButtonText("Tube");
    tubeEQButton.setRadioGroupId(1);
    tubeEQButton.onClick = [this]()
    {
        tubeEQComponent.setVisible(tubeEQButton.getToggleState());
        tubeEQComponent.setEnabled(tubeEQButton.getToggleState());
    };
    
    // Graphic EQ
    addAndMakeVisible(graphicEQComponent);
    graphicEQComponent.setVisible(graphicEQButton.getToggleState());
    graphicEQComponent.setEnabled(graphicEQButton.getToggleState());
    
    // Parametric EQ
    addAndMakeVisible(parametricEQComponent);
    parametricEQComponent.setVisible(paraEQButton.getToggleState());
    parametricEQComponent.setEnabled(paraEQButton.getToggleState());
    
    // Tube EQ
    addAndMakeVisible(tubeEQComponent);
    tubeEQComponent.setVisible(tubeEQButton.getToggleState());
    tubeEQComponent.setEnabled(tubeEQButton.getToggleState());
}
