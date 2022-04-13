/*
  ==============================================================================

    GraphicEQComponent.cpp
    Created: 12 Apr 2022 7:10:23pm
    Author:  Landon Viator

  ==============================================================================
*/

#include <JuceHeader.h>
#include "GraphicEQComponent.h"

//==============================================================================
GraphicEQComponent::GraphicEQComponent()
{
    addAndMakeVisible(band1);
    addAndMakeVisible(band2);
    addAndMakeVisible(band3);
    addAndMakeVisible(band4);
    addAndMakeVisible(band5);
    addAndMakeVisible(band6);
    addAndMakeVisible(band7);
    addAndMakeVisible(band8);
    addAndMakeVisible(band9);
    addAndMakeVisible(band10);
    
}

GraphicEQComponent::~GraphicEQComponent()
{
}

void GraphicEQComponent::paint (juce::Graphics& g)
{
    
}

void GraphicEQComponent::resized()
{
    auto leftMargin = getWidth() * 0.1;
    auto topMargin = getHeight() * 0.12;
    auto faderheight = getHeight() * 0.28;
    auto faderWidth = faderheight * 0.65;

    band1.setBounds(leftMargin, topMargin, faderWidth, faderheight);
    band2.setBounds(band1.getX() + band1.getWidth(), topMargin, faderWidth, faderheight);
    band3.setBounds(band2.getX() + band2.getWidth(), topMargin, faderWidth, faderheight);
    band4.setBounds(band3.getX() + band3.getWidth(), topMargin, faderWidth, faderheight);
    band5.setBounds(band4.getX() + band4.getWidth(), topMargin, faderWidth, faderheight);
    
    auto bottomMargin = band4.getY() + band4.getHeight() * 1.25;
    
    band6.setBounds(band1.getX(), bottomMargin, faderWidth, faderheight);
    band7.setBounds(band2.getX(), bottomMargin, faderWidth, faderheight);
    band8.setBounds(band3.getX(), bottomMargin, faderWidth, faderheight);
    band9.setBounds(band4.getX(), bottomMargin, faderWidth, faderheight);
    band10.setBounds(band5.getX(), bottomMargin, faderWidth, faderheight);
}
