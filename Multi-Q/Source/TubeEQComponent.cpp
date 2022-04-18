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
    addAndMakeVisible(lowBoostLabel);
    lowBoostLabel.setText("Low Boost", juce::dontSendNotification);
    lowBoostLabel.attachToComponent(&lowBoostDial, false);
    lowBoostLabel.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(lowCutDial);
    addAndMakeVisible(lowCutLabel);
    lowCutLabel.setText("Low Cut", juce::dontSendNotification);
    lowCutLabel.attachToComponent(&lowCutDial, false);
    lowCutLabel.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(highBoostDial);
    addAndMakeVisible(highBoostLabel);
    highBoostLabel.setText("High Boost", juce::dontSendNotification);
    highBoostLabel.attachToComponent(&highBoostDial, false);
    highBoostLabel.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(highCutDial);
    addAndMakeVisible(highCutLabel);
    highCutLabel.setText("High Cut", juce::dontSendNotification);
    highCutLabel.attachToComponent(&highCutDial, false);
    highCutLabel.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(lowFreqDial);
    lowFreqDial.setSkewFactorFromMidPoint(100.0);
    addAndMakeVisible(lowFreqLabel);
    lowFreqLabel.setText("Low Freq", juce::dontSendNotification);
    lowFreqLabel.attachToComponent(&lowFreqDial, false);
    lowFreqLabel.setJustificationType(juce::Justification::centred);
    
    
    addAndMakeVisible(highFreqDial);
    highFreqDial.setSkewFactorFromMidPoint(5000.0);
    addAndMakeVisible(highFreqLabel);
    highFreqLabel.setText("High Freq", juce::dontSendNotification);
    highFreqLabel.attachToComponent(&highFreqDial, false);
    highFreqLabel.setJustificationType(juce::Justification::centred);
    
    
    addAndMakeVisible(bandwidthDial);
    addAndMakeVisible(bandwidthLabel);
    bandwidthLabel.setText("BW", juce::dontSendNotification);
    bandwidthLabel.attachToComponent(&bandwidthDial, false);
    bandwidthLabel.setJustificationType(juce::Justification::centred);
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
    auto spaceBetweenDials = 1.05;
    auto labelSize = dialSize * 0.08f;
    
    lowBoostDial.setBounds(leftMargin, topMargin, dialSize, dialSize);
    lowBoostLabel.setFont(juce::Font ("Helvetica", labelSize, juce::Font::FontStyleFlags::bold));

    lowCutDial.setBounds(lowBoostDial.getX() + lowBoostDial.getWidth() * spaceBetweenDials, topMargin, dialSize, dialSize);
    lowCutLabel.setFont(juce::Font ("Helvetica", labelSize, juce::Font::FontStyleFlags::bold));

    highBoostDial.setBounds(lowCutDial.getX() + lowCutDial.getWidth() * spaceBetweenDials, topMargin, dialSize, dialSize);
    highBoostLabel.setFont(juce::Font ("Helvetica", labelSize, juce::Font::FontStyleFlags::bold));

    highCutDial.setBounds(highBoostDial.getX() + highBoostDial.getWidth() * spaceBetweenDials, topMargin, dialSize, dialSize);
    highCutLabel.setFont(juce::Font ("Helvetica", labelSize, juce::Font::FontStyleFlags::bold));
        
    lowFreqDial.setBounds(lowBoostDial.getX() + (lowBoostDial.getWidth() / 1.55), lowBoostDial.getY() + lowBoostDial.getHeight() * 1.2, smallDialSize, smallDialSize);
    lowFreqLabel.setFont(juce::Font ("Helvetica", labelSize, juce::Font::FontStyleFlags::bold));

    bandwidthDial.setBounds(lowFreqDial.getX() + lowFreqDial.getWidth() * 1.3, lowFreqDial.getY(), smallDialSize, smallDialSize);
    bandwidthLabel.setFont(juce::Font ("Helvetica", labelSize, juce::Font::FontStyleFlags::bold));

    highFreqDial.setBounds(highBoostDial.getX() + (highBoostDial.getWidth() / 1.55), bandwidthDial.getY(), smallDialSize, smallDialSize);
    highFreqLabel.setFont(juce::Font ("Helvetica", labelSize, juce::Font::FontStyleFlags::bold));
}
