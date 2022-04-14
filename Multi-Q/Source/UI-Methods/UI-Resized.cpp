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
    auto leftMargin = getWidth() * 0.075;
    auto topMargin = getHeight() * 0.085;
    
    // Window
    windowComponent.setBounds(getLocalBounds());
    
    // Graphic EQ Component
    graphicEQComponent.setBounds(leftMargin, topMargin, getWidth() * 0.6, getHeight() * 0.7);
    
    // Output
    outputComponent.setBounds(leftMargin + getWidth() * 0.55, topMargin, getWidth() * 0.5, getHeight() * 0.7);
    
    // Save plugin size in the tree
    saveWindowSize();
}
