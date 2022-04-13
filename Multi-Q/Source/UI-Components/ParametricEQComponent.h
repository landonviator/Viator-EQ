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
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParametricEQComponent)
};
