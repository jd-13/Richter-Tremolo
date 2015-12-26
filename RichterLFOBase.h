/*
 *  File:       RichterLFOBase.h
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

#ifndef Richter_RichterLFOBase_h
#define Richter_RichterLFOBase_h

#include "math.h"
#include "ParameterData.h"

class RichterLFOBase {
protected:
    int bypassSwitch,
        tempoSyncSwitch,
        phaseSyncSwitch,
        manualPhase,
        wave,
        index,
        indexOffset;
    
    bool needsPhaseCalc;
        
    float   tempoNumer,
            tempoDenom,
            tempoFreq,
            freq,
            depth,
            samplesPerTremoloCycle,
            gain,
            offset,
            currentScale,
            nextScale;
    
    float   *waveArrayPointer;
    
    float mSine[kWaveArraySize];
    float mSquare[kWaveArraySize];
    float mSaw[kWaveArraySize];
    
    template<typename T>
    T boundsCheck(T param, T min, T max);
    
public:
    RichterLFOBase() : currentScale(0) {}
        
    // getter methods
    
    int getBypassSwitch() const { return bypassSwitch; }
    
    int getPhaseSyncSwitch() const { return phaseSyncSwitch; }
    
    int getTempoSyncSwitch() const { return tempoSyncSwitch; }
    
    float getWave() const { return wave; }
    
    float getDepth() const { return depth; }
    
    float getFreq() const { return freq; }
    
    int getManualPhase() const { return manualPhase; }
    
    float getTempoNumer() const { return tempoNumer; }
    
    float getTempoDenom() const { return tempoDenom; }
    
    float getWaveArraySize() const { return kWaveArraySize; }
    
    
    int getIndexOffset() { return indexOffset; }
        
    void setIndexOffset(int val) { indexOffset = val; }
        
    
    // set parameter methods, w/ integrated bounds checks
    
    void setBypassSwitch(int val);
    
    void setPhaseSyncSwitch(int val);
    
    void setTempoSyncSwitch(int val);
    
    void setTempoNumer(int val);
    
    void setTempoDenom (int val);
    
    void setFreq(float val);
    
    void setDepth(float val);
    
    void setManualPhase(int val);
    
    void setWave(float val);
    
    void setWaveTablePointers();
    
    
    
    
    
    void reset();
    
    void calcPhaseOffset(double timeInSeconds);
    
    void calcFreq(double bpm);
    
    void calcSamplesPerTremoloCycle(float sampleRate);
    
    void calcIndexAndScaleInLoop(long &mSamplesProcessed);
    
    void calcNextScale();
    
    float calcGain() const;
        
};

#endif
