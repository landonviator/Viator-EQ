/*
  ==============================================================================

    LV_Window.h
    Created: 23 Oct 2021 12:53:38am
    Author:  Landon Viator

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../PluginProcessor.h"

//==============================================================================
/*
*/
class LV_Window  : public juce::Component
{
public:
    LV_Window(MultiQAudioProcessor& p);
    ~LV_Window() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
private:
    
    MultiQAudioProcessor& audioProcessor;
    
    juce::HyperlinkButton mWebLink;
    juce::URL mWebUrl {"https://www.patreon.com/ViatorDSP"};
    
    viator_gui::Toggle phaseToggle {""};
    viator_gui::Menu osMenu;
    viator_gui::Menu stereoMenu;
    
    std::unique_ptr <juce::AudioProcessorValueTreeState::ButtonAttachment> phaseButtonAttach;
    std::unique_ptr <juce::AudioProcessorValueTreeState::ComboBoxAttachment> osAttach;
    std::unique_ptr <juce::AudioProcessorValueTreeState::ComboBoxAttachment> msAttach;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LV_Window)
};
