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
 *  along with the Richter Tremolo.  If not, see <http://www.gnu.org/licenses/>.
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

void RichterLFOBase::setWave(float val) {
    wave = val;
    wave = boundsCheck<int>(wave, WAVE_MIN, WAVE_MAX);
}

void RichterLFOBase::setWaveTablePointers() {
    if (wave == 1) { waveArrayPointer = &mSine[0]; }
    if (wave == 2) { waveArrayPointer = &mSquare[0]; }
    if (wave == 3) { waveArrayPointer = &mSaw[0]; }
}




void RichterLFOBase::calcTempoOffset(float beats, int nBeats, float tempo, long mSamplesProcessed) {
    
    // Convert the bpm to a frequency value in HZ
    tempoFreq = (tempo / 60) * (tempoDenom / tempoNumer);
    
    // The below int is later used to check if any beat correction is actually needed at all (beat correction is explained below)
    // They are multiplied by 100000 as the smallest value ratio is 1/32, and this enables int casting, such that modulo is easier later on
    int tempoRatio = (tempoNumer / tempoDenom) * 100000;
    
    // The following calcs should only be applied at the instant the sequencer begins playing, hence the if statement. They allow an index offset to be calculated such that the oscs can start playing at a different part of the wave depending on where the sequencer starts playing in order to ensure consistent processing.
    
    if (mSamplesProcessed < 1000) { // TODO: The upper bound for mSamplesProcessed should be experimented with, and the optimal value may be related to the frequency
        
        if (tempoSyncSwitch) {
            
            if ( (tempoNumer / tempoDenom) < beats ) {
                offset = fmod(beats, (tempoNumer / tempoDenom)) / (tempoNumer / tempoDenom); // This is the offset as a fraction of kWaveArraySize
                
                indexOffset = offset * kWaveArraySize;
            }
            
            else {
                offset = beats / (tempoNumer / tempoDenom); // Again this is the offset as a fraction of kWaveArraySize
                indexOffset = offset * kWaveArraySize;
                
            }
            
        }
        
        if (!tempoSyncSwitch || ((nBeats % tempoRatio) < 1)) {
            //offset = 0;
            //indexOffset = 0;
            //LFO1Offset = GetParameter();              Possibly add in a user adjustable phase control
        }
    }
    
    if (beats < (1/64)) {
        indexOffset = 0;
    }
}




 void RichterLFOBase::calcFreq() {
    // calculate the frequency based on whether tempo sync is active
    
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
    
    if ((index + indexOffset) < kWaveArraySize)    { gain = waveArrayPointer[index + indexOffset]; }
    else if ((index + indexOffset) >= kWaveArraySize)   { gain = waveArrayPointer[(index + indexOffset) % kWaveArraySize]; }
    
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