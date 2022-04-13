/*
  ==============================================================================

    GraphicEQComponent.h
    Created: 12 Apr 2022 7:10:23pm
    Author:  Landon Viator

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class GraphicEQComponent  : public juce::Component
{
public:
    GraphicEQComponent();
    ~GraphicEQComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    viator_gui::Fader band1 {" dB", "Gain", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Fader band2 {" dB", "Gain", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Fader band3 {" dB", "Gain", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Fader band4 {" dB", "Gain", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Fader band5 {" dB", "Gain", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Fader band6 {" dB", "Gain", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Fader band7 {" dB", "Gain", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Fader band8 {" dB", "Gain", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Fader band9 {" dB", "Gain", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Fader band10 {" dB", "Gain", -12.0, 12.0, 0.01, 0.0};
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GraphicEQComponent)
};
