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

    constexpr float PRECISION {0.01f};

    registerParameter(bypassSwitchLFO1, SWITCHLFO1_STR, RP::LFOSWITCH_ON);
    registerParameter(phaseSyncLFO1, PHASELFO1_STR, RP::PHASESYNC_DEFAULT);
    registerParameter(tempoSyncLFO1, TEMPOSYNCLFO1_STR, RP::TEMPOSYNC_DEFAULT);
    registerParameter(invertLFO1, INVERTLFO1_STR, RP::INVERT_DEFAULT);
    registerParameter(waveLFO1, WAVELFO1_STR, &RP::WAVE, RP::WAVE.defaultValue);
    registerParameter(depthLFO1, DEPTHLFO1_STR, &RP::DEPTH, RP::DEPTH.defaultValue, PRECISION);
    registerParameter(depthModLFO1, DEPTHMODLFO1_STR, &RP::DEPTHMOD, RP::DEPTHMOD.defaultValue, PRECISION);
    registerParameter(freqLFO1, FREQLFO1_STR, &RP::FREQ, RP::FREQ.defaultValue, PRECISION);
    registerParameter(freqModLFO1, FREQMODLFO1_STR, &RP::FREQMOD, RP::FREQMOD.defaultValue, PRECISION);
    registerParameter(phaseLFO1, PHASELFO1_STR, &RP::PHASE, RP::PHASE.defaultValue, PRECISION);
    registerParameter(tempoNumerLFO1, TEMPONUMERLFO1_STR,&RP::TEMPONUMER, RP::TEMPONUMER.defaultValue);
    registerParameter(tempoDenomLFO1, TEMPODENOMLFO1_STR, &RP::TEMPODENOM, RP::TEMPODENOM.defaultValue);

    registerParameter(bypassSwitchLFO2, SWITCHLFO2_STR, RP::LFOSWITCH_ON);
    registerParameter(phaseSyncLFO2, PHASELFO2_STR, RP::PHASESYNC_DEFAULT);
    registerParameter(tempoSyncLFO2, TEMPOSYNCLFO2_STR, RP::TEMPOSYNC_DEFAULT);
    registerParameter(invertLFO2, INVERTLFO2_STR, RP::INVERT_DEFAULT);
    registerParameter(waveLFO2, WAVELFO2_STR, &RP::WAVE, RP::WAVE.defaultValue);
    registerParameter(depthLFO2, DEPTHLFO2_STR, &RP::DEPTH, RP::DEPTH.defaultValue, PRECISION);
    registerParameter(depthModLFO2, DEPTHMODLFO2_STR, &RP::DEPTHMOD, RP::DEPTHMOD.defaultValue, PRECISION);
    registerParameter(freqLFO2, FREQLFO2_STR, &RP::FREQ, RP::FREQ.defaultValue, PRECISION);
    registerParameter(freqModLFO2, FREQMODLFO2_STR, &RP::FREQMOD, RP::FREQMOD.defaultValue, PRECISION);
    registerParameter(phaseLFO2, PHASELFO2_STR, &RP::PHASE, RP::PHASE.defaultValue, PRECISION);
    registerParameter(tempoNumerLFO2, TEMPONUMERLFO2_STR,&RP::TEMPONUMER, RP::TEMPONUMER.defaultValue);
    registerParameter(tempoDenomLFO2, TEMPODENOMLFO2_STR, &RP::TEMPODENOM, RP::TEMPODENOM.defaultValue);

    registerParameter(bypassSwitchMOD1, SWITCHMOD1_STR, RP::LFOSWITCH_DEFAULT);
    registerParameter(phaseSyncMOD1, PHASEMOD1_STR, RP::PHASESYNC_DEFAULT);
    registerParameter(tempoSyncMOD1, TEMPOSYNCMOD1_STR, RP::TEMPOSYNC_DEFAULT);
    registerParameter(invertMOD1, INVERTMOD1_STR, RP::INVERT_DEFAULT);
    registerParameter(waveMOD1, WAVEMOD1_STR, &RP::WAVE, RP::WAVE.defaultValue);
    registerParameter(depthMOD1, DEPTHMOD1_STR, &RP::DEPTH, RP::DEPTH.defaultValue, PRECISION);
    registerParameter(freqMOD1, FREQMOD1_STR, &RP::FREQ, RP::FREQ.defaultValue, PRECISION);
    registerParameter(phaseMOD1, PHASEMOD1_STR, &RP::PHASE, RP::PHASE.defaultValue, PRECISION);
    registerParameter(tempoNumerMOD1, TEMPONUMERMOD1_STR,&RP::TEMPONUMER, RP::TEMPONUMER.defaultValue);
    registerParameter(tempoDenomMOD1, TEMPODENOMMOD1_STR, &RP::TEMPODENOM, RP::TEMPODENOM.defaultValue);

    registerParameter(bypassSwitchMOD2, SWITCHMOD2_STR, RP::LFOSWITCH_DEFAULT);
    registerParameter(phaseSyncMOD2, PHASEMOD2_STR, RP::PHASESYNC_DEFAULT);
    registerParameter(tempoSyncMOD2, TEMPOSYNCMOD2_STR, RP::TEMPOSYNC_DEFAULT);
    registerParameter(invertMOD2, INVERTMOD2_STR, RP::INVERT_DEFAULT);
    registerParameter(waveMOD2, WAVEMOD2_STR, &RP::WAVE, RP::WAVE.defaultValue);
    registerParameter(depthMOD2, DEPTHMOD2_STR, &RP::DEPTH, RP::DEPTH.defaultValue, PRECISION);
    registerParameter(freqMOD2, FREQMOD2_STR, &RP::FREQ, RP::FREQ.defaultValue, PRECISION);
    registerParameter(phaseMOD2, PHASEMOD2_STR, &RP::PHASE, RP::PHASE.defaultValue, PRECISION);
    registerParameter(tempoNumerMOD2, TEMPONUMERMOD2_STR,&RP::TEMPONUMER, RP::TEMPONUMER.defaultValue);
    registerParameter(tempoDenomMOD2, TEMPODENOMMOD2_STR, &RP::TEMPODENOM, RP::TEMPODENOM.defaultValue);

    registerParameter(stereo, STEREO_STR, STEREO_DEFAULT);
    registerParameter(outputGain, OUTPUTGAIN_STR, &OUTPUTGAIN, OUTPUTGAIN.defaultValue, PRECISION);
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

    mRichter.LFOPair1.setSampleRate(getSampleRate());
    mRichter.LFOPair2.setSampleRate(getSampleRate());
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

    mRichter.LFOPair1.prepareForNextBuffer(mTempoInfo.bpm, mTempoInfo.timeInSeconds);
    mRichter.LFOPair2.prepareForNextBuffer(mTempoInfo.bpm, mTempoInfo.timeInSeconds);

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
std::vector<juce::String> RichterAudioProcessor::_provideParamNamesForMigration() {
    return std::vector<juce::String> {
        SWITCHLFO1_STR,
        PHASELFO1_STR,
        TEMPOSYNCLFO1_STR,
        WAVELFO1_STR,
        DEPTHLFO1_STR,
        DEPTHMODLFO1_STR,
        FREQLFO1_STR,
        FREQMODLFO1_STR,
        PHASELFO1_STR,
        TEMPONUMERLFO1_STR,
        TEMPODENOMLFO1_STR,

        SWITCHLFO2_STR,
        PHASELFO2_STR,
        TEMPOSYNCLFO2_STR,
        WAVELFO2_STR,
        DEPTHLFO2_STR,
        DEPTHMODLFO2_STR,
        FREQLFO2_STR,
        FREQMODLFO2_STR,
        PHASELFO2_STR,
        TEMPONUMERLFO2_STR,
        TEMPODENOMLFO2_STR,

        SWITCHMOD1_STR,
        PHASEMOD1_STR,
        TEMPOSYNCMOD1_STR,
        WAVEMOD1_STR,
        DEPTHMOD1_STR,
        FREQMOD1_STR,
        PHASEMOD1_STR,
        TEMPONUMERMOD1_STR,
        TEMPODENOMMOD1_STR,

        SWITCHMOD2_STR,
        PHASEMOD2_STR,
        TEMPOSYNCMOD2_STR,
        WAVEMOD2_STR,
        DEPTHMOD2_STR,
        FREQMOD2_STR,
        PHASEMOD2_STR,
        TEMPONUMERMOD2_STR,
        TEMPODENOMMOD2_STR,

        STEREO_STR,
        OUTPUTGAIN_STR,

        INVERTLFO1_STR,
        INVERTLFO2_STR,
        INVERTMOD1_STR,
        INVERTMOD2_STR,
    };
}

void RichterAudioProcessor::_migrateParamValues(std::vector<float>& paramValues) {

    namespace RP = WECore::Richter::Parameters;

    if (paramValues.size() == 46) {
        paramValues[4] = RP::DEPTH.NormalisedToInternal(paramValues[4]);
        paramValues[5] = RP::DEPTHMOD.NormalisedToInternal(paramValues[5]);
        paramValues[6] = RP::FREQ.NormalisedToInternal(paramValues[6]);
        paramValues[7] = RP::FREQMOD.NormalisedToInternal(paramValues[7]);
        paramValues[8] = RP::PHASE.NormalisedToInternal(paramValues[8]);

        paramValues[15] = RP::DEPTH.NormalisedToInternal(paramValues[15]);
        paramValues[16] = RP::DEPTHMOD.NormalisedToInternal(paramValues[16]);
        paramValues[17] = RP::FREQ.NormalisedToInternal(paramValues[17]);
        paramValues[18] = RP::FREQMOD.NormalisedToInternal(paramValues[18]);
        paramValues[19] = RP::PHASE.NormalisedToInternal(paramValues[19]);

        paramValues[26] = RP::DEPTH.NormalisedToInternal(paramValues[26]);
        paramValues[27] = RP::FREQ.NormalisedToInternal(paramValues[27]);
        paramValues[28] = RP::PHASE.NormalisedToInternal(paramValues[28]);

        paramValues[35] = RP::DEPTH.NormalisedToInternal(paramValues[35]);
        paramValues[36] = RP::FREQ.NormalisedToInternal(paramValues[36]);
        paramValues[37] = RP::PHASE.NormalisedToInternal(paramValues[37]);
        paramValues[41] = OUTPUTGAIN.NormalisedToInternal(paramValues[41]);
    }
}

void RichterAudioProcessor::_onParameterUpdate() {
    mRichter.LFOPair1.LFO.setBypassSwitch(bypassSwitchLFO1->get());
    mRichter.LFOPair1.LFO.setPhaseSyncSwitch(phaseSyncLFO1->get());
    mRichter.LFOPair1.LFO.setTempoSyncSwitch(tempoSyncLFO1->get());
    mRichter.LFOPair1.LFO.setInvertSwitch(invertLFO1->get());
    mRichter.LFOPair1.LFO.setWave(waveLFO1->get());
    mRichter.LFOPair1.LFO.setDepth(depthLFO1->get());
    mRichter.LFOPair1.LFO.setDepthMod(depthModLFO1->get());
    mRichter.LFOPair1.LFO.setFreq(freqLFO1->get());
    mRichter.LFOPair1.LFO.setFreqMod(freqModLFO1->get());
    mRichter.LFOPair1.LFO.setManualPhase(phaseLFO1->get());
    mRichter.LFOPair1.LFO.setTempoNumer(tempoNumerLFO1->get());
    mRichter.LFOPair1.LFO.setTempoDenom(tempoDenomLFO1->get());

    mRichter.LFOPair2.LFO.setBypassSwitch(bypassSwitchLFO2->get());
    mRichter.LFOPair2.LFO.setPhaseSyncSwitch(phaseSyncLFO2->get());
    mRichter.LFOPair2.LFO.setTempoSyncSwitch(tempoSyncLFO2->get());
    mRichter.LFOPair2.LFO.setInvertSwitch(invertLFO2->get());
    mRichter.LFOPair2.LFO.setWave(waveLFO2->get());
    mRichter.LFOPair2.LFO.setDepth(depthLFO2->get());
    mRichter.LFOPair2.LFO.setDepthMod(depthModLFO2->get());
    mRichter.LFOPair2.LFO.setFreq(freqLFO2->get());
    mRichter.LFOPair2.LFO.setFreqMod(freqModLFO2->get());
    mRichter.LFOPair2.LFO.setManualPhase(phaseLFO2->get());
    mRichter.LFOPair2.LFO.setTempoNumer(tempoNumerLFO2->get());
    mRichter.LFOPair2.LFO.setTempoDenom(tempoDenomLFO2->get());

    mRichter.LFOPair1.MOD->setBypassSwitch(bypassSwitchMOD1->get());
    mRichter.LFOPair1.MOD->setPhaseSyncSwitch(phaseSyncMOD1->get());
    mRichter.LFOPair1.MOD->setTempoSyncSwitch(tempoSyncMOD1->get());
    mRichter.LFOPair1.MOD->setInvertSwitch(invertMOD1->get());
    mRichter.LFOPair1.MOD->setWave(waveMOD1->get());
    mRichter.LFOPair1.MOD->setDepth(depthMOD1->get());
    mRichter.LFOPair1.MOD->setFreq(freqMOD1->get());
    mRichter.LFOPair1.MOD->setManualPhase(phaseMOD1->get());
    mRichter.LFOPair1.MOD->setTempoNumer(tempoNumerMOD1->get());
    mRichter.LFOPair1.MOD->setTempoDenom(tempoDenomMOD1->get());

    mRichter.LFOPair2.MOD->setBypassSwitch(bypassSwitchMOD2->get());
    mRichter.LFOPair2.MOD->setPhaseSyncSwitch(phaseSyncMOD2->get());
    mRichter.LFOPair2.MOD->setTempoSyncSwitch(tempoSyncMOD2->get());
    mRichter.LFOPair2.MOD->setInvertSwitch(invertMOD2->get());
    mRichter.LFOPair2.MOD->setWave(waveMOD2->get());
    mRichter.LFOPair2.MOD->setDepth(depthMOD2->get());
    mRichter.LFOPair2.MOD->setFreq(freqMOD2->get());
    mRichter.LFOPair2.MOD->setManualPhase(phaseMOD2->get());
    mRichter.LFOPair2.MOD->setTempoNumer(tempoNumerMOD2->get());
    mRichter.LFOPair2.MOD->setTempoDenom(tempoDenomMOD2->get());

    mRichter.setStereo(stereo->get());
    mRichter.setOutputGain(outputGain->get());
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new RichterAudioProcessor();
}
