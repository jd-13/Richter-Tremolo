/*
  ==============================================================================

    Richter.cpp
    Created: 24 Nov 2015 6:56:33pm
    Author:  Jack Devlin

  ==============================================================================
*/

#include "Richter.h"

Richter::Richter() : LFO1(), LFO2(), MOD1(), MOD2() {
}

Richter::~Richter() {}

void Richter::ClockProcess(float* inLeftSample, float* inRightSample, int index) {
    LFO1.calcIndexAndScaleInLoop(samplesProcessed);
    LFO2.calcIndexAndScaleInLoop(samplesProcessed);
    MOD1.calcIndexAndScaleInLoop(samplesProcessed);
    MOD2.calcIndexAndScaleInLoop(samplesProcessed);
    
    if ((samplesProcessed >= sampleLimit) && (index == 0)) { // TODO: replace with index stored in LFO 1
        resetSamplesProcessed();
    }
    
    // Check whether MOD oscs are activated and apply depth parameter modulation accordingly
    
    LFO1.calcDepthInLoop(MOD1.getBypassSwitch(), MOD1.getGain());
    LFO2.calcDepthInLoop(MOD2.getBypassSwitch(), MOD2.getGain());
    
    
    float tremoloGain = (LFO1.calcGain()) * (LFO2.calcGain());
    
    *inLeftSample = *inLeftSample * tremoloGain * masterVol;
    *inRightSample = *inRightSample * tremoloGain * masterVol;
    
    samplesProcessed += 1;
    
}
