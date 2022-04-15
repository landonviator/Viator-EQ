/*
  ==============================================================================

    ParametricEQComponent.h
    Created: 12 Apr 2022 7:10:38pm
    Author:  Landon Viator

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ParametricEQComponent  : public juce::Component
{
public:
    ParametricEQComponent();
    ~ParametricEQComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    viator_gui::Dial band1GainDial {" dB", "Gain", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Dial band2GainDial {" dB", "Gain", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Dial band3GainDial {" dB", "Gain", -12.0, 12.0, 0.01, 0.0};
    viator_gui::Dial band4GainDial {" dB", "Gain", -12.0, 12.0, 0.01, 0.0};
    
    viator_gui::Dial band1FreqDial {" Hz", "Freq", 30.0, 400.0, 1.0, 0.0};
    viator_gui::Dial band2FreqDial {" Hz", "Freq", 200.0, 2000.0, 1.0, 0.0};
    viator_gui::Dial band3FreqDial {" Hz", "Freq", 200.0, 2000.0, 1.0, 0.0};
    viator_gui::Dial band4FreqDial {" Hz", "Freq", 1000.0, 20000.0, 1.0, 0.0};
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParametricEQComponent)
};
