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

template <typename T>
T RichterLFOBase::boundsCheck(T param, T min, T max) {
    if (param < min) param = min;
    if (param > max) param = max;
    
    return param;
}


// setter methods
void RichterLFOBase::setBypassSwitch(int val) {
    bypassSwitch = val;
    bypassSwitch = boundsCheck(bypassSwitch, 0, 1);
}

void RichterLFOBase::setPhaseSyncSwitch(int val) {
    phaseSyncSwitch = val;
    phaseSyncSwitch = boundsCheck(phaseSyncSwitch, 0, 1);
}


void RichterLFOBase::setTempoSyncSwitch(int val) {
    tempoSyncSwitch = val;
    tempoSyncSwitch = boundsCheck(tempoSyncSwitch, 0, 1);
}

void RichterLFOBase::setTempoNumer(int val) {
    tempoNumer = val;
    tempoNumer = boundsCheck<int>(tempoNumer, TEMPONUMER_MIN, TEMPONUMER_MAX);
}

void RichterLFOBase::setTempoDenom (int val) {
    tempoDenom = val;
    tempoDenom = boundsCheck<int>(tempoDenom, TEMPODENOM_MIN, TEMPODENOM_MAX);
}

void RichterLFOBase::setFreq(float val) {
    freq = val;
    freq = boundsCheck(freq, FREQ_MIN, FREQ_MAX);
}

void RichterLFOBase::setDepth(float val) {
    depth = val;
    depth = boundsCheck(depth, DEPTH_MIN, DEPTH_MAX);
}

void RichterLFOBase::setManualPhase(int val) {
    manualPhase = val;
    manualPhase = boundsCheck(manualPhase, PHASE_MIN, PHASE_MAX);
}

void RichterLFOBase::setWave(float val) {
    wave = val;
    wave = boundsCheck<int>(wave, WAVE_MIN, WAVE_MAX);
}

void RichterLFOBase::setWaveTablePointers() {
    if (wave == 1) { waveArrayPointer = &mSine[0]; }
    if (wave == 2) { waveArrayPointer = &mSquare[0]; }
    if (wave == 3) { waveArrayPointer = &mSaw[0]; }
}



void RichterLFOBase::reset() {
    needsPhaseCalc = true;
    indexOffset = 0;
    currentScale = 0;
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
        Logger::outputDebugString(String(indexOffset));
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



void RichterLFOBase::calcIndexAndScaleInLoop(long &mSamplesProcessed) {
    // calculate the current index within the wave table
    
    index = static_cast<long>(mSamplesProcessed * currentScale) % kWaveArraySize;
    
    if ((nextScale != currentScale) && (index == 0)) {
        currentScale = nextScale;
        mSamplesProcessed = 0;
    }
    
    
    // Must provide two possibilities for each index lookup in order to protect the array from being overflowed by the indexOffset, the first if statement uses the standard index lookup while second if statement deals with the overflow possibility
    
    if ((index + indexOffset) < kWaveArraySize) {
        gain = waveArrayPointer[index + indexOffset];
    } else if ((index + indexOffset) >= kWaveArraySize) {
        gain = waveArrayPointer[(index + indexOffset) % kWaveArraySize];
    }
}

void RichterLFOBase::calcNextScale() {
    nextScale = kWaveArraySize / samplesPerTremoloCycle;
}




float RichterLFOBase::calcGain() const {
    if (bypassSwitch) {
        return ((gain * depth - depth + 1));
    } else {
        return 1;
    }
}