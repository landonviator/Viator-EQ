/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "./DSP/GraphicEQ.h"
#include "./DSP/ParametricEQ.h"
#include "./DSP/TubeEQ.h"
#include "./Parameters/Parameters.h"

//==============================================================================
/**
*/
class MultiQAudioProcessor  : public juce::AudioProcessor, juce::AudioProcessorValueTreeState::Listener
{
public:
    //==============================================================================
    MultiQAudioProcessor();
    ~MultiQAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    juce::AudioProcessorValueTreeState treeState;
    
    juce::ValueTree variableTree
    { "Variables", {},
        {
        { "Group", {{ "name", "Vars" }},
            {
                { "Parameter", {{ "id", "width" }, { "value", 0.0 }}},
                { "Parameter", {{ "id", "height" }, { "value", 0.0 }}},
            }
        }
        }
    };
    
    /** Window Vars =====================================================*/
    float windowWidth {0.0f};
    float windowHeight {0.0f};

private:
    
    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    void parameterChanged (const juce::String& parameterID, float newValue) override;
    
    /** DSP */
    juce::dsp::Oversampling<float> oversamplingModule;
    juce::dsp::ProcessSpec spec;
    void updateCommonParameters();
    bool osToggle = false;
    bool phaseToggle = false;
    
    GraphicEQ<float> graphicEQModule;
    void updateGraphicParameters();
    
    ParametricEQ<float> parametricEQModule;
    void updateParametricParameters();
    
    TubeEQ<float> tubeEQModule;
    
    viator_dsp::SVFilter<float> hpFilter;
    viator_dsp::SVFilter<float> lpFilter;
    juce::dsp::Gain<float> gainModule;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MultiQAudioProcessor)
};
