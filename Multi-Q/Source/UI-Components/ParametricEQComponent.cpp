/*
  ==============================================================================

    ParametricEQComponent.cpp
    Created: 12 Apr 2022 7:10:38pm
    Author:  Landon Viator

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ParametricEQComponent.h"

//==============================================================================
ParametricEQComponent::ParametricEQComponent()
{
    addAndMakeVisible(band1GainDial);
    addAndMakeVisible(band1Label);
    band1Label.setText("Low Gain", juce::dontSendNotification);
    band1Label.attachToComponent(&band1GainDial, false);
    band1Label.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(band2GainDial);
    addAndMakeVisible(band2Label);
    band2Label.setText("Mid Gain", juce::dontSendNotification);
    band2Label.attachToComponent(&band2GainDial, false);
    band2Label.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(band3GainDial);
    addAndMakeVisible(band3Label);
    band3Label.setText("Mid Gain", juce::dontSendNotification);
    band3Label.attachToComponent(&band3GainDial, false);
    band3Label.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(band4GainDial);
    addAndMakeVisible(band4Label);
    band4Label.setText("High Gain", juce::dontSendNotification);
    band4Label.attachToComponent(&band4GainDial, false);
    band4Label.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(band1FreqDial);
    addAndMakeVisible(band1FreqLabel);
    band1FreqLabel.setText("Low Freq", juce::dontSendNotification);
    band1FreqLabel.attachToComponent(&band1FreqDial, false);
    band1FreqLabel.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(band2FreqDial);
    addAndMakeVisible(band2FreqLabel);
    band2FreqLabel.setText("Mid Freq", juce::dontSendNotification);
    band2FreqLabel.attachToComponent(&band2FreqDial, false);
    band2FreqLabel.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(band3FreqDial);
    addAndMakeVisible(band3FreqLabel);
    band3FreqLabel.setText("Mid Freq", juce::dontSendNotification);
    band3FreqLabel.attachToComponent(&band3FreqDial, false);
    band3FreqLabel.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(band4FreqDial);
    addAndMakeVisible(band4FreqLabel);
    band4FreqLabel.setText("High Freq", juce::dontSendNotification);
    band4FreqLabel.attachToComponent(&band4FreqDial, false);
    band4FreqLabel.setJustificationType(juce::Justification::centred);
}

ParametricEQComponent::~ParametricEQComponent()
{
}

void ParametricEQComponent::paint (juce::Graphics& g)
{
    
}

void ParametricEQComponent::resized()
{
    auto leftMargin = 0;
    auto topMargin = 24;
    auto sliderSize = getWidth() * 0.23;
    auto labelSize = sliderSize * 0.08f;
    
    band1GainDial.setBounds(leftMargin, topMargin, sliderSize, sliderSize);
    band1Label.setFont(juce::Font ("Helvetica", labelSize, juce::Font::FontStyleFlags::bold));

    band1FreqDial.setBounds(band1GainDial.getX(), band1GainDial.getY() + band1GainDial.getHeight() * 1.25, sliderSize, sliderSize);
    band2Label.setFont(juce::Font ("Helvetica", labelSize, juce::Font::FontStyleFlags::bold));

    band2GainDial.setBounds(band1GainDial.getX() + band1GainDial.getWidth(), topMargin, sliderSize, sliderSize);
    band3Label.setFont(juce::Font ("Helvetica", labelSize, juce::Font::FontStyleFlags::bold));

    band2FreqDial.setBounds(band2GainDial.getX(), band2GainDial.getY() + band2GainDial.getHeight() * 1.25, sliderSize, sliderSize);
    band4Label.setFont(juce::Font ("Helvetica", labelSize, juce::Font::FontStyleFlags::bold));

    band3GainDial.setBounds(band2GainDial.getX() + band2GainDial.getWidth(), topMargin, sliderSize, sliderSize);
    band1FreqLabel.setFont(juce::Font ("Helvetica", labelSize, juce::Font::FontStyleFlags::bold));

    band3FreqDial.setBounds(band3GainDial.getX(), band3GainDial.getY() + band3GainDial.getHeight() * 1.25, sliderSize, sliderSize);
    band2FreqLabel.setFont(juce::Font ("Helvetica", labelSize, juce::Font::FontStyleFlags::bold));

    band4GainDial.setBounds(band3GainDial.getX() + band3GainDial.getWidth(), topMargin, sliderSize, sliderSize);
    band3FreqLabel.setFont(juce::Font ("Helvetica", labelSize, juce::Font::FontStyleFlags::bold));

    band4FreqDial.setBounds(band4GainDial.getX(), band4GainDial.getY() + band4GainDial.getHeight() * 1.25, sliderSize, sliderSize);
    band4FreqLabel.setFont(juce::Font ("Helvetica", labelSize, juce::Font::FontStyleFlags::bold));

}
