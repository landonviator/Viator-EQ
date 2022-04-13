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
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TubeEQComponent)
};
