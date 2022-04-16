/*
  ==============================================================================

    TubeEQComponent.cpp
    Created: 12 Apr 2022 7:10:54pm
    Author:  Landon Viator

  ==============================================================================
*/

#include <JuceHeader.h>
#include "TubeEQComponent.h"

//==============================================================================
TubeEQComponent::TubeEQComponent()
{
    addAndMakeVisible(lowBoostDial);
    addAndMakeVisible(lowCutDial);
    addAndMakeVisible(highBoostDial);
    addAndMakeVisible(highCutDial);
    addAndMakeVisible(lowFreqDial);
    addAndMakeVisible(highFreqDial);
    addAndMakeVisible(bandwidthDial);
}

TubeEQComponent::~TubeEQComponent()
{
}

void TubeEQComponent::paint (juce::Graphics& g)
{
    
}

void TubeEQComponent::resized()
{
    auto leftMargin = 0;
    auto topMargin = 36;
    auto dialSize = getHeight() * 0.4;
    auto smallDialSize = dialSize * 0.85;
    auto spaceBetweenDials = 1.1;
    
    lowBoostDial.setBounds(leftMargin, topMargin, dialSize, dialSize);
    lowCutDial.setBounds(lowBoostDial.getX() + lowBoostDial.getWidth() * spaceBetweenDials, topMargin, dialSize, dialSize);
    highBoostDial.setBounds(lowCutDial.getX() + lowCutDial.getWidth() * spaceBetweenDials, topMargin, dialSize, dialSize);
    highCutDial.setBounds(highBoostDial.getX() + highBoostDial.getWidth() * spaceBetweenDials, topMargin, dialSize, dialSize);
        
    lowFreqDial.setBounds(lowBoostDial.getX() + (lowBoostDial.getWidth() / 1.55), lowBoostDial.getY() + lowBoostDial.getHeight() * 1.2, smallDialSize, smallDialSize);
    bandwidthDial.setBounds(lowFreqDial.getX() + lowFreqDial.getWidth() * 1.3, lowFreqDial.getY(), smallDialSize, smallDialSize);
    highFreqDial.setBounds(highBoostDial.getX() + (highBoostDial.getWidth() / 1.55), bandwidthDial.getY(), smallDialSize, smallDialSize);
}
