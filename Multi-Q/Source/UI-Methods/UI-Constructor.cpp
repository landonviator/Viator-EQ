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
    
    // Graphic EQ
    addAndMakeVisible(graphicEQComponent);
    
    // Choice buttons
    addAndMakeVisible(graphicEQButton);
    graphicEQButton.setButtonText("Graphic");
    graphicEQButton.setRadioGroupId(1);
    
    addAndMakeVisible(paraEQButton);
    paraEQButton.setButtonText("Parametric");
    paraEQButton.setRadioGroupId(1);
    
    addAndMakeVisible(tubeEQButton);
    tubeEQButton.setButtonText("Tube");
    tubeEQButton.setRadioGroupId(1);
}
