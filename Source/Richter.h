/*
 *  File:       Richter.h
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

#ifndef RICHTER_H_INCLUDED
#define RICHTER_H_INCLUDED

#include "RichterLFO/RichterLFOPair.h"
#include "ParameterData.h"
#include "../JuceLibraryCode/JuceHeader.h"

class Richter {
public:
    Richter();
    ~Richter();

    WECore::Richter::RichterLFOPair LFOPair1, LFOPair2;

    /* ClockProcess1in1out
     *
     * Performs the effect processing on inSample. Use for mono in->mono out signals.
     *
     * args: inSample   Pointer to the sample to be processed
     */
    void ClockProcess1in1out(float* inSample);

    /* ClockProcess1in2out
     *
     * Performs the effect processing on inLeftSample. Provides stereo processing for
     * mono in->stereo out signals by processing inLeftSample differently for the left
     * and right samples.
     *
     * args: inLeftSample    Pointer to the sample to be processed
     *       inRightSample   Pointer to a location in an empty sample buffer
     */
    void ClockProcess1in2out(float* inLeftSample, float* inRightSample);

    /* ClockProcess2in2out
     *
     * Performs the effect processing on inLeftSample and inRightSample. Use for
     * stereo in->stereo out signals.
     *
     * args: inLeftSample    Pointer to the left sample to be processed
     *       inRightSample   Pointer to the right sample to be processed
     */
    void ClockProcess2in2out(float* inLeftSample, float* inRightSample);



    float getStereo() const { return isStereo; }

    float getOutputGain() const { return outputGain; }




    void setStereo(bool val) { isStereo = val; }

    void setOutputGain(float val) { outputGain = OUTPUTGAIN.BoundsCheck(val); }



private:
    float   outputGain;

    enum    { sampleLimit = (int) 10E6 };

    bool    isStereo;

};



#endif  // RICHTER_H_INCLUDED
