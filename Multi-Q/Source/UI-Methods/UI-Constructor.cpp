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
    // Highpass
    addAndMakeVisible(hpFader);
    hpFaderAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, highpassID, hpFader);
    addAndMakeVisible(hpFaderLabel);
    hpFaderLabel.setText("HP", juce::dontSendNotification);
    hpFaderLabel.attachToComponent(&hpFader, false);
    hpFaderLabel.setJustificationType(juce::Justification::centred);

    // Lowpass
    addAndMakeVisible(lpFader);
    lpFaderAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, lowpassID, lpFader);
    addAndMakeVisible(lpFaderLabel);
    lpFaderLabel.setText("LP", juce::dontSendNotification);
    lpFaderLabel.attachToComponent(&lpFader, false);
    lpFaderLabel.setJustificationType(juce::Justification::centred);

    // Drive
    addAndMakeVisible(driveFader);
    driveFaderAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, driveID, driveFader);
    addAndMakeVisible(driveFaderLabel);
    driveFaderLabel.setText("Drive", juce::dontSendNotification);
    driveFaderLabel.attachToComponent(&driveFader, false);
    driveFaderLabel.setJustificationType(juce::Justification::centred);

    // Trim
    addAndMakeVisible(trimFader);
    trimFaderAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, trimID, trimFader);
    addAndMakeVisible(trimFaderLabel);
    trimFaderLabel.setText("Trim", juce::dontSendNotification);
    trimFaderLabel.attachToComponent(&trimFader, false);
    trimFaderLabel.setJustificationType(juce::Justification::centred);

    // Phase
    addAndMakeVisible(phaseToggle);
    
    // Choice buttons
    // Graphic
    addAndMakeVisible(graphicEQButton);
    graphicButtonAttach = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, graphicEQONID, graphicEQButton);
    graphicEQButton.setButtonText("Graphic");
    graphicEQButton.setRadioGroupId(1);
    graphicEQButton.onClick = [this]()
    {
        graphicEQComponent.setVisible(graphicEQButton.getToggleState());
        graphicEQComponent.setEnabled(graphicEQButton.getToggleState());
    };
    
    // Parametric
    addAndMakeVisible(paraEQButton);
    parametricButtonAttach = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, paraEQONID, paraEQButton);
    paraEQButton.setButtonText("Parametric");
    paraEQButton.setRadioGroupId(1);
    paraEQButton.onClick = [this]()
    {
        parametricEQComponent.setVisible(paraEQButton.getToggleState());
        parametricEQComponent.setEnabled(paraEQButton.getToggleState());
    };
    
    // Tube
    addAndMakeVisible(tubeEQButton);
    tubeButtonAttach = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, tubeEQONID, tubeEQButton);
    tubeEQButton.setButtonText("Tube");
    tubeEQButton.setRadioGroupId(1);
    tubeEQButton.onClick = [this]()
    {
        tubeEQComponent.setVisible(tubeEQButton.getToggleState());
        tubeEQComponent.setEnabled(tubeEQButton.getToggleState());
    };
    
    // EQ Components
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
