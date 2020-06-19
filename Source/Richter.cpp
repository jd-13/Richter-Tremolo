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

Richter::Richter() :    LFOPair1(), LFOPair2(),
                        isStereo(STEREO_DEFAULT) {
}

Richter::~Richter() {}

void Richter::ClockProcess1in1out(float *inSample) {
    
    double tremoloGain { LFOPair1.calcGainInLoop()
                         * LFOPair2.calcGainInLoop()};
    
    *inSample = *inSample * tremoloGain * outputGain;
}

void Richter::ClockProcess1in2out(float *inLeftSample, float *inRightSample) {
    
    if (isStereo) {
        *inRightSample =    *inLeftSample
                            * LFOPair2.calcGainInLoop()
                            * outputGain;
        *inLeftSample =     *inLeftSample
                            * LFOPair1.calcGainInLoop()
                            * outputGain;
    } else {
        double tremoloGain { LFOPair1.calcGainInLoop()
                             * LFOPair2.calcGainInLoop()};
        
        *inLeftSample = *inLeftSample * tremoloGain * outputGain;
        *inRightSample = *inRightSample * tremoloGain * outputGain;
    }
}

void Richter::ClockProcess2in2out(float* inLeftSample, float* inRightSample) {
    
    if (isStereo) {
        *inLeftSample =     *inLeftSample
                            * LFOPair1.calcGainInLoop()
                            * outputGain;
        
        *inRightSample =    *inRightSample
                            * LFOPair2.calcGainInLoop()
                            * outputGain;
    } else {
        double tremoloGain {LFOPair1.calcGainInLoop()
                            * LFOPair2.calcGainInLoop()};
        
        *inLeftSample = *inLeftSample * tremoloGain * outputGain;
        *inRightSample = *inRightSample * tremoloGain * outputGain;
    }
}
