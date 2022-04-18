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
GraphicEQComponent::GraphicEQComponent(MultiQAudioProcessor& p) : audioProcessor(p)
{
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    
    addAndMakeVisible(band1);
    band1FaderAttach = std::make_unique<SliderAttachment>(audioProcessor.treeState, graphicFilter1GainID, band1);

    addAndMakeVisible(band1Label);
    band1Label.setText("31", juce::dontSendNotification);
    band1Label.attachToComponent(&band1, false);
    band1Label.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(band2);
    band2FaderAttach = std::make_unique<SliderAttachment>(audioProcessor.treeState, graphicFilter2GainID, band2);

    addAndMakeVisible(band2Label);
    band2Label.setText("63", juce::dontSendNotification);
    band2Label.attachToComponent(&band2, false);
    band2Label.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(band3);
    band3FaderAttach = std::make_unique<SliderAttachment>(audioProcessor.treeState, graphicFilter3GainID, band3);

    addAndMakeVisible(band3Label);
    band3Label.setText("125", juce::dontSendNotification);
    band3Label.attachToComponent(&band3, false);
    band3Label.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(band4);
    band4FaderAttach = std::make_unique<SliderAttachment>(audioProcessor.treeState, graphicFilter4GainID, band4);

    addAndMakeVisible(band4Label);
    band4Label.setText("250", juce::dontSendNotification);
    band4Label.attachToComponent(&band4, false);
    band4Label.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(band5);
    band5FaderAttach = std::make_unique<SliderAttachment>(audioProcessor.treeState, graphicFilter5GainID, band5);

    addAndMakeVisible(band5Label);
    band5Label.setText("500", juce::dontSendNotification);
    band5Label.attachToComponent(&band5, false);
    band5Label.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(band6);
    band6FaderAttach = std::make_unique<SliderAttachment>(audioProcessor.treeState, graphicFilter6GainID, band6);

    addAndMakeVisible(band6Label);
    band6Label.setText("1K", juce::dontSendNotification);
    band6Label.attachToComponent(&band6, false);
    band6Label.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(band7);
    band7FaderAttach = std::make_unique<SliderAttachment>(audioProcessor.treeState, graphicFilter7GainID, band7);

    addAndMakeVisible(band7Label);
    band7Label.setText("2K", juce::dontSendNotification);
    band7Label.attachToComponent(&band7, false);
    band7Label.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(band8);
    band8FaderAttach = std::make_unique<SliderAttachment>(audioProcessor.treeState, graphicFilter8GainID, band8);

    addAndMakeVisible(band8Label);
    band8Label.setText("4K", juce::dontSendNotification);
    band8Label.attachToComponent(&band8, false);
    band8Label.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(band9);
    band9FaderAttach = std::make_unique<SliderAttachment>(audioProcessor.treeState, graphicFilter9GainID, band9);

    addAndMakeVisible(band9Label);
    band9Label.setText("8K", juce::dontSendNotification);
    band9Label.attachToComponent(&band9, false);
    band9Label.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(band10);
    band10FaderAttach = std::make_unique<SliderAttachment>(audioProcessor.treeState, graphicFilter10GainID, band10);

    addAndMakeVisible(band10Label);
    band10Label.setText("15K", juce::dontSendNotification);
    band10Label.attachToComponent(&band10, false);
    band10Label.setJustificationType(juce::Justification::centred);
    
    
}

GraphicEQComponent::~GraphicEQComponent()
{
    DBG("Destroyed");
}

void GraphicEQComponent::paint (juce::Graphics& g)
{
}

void GraphicEQComponent::resized()
{
    auto leftMargin = 12;
    auto topMargin = 24;
    auto faderWidth = getWidth() * 0.1;
    auto faderheight = faderWidth * 2.35;
    auto spaceBetween = 1.85;

    band1.setBounds(leftMargin, topMargin, faderWidth, faderheight);
    band1Label.setFont(juce::Font ("Helvetica", band1.getWidth() * 0.2f, juce::Font::FontStyleFlags::bold));

    band2.setBounds(band1.getX() + band1.getWidth() * spaceBetween, topMargin, faderWidth, faderheight);
    band2Label.setFont(juce::Font ("Helvetica", band1.getWidth() * 0.2f, juce::Font::FontStyleFlags::bold));
    
    band3.setBounds(band2.getX() + band2.getWidth() * spaceBetween, topMargin, faderWidth, faderheight);
    band3Label.setFont(juce::Font ("Helvetica", band1.getWidth() * 0.2f, juce::Font::FontStyleFlags::bold));
    
    band4.setBounds(band3.getX() + band3.getWidth() * spaceBetween, topMargin, faderWidth, faderheight);
    band4Label.setFont(juce::Font ("Helvetica", band1.getWidth() * 0.2f, juce::Font::FontStyleFlags::bold));
    
    band5.setBounds(band4.getX() + band4.getWidth() * spaceBetween, topMargin, faderWidth, faderheight);
    band5Label.setFont(juce::Font ("Helvetica", band1.getWidth() * 0.2f, juce::Font::FontStyleFlags::bold));
    
    auto bottomMargin = band4.getY() + band4.getHeight() * 1.2;
    
    band6.setBounds(band1.getX(), bottomMargin, faderWidth, faderheight);
    band6Label.setFont(juce::Font ("Helvetica", band1.getWidth() * 0.2f, juce::Font::FontStyleFlags::bold));
    
    band7.setBounds(band2.getX(), bottomMargin, faderWidth, faderheight);
    band7Label.setFont(juce::Font ("Helvetica", band1.getWidth() * 0.2f, juce::Font::FontStyleFlags::bold));
    
    band8.setBounds(band3.getX(), bottomMargin, faderWidth, faderheight);
    band8Label.setFont(juce::Font ("Helvetica", band1.getWidth() * 0.2f, juce::Font::FontStyleFlags::bold));
    
    band9.setBounds(band4.getX(), bottomMargin, faderWidth, faderheight);
    band9Label.setFont(juce::Font ("Helvetica", band1.getWidth() * 0.2f, juce::Font::FontStyleFlags::bold));
    
    band10.setBounds(band5.getX(), bottomMargin, faderWidth, faderheight);
    band10Label.setFont(juce::Font ("Helvetica", band1.getWidth() * 0.2f, juce::Font::FontStyleFlags::bold));
}
