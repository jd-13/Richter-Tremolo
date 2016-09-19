/*
 *  File:       RichterLFOPair.h
 *
 *  Version:    2.0.0
 *
 *  Created:    18/05/2015
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

#ifndef RICHTERLFOPAIR_H_INCLUDED
#define RICHTERLFOPAIR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "RichterLFO.h"
#include "RichterMOD.h"

class RichterLFOPair {
public:
    RichterLFOPair();
    
    void reset();
    
    void processBlock(const juce::AudioPlayHead::CurrentPositionInfo& mTempoInfo,
                      double sampleRate);
    
    float calcGainInLoop();
        
    RichterLFO _LFO;
    RichterMOD _MOD;
    
    RichterLFOPair operator= (RichterLFOPair& other) = delete;
    RichterLFOPair(RichterLFOPair& other) = delete;
    
};



#endif  // RICHTERLFOPAIR_H_INCLUDED
