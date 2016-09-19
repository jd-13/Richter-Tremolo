/*
 *  File:       RichterLFO.h
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

#ifndef Richter_RichterLFO_h
#define Richter_RichterLFO_h

#include "RichterLFOBase.h"

class RichterLFO : public RichterLFOBase {
    
public:
    RichterLFO();
    
    float getRawDepth() { return rawDepth; }
    
    float getDepthMod() { return depthMod; }
    
    float getRawFreq() { return rawFreq; }
    
    float getFreqMod() { return freqMod; }
    
    
    
    // set parameter methods, w/ integrated bounds checks
    
    void setRawFreq(float val);
    
    void setFreqMod(float val);
    
    void setRawDepth(float val);
    
    void setDepthMod(float val);
    
    /* calcGain
     *
     * Calculates the gain value to be applied to a signal which the oscillator
     * is operating on. Outputs a value between 0 and 1. Always outputs 1 if bypassed.
     *
     * args: modBypassSwitch   The state of the modulation oscillator. Determines
     *                         whether modGain is applied to the calculation
     *       modGain           The gain output from the modulation oscillator
     */
    virtual float calcGain(int modBypassSwitch, float modGain);
    
    RichterLFO operator= (RichterLFO& other) = delete;
    RichterLFO(RichterLFO&) = delete;
    
private:
    
    float   rawFreq,
            freqMod,
            rawDepth,
            depthMod;
    
    /* calcFreqInLoop
     *
     * Applies frequency modulation to the oscillator. Performed in the processing
     * loop so that the frequency can be updated before processing each sample.
     *
     * args: modBypassSwitch   The state of the modulation oscillator. Determines
     *                         whether modGain is applied to the calculation
     *       modGain           The gain output from the modulation oscillator
     */
    void calcFreqInLoop(int modBypassSwitch, float modGain);
    
    /* calcDepthInLoop
     *
     * Applies depth modulation to the oscillator. Performed in the processing
     * loop so that the frequency can be updated before processing each sample.
     *
     * args: modBypassSwitch   The state of the modulation oscillator. Determines
     *                         whether modGain is applied to the calculation
     *       modGain           The gain output from the modulation oscillator
     */
    void calcDepthInLoop(int modBypassSwitch, float modGain);
};

#endif
