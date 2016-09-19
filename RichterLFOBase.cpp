/*
 *  File:       RichterLFOBase.cpp
 *
 *  Version:    2.0.0
 *
 *  Created:    18/01/2015
 *
 *	This file is part of Richter.
 *
 *  Richter is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Richter is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with the Richter.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "RichterLFOBase.h"

RichterLFOBase::RichterLFOBase() :  manualPhase(0),
                                    wave(WAVE_DEFAULT),
                                    index(0),
                                    indexOffset(0),
                                    samplesProcessed(0),
                                    bypassSwitch(LFOSWITCH_DEFAULT),
                                    tempoSyncSwitch(TEMPOSYNC_DEFAULT),
                                    phaseSyncSwitch(PHASESYNC_DEFAULT),
                                    needsPhaseCalc(true),
                                    tempoNumer(TEMPONUMER_DEFAULT),
                                    tempoDenom(TEMPODENOM_DEFAULT),
                                    tempoFreq(FREQ_DEFAULT),
                                    freq(FREQ_DEFAULT),
                                    depth(DEPTH_DEFAULT),
                                    samplesPerTremoloCycle(1),
                                    gain(1),
                                    offset(0),
                                    currentScale(0),
                                    nextScale(0),
                                    waveArrayPointer(&mSine[0]) {
}





// setter methods
void RichterLFOBase::setBypassSwitch(bool val) {
    bypassSwitch = val;
}

void RichterLFOBase::setPhaseSyncSwitch(bool val) {
    phaseSyncSwitch = val;

}

void RichterLFOBase::setTempoSyncSwitch(bool val) {
    tempoSyncSwitch = val;

}

void RichterLFOBase::setTempoNumer(int val) {
    tempoNumer = boundsCheck<int>(val, TEMPONUMER_MIN, TEMPONUMER_MAX);
}

void RichterLFOBase::setTempoDenom (int val) {
    tempoDenom = boundsCheck<int>(val, TEMPODENOM_MIN, TEMPODENOM_MAX);
}

void RichterLFOBase::setFreq(float val) {
    freq = boundsCheck(val, FREQ_MIN, FREQ_MAX);
}

void RichterLFOBase::setDepth(float val) {
    depth = boundsCheck(val, DEPTH_MIN, DEPTH_MAX);
}

void RichterLFOBase::setManualPhase(int val) {
    manualPhase = boundsCheck(val, PHASE_MIN, PHASE_MAX);
}

void RichterLFOBase::setWave(float val) {
    wave = boundsCheck<int>(val, WAVE_MIN, WAVE_MAX);
}

void RichterLFOBase::setWaveTablePointers() {
    if (wave == WAVE_SINE) { waveArrayPointer = &mSine[0]; }
    if (wave == WAVE_SQUARE) { waveArrayPointer = &mSquare[0]; }
    if (wave == WAVE_SAW) { waveArrayPointer = &mSaw[0]; }
}



void RichterLFOBase::reset() {
    needsPhaseCalc = true;
    indexOffset = 0;
    currentScale = 0;
    samplesProcessed = 0;
}

void RichterLFOBase::calcPhaseOffset(double timeInSeconds) {
    if (phaseSyncSwitch && needsPhaseCalc) {
        float waveLength {1 / freq};
        double waveTimePosition {0};
        
        if (waveLength < timeInSeconds) {
            waveTimePosition = fmod(timeInSeconds, waveLength);
        } else {
            waveTimePosition = timeInSeconds;
        }
        indexOffset = (waveTimePosition / waveLength) * kWaveArraySize + manualPhase;
    }
    
    if (!phaseSyncSwitch && needsPhaseCalc) {
        indexOffset = manualPhase;
    }
    needsPhaseCalc = false;

}




void RichterLFOBase::calcFreq(double bpm) {
    // calculate the frequency based on whether tempo sync is active
     
    tempoFreq = (bpm / 60) * (tempoDenom / tempoNumer);
    
    if (tempoSyncSwitch) { freq = tempoFreq; }
    
    boundsCheck(freq, FREQ_MIN, FREQ_MAX);
    
}


void RichterLFOBase::calcSamplesPerTremoloCycle(float sampleRate) {
    samplesPerTremoloCycle = sampleRate / freq;
}



void RichterLFOBase::calcIndexAndScaleInLoop() {
    // calculate the current index within the wave table
    
    index = static_cast<long>(samplesProcessed * currentScale) % kWaveArraySize;
    
    if ((nextScale != currentScale) && (index == 0)) {
        currentScale = nextScale;
        samplesProcessed = 0;
    }
    
    
    // Must provide two possibilities for each index lookup in order to protect the array from being overflowed by the indexOffset, the first if statement uses the standard index lookup while second if statement deals with the overflow possibility
    
    if ((index + indexOffset) < kWaveArraySize) {
        gain = waveArrayPointer[index + indexOffset];
    } else if ((index + indexOffset) >= kWaveArraySize) {
        gain = waveArrayPointer[(index + indexOffset) % kWaveArraySize];
    }
    
    samplesProcessed++;
}

void RichterLFOBase::calcNextScale() {
    nextScale = kWaveArraySize / samplesPerTremoloCycle;
}