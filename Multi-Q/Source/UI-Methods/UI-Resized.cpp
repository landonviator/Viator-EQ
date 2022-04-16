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
    
    // Parametric EQ
    parametricEQComponent.setBounds(leftMargin, topMargin, getWidth() * 0.6, getHeight() * 0.7);
    
    // Tube EQ
    tubeEQComponent.setBounds(leftMargin, topMargin, getWidth() * 0.6, getHeight() * 0.7);
    
    // Output
    auto leftOutputMargin = getWidth() * 0.64;
    auto topOutputMargin = getHeight() * 0.12;
    auto faderheight = getHeight() * 0.55;
    auto faderWidth = getWidth() * 0.065;
    auto buttonWidth = faderWidth * 1.3333;
    auto buttonheight = buttonWidth * 0.33;
    
    hpFader.setBounds(leftOutputMargin, topOutputMargin, faderWidth, faderheight);
    lpFader.setBounds(hpFader.getX() + hpFader.getWidth(), topOutputMargin, faderWidth, faderheight);
    driveFader.setBounds(lpFader.getX() + lpFader.getWidth(), topOutputMargin, faderWidth, faderheight);
    trimFader.setBounds(driveFader.getX() + driveFader.getWidth(), topOutputMargin, faderWidth, faderheight);
    
    graphicEQButton.setBounds(hpFader.getX(), driveFader.getY() + driveFader.getHeight(), buttonWidth, buttonheight);
    paraEQButton.setBounds(graphicEQButton.getX() + graphicEQButton.getWidth(), driveFader.getY() + driveFader.getHeight(), buttonWidth, buttonheight);
    tubeEQButton.setBounds(paraEQButton.getX() + paraEQButton.getWidth(), driveFader.getY() + driveFader.getHeight(), buttonWidth, buttonheight);
    
    // Save plugin size in the tree
    saveWindowSize();
}
