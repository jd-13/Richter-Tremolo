/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
RichterAudioProcessor::RichterAudioProcessor()
{
    namespace RP = WECore::Richter::Parameters;

    // Set defaults
    mRichter.LFOPair1.LFO.setBypassSwitch(RP::LFOSWITCH_ON);
    mRichter.LFOPair2.LFO.setBypassSwitch(RP::LFOSWITCH_ON);

    registerParameter(bypassSwitchLFO1, SWITCHLFO1_STR, RP::LFOSWITCH_ON, [&](bool val) { setBypassSwitchLFO1(val); });
    registerParameter(phaseSyncLFO1, PHASELFO1_STR, RP::PHASESYNC_DEFAULT, [&](bool val) { setPhaseSyncLFO1(val); });
    registerParameter(tempoSyncLFO1, TEMPOSYNCLFO1_STR, RP::TEMPOSYNC_DEFAULT, [&](bool val) { setTempoSyncLFO1(val); });
    registerParameter(waveLFO1, WAVELFO1_STR, &RP::WAVE, RP::WAVE.defaultValue, [&](int val) { setWaveLFO1(val); });
    registerParameter(depthLFO1, DEPTHLFO1_STR, &RP::DEPTH, RP::DEPTH.defaultValue, [&](float val) { setDepthLFO1(val); });
    registerParameter(depthModLFO1, DEPTHMODLFO1_STR, &RP::DEPTHMOD, RP::DEPTHMOD.defaultValue, [&](float val) { setDepthModLFO1(val); });
    registerParameter(freqLFO1, FREQLFO1_STR, &RP::FREQ, RP::FREQ.defaultValue, [&](float val) { setFreqLFO1(val); });
    registerParameter(freqModLFO1, FREQMODLFO1_STR, &RP::FREQMOD, RP::FREQMOD.defaultValue, [&](float val) { setFreqModLFO1(val); });
    registerParameter(phaseLFO1, PHASELFO1_STR, &RP::PHASE, RP::PHASE.defaultValue, [&](float val) { setPhaseLFO1(val); });
    registerParameter(tempoNumerLFO1, TEMPONUMERLFO1_STR,&RP::TEMPONUMER, RP::TEMPONUMER.defaultValue, [&](int val) { setTempoNumerLFO1(val); });
    registerParameter(tempoDenomLFO1, TEMPODENOMLFO1_STR, &RP::TEMPODENOM, RP::TEMPODENOM.defaultValue, [&](int val) { setTempoDenomLFO1(val); });

    registerParameter(bypassSwitchLFO2, SWITCHLFO2_STR, RP::LFOSWITCH_ON, [&](bool val) { setBypassSwitchLFO2(val); });
    registerParameter(phaseSyncLFO2, PHASELFO2_STR, RP::PHASESYNC_DEFAULT, [&](bool val) { setPhaseSyncLFO2(val); });
    registerParameter(tempoSyncLFO2, TEMPOSYNCLFO2_STR, RP::TEMPOSYNC_DEFAULT, [&](bool val) { setTempoSyncLFO2(val); });
    registerParameter(waveLFO2, WAVELFO2_STR, &RP::WAVE, RP::WAVE.defaultValue, [&](int val) { setWaveLFO2(val); });
    registerParameter(depthLFO2, DEPTHLFO2_STR, &RP::DEPTH, RP::DEPTH.defaultValue, [&](float val) { setDepthLFO2(val); });
    registerParameter(depthModLFO2, DEPTHMODLFO2_STR, &RP::DEPTHMOD, RP::DEPTHMOD.defaultValue, [&](float val) { setDepthModLFO2(val); });
    registerParameter(freqLFO2, FREQLFO2_STR, &RP::FREQ, RP::FREQ.defaultValue, [&](float val) { setFreqLFO2(val); });
    registerParameter(freqModLFO2, FREQMODLFO2_STR, &RP::FREQMOD, RP::FREQMOD.defaultValue, [&](float val) { setFreqModLFO2(val); });
    registerParameter(phaseLFO2, PHASELFO2_STR, &RP::PHASE, RP::PHASE.defaultValue, [&](float val) { setPhaseLFO2(val); });
    registerParameter(tempoNumerLFO2, TEMPONUMERLFO2_STR,&RP::TEMPONUMER, RP::TEMPONUMER.defaultValue, [&](int val) { setTempoNumerLFO2(val); });
    registerParameter(tempoDenomLFO2, TEMPODENOMLFO2_STR, &RP::TEMPODENOM, RP::TEMPODENOM.defaultValue, [&](int val) { setTempoDenomLFO2(val); });

    registerParameter(bypassSwitchMOD1, SWITCHMOD1_STR, RP::LFOSWITCH_DEFAULT, [&](bool val) { setBypassSwitchMOD1(val); });
    registerParameter(phaseSyncMOD1, PHASEMOD1_STR, RP::PHASESYNC_DEFAULT, [&](bool val) { setPhaseSyncMOD1(val); });
    registerParameter(tempoSyncMOD1, TEMPOSYNCMOD1_STR, RP::TEMPOSYNC_DEFAULT, [&](bool val) { setTempoSyncMOD1(val); });
    registerParameter(waveMOD1, WAVEMOD1_STR, &RP::WAVE, RP::WAVE.defaultValue, [&](int val) { setWaveMOD1(val); });
    registerParameter(depthMOD1, DEPTHMOD1_STR, &RP::DEPTH, RP::DEPTH.defaultValue, [&](float val) { setDepthMOD1(val); });
    registerParameter(freqMOD1, FREQMOD1_STR, &RP::FREQ, RP::FREQ.defaultValue, [&](float val) { setFreqMOD1(val); });
    registerParameter(phaseMOD1, PHASEMOD1_STR, &RP::PHASE, RP::PHASE.defaultValue, [&](float val) { setPhaseMOD1(val); });
    registerParameter(tempoNumerMOD1, TEMPONUMERMOD1_STR,&RP::TEMPONUMER, RP::TEMPONUMER.defaultValue, [&](int val) { setTempoNumerMOD1(val); });
    registerParameter(tempoDenomMOD1, TEMPODENOMMOD1_STR, &RP::TEMPODENOM, RP::TEMPODENOM.defaultValue, [&](int val) { setTempoDenomMOD1(val); });

    registerParameter(bypassSwitchMOD2, SWITCHMOD2_STR, RP::LFOSWITCH_DEFAULT, [&](bool val) { setBypassSwitchMOD2(val); });
    registerParameter(phaseSyncMOD2, PHASEMOD2_STR, RP::PHASESYNC_DEFAULT, [&](bool val) { setPhaseSyncMOD2(val); });
    registerParameter(tempoSyncMOD2, TEMPOSYNCMOD2_STR, RP::TEMPOSYNC_DEFAULT, [&](bool val) { setTempoSyncMOD2(val); });
    registerParameter(waveMOD2, WAVEMOD2_STR, &RP::WAVE, RP::WAVE.defaultValue, [&](int val) { setWaveMOD2(val); });
    registerParameter(depthMOD2, DEPTHMOD2_STR, &RP::DEPTH, RP::DEPTH.defaultValue, [&](float val) { setDepthMOD2(val); });
    registerParameter(freqMOD2, FREQMOD2_STR, &RP::FREQ, RP::FREQ.defaultValue, [&](float val) { setFreqMOD2(val); });
    registerParameter(phaseMOD2, PHASEMOD2_STR, &RP::PHASE, RP::PHASE.defaultValue, [&](float val) { setPhaseMOD2(val); });
    registerParameter(tempoNumerMOD2, TEMPONUMERMOD2_STR,&RP::TEMPONUMER, RP::TEMPONUMER.defaultValue, [&](int val) { setTempoNumerMOD2(val); });
    registerParameter(tempoDenomMOD2, TEMPODENOMMOD2_STR, &RP::TEMPODENOM, RP::TEMPODENOM.defaultValue, [&](int val) { setTempoDenomMOD2(val); });

    registerParameter(stereo, STEREO_STR, STEREO_DEFAULT, [&](bool val) { setStereo(val); });
    registerParameter(outputGain, OUTPUTGAIN_STR, &OUTPUTGAIN, OUTPUTGAIN.defaultValue, [&](float val) { setOutputGain(val); });

    // New parameters must be registered last to maintain backwards compatibility during setStateInformation
    registerParameter(invertLFO1, INVERTLFO1_STR, RP::INVERT_DEFAULT, [&](bool val) { setInvertLFO1(val); });
    registerParameter(invertLFO2, INVERTLFO2_STR, RP::INVERT_DEFAULT, [&](bool val) { setInvertLFO2(val); });
    registerParameter(invertMOD1, INVERTMOD1_STR, RP::INVERT_DEFAULT, [&](bool val) { setInvertMOD1(val); });
    registerParameter(invertMOD2, INVERTMOD2_STR, RP::INVERT_DEFAULT, [&](bool val) { setInvertMOD2(val); });
}

RichterAudioProcessor::~RichterAudioProcessor()
{
}

//==============================================================================
const String RichterAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

const String RichterAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String RichterAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool RichterAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool RichterAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool RichterAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool RichterAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool RichterAudioProcessor::silenceInProducesSilenceOut() const
{
    return true;
}

double RichterAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int RichterAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int RichterAudioProcessor::getCurrentProgram()
{
    return 0;
}

void RichterAudioProcessor::setCurrentProgram (int index)
{
}

const String RichterAudioProcessor::getProgramName (int index)
{
    return String();
}

void RichterAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void RichterAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    mRichter.LFOPair1.reset();
    mRichter.LFOPair2.reset();
}

void RichterAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}


void RichterAudioProcessor::reset()
{
    mRichter.LFOPair1.reset();
    mRichter.LFOPair2.reset();
}


void RichterAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback
    // when they first compile the plugin, but obviously you don't need to
    // this code if your algorithm already fills all the output channels.
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i) {
        buffer.clear (i, 0, buffer.getNumSamples());
    }

    juce::AudioPlayHead::CurrentPositionInfo mTempoInfo;
    getPlayHead()->getCurrentPosition(mTempoInfo);

    mRichter.LFOPair1.prepareForNextBuffer(mTempoInfo.bpm, mTempoInfo.timeInSeconds, getSampleRate());
    mRichter.LFOPair2.prepareForNextBuffer(mTempoInfo.bpm, mTempoInfo.timeInSeconds, getSampleRate());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    if (getNumInputChannels() == 1 && getNumOutputChannels() == 1) {
        float* inSample {buffer.getWritePointer(0)};

        for (long iii = 0; iii < buffer.getNumSamples(); iii++) {
            mRichter.ClockProcess1in1out(&inSample[iii]);
        }
    } else if (getNumInputChannels() == 1 && getNumOutputChannels() == 2) {
        float* inLeftSample {buffer.getWritePointer(0)};
        float* inRightSample {buffer.getWritePointer(1)};

        for (long iii = 0; iii < buffer.getNumSamples(); iii++) {
            mRichter.ClockProcess1in2out(&inLeftSample[iii], &inRightSample[iii]);
        }
    } else if (getNumInputChannels() == 2 && getNumOutputChannels() == 2) {
        float* inLeftSample {buffer.getWritePointer(0)};
        float* inRightSample {buffer.getWritePointer(1)};

        for (long iii = 0; iii < buffer.getNumSamples(); iii++) {
            mRichter.ClockProcess2in2out(&inLeftSample[iii], &inRightSample[iii]);
        }
    }

}

//==============================================================================
bool RichterAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* RichterAudioProcessor::createEditor()
{
    return new RichterAudioProcessorEditor (*this);
}

//==============================================================================
void RichterAudioProcessor::setBypassSwitchLFO1(bool val) {
    mRichter.LFOPair1.LFO.setBypassSwitch(val);
    bypassSwitchLFO1->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setPhaseSyncLFO1(bool val) {
    mRichter.LFOPair1.LFO.setPhaseSyncSwitch(val);
    phaseSyncLFO1->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setTempoSyncLFO1(bool val) {
    mRichter.LFOPair1.LFO.setTempoSyncSwitch(val);
    tempoSyncLFO1->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setInvertLFO1(bool val) {
    mRichter.LFOPair1.LFO.setInvertSwitch(val);
    invertLFO1->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setWaveLFO1(int val) {
    mRichter.LFOPair1.LFO.setWave(val);
    waveLFO1->setValueNotifyingHost(waveLFO1->getNormalisableRange().convertTo0to1(val));
}

void RichterAudioProcessor::setDepthLFO1(float val) {
    mRichter.LFOPair1.LFO.setRawDepth(WECore::Richter::Parameters::DEPTH.NormalisedToInternal(val));
    depthLFO1->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setDepthModLFO1(float val) {
    mRichter.LFOPair1.LFO.setDepthMod(WECore::Richter::Parameters::DEPTHMOD.NormalisedToInternal(val));
    depthModLFO1->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setFreqLFO1(float val) {
    mRichter.LFOPair1.LFO.setRawFreq(WECore::Richter::Parameters::FREQ.NormalisedToInternal(val));
    freqLFO1->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setFreqModLFO1(float val) {
    mRichter.LFOPair1.LFO.setFreqMod(WECore::Richter::Parameters::FREQMOD.NormalisedToInternal(val));
    freqModLFO1->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setPhaseLFO1(float val) {
    mRichter.LFOPair1.LFO.setManualPhase(WECore::Richter::Parameters::PHASE.NormalisedToInternal(val));
    phaseLFO1->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setTempoNumerLFO1(int val) {
    mRichter.LFOPair1.LFO.setTempoNumer(val);
    tempoNumerLFO1->setValueNotifyingHost(tempoNumerLFO1->getNormalisableRange().convertTo0to1(val));
}

void RichterAudioProcessor::setTempoDenomLFO1(int val) {
    mRichter.LFOPair1.LFO.setTempoDenom(val);
    tempoDenomLFO1->setValueNotifyingHost(tempoDenomLFO1->getNormalisableRange().convertTo0to1(val));
}

void RichterAudioProcessor::setBypassSwitchLFO2(bool val) {
    mRichter.LFOPair2.LFO.setBypassSwitch(val);
    bypassSwitchLFO2->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setPhaseSyncLFO2(bool val) {
    mRichter.LFOPair2.LFO.setPhaseSyncSwitch(val);
    phaseSyncLFO2->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setTempoSyncLFO2(bool val) {
    mRichter.LFOPair2.LFO.setTempoSyncSwitch(val);
    tempoSyncLFO2->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setInvertLFO2(bool val) {
    mRichter.LFOPair2.LFO.setInvertSwitch(val);
    invertLFO2->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setWaveLFO2(int val) {
    mRichter.LFOPair2.LFO.setWave(val);
    waveLFO2->setValueNotifyingHost(waveLFO2->getNormalisableRange().convertTo0to1(val));
}

void RichterAudioProcessor::setDepthLFO2(float val) {
    mRichter.LFOPair2.LFO.setRawDepth(WECore::Richter::Parameters::DEPTH.NormalisedToInternal(val));
    depthLFO2->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setDepthModLFO2(float val) {
    mRichter.LFOPair2.LFO.setDepthMod(WECore::Richter::Parameters::DEPTHMOD.NormalisedToInternal(val));
    depthModLFO2->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setFreqLFO2(float val) {
    mRichter.LFOPair2.LFO.setRawFreq(WECore::Richter::Parameters::FREQ.NormalisedToInternal(val));
    freqLFO2->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setFreqModLFO2(float val) {
    mRichter.LFOPair2.LFO.setFreqMod(WECore::Richter::Parameters::FREQMOD.NormalisedToInternal(val));
    freqModLFO2->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setPhaseLFO2(float val) {
    mRichter.LFOPair2.LFO.setManualPhase(WECore::Richter::Parameters::PHASE.NormalisedToInternal(val));
    phaseLFO2->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setTempoNumerLFO2(int val) {
    mRichter.LFOPair2.LFO.setTempoNumer(val);
    tempoNumerLFO2->setValueNotifyingHost(tempoNumerLFO2->getNormalisableRange().convertTo0to1(val));
}

void RichterAudioProcessor::setTempoDenomLFO2(int val) {
    mRichter.LFOPair2.LFO.setTempoDenom(val);
    tempoDenomLFO2->setValueNotifyingHost(tempoDenomLFO2->getNormalisableRange().convertTo0to1(val));
}

void RichterAudioProcessor::setBypassSwitchMOD1(bool val) {
    mRichter.LFOPair1.MOD->setBypassSwitch(val);
    bypassSwitchMOD1->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setPhaseSyncMOD1(bool val) {
    mRichter.LFOPair1.MOD->setPhaseSyncSwitch(val);
    phaseSyncMOD1->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setTempoSyncMOD1(bool val) {
    mRichter.LFOPair1.MOD->setTempoSyncSwitch(val);
    tempoSyncMOD1->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setInvertMOD1(bool val) {
    mRichter.LFOPair1.MOD->setInvertSwitch(val);
    invertMOD1->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setWaveMOD1(int val) {
    mRichter.LFOPair1.MOD->setWave(val);
    waveMOD1->setValueNotifyingHost(waveMOD1->getNormalisableRange().convertTo0to1(val));
}

void RichterAudioProcessor::setDepthMOD1(float val) {
    mRichter.LFOPair1.MOD->setDepth(WECore::Richter::Parameters::DEPTH.NormalisedToInternal(val));
    depthMOD1->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setFreqMOD1(float val) {
    mRichter.LFOPair1.MOD->setFreq(WECore::Richter::Parameters::FREQ.NormalisedToInternal(val));
    freqMOD1->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setPhaseMOD1(float val) {
    mRichter.LFOPair1.MOD->setManualPhase(WECore::Richter::Parameters::PHASE.NormalisedToInternal(val));
    phaseMOD1->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setTempoNumerMOD1(int val) {
    mRichter.LFOPair1.MOD->setTempoNumer(val);
    tempoNumerMOD1->setValueNotifyingHost(tempoNumerMOD1->getNormalisableRange().convertTo0to1(val));
}

void RichterAudioProcessor::setTempoDenomMOD1(int val) {
    mRichter.LFOPair1.MOD->setTempoDenom(val);
    tempoDenomMOD1->setValueNotifyingHost(tempoDenomMOD1->getNormalisableRange().convertTo0to1(val));
}

void RichterAudioProcessor::setBypassSwitchMOD2(bool val) {
    mRichter.LFOPair2.MOD->setBypassSwitch(val);
    bypassSwitchMOD2->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setPhaseSyncMOD2(bool val) {
    mRichter.LFOPair2.MOD->setPhaseSyncSwitch(val);
    phaseSyncMOD2->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setTempoSyncMOD2(bool val) {
    mRichter.LFOPair2.MOD->setTempoSyncSwitch(val);
    tempoSyncMOD2->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setInvertMOD2(bool val) {
    mRichter.LFOPair2.MOD->setInvertSwitch(val);
    invertMOD2->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setWaveMOD2(int val) {
    mRichter.LFOPair2.MOD->setWave(val);
    waveMOD2->setValueNotifyingHost(waveMOD2->getNormalisableRange().convertTo0to1(val));
}

void RichterAudioProcessor::setDepthMOD2(float val) {
    mRichter.LFOPair2.MOD->setDepth(WECore::Richter::Parameters::DEPTH.NormalisedToInternal(val));
    depthMOD2->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setFreqMOD2(float val) {
    mRichter.LFOPair2.MOD->setFreq(WECore::Richter::Parameters::FREQ.NormalisedToInternal(val));
    freqMOD2->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setPhaseMOD2(float val) {
    mRichter.LFOPair2.MOD->setManualPhase(WECore::Richter::Parameters::PHASE.NormalisedToInternal(val));
    phaseMOD2->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setTempoNumerMOD2(int val) {
    mRichter.LFOPair2.MOD->setTempoNumer(val);
    tempoNumerMOD2->setValueNotifyingHost(tempoNumerMOD2->getNormalisableRange().convertTo0to1(val));
}

void RichterAudioProcessor::setTempoDenomMOD2(int val) {
    mRichter.LFOPair2.MOD->setTempoDenom(val);
    tempoDenomMOD2->setValueNotifyingHost(tempoDenomMOD2->getNormalisableRange().convertTo0to1(val));
}

void RichterAudioProcessor::setStereo(bool val) {
    mRichter.setStereo(val);
    stereo->setValueNotifyingHost(val);
}

void RichterAudioProcessor::setOutputGain(float val) {
    mRichter.setOutputGain(OUTPUTGAIN.NormalisedToInternal(val));
    outputGain->setValueNotifyingHost(val);
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new RichterAudioProcessor();
}
