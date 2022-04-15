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
    addAndMakeVisible(band2GainDial);
    addAndMakeVisible(band3GainDial);
    addAndMakeVisible(band4GainDial);
    
    addAndMakeVisible(band1FreqDial);
    addAndMakeVisible(band2FreqDial);
    addAndMakeVisible(band3FreqDial);
    addAndMakeVisible(band4FreqDial);
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
    
    band1GainDial.setBounds(leftMargin, topMargin, sliderSize, sliderSize);
    band1FreqDial.setBounds(band1GainDial.getX(), band1GainDial.getY() + band1GainDial.getHeight() * 1.25, sliderSize, sliderSize);

    band2GainDial.setBounds(band1GainDial.getX() + band1GainDial.getWidth(), topMargin, sliderSize, sliderSize);
    band2FreqDial.setBounds(band2GainDial.getX(), band2GainDial.getY() + band2GainDial.getHeight() * 1.25, sliderSize, sliderSize);

    band3GainDial.setBounds(band2GainDial.getX() + band2GainDial.getWidth(), topMargin, sliderSize, sliderSize);
    band3FreqDial.setBounds(band3GainDial.getX(), band3GainDial.getY() + band3GainDial.getHeight() * 1.25, sliderSize, sliderSize);

    band4GainDial.setBounds(band3GainDial.getX() + band3GainDial.getWidth(), topMargin, sliderSize, sliderSize);
    band4FreqDial.setBounds(band4GainDial.getX(), band4GainDial.getY() + band4GainDial.getHeight() * 1.25, sliderSize, sliderSize);
}
