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
    
    viator_gui::Fader band1 {" dB", "31", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Fader band2 {" dB", "63", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Fader band3 {" dB", "125", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Fader band4 {" dB", "250", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Fader band5 {" dB", "500", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Fader band6 {" dB", "1K", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Fader band7 {" dB", "2K", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Fader band8 {" dB", "4K", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Fader band9 {" dB", "8K", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Fader band10 {" dB", "15K", -12.0, 12.0, 0.01, 0.0};
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GraphicEQComponent)
};
