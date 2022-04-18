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
LV_Window::LV_Window(MultiQAudioProcessor& p) : audioProcessor(p)
{
    addAndMakeVisible(phaseToggle);
    phaseToggle.setToggleStyle(viator_gui::Toggle::ToggleStyle::kPhase);
    phaseButtonAttach = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, phaseID, phaseToggle);
    
    addAndMakeVisible(osMenu);
    osMenu.setText("Quality");
    osMenu.addItem("Normal", 1);
    osMenu.addItem("High", 2);
    osAttach = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.treeState, qualityID, osMenu);
    
    addAndMakeVisible(stereoMenu);
    stereoMenu.setText("M / S");
    stereoMenu.addItem("Stereo", 1);
    stereoMenu.addItem("Mid", 2);
    stereoMenu.addItem("Sides", 3);
    msAttach = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.treeState, msID, stereoMenu);
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
    auto buttonSize = getWidth() * 0.05;
    auto menuWidth = getWidth() * 0.1;
    auto menuHeight = menuWidth * 0.33;
    
    phaseToggle.setBounds(getWidth() * 0.65, getHeight() * 0.81, buttonSize, buttonSize);
    osMenu.setBounds(phaseToggle.getX() + phaseToggle.getWidth(), phaseToggle.getY() * 1.02, menuWidth, menuHeight);
    stereoMenu.setBounds(osMenu.getX() + osMenu.getWidth(), osMenu.getY(), menuWidth, menuHeight);
}

