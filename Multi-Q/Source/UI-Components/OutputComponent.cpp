/*
  ==============================================================================

    OutputComponent.cpp
    Created: 13 Apr 2022 9:06:33pm
    Author:  Landon Viator

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OutputComponent.h"

//==============================================================================
OutputComponent::OutputComponent()
{
    addAndMakeVisible(driveFader);
    addAndMakeVisible(trimFader);
    addAndMakeVisible(phaseToggle);
    
    // Choice buttons
    addAndMakeVisible(graphicEQButton);
    graphicEQButton.setButtonText("Graphic");
    graphicEQButton.setRadioGroupId(1);
    graphicEQButton.onStateChange = [this]()
    {
        
    };
    
    addAndMakeVisible(paraEQButton);
    paraEQButton.setButtonText("Parametric");
    paraEQButton.setRadioGroupId(1);
    
    addAndMakeVisible(tubeEQButton);
    tubeEQButton.setButtonText("Tube");
    tubeEQButton.setRadioGroupId(1);
}

OutputComponent::~OutputComponent()
{
}

void OutputComponent::paint (juce::Graphics& g)
{
}

void OutputComponent::resized()
{
    auto leftMargin = getWidth() * 0.045;
    auto topMargin = 24;
    auto faderheight = getHeight() * 0.78;
    auto faderWidth = faderheight * 0.4;
    auto buttonWidth = getWidth() * 0.18;
    auto buttonheight = buttonWidth * 0.33;
    
    driveFader.setBounds(leftMargin, topMargin, faderWidth, faderheight);
    trimFader.setBounds(driveFader.getX() + driveFader.getWidth() * 1.25, topMargin, faderWidth, faderheight);
    
    graphicEQButton.setBounds(0, driveFader.getY() + driveFader.getHeight(), buttonWidth, buttonheight);
    paraEQButton.setBounds(graphicEQButton.getX() + graphicEQButton.getWidth(), driveFader.getY() + driveFader.getHeight(), buttonWidth, buttonheight);
    tubeEQButton.setBounds(paraEQButton.getX() + paraEQButton.getWidth(), driveFader.getY() + driveFader.getHeight(), buttonWidth, buttonheight);
}
