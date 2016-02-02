/*
 *  File:       RichterMOD.h
 *
 *  Version:    2.0.0
 *
 *  Created:    05/02/2015
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

#include "RichterMOD.h"

RichterMOD::RichterMOD() : RichterLFOBase() {
    
    // mod wavetables below (no correction, move below 0)
        
    for (int i = 0; i < kWaveArraySize; ++i) {
        
        // sine wavetable
        double radians {i * 2.0 * M_PI / kWaveArraySize};
        mSine[i] = (sin (radians)) * 0.5;
        
        // square wavetable
        double squareRadians {radians + 0.32};
        mSquare[i] =
        (
         sin (radians) +
         0.3 * sin (3 * squareRadians) +
         0.15 * sin (5 * squareRadians) +
         0.075 * sin (7 * squareRadians) +
         0.0375 * sin (9 * squareRadians) +
         0.01875 * sin (11 * squareRadians) +
         0.009375 * sin (13 * squareRadians)
         );
        
        // saw wavetable
        double sawRadians {radians + M_PI};
        mSaw[i] =
        (1/M_PI) *
        (
         sin (sawRadians) -
         0.5 * sin (2 * sawRadians) +
         (1.0/3.0) * sin (3 * sawRadians) -
         0.25 * sin (4 * sawRadians) +
         0.2 * sin (5 * sawRadians) -
         (1.0/6.0) * sin (6 * sawRadians) +
         (1.0/7.0) * sin (7 * sawRadians) -
         (1.0/8.0) * sin (8 * sawRadians) +
         (1.0/9.0) * sin (9 * sawRadians) -
         0.1 * sin (10 * sawRadians) +
         (1.0/11.0) * sin (11 * sawRadians) -
         (1.0/12.0) * sin (12 * sawRadians) +
         (1.0/13.0) * sin (13 * sawRadians) -
         (1.0/14.0) * sin (14 * sawRadians)
         );
    }
    
}

float RichterMOD::calcGain() const {
    if (bypassSwitch) {
        return (gain * depth);
    } else {
        return 0;
    }
}