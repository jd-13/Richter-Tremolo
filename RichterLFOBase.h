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

#define _USE_MATH_DEFINES

#include "math.h"
#include "ParameterData.h"

class RichterLFOBase {
protected:
    int manualPhase,
        wave,
        index,
        indexOffset,
        samplesProcessed;
    
    bool    bypassSwitch,
            tempoSyncSwitch,
            phaseSyncSwitch,
            needsPhaseCalc;
        
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
    
    template <typename T>
    T boundsCheck(T param, T min, T max) {
        if (param < min) param = min;
        if (param > max) param = max;
        
        return param;
    }
    
public:
    RichterLFOBase();
    
    virtual ~RichterLFOBase() {};
        
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
        
    
    
    // set parameter methods, w/ integrated bounds checks
    
    void setBypassSwitch(bool val);
    
    void setPhaseSyncSwitch(bool val);
    
    void setTempoSyncSwitch(bool val);
    
    void setTempoNumer(int val);
    
    void setTempoDenom (int val);
    
    void setFreq(float val);
    
    void setDepth(float val);
    
    void setManualPhase(int val);
    
    void setWave(float val);
    
    void setWaveTablePointers();
    
    void setIndexOffset(int val) { indexOffset = val; }
    
    
    /* reset
     *
     * Resets indexOffset and currentScale. Call before beginning a new buffer of
     * samples.
     */
    void reset();
    
    /* calcPhaseOffset
     *
     * Calculates the phase offset to be applied to the oscillator, including any
     * offset required by the phase sync and any offset applied by the user.
     *
     * args: timeInSeconds   Position of the host DAW's playhead at the start of
     *                       playback
     */
    void calcPhaseOffset(double timeInSeconds);
    
    /* calcFreq
     *
     * Calculates the frequency of the oscillator. Will use either the frequency
     * or tempoNumer/tempoDenom depending on whether tempo sync is enabled.
     *
     * args: bpm   Current bpm of the host DAW
     */
    void calcFreq(double bpm);
    
    /* calcSamplesPerTremoloCycle
     *
     * Calculates the number of samples which pass in the same time as one cycle
     * of the LFO. Dependant on the LFO frequency and the sample rate.
     *
     * args: sampleRate   Sample rate of the host DAW
     */
    void calcSamplesPerTremoloCycle(float sampleRate);
    
    /* calcIndexAndScaleInLoop
     *
     * Calculates the current index of the oscillator in its wavetable. Includes
     * protection against indexes out of range (caused by phase offset) and updates
     * currentScale. Call from within the processing loop. Increments the number of 
     * samples processed
     *
     */
    void calcIndexAndScaleInLoop();
    
    /* calcNextScale
     *
     * Calculates the scale factor to be applied when calculating the index. 
     */
    void calcNextScale();
    
    RichterLFOBase operator=(RichterLFOBase& other) = delete;
    RichterLFOBase(RichterLFOBase& other) = delete;
};

#endif
