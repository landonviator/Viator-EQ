/*
  ==============================================================================

    UI-Resized.cpp
    Created: 24 Oct 2021 1:41:10am
    Author:  Landon Viator

  ==============================================================================
*/

#include "../PluginEditor.h"

void MultiQAudioProcessorEditor::uiResized()
{
    auto leftButtonMargin = getWidth() * 0.35;
    auto topButtonMargin = getHeight() * 0.81;
    auto buttonWidth = getWidth() * 0.1;
    auto buttonheight = buttonWidth * 0.5;
    
    // Graphic EQ Component
    graphicEQComponent.setBounds(getLocalBounds());
    
    graphicEQButton.setBounds(leftButtonMargin, topButtonMargin, buttonWidth, buttonheight);
    paraEQButton.setBounds(graphicEQButton.getX() + graphicEQButton.getWidth(), topButtonMargin, buttonWidth, buttonheight);
    tubeEQButton.setBounds(paraEQButton.getX() + paraEQButton.getWidth(), topButtonMargin, buttonWidth, buttonheight);
    
    // Save plugin size in the tree
    saveWindowSize();
}
