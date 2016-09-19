/*
  ==============================================================================

    Richter.cpp
    Created: 24 Nov 2015 6:56:33pm
    Author:  Jack Devlin

  ==============================================================================
*/

#include "Richter.h"

Richter::Richter() :    LFOPair1(), LFOPair2(),
                        isStereo(STEREO_DEFAULT) {
}

Richter::~Richter() {}

void Richter::ClockProcess1in1out(float *inSample) {
    
    float tremoloGain { LFOPair1.calcGainInLoop()
                        * LFOPair2.calcGainInLoop()};
    
    *inSample = *inSample * tremoloGain * masterVol;
}

void Richter::ClockProcess1in2out(float *inLeftSample, float *inRightSample) {
    
    if (isStereo) {
        *inRightSample =    *inLeftSample
                            * LFOPair2.calcGainInLoop()
                            * masterVol;
        *inLeftSample =     *inLeftSample
                            * LFOPair1.calcGainInLoop()
                            * masterVol;
    } else {
        float tremoloGain { LFOPair1.calcGainInLoop()
                            * LFOPair2.calcGainInLoop()};
        
        *inLeftSample = *inLeftSample * tremoloGain * masterVol;
        *inRightSample = *inRightSample * tremoloGain * masterVol;
    }
}

void Richter::ClockProcess2in2out(float* inLeftSample, float* inRightSample) {
    
    if (isStereo) {
        *inLeftSample =     *inLeftSample
                            * LFOPair1.calcGainInLoop()
                            * masterVol;
        
        *inRightSample =    *inRightSample
                            * LFOPair2.calcGainInLoop()
                            * masterVol;
    } else {
        float tremoloGain {LFOPair1.calcGainInLoop()
                            * LFOPair2.calcGainInLoop()};
        
        *inLeftSample = *inLeftSample * tremoloGain * masterVol;
        *inRightSample = *inRightSample * tremoloGain * masterVol;
    }
}
