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

#include "RichterLFOBase.h"

#ifndef Richter_RichterLFO_h
#define Richter_RichterLFO_h

class RichterLFO : public RichterLFOBase {
private:
    
    float   rawFreq,
            freqMod,
            rawDepth,
            depthMod;
    
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
    
    
    
    
    // override the similar method in the base class, as the true LFOs are depentant on more parameters
    void calcFreq(int modBypassSwitch, float modGain);
    
    
    
    void calcDepthInLoop(int modBypassSwitch, float modGain);
    
    
};

#endif
