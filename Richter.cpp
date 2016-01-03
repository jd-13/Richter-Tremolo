/*
  ==============================================================================

    Richter.cpp
    Created: 24 Nov 2015 6:56:33pm
    Author:  Jack Devlin

  ==============================================================================
*/

#include "Richter.h"

Richter::Richter() :    LFO1(), LFO2(), MOD1(), MOD2(),
                        isStereo(STEREO_DEFAULT) {
}

Richter::~Richter() {}

void Richter::ClockProcess1in1out(float *inSample, int index) {
    LFO1.calcIndexAndScaleInLoop(samplesProcessed);
    LFO2.calcIndexAndScaleInLoop(samplesProcessed);
    MOD1.calcIndexAndScaleInLoop(samplesProcessed);
    MOD2.calcIndexAndScaleInLoop(samplesProcessed);
    
    if ((samplesProcessed >= sampleLimit) && (index == 0)) { // TODO: replace with index stored in LFO 1
        resetSamplesProcessed();
    }
    
    // Check whether MOD oscs are activated and apply depth parameter modulation accordingly
    LFO1.calcDepthInLoop(MOD1.getBypassSwitch(), MOD1.calcGain());
    LFO2.calcDepthInLoop(MOD2.getBypassSwitch(), MOD2.calcGain());
    
    LFO1.calcFreqInLoop(MOD1.getBypassSwitch(), MOD1.calcGain());
    LFO2.calcFreqInLoop(MOD2.getBypassSwitch(), MOD2.calcGain());
    
    
    float tremoloGain = (LFO1.calcGain()) * (LFO2.calcGain());
    
    *inSample = *inSample * tremoloGain * masterVol;
    
    samplesProcessed += 1;
}

void Richter::ClockProcess1in2out(float *inLeftSample, float *inRightSample, int index) {
    LFO1.calcIndexAndScaleInLoop(samplesProcessed);
    LFO2.calcIndexAndScaleInLoop(samplesProcessed);
    MOD1.calcIndexAndScaleInLoop(samplesProcessed);
    MOD2.calcIndexAndScaleInLoop(samplesProcessed);
    
    if ((samplesProcessed >= sampleLimit) && (index == 0)) { // TODO: replace with index stored in LFO 1
        resetSamplesProcessed();
    }
    
    // Check whether MOD oscs are activated and apply depth parameter modulation accordingly
    LFO1.calcDepthInLoop(MOD1.getBypassSwitch(), MOD1.calcGain());
    LFO2.calcDepthInLoop(MOD2.getBypassSwitch(), MOD2.calcGain());
    
    LFO1.calcFreqInLoop(MOD1.getBypassSwitch(), MOD1.calcGain());
    LFO2.calcFreqInLoop(MOD2.getBypassSwitch(), MOD2.calcGain());
    
    
    
    if (isStereo) {
        *inRightSample = *inLeftSample * LFO2.calcGain() * masterVol;
        *inLeftSample = *inLeftSample * LFO1.calcGain() * masterVol;
    } else {
        float tremoloGain = (LFO1.calcGain()) * (LFO2.calcGain());
        *inLeftSample = *inLeftSample * tremoloGain * masterVol;
        *inRightSample = *inRightSample * tremoloGain * masterVol;
    }
    
    
    samplesProcessed += 1;
}

void Richter::ClockProcess2in2out(float* inLeftSample, float* inRightSample, int index) {
    LFO1.calcIndexAndScaleInLoop(samplesProcessed);
    LFO2.calcIndexAndScaleInLoop(samplesProcessed);
    MOD1.calcIndexAndScaleInLoop(samplesProcessed);
    MOD2.calcIndexAndScaleInLoop(samplesProcessed);
    
    if ((samplesProcessed >= sampleLimit) && (index == 0)) { // TODO: replace with index stored in LFO 1
        resetSamplesProcessed();
    }
    
    // Check whether MOD oscs are activated and apply depth parameter modulation accordingly
    LFO1.calcDepthInLoop(MOD1.getBypassSwitch(), MOD1.calcGain());
    LFO2.calcDepthInLoop(MOD2.getBypassSwitch(), MOD2.calcGain());
    
    LFO1.calcFreqInLoop(MOD1.getBypassSwitch(), MOD1.calcGain());
    LFO2.calcFreqInLoop(MOD2.getBypassSwitch(), MOD2.calcGain());
    
    
    
    if (isStereo) {
        *inLeftSample = *inLeftSample * LFO1.calcGain() * masterVol;
        *inRightSample = *inRightSample * LFO2.calcGain() * masterVol;
    } else {
        float tremoloGain = (LFO1.calcGain()) * (LFO2.calcGain());
        *inLeftSample = *inLeftSample * tremoloGain * masterVol;
        *inRightSample = *inRightSample * tremoloGain * masterVol;
    }
    
    samplesProcessed += 1;
    
}
