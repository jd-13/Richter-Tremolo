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
    mRichter.LFOPair1.LFO.setBypassSwitch(WECore::Richter::Parameters::LFOSWITCH_DEFAULT);
    mRichter.LFOPair1.LFO.setPhaseSyncSwitch(WECore::Richter::Parameters::PHASESYNC_DEFAULT);
    mRichter.LFOPair1.LFO.setTempoSyncSwitch(WECore::Richter::Parameters::TEMPOSYNC_DEFAULT);
    mRichter.LFOPair1.LFO.setWave(WECore::Richter::Parameters::WAVE.defaultValue);
    mRichter.LFOPair1.LFO.setDepth(WECore::Richter::Parameters::DEPTH.defaultValue);
    mRichter.LFOPair1.LFO.setDepthMod(WECore::Richter::Parameters::DEPTHMOD.defaultValue);
    mRichter.LFOPair1.LFO.setFreq(WECore::Richter::Parameters::FREQ.defaultValue);
    mRichter.LFOPair1.LFO.setFreqMod(WECore::Richter::Parameters::FREQMOD.defaultValue);
    mRichter.LFOPair1.LFO.setManualPhase(WECore::Richter::Parameters::PHASE.defaultValue);
    mRichter.LFOPair1.LFO.setTempoNumer(WECore::Richter::Parameters::TEMPONUMER.defaultValue);
    mRichter.LFOPair1.LFO.setTempoDenom(WECore::Richter::Parameters::TEMPODENOM.defaultValue);

    mRichter.LFOPair2.LFO.setBypassSwitch(WECore::Richter::Parameters::LFOSWITCH_DEFAULT);
    mRichter.LFOPair2.LFO.setPhaseSyncSwitch(WECore::Richter::Parameters::PHASESYNC_DEFAULT);
    mRichter.LFOPair2.LFO.setTempoSyncSwitch(WECore::Richter::Parameters::TEMPOSYNC_DEFAULT);
    mRichter.LFOPair2.LFO.setWave(WECore::Richter::Parameters::WAVE.defaultValue);
    mRichter.LFOPair2.LFO.setDepth(WECore::Richter::Parameters::DEPTH.defaultValue);
    mRichter.LFOPair2.LFO.setDepthMod(WECore::Richter::Parameters::DEPTHMOD.defaultValue);
    mRichter.LFOPair2.LFO.setFreq(WECore::Richter::Parameters::FREQ.defaultValue);
    mRichter.LFOPair2.LFO.setFreqMod(WECore::Richter::Parameters::FREQMOD.defaultValue);
    mRichter.LFOPair2.LFO.setManualPhase(WECore::Richter::Parameters::PHASE.defaultValue);
    mRichter.LFOPair2.LFO.setTempoNumer(WECore::Richter::Parameters::TEMPONUMER.defaultValue);
    mRichter.LFOPair2.LFO.setTempoDenom(WECore::Richter::Parameters::TEMPODENOM.defaultValue);

    mRichter.LFOPair1.MOD.setBypassSwitch(WECore::Richter::Parameters::LFOSWITCH_DEFAULT);
    mRichter.LFOPair1.MOD.setPhaseSyncSwitch(WECore::Richter::Parameters::PHASESYNC_DEFAULT);
    mRichter.LFOPair1.MOD.setTempoSyncSwitch(WECore::Richter::Parameters::TEMPOSYNC_DEFAULT);
    mRichter.LFOPair1.MOD.setWave(WECore::Richter::Parameters::WAVE.defaultValue);
    mRichter.LFOPair1.MOD.setDepth(WECore::Richter::Parameters::DEPTH.defaultValue);
    mRichter.LFOPair1.MOD.setFreq(WECore::Richter::Parameters::FREQ.defaultValue);
    mRichter.LFOPair1.MOD.setManualPhase(WECore::Richter::Parameters::PHASE.defaultValue);
    mRichter.LFOPair1.MOD.setTempoNumer(WECore::Richter::Parameters::TEMPONUMER.defaultValue);
    mRichter.LFOPair1.MOD.setTempoDenom(WECore::Richter::Parameters::TEMPODENOM.defaultValue);

    mRichter.LFOPair2.MOD.setBypassSwitch(WECore::Richter::Parameters::LFOSWITCH_DEFAULT);
    mRichter.LFOPair2.MOD.setPhaseSyncSwitch(WECore::Richter::Parameters::PHASESYNC_DEFAULT);
    mRichter.LFOPair2.MOD.setTempoSyncSwitch(WECore::Richter::Parameters::TEMPOSYNC_DEFAULT);
    mRichter.LFOPair2.MOD.setWave(WECore::Richter::Parameters::WAVE.defaultValue);
    mRichter.LFOPair2.MOD.setDepth(WECore::Richter::Parameters::DEPTH.defaultValue);
    mRichter.LFOPair2.MOD.setFreq(WECore::Richter::Parameters::FREQ.defaultValue);
    mRichter.LFOPair2.MOD.setManualPhase(WECore::Richter::Parameters::PHASE.defaultValue);
    mRichter.LFOPair2.MOD.setTempoNumer(WECore::Richter::Parameters::TEMPONUMER.defaultValue);
    mRichter.LFOPair2.MOD.setTempoDenom(WECore::Richter::Parameters::TEMPODENOM.defaultValue);

    mRichter.setStereo(STEREO_DEFAULT);
    mRichter.setOutputGain(OUTPUTGAIN.defaultValue);

    _UIUpdateFlag = true;

}

RichterAudioProcessor::~RichterAudioProcessor()
{
}

//==============================================================================
const String RichterAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int RichterAudioProcessor::getNumParameters()
{
    return totalNumParams;
}

float RichterAudioProcessor::getParameter (int index)
{
    switch (index) {
        case bypassSwitchLFO1:
            return mRichter.LFOPair1.LFO.getBypassSwitch();

        case phaseSyncLFO1:
            return mRichter.LFOPair1.LFO.getPhaseSyncSwitch();

        case tempoSyncLFO1:
            return mRichter.LFOPair1.LFO.getTempoSyncSwitch();

        case waveLFO1:
            return mRichter.LFOPair1.LFO.getWave();

        case depthLFO1:
            return WECore::Richter::Parameters::DEPTH.InteralToNormalised(mRichter.LFOPair1.LFO.getRawDepth());

        case depthModLFO1:
            return WECore::Richter::Parameters::DEPTHMOD.InteralToNormalised(mRichter.LFOPair1.LFO.getDepthMod());

        case freqLFO1:
            return WECore::Richter::Parameters::FREQ.InteralToNormalised(mRichter.LFOPair1.LFO.getRawFreq());

        case freqModLFO1:
            return WECore::Richter::Parameters::FREQMOD.InteralToNormalised(mRichter.LFOPair1.LFO.getFreqMod());

        case phaseLFO1:
            return WECore::Richter::Parameters::PHASE.InteralToNormalised(mRichter.LFOPair1.LFO.getManualPhase());

        case tempoNumerLFO1:
            return mRichter.LFOPair1.LFO.getTempoNumer();

        case tempoDenomLFO1:
            return mRichter.LFOPair1.LFO.getTempoDenom();





        case bypassSwitchLFO2:
            return mRichter.LFOPair2.LFO.getBypassSwitch();

        case phaseSyncLFO2:
            return mRichter.LFOPair2.LFO.getPhaseSyncSwitch();

        case tempoSyncLFO2:
            return mRichter.LFOPair2.LFO.getTempoSyncSwitch();

        case waveLFO2:
            return mRichter.LFOPair2.LFO.getWave();

        case depthLFO2:
            return WECore::Richter::Parameters::DEPTH.InteralToNormalised(mRichter.LFOPair2.LFO.getRawDepth());

        case depthModLFO2:
            return WECore::Richter::Parameters::DEPTHMOD.InteralToNormalised(mRichter.LFOPair2.LFO.getDepthMod());

        case freqLFO2:
            return WECore::Richter::Parameters::FREQ.InteralToNormalised(mRichter.LFOPair2.LFO.getRawFreq());

        case freqModLFO2:
            return WECore::Richter::Parameters::FREQMOD.InteralToNormalised(mRichter.LFOPair2.LFO.getFreqMod());

        case phaseLFO2:
            return WECore::Richter::Parameters::PHASE.InteralToNormalised(mRichter.LFOPair2.LFO.getManualPhase());

        case tempoNumerLFO2:
            return mRichter.LFOPair2.LFO.getTempoNumer();

        case tempoDenomLFO2:
            return mRichter.LFOPair2.LFO.getTempoDenom();






        case bypassSwitchMOD1:
            return mRichter.LFOPair1.MOD.getBypassSwitch();

        case phaseSyncMOD1:
            return mRichter.LFOPair1.MOD.getPhaseSyncSwitch();

        case tempoSyncMOD1:
            return mRichter.LFOPair1.MOD.getTempoSyncSwitch();

        case waveMOD1:
            return mRichter.LFOPair1.MOD.getWave();

        case depthMOD1:
            return WECore::Richter::Parameters::DEPTH.InteralToNormalised(mRichter.LFOPair1.MOD.getDepth());

        case freqMOD1:
            return WECore::Richter::Parameters::FREQ.InteralToNormalised(mRichter.LFOPair1.MOD.getFreq());

        case phaseMOD1:
            return WECore::Richter::Parameters::PHASE.InteralToNormalised(mRichter.LFOPair1.MOD.getManualPhase());

        case tempoNumerMOD1:
            return mRichter.LFOPair1.MOD.getTempoNumer();

        case tempoDenomMOD1:
            return mRichter.LFOPair1.MOD.getTempoDenom();







        case bypassSwitchMOD2:
            return mRichter.LFOPair2.MOD.getBypassSwitch();

        case phaseSyncMOD2:
            return mRichter.LFOPair2.MOD.getPhaseSyncSwitch();

        case tempoSyncMOD2:
            return mRichter.LFOPair2.MOD.getTempoSyncSwitch();

        case waveMOD2:
            return mRichter.LFOPair2.MOD.getWave();

        case depthMOD2:
            return WECore::Richter::Parameters::DEPTH.InteralToNormalised(mRichter.LFOPair2.MOD.getDepth());

        case freqMOD2:
            return WECore::Richter::Parameters::FREQ.InteralToNormalised(mRichter.LFOPair2.MOD.getFreq());

        case phaseMOD2:
            return WECore::Richter::Parameters::PHASE.InteralToNormalised(mRichter.LFOPair2.MOD.getManualPhase());

        case tempoNumerMOD2:
            return mRichter.LFOPair2.MOD.getTempoNumer();

        case tempoDenomMOD2:
            return mRichter.LFOPair2.MOD.getTempoDenom();



        case stereo:
            return mRichter.getStereo();

        case outputGain:
            return OUTPUTGAIN.InteralToNormalised(mRichter.getOutputGain());



        default:
            return 0.0f;

    }

}

void RichterAudioProcessor::setParameter (int index, float newValue)
{
    switch (index) {
        case bypassSwitchLFO1:
            mRichter.LFOPair1.LFO.setBypassSwitch(newValue < 0.5);
            break;

        case phaseSyncLFO1:
            mRichter.LFOPair1.LFO.setPhaseSyncSwitch(newValue < 0.5);
            break;

        case tempoSyncLFO1:
            mRichter.LFOPair1.LFO.setTempoSyncSwitch(newValue < 0.5);
            break;

        case waveLFO1:
            mRichter.LFOPair1.LFO.setWave(round(newValue));
            break;

        case depthLFO1:
            mRichter.LFOPair1.LFO.setRawDepth(WECore::Richter::Parameters::DEPTH.NormalisedToInteral(newValue));
            break;

        case depthModLFO1:
            mRichter.LFOPair1.LFO.setDepthMod(WECore::Richter::Parameters::DEPTHMOD.NormalisedToInteral(newValue));
            break;

        case freqLFO1:
            mRichter.LFOPair1.LFO.setRawFreq(WECore::Richter::Parameters::FREQ.NormalisedToInteral(newValue));
            break;

        case freqModLFO1:
            mRichter.LFOPair1.LFO.setFreqMod(WECore::Richter::Parameters::FREQMOD.NormalisedToInteral(newValue));
            break;

        case phaseLFO1:
            mRichter.LFOPair1.LFO.setManualPhase(WECore::Richter::Parameters::PHASE.NormalisedToInteral(newValue));
            break;

        case tempoNumerLFO1:
            mRichter.LFOPair1.LFO.setTempoNumer(newValue);
            break;

        case tempoDenomLFO1:
            mRichter.LFOPair1.LFO.setTempoDenom(newValue);
            break;





        case bypassSwitchLFO2:
            mRichter.LFOPair2.LFO.setBypassSwitch(newValue < 0.5);
            break;

        case phaseSyncLFO2:
            mRichter.LFOPair2.LFO.setPhaseSyncSwitch(newValue < 0.5);
            break;

        case tempoSyncLFO2:
            mRichter.LFOPair2.LFO.setTempoSyncSwitch(newValue < 0.5);
            break;

        case waveLFO2:
            mRichter.LFOPair2.LFO.setWave(round(newValue));
            break;

        case depthLFO2:
            mRichter.LFOPair2.LFO.setRawDepth(WECore::Richter::Parameters::DEPTH.NormalisedToInteral(newValue));
            break;

        case depthModLFO2:
            mRichter.LFOPair2.LFO.setDepthMod(WECore::Richter::Parameters::DEPTHMOD.NormalisedToInteral(newValue));
            break;

        case freqLFO2:
            mRichter.LFOPair2.LFO.setRawFreq(WECore::Richter::Parameters::FREQ.NormalisedToInteral(newValue));
            break;

        case freqModLFO2:
            mRichter.LFOPair2.LFO.setFreqMod(WECore::Richter::Parameters::FREQMOD.NormalisedToInteral(newValue));
            break;

        case phaseLFO2:
            mRichter.LFOPair2.LFO.setManualPhase(WECore::Richter::Parameters::PHASE.NormalisedToInteral(newValue));
            break;

        case tempoNumerLFO2:
            mRichter.LFOPair2.LFO.setTempoNumer(newValue);
            break;

        case tempoDenomLFO2:
            mRichter.LFOPair2.LFO.setTempoDenom(newValue);
            break;





        case bypassSwitchMOD1:
            mRichter.LFOPair1.MOD.setBypassSwitch(newValue < 0.5);
            break;

        case phaseSyncMOD1:
            mRichter.LFOPair1.MOD.setPhaseSyncSwitch(newValue < 0.5);
            break;

        case tempoSyncMOD1:
            mRichter.LFOPair1.MOD.setTempoSyncSwitch(newValue < 0.5);
            break;

        case waveMOD1:
            mRichter.LFOPair1.MOD.setWave(round(newValue));
            break;

        case depthMOD1:
            mRichter.LFOPair1.MOD.setDepth(WECore::Richter::Parameters::DEPTH.NormalisedToInteral(newValue));
            break;

        case freqMOD1:
            mRichter.LFOPair1.MOD.setFreq(WECore::Richter::Parameters::FREQ.NormalisedToInteral(newValue));
            break;

        case phaseMOD1:
            mRichter.LFOPair1.MOD.setManualPhase(WECore::Richter::Parameters::PHASE.NormalisedToInteral(newValue));
            break;

        case tempoNumerMOD1:
            mRichter.LFOPair1.MOD.setTempoNumer(newValue);
            break;

        case tempoDenomMOD1:
            mRichter.LFOPair1.MOD.setTempoDenom(newValue);
            break;





        case bypassSwitchMOD2:
            mRichter.LFOPair2.MOD.setBypassSwitch(newValue < 0.5);
            break;

        case phaseSyncMOD2:
            mRichter.LFOPair2.MOD.setPhaseSyncSwitch(newValue < 0.5);
            break;

        case tempoSyncMOD2:
            mRichter.LFOPair2.MOD.setTempoSyncSwitch(newValue < 0.5);
            break;

        case waveMOD2:
            mRichter.LFOPair2.MOD.setWave(round(newValue));
            break;

        case depthMOD2:
            mRichter.LFOPair2.MOD.setDepth(WECore::Richter::Parameters::DEPTH.NormalisedToInteral(newValue));
            break;

        case freqMOD2:
            mRichter.LFOPair2.MOD.setFreq(WECore::Richter::Parameters::FREQ.NormalisedToInteral(newValue));
            break;

        case phaseMOD2:
            mRichter.LFOPair2.MOD.setManualPhase(WECore::Richter::Parameters::PHASE.NormalisedToInteral(newValue));
            break;

        case tempoNumerMOD2:
            mRichter.LFOPair2.MOD.setTempoNumer(newValue);
            break;

        case tempoDenomMOD2:
            mRichter.LFOPair2.MOD.setTempoDenom(newValue);
            break;



        case stereo:
            mRichter.setStereo(newValue < 0.5);
            break;

        case outputGain:
            mRichter.setOutputGain(OUTPUTGAIN.NormalisedToInteral(newValue));
            break;


        default:
            break;


    }

}

const String RichterAudioProcessor::getParameterName (int index)
{
    switch (index) {
        case bypassSwitchLFO1:
            return SWITCHLFO1_STR;

        case phaseSyncLFO1:
            return PHASESYNCLFO1_STR;

        case tempoSyncLFO1:
            return TEMPOSYNCLFO1_STR;

        case waveLFO1:
            return WAVELFO1_STR;

        case depthLFO1:
            return DEPTHLFO1_STR;

        case depthModLFO1:
            return DEPTHMODLFO1_STR;

        case freqLFO1:
            return FREQLFO1_STR;

        case freqModLFO1:
            return FREQMODLFO1_STR;

        case phaseLFO1:
            return PHASELFO1_STR;

        case tempoNumerLFO1:
            return TEMPONUMERLFO1_STR;

        case tempoDenomLFO1:
            return TEMPODENOMLFO1_STR;




        case bypassSwitchLFO2:
            return SWITCHLFO2_STR;

        case phaseSyncLFO2:
            return PHASESYNCLFO2_STR;

        case tempoSyncLFO2:
            return TEMPOSYNCLFO2_STR;

        case waveLFO2:
            return WAVELFO2_STR;

        case depthLFO2:
            return DEPTHLFO2_STR;

        case depthModLFO2:
            return DEPTHMODLFO2_STR;

        case freqLFO2:
            return FREQLFO2_STR;

        case freqModLFO2:
            return FREQMODLFO2_STR;

        case phaseLFO2:
            return PHASELFO2_STR;

        case tempoNumerLFO2:
            return TEMPONUMERLFO2_STR;

        case tempoDenomLFO2:
            return TEMPODENOMLFO2_STR;





        case bypassSwitchMOD1:
            return SWITCHMOD1_STR;

        case phaseSyncMOD1:
            return PHASESYNCMOD1_STR;

        case tempoSyncMOD1:
            return TEMPOSYNCMOD1_STR;

        case waveMOD1:
            return WAVEMOD1_STR;

        case depthMOD1:
            return DEPTHMOD1_STR;

        case freqMOD1:
            return FREQMOD1_STR;

        case phaseMOD1:
            return PHASEMOD1_STR;

        case tempoNumerMOD1:
            return TEMPONUMERMOD1_STR;

        case tempoDenomMOD1:
            return TEMPODENOMMOD1_STR;





        case bypassSwitchMOD2:
            return SWITCHMOD2_STR;

        case phaseSyncMOD2:
            return PHASESYNCMOD2_STR;

        case tempoSyncMOD2:
            return TEMPOSYNCMOD2_STR;

        case waveMOD2:
            return WAVEMOD2_STR;

        case depthMOD2:
            return DEPTHMOD2_STR;

        case freqMOD2:
            return FREQMOD2_STR;

        case phaseMOD2:
            return PHASEMOD2_STR;

        case tempoNumerMOD2:
            return TEMPONUMERMOD2_STR;

        case tempoDenomMOD2:
            return TEMPODENOMMOD2_STR;




        case stereo:
            return STEREO_STR;


        case outputGain:
            return OUTPUTGAIN_STR;

        default:
            return String();
    }
}

const String RichterAudioProcessor::getParameterText (int index)
{
    switch (index) {
        case bypassSwitchLFO1:
            return String(static_cast<int>(mRichter.LFOPair1.LFO.getBypassSwitch()));

        case phaseSyncLFO1:
            return String(static_cast<int>(mRichter.LFOPair1.LFO.getPhaseSyncSwitch()));

        case tempoSyncLFO1:
            return String(static_cast<int>(mRichter.LFOPair1.LFO.getTempoSyncSwitch()));

        case waveLFO1:
            return String(mRichter.LFOPair1.LFO.getWave());

        case depthLFO1:
            return String(WECore::Richter::Parameters::DEPTH.InteralToNormalised(mRichter.LFOPair1.LFO.getDepth()));

        case depthModLFO1:
            return String(WECore::Richter::Parameters::DEPTHMOD.InteralToNormalised(mRichter.LFOPair1.LFO.getDepthMod()));

        case freqLFO1:
            return String(WECore::Richter::Parameters::FREQ.InteralToNormalised(mRichter.LFOPair1.LFO.getFreq()));

        case freqModLFO1:
            return String(WECore::Richter::Parameters::FREQMOD.InteralToNormalised(mRichter.LFOPair1.LFO.getFreqMod()));

        case phaseLFO1:
            return String(WECore::Richter::Parameters::PHASE.InteralToNormalised(mRichter.LFOPair1.LFO.getManualPhase()));

        case tempoNumerLFO1:
            return String(mRichter.LFOPair1.LFO.getTempoNumer());

        case tempoDenomLFO1:
            return String(mRichter.LFOPair1.LFO.getTempoDenom());





        case bypassSwitchLFO2:
            return String(static_cast<int>(mRichter.LFOPair2.LFO.getBypassSwitch()));

        case phaseSyncLFO2:
            return String(static_cast<int>(mRichter.LFOPair2.LFO.getPhaseSyncSwitch()));

        case tempoSyncLFO2:
            return String(static_cast<int>(mRichter.LFOPair2.LFO.getTempoSyncSwitch()));

        case waveLFO2:
            return String(mRichter.LFOPair2.LFO.getWave());

        case depthLFO2:
            return String(WECore::Richter::Parameters::DEPTH.InteralToNormalised(mRichter.LFOPair2.LFO.getDepth()));

        case depthModLFO2:
            return String(WECore::Richter::Parameters::DEPTHMOD.InteralToNormalised(mRichter.LFOPair2.LFO.getDepthMod()));

        case freqLFO2:
            return String(WECore::Richter::Parameters::FREQ.InteralToNormalised(mRichter.LFOPair2.LFO.getFreq()));

        case freqModLFO2:
            return String(WECore::Richter::Parameters::FREQMOD.InteralToNormalised(mRichter.LFOPair2.LFO.getFreqMod()));

        case phaseLFO2:
            return String(WECore::Richter::Parameters::PHASE.InteralToNormalised(mRichter.LFOPair2.LFO.getManualPhase()));

        case tempoNumerLFO2:
            return String(mRichter.LFOPair2.LFO.getTempoNumer());

        case tempoDenomLFO2:
            return String(mRichter.LFOPair2.LFO.getTempoDenom());





        case bypassSwitchMOD1:
            return String(static_cast<int>(mRichter.LFOPair1.MOD.getBypassSwitch()));

        case phaseSyncMOD1:
            return String(static_cast<int>(mRichter.LFOPair1.MOD.getPhaseSyncSwitch()));

        case tempoSyncMOD1:
            return String(static_cast<int>(mRichter.LFOPair1.MOD.getTempoSyncSwitch()));

        case waveMOD1:
            return String(mRichter.LFOPair1.MOD.getWave());

        case depthMOD1:
            return String(WECore::Richter::Parameters::DEPTH.InteralToNormalised(mRichter.LFOPair1.MOD.getDepth()));

        case freqMOD1:
            return String(WECore::Richter::Parameters::FREQ.InteralToNormalised(mRichter.LFOPair1.MOD.getFreq()));

        case phaseMOD1:
            return String(WECore::Richter::Parameters::PHASE.InteralToNormalised(mRichter.LFOPair1.MOD.getManualPhase()));

        case tempoNumerMOD1:
            return String(mRichter.LFOPair1.MOD.getTempoNumer());

        case tempoDenomMOD1:
            return String(mRichter.LFOPair1.MOD.getTempoDenom());





        case bypassSwitchMOD2:
            return String(static_cast<int>(mRichter.LFOPair2.MOD.getBypassSwitch()));

        case phaseSyncMOD2:
            return String(static_cast<int>(mRichter.LFOPair2.MOD.getPhaseSyncSwitch()));

        case tempoSyncMOD2:
            return String(static_cast<int>(mRichter.LFOPair2.MOD.getTempoSyncSwitch()));

        case waveMOD2:
            return String(mRichter.LFOPair2.MOD.getWave());

        case depthMOD2:
            return String(WECore::Richter::Parameters::DEPTH.InteralToNormalised(mRichter.LFOPair2.MOD.getDepth()));

        case freqMOD2:
            return String(WECore::Richter::Parameters::FREQ.InteralToNormalised(mRichter.LFOPair2.MOD.getFreq()));

        case phaseMOD2:
            return String(WECore::Richter::Parameters::PHASE.InteralToNormalised(mRichter.LFOPair2.MOD.getManualPhase()));

        case tempoNumerMOD2:
            return String(mRichter.LFOPair2.MOD.getTempoNumer());

        case tempoDenomMOD2:
            return String(mRichter.LFOPair2.MOD.getTempoDenom());




        case stereo:
            return String(mRichter.getStereo());

        case outputGain:
            return String(OUTPUTGAIN.InteralToNormalised(mRichter.getOutputGain()));

        default:
            return String();

    }
}


bool RichterAudioProcessor::isParameterAutomatable(int parameterIndex) const {
    switch (parameterIndex) {
        case bypassSwitchLFO1:
        case bypassSwitchLFO2:
        case bypassSwitchMOD1:
        case bypassSwitchMOD2:
        case tempoSyncLFO1:
        case tempoSyncLFO2:
        case tempoSyncMOD1:
        case tempoSyncMOD2:
        case phaseSyncLFO1:
        case phaseSyncLFO2:
        case phaseSyncMOD1:
        case phaseSyncMOD2:
        case waveLFO1:
        case waveLFO2:
        case waveMOD1:
        case waveMOD2:
        case stereo:
            return false;

        default:
            return true;
    }
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
void RichterAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    std::vector<float> userParams;
    for (int iii {0}; iii < totalNumParams; iii++) {
        userParams.push_back(getParameter(iii));
    }

    XmlElement root("Root");
    XmlElement *el = root.createNewChildElement("AllUserParam");

    el->addTextElement(String(floatVectorToString(userParams)));
    copyXmlToBinary(root, destData);
}

void RichterAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    std::unique_ptr<XmlElement> pRoot(getXmlFromBinary(data, sizeInBytes));
    std::vector<float> tmpUserParam;

    if (pRoot != NULL) {
        forEachXmlChildElement((*pRoot), pChild) {
            if (pChild->hasTagName("AllUserParam")) {
                String sFloatCSV = pChild->getAllSubText();
                if (stringToFloatVector(sFloatCSV, tmpUserParam, totalNumParams) == totalNumParams) {
                    for (int iii {0}; iii < totalNumParams; iii++) {
                        setParameter(iii, tmpUserParam[iii]);
                    }
                }
            }
        }

        // Slightly hacky fix to prevent inverted button settings on startup
        setParameter(stereo, getParameter(stereo));

        setParameter(bypassSwitchLFO1, getParameter(bypassSwitchLFO1));
        setParameter(phaseSyncLFO1, getParameter(phaseSyncLFO1));
        setParameter(tempoSyncLFO1, getParameter(tempoSyncLFO1));

        setParameter(bypassSwitchLFO2, getParameter(bypassSwitchLFO2));
        setParameter(phaseSyncLFO2, getParameter(phaseSyncLFO2));
        setParameter(tempoSyncLFO2, getParameter(tempoSyncLFO2));

        setParameter(bypassSwitchMOD1, getParameter(bypassSwitchMOD1));
        setParameter(phaseSyncMOD1, getParameter(phaseSyncMOD1));
        setParameter(tempoSyncMOD1, getParameter(tempoSyncMOD1));

        setParameter(bypassSwitchMOD2, getParameter(bypassSwitchMOD2));
        setParameter(phaseSyncMOD2, getParameter(phaseSyncMOD2));
        setParameter(tempoSyncMOD2, getParameter(tempoSyncMOD2));


        _UIUpdateFlag = true;
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new RichterAudioProcessor();
}
