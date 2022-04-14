/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "./UI-Components/LV_Window.h"
#include "./UI-Components/GraphicEQComponent.h"
#include "./UI-Components/OutputComponent.h"

//==============================================================================
/**
*/
class MultiQAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    MultiQAudioProcessorEditor (MultiQAudioProcessor&);
    ~MultiQAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MultiQAudioProcessor& audioProcessor;
    
    /** Boiler plate UI stuff */
    void uiConstructor();
    void initWindow();
    void uiPaint(juce::Graphics &g);
    void uiResized();
    void saveWindowSize();
    bool constructorFinished = false;
    
    /** Window */
    LV_Window windowComponent;
    
    /** Output */
    OutputComponent outputComponent;
    
    /** Graphic EQ*/
    GraphicEQComponent graphicEQComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MultiQAudioProcessorEditor)
};
