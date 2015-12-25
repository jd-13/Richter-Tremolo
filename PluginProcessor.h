/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Richter.h"
#include "ParameterData.h"


//==============================================================================
/**
*/
class RichterAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    RichterAudioProcessor();
    ~RichterAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    int getNumParameters() override;
    float getParameter (int index) override;
    void setParameter (int index, float newValue) override;
    bool isParameterAutomatable(int parameterIndex) const override;

    const String getParameterName (int index) override;
    const String getParameterText (int index) override;

    const String getInputChannelName (int channelIndex) const override;
    const String getOutputChannelName (int channelIndex) const override;
    bool isInputChannelStereoPair (int index) const override;
    bool isOutputChannelStereoPair (int index) const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    enum Parameters {
        bypassSwitchLFO1 = 0,
        tempoSyncLFO1,
        waveLFO1,
        depthLFO1,
        depthModLFO1,
        freqLFO1,
        freqModLFO1,
        tempoNumerLFO1,
        tempoDenomLFO1,
        
        bypassSwitchLFO2,
        tempoSyncLFO2,
        waveLFO2,
        depthLFO2,
        depthModLFO2,
        freqLFO2,
        freqModLFO2,
        tempoNumerLFO2,
        tempoDenomLFO2,
        
        bypassSwitchMOD1,
        tempoSyncMOD1,
        waveMOD1,
        depthMOD1,
        freqMOD1,
        tempoNumerMOD1,
        tempoDenomMOD1,
        
        bypassSwitchMOD2,
        tempoSyncMOD2,
        waveMOD2,
        depthMOD2,
        freqMOD2,
        tempoNumerMOD2,
        tempoDenomMOD2,
        
        masterVol,
        totalNumParams
    };
    
    bool NeedsUIUpdate() {
        return UIUpdateFlag;
    }
    
    void RequestUIUpdate() {
        UIUpdateFlag = true;
    }
    
    void ClearUIUpdate() {
        UIUpdateFlag = false;
    }

private:
    Richter mRichter;
    bool UIUpdateFlag;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RichterAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
