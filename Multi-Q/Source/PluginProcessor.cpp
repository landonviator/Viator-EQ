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
, oversamplingModule(2, 1, juce::dsp::Oversampling<float>::FilterType::filterHalfBandPolyphaseIIR)

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
    
    treeState.addParameterListener(graphicEQONID, this);
    treeState.addParameterListener(paraEQONID, this);
    treeState.addParameterListener(tubeEQONID, this);
    
    treeState.addParameterListener(phaseID, this);
    treeState.addParameterListener(qualityID, this);
    treeState.addParameterListener(msID, this);
    
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
    
    treeState.removeParameterListener(graphicEQONID, this);
    treeState.removeParameterListener(paraEQONID, this);
    treeState.removeParameterListener(tubeEQONID, this);
    
    treeState.removeParameterListener(phaseID, this);
    treeState.removeParameterListener(qualityID, this);
    treeState.removeParameterListener(msID, this);
    
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
    
    auto gON = std::make_unique<juce::AudioParameterBool>(graphicEQONID, graphicEQONName, true);
    auto pON = std::make_unique<juce::AudioParameterBool>(paraEQONID, paraEQONName, false);
    auto tON = std::make_unique<juce::AudioParameterBool>(tubeEQONID, tubeEQONName, false);
    
    auto pPhase = std::make_unique<juce::AudioParameterBool>(phaseID, phaseName, false);
    auto pQuality = std::make_unique<juce::AudioParameterInt>(qualityID, qualityName, 0, 1, 0);
    auto pMS = std::make_unique<juce::AudioParameterInt>(msID, msName, 0, 2, 0);
    
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
    
    params.push_back(std::move(gON));
    params.push_back(std::move(pON));
    params.push_back(std::move(tON));
    
    params.push_back(std::move(pPhase));
    params.push_back(std::move(pQuality));
    params.push_back(std::move(pMS));
    
    params.push_back(std::move(hpParam));
    params.push_back(std::move(lpParam));
    
    params.push_back(std::move(driveParam));
    params.push_back(std::move(trimParam));
    
    return { params.begin(), params.end() };
}

void MultiQAudioProcessor::parameterChanged(const juce::String &parameterID, float newValue)
{
    if (parameterID == qualityID)
    {
        osToggle = static_cast<bool>(treeState.getRawParameterValue(qualityID)->load());
            
        // Adjust samplerate of filters when oversampling
        if (osToggle)
        {
            spec.sampleRate = getSampleRate() * oversamplingModule.getOversamplingFactor();
            graphicEQModule.prepare(spec);
        }

        else
        {
            spec.sampleRate = getSampleRate();
            graphicEQModule.prepare(spec);
        }
    }
    
    updateGraphicParameters();
    updateCommonParameters();
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
    /** Oversampling */
    oversamplingModule.initProcessing(samplesPerBlock);
    oversamplingModule.reset();
    
    updateCommonParameters();
    
    // Adjust samplerate of filters when oversampling
    if (osToggle)
    {
        spec.sampleRate = getSampleRate() * oversamplingModule.getOversamplingFactor();
    }

    else
    {
        spec.sampleRate = getSampleRate();
    }
    
    // Initialize spec for dsp modules
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = getTotalNumOutputChannels();
    
    graphicEQModule.prepare(spec);
    updateGraphicParameters();
}

void MultiQAudioProcessor::releaseResources()
{
    oversamplingModule.reset();
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
    
    juce::dsp::AudioBlock<float> block (buffer);
    juce::dsp::AudioBlock<float> upSampledBlock (buffer);

    // Oversample if ON
    if (osToggle)
    {
        upSampledBlock = oversamplingModule.processSamplesUp(block);
        graphicEQModule.process(juce::dsp::ProcessContextReplacing<float>(upSampledBlock));
        oversamplingModule.processSamplesDown(block);
    }

    // Don't Oversample if OFF
    else
    {
        graphicEQModule.process(juce::dsp::ProcessContextReplacing<float>(block));
    }
}

//==============================================================================
bool MultiQAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* MultiQAudioProcessor::createEditor()
{
    //return new MultiQAudioProcessorEditor (*this);
    return new juce::GenericAudioProcessorEditor (*this);
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
        
        updateCommonParameters();
        updateGraphicParameters();
    }
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MultiQAudioProcessor();
}
