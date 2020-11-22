/*
 *  File:       Richter.cpp
 *
 *  Version:    2.0.0
 *
 *  Created:    24/11/2015
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

#include "Richter.h"

Richter::Richter() : outputGain(OUTPUTGAIN.defaultValue), isStereo(STEREO_DEFAULT) {
}

Richter::~Richter() {}

void Richter::ClockProcess1in1out(float *inSample) {

    _updateLFOCache();

    double tremoloGain { _lfoCache.lfo1 * _lfoCache.lfo2};

    *inSample = *inSample * tremoloGain * outputGain;
}

void Richter::ClockProcess1in2out(float *inLeftSample, float *inRightSample) {

    _updateLFOCache();

    if (isStereo) {
        *inRightSample =    *inLeftSample
                            * _lfoCache.lfo2
                            * outputGain;
        *inLeftSample =     *inLeftSample
                            * _lfoCache.lfo1
                            * outputGain;
    } else {
        double tremoloGain { _lfoCache.lfo1 * _lfoCache.lfo2};

        *inLeftSample = *inLeftSample * tremoloGain * outputGain;
        *inRightSample = *inRightSample * tremoloGain * outputGain;
    }
}

void Richter::ClockProcess2in2out(float* inLeftSample, float* inRightSample) {

    _updateLFOCache();

    if (isStereo) {
        *inLeftSample =     *inLeftSample
                            * _lfoCache.lfo1
                            * outputGain;

        *inRightSample =    *inRightSample
                            * _lfoCache.lfo2
                            * outputGain;
    } else {
        double tremoloGain {_lfoCache.lfo1 * _lfoCache.lfo2};

        *inLeftSample = *inLeftSample * tremoloGain * outputGain;
        *inRightSample = *inRightSample * tremoloGain * outputGain;
    }
}

void Richter::_updateLFOCache() {
    // Advance the LFOs
    LFOPair1.getNextOutput(0);
    LFOPair2.getNextOutput(0);
    
    // Store the values
    _lfoCache.lfo1 = LFOPair1.getLastOutput();
    _lfoCache.lfo2 = LFOPair2.getLastOutput();
    _lfoCache.mod1 = LFOPair1.MOD->getLastOutput();
    _lfoCache.mod2 = LFOPair2.MOD->getLastOutput();
}
