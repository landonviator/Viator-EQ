/*
  ==============================================================================

    OutputComponent.h
    Created: 13 Apr 2022 9:06:33pm
    Author:  Landon Viator

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class OutputComponent  : public juce::Component
{
public:
    OutputComponent();
    ~OutputComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    viator_gui::Fader driveFader {" dB", "Drive", 0.0, 12.0, 0.01, 0.0};
    viator_gui::Fader trimFader {" dB", "Trim", -12.0, 12.0, 0.01, 0.0};
    
    viator_gui::Toggle phaseToggle {""};
    
    viator_gui::PushButton graphicEQButton;
    viator_gui::PushButton paraEQButton;
    viator_gui::PushButton tubeEQButton;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OutputComponent)
};
