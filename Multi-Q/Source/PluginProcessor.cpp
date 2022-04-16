/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MultiQAudioProcessor::MultiQAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
, treeState(*this, nullptr, "PARAMETERS", createParameterLayout())
#endif
{
    treeState.addParameterListener(graphicFilter1GainID, this);
    treeState.addParameterListener(graphicFilter2GainID, this);
    treeState.addParameterListener(graphicFilter3GainID, this);
    treeState.addParameterListener(graphicFilter4GainID, this);
    treeState.addParameterListener(graphicFilter5GainID, this);
    treeState.addParameterListener(graphicFilter6GainID, this);
    treeState.addParameterListener(graphicFilter7GainID, this);
    treeState.addParameterListener(graphicFilter8GainID, this);
    treeState.addParameterListener(graphicFilter9GainID, this);
    treeState.addParameterListener(graphicFilter10GainID, this);
    
    treeState.addParameterListener(highpassID, this);
    treeState.addParameterListener(lowpassID, this);
    
    treeState.addParameterListener(driveID, this);
    treeState.addParameterListener(trimID, this);
}

MultiQAudioProcessor::~MultiQAudioProcessor()
{
    treeState.removeParameterListener(graphicFilter1GainID, this);
    treeState.removeParameterListener(graphicFilter2GainID, this);
    treeState.removeParameterListener(graphicFilter3GainID, this);
    treeState.removeParameterListener(graphicFilter4GainID, this);
    treeState.removeParameterListener(graphicFilter5GainID, this);
    treeState.removeParameterListener(graphicFilter6GainID, this);
    treeState.removeParameterListener(graphicFilter7GainID, this);
    treeState.removeParameterListener(graphicFilter8GainID, this);
    treeState.removeParameterListener(graphicFilter9GainID, this);
    treeState.removeParameterListener(graphicFilter10GainID, this);
    
    treeState.removeParameterListener(highpassID, this);
    treeState.removeParameterListener(lowpassID, this);
    
    treeState.removeParameterListener(driveID, this);
    treeState.removeParameterListener(trimID, this);
}

juce::AudioProcessorValueTreeState::ParameterLayout MultiQAudioProcessor::createParameterLayout()
{
    std::vector <std::unique_ptr<juce::RangedAudioParameter>> params;
    
    auto gF1 = std::make_unique<juce::AudioParameterFloat>(graphicFilter1GainID, graphicFilter1GainName, -12.0f, 12.0f, 0.0f);
    auto gF2 = std::make_unique<juce::AudioParameterFloat>(graphicFilter2GainID, graphicFilter2GainName, -12.0f, 12.0f, 0.0f);
    auto gF3 = std::make_unique<juce::AudioParameterFloat>(graphicFilter3GainID, graphicFilter3GainName, -12.0f, 12.0f, 0.0f);
    auto gF4 = std::make_unique<juce::AudioParameterFloat>(graphicFilter4GainID, graphicFilter4GainName, -12.0f, 12.0f, 0.0f);
    auto gF5 = std::make_unique<juce::AudioParameterFloat>(graphicFilter5GainID, graphicFilter5GainName, -12.0f, 12.0f, 0.0f);
    auto gF6 = std::make_unique<juce::AudioParameterFloat>(graphicFilter6GainID, graphicFilter6GainName, -12.0f, 12.0f, 0.0f);
    auto gF7 = std::make_unique<juce::AudioParameterFloat>(graphicFilter7GainID, graphicFilter7GainName, -12.0f, 12.0f, 0.0f);
    auto gF8 = std::make_unique<juce::AudioParameterFloat>(graphicFilter8GainID, graphicFilter8GainName, -12.0f, 12.0f, 0.0f);
    auto gF9 = std::make_unique<juce::AudioParameterFloat>(graphicFilter9GainID, graphicFilter9GainName, -12.0f, 12.0f, 0.0f);
    auto gF10 = std::make_unique<juce::AudioParameterFloat>(graphicFilter10GainID, graphicFilter10GainName, -12.0f, 12.0f, 0.0f);
    
    auto hpParam = std::make_unique<juce::AudioParameterFloat>(highpassID, highpassName, 20.0f, 1000.0f, 20.0f);
    auto lpParam = std::make_unique<juce::AudioParameterFloat>(lowpassID, lowpassName, 1000.0f, 20000.0f, 20000.0f);
    
    auto driveParam = std::make_unique<juce::AudioParameterFloat>(driveID, driveName, 0.0f, 12.0f, 0.0f);
    auto trimParam = std::make_unique<juce::AudioParameterFloat>(trimID, trimName, -24.0f, 24.0f, 0.0f);
    
    params.push_back(std::move(gF1));
    params.push_back(std::move(gF2));
    params.push_back(std::move(gF3));
    params.push_back(std::move(gF4));
    params.push_back(std::move(gF5));
    params.push_back(std::move(gF6));
    params.push_back(std::move(gF7));
    params.push_back(std::move(gF8));
    params.push_back(std::move(gF9));
    params.push_back(std::move(gF10));
    
    params.push_back(std::move(hpParam));
    params.push_back(std::move(lpParam));
    
    params.push_back(std::move(driveParam));
    params.push_back(std::move(trimParam));
    
    return { params.begin(), params.end() };
}

void MultiQAudioProcessor::parameterChanged(const juce::String &parameterID, float newValue)
{
    if (parameterID == "trim")
    {
        DBG(newValue);
    }
}

//==============================================================================
const juce::String MultiQAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MultiQAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MultiQAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MultiQAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double MultiQAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MultiQAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int MultiQAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MultiQAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String MultiQAudioProcessor::getProgramName (int index)
{
    return {};
}

void MultiQAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void MultiQAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Initialize spec for dsp modules
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = getTotalNumOutputChannels();
    
}

void MultiQAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MultiQAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void MultiQAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

}

//==============================================================================
bool MultiQAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* MultiQAudioProcessor::createEditor()
{
    return new MultiQAudioProcessorEditor (*this);
    //return new juce::GenericAudioProcessorEditor (*this);
}

//==============================================================================
void MultiQAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // Save params
    treeState.state.appendChild(variableTree, nullptr);
    juce::MemoryOutputStream stream(destData, false);
    treeState.state.writeToStream (stream);
}

void MultiQAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // Recall params
    auto tree = juce::ValueTree::readFromData (data, size_t(sizeInBytes));
    variableTree = tree.getChildWithName("Variables");
    
    if (tree.isValid())
    {
        treeState.state = tree;
        
        // Window Size
        windowWidth = variableTree.getProperty("width");
        windowHeight = variableTree.getProperty("height");
    }
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MultiQAudioProcessor();
}
