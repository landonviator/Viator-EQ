/*
  ==============================================================================

    TubeEQComponent.h
    Created: 12 Apr 2022 7:10:54pm
    Author:  Landon Viator

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class TubeEQComponent  : public juce::Component
{
public:
    TubeEQComponent();
    ~TubeEQComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    viator_gui::Dial lowBoostDial {" dB", "Low Boost", 0.0, 10.0, 0.1, 0.0};
    viator_gui::Label lowBoostLabel;
    
    viator_gui::Dial lowCutDial {" dB", "Low Cut", 0.0, 10.0, 0.1, 0.0};
    viator_gui::Label lowCutLabel;
    
    viator_gui::Dial lowFreqDial {" Hz", "Low Freq", 30.0, 300.0, 1.0, 30.0};
    viator_gui::Label lowFreqLabel;
    
    viator_gui::Dial bandwidthDial {" BW", "Band Width", 0.0, 10.0, 0.1, 0.0};
    viator_gui::Label bandwidthLabel;
    
    viator_gui::Dial highBoostDial {" dB", "High Boost", 0.0, 10.0, 0.1, 0.0};
    viator_gui::Label highBoostLabel;
    
    viator_gui::Dial highCutDial {" dB", "High Cut", 0.0, 10.0, 0.1, 0.0};
    viator_gui::Label highCutLabel;
    
    viator_gui::Dial highFreqDial {" Hz", "High Freq", 1000.0, 16000.0, 1.0, 0.0};
    viator_gui::Label highFreqLabel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TubeEQComponent)
};
