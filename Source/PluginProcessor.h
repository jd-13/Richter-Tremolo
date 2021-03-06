/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include <memory>
#include "../JuceLibraryCode/JuceHeader.h"
#include "CoreJUCEPlugin/CoreAudioProcessor.h"
#include "ParameterData.h"
#include "Richter.h"



//==============================================================================
/**
*/
class RichterAudioProcessor  : public WECore::JUCEPlugin::CoreAudioProcessor
{
public:
    //==============================================================================
    RichterAudioProcessor();
    ~RichterAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void reset() override;


    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

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
    const RichterLFOCache& getLFOCache() { return mRichter.getLFOCache(); }

    /**
     * Parameter setters.
     *
     * For float parameters a value in the normalised 0 to 1 range is expected.
     *
     * For int parameters are used to represent menu items, the integer value in the real range of
     * the parameter (eg. 0 to 4) is expected.
     *
     * For bool parameters they can only be true or false anyway.
     *
     * These do not call the ChangeBroadcaster as the UI will already know about these changes since
     * it is the only one calling these methods.
     */
    /** @{ */
    void setBypassSwitchLFO1(bool val);
    void setPhaseSyncLFO1(bool val);
    void setTempoSyncLFO1(bool val);
    void setInvertLFO1(bool val);
    void setWaveLFO1(int val);
    void setDepthLFO1(float val);
    void setDepthModLFO1(float val);
    void setFreqLFO1(float val);
    void setFreqModLFO1(float val);
    void setPhaseLFO1(float val);
    void setTempoNumerLFO1(int val);
    void setTempoDenomLFO1(int val);

    void setBypassSwitchLFO2(bool val);
    void setPhaseSyncLFO2(bool val);
    void setTempoSyncLFO2(bool val);
    void setInvertLFO2(bool val);
    void setWaveLFO2(int val);
    void setDepthLFO2(float val);
    void setDepthModLFO2(float val);
    void setFreqLFO2(float val);
    void setFreqModLFO2(float val);
    void setPhaseLFO2(float val);
    void setTempoNumerLFO2(int val);
    void setTempoDenomLFO2(int val);

    void setBypassSwitchMOD1(bool val);
    void setPhaseSyncMOD1(bool val);
    void setTempoSyncMOD1(bool val);
    void setInvertMOD1(bool val);
    void setWaveMOD1(int val);
    void setDepthMOD1(float val);
    void setFreqMOD1(float val);
    void setPhaseMOD1(float val);
    void setTempoNumerMOD1(int val);
    void setTempoDenomMOD1(int val);

    void setBypassSwitchMOD2(bool val);
    void setPhaseSyncMOD2(bool val);
    void setTempoSyncMOD2(bool val);
    void setInvertMOD2(bool val);
    void setWaveMOD2(int val);
    void setDepthMOD2(float val);
    void setFreqMOD2(float val);
    void setPhaseMOD2(float val);
    void setTempoNumerMOD2(int val);
    void setTempoDenomMOD2(int val);

    void setStereo(bool val);
    void setOutputGain(float val);
    /** @} */

    AudioParameterBool* bypassSwitchLFO1;
    AudioParameterBool* phaseSyncLFO1;
    AudioParameterBool* tempoSyncLFO1;
    AudioParameterBool* invertLFO1;
    AudioParameterInt* waveLFO1;
    AudioParameterFloat* depthLFO1;
    AudioParameterFloat* depthModLFO1;
    AudioParameterFloat* freqLFO1;
    AudioParameterFloat* freqModLFO1;
    AudioParameterFloat* phaseLFO1;
    AudioParameterInt* tempoNumerLFO1;
    AudioParameterInt* tempoDenomLFO1;

    AudioParameterBool* bypassSwitchLFO2;
    AudioParameterBool* phaseSyncLFO2;
    AudioParameterBool* tempoSyncLFO2;
    AudioParameterBool* invertLFO2;
    AudioParameterInt* waveLFO2;
    AudioParameterFloat* depthLFO2;
    AudioParameterFloat* depthModLFO2;
    AudioParameterFloat* freqLFO2;
    AudioParameterFloat* freqModLFO2;
    AudioParameterFloat* phaseLFO2;
    AudioParameterInt* tempoNumerLFO2;
    AudioParameterInt* tempoDenomLFO2;

    AudioParameterBool* bypassSwitchMOD1;
    AudioParameterBool* phaseSyncMOD1;
    AudioParameterBool* tempoSyncMOD1;
    AudioParameterBool* invertMOD1;
    AudioParameterInt* waveMOD1;
    AudioParameterFloat* depthMOD1;
    AudioParameterFloat* freqMOD1;
    AudioParameterFloat* phaseMOD1;
    AudioParameterInt* tempoNumerMOD1;
    AudioParameterInt* tempoDenomMOD1;

    AudioParameterBool* bypassSwitchMOD2;
    AudioParameterBool* phaseSyncMOD2;
    AudioParameterBool* tempoSyncMOD2;
    AudioParameterBool* invertMOD2;
    AudioParameterInt* waveMOD2;
    AudioParameterFloat* depthMOD2;
    AudioParameterFloat* freqMOD2;
    AudioParameterFloat* phaseMOD2;
    AudioParameterInt* tempoNumerMOD2;
    AudioParameterInt* tempoDenomMOD2;

    AudioParameterBool* stereo;
    AudioParameterFloat* outputGain;

private:
    Richter mRichter;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RichterAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
