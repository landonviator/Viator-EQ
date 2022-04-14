/*
  ==============================================================================

    LV_Window.cpp
    Created: 23 Oct 2021 12:53:38am
    Author:  Landon Viator

  ==============================================================================
*/

#include <JuceHeader.h>
#include "LV_Window.h"

//==============================================================================
LV_Window::LV_Window()
{
}

LV_Window::~LV_Window()
{
}

void LV_Window::paint (juce::Graphics& g)
{
    // Background
    auto background = juce::ImageCache::getFromMemory(BinaryData::pluginBackground2_png, BinaryData::pluginBackground2_pngSize);
    g.drawImageWithin(background, 0, 0, getWidth(), getHeight(), juce::RectanglePlacement::stretchToFit);
    
    // Logo layer
    auto footerLogo = juce::ImageCache::getFromMemory(BinaryData::landon5504_png, BinaryData::landon5504_pngSize);
    
    // Draw and position the image
    g.drawImageWithin(footerLogo, getWidth() * 0.38, getHeight() * 0.8 + 4, getWidth() * 0.25, getHeight() * 0.1, juce::RectanglePlacement::centred);
    
    // Patreon link
    mWebLink.setURL(mWebUrl);
    addAndMakeVisible(mWebLink);
    mWebLink.setBounds(getWidth() * 0.38, getHeight() * 0.8 + 4, getWidth() * 0.25, getHeight() * 0.1);
    
    // Plugin text
    g.setColour (juce::Colours::whitesmoke.withAlpha(0.125f));
    g.setFont(getWidth() * 0.015);
    g.drawFittedText ("Multi-Q v1.1.1", getWidth() * 0.12, getHeight() * 0.84, getWidth(), getHeight(), juce::Justification::topLeft, 1);
}

void LV_Window::resized()
{
}

