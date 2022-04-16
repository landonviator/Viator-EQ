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
#include "./UI-Components/ParametricEQComponent.h"
#include "TubeEQComponent.h"

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
    
    /** Graphic EQ*/
    GraphicEQComponent graphicEQComponent;
    
    /** Parametric EQ*/
    ParametricEQComponent parametricEQComponent;
    
    /** Tube EQ */
    TubeEQComponent tubeEQComponent;
    
    viator_gui::Fader driveFader {" dB", "Drive", 0.0, 12.0, 0.01, 0.0};
    viator_gui::Fader trimFader {" dB", "Trim", -12.0, 12.0, 0.01, 0.0};
    
    viator_gui::Toggle phaseToggle {""};
    
    viator_gui::PushButton graphicEQButton;
    viator_gui::PushButton paraEQButton;
    viator_gui::PushButton tubeEQButton;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MultiQAudioProcessorEditor)
};
