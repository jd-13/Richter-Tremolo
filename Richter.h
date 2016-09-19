/*
  ==============================================================================

    Richter.h
    Created: 24 Nov 2015 6:56:33pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef RICHTER_H_INCLUDED
#define RICHTER_H_INCLUDED

#include "RichterLFOPair.h"
#include "../JuceLibraryCode/JuceHeader.h"

class Richter {
public:
    Richter();
    ~Richter();
    
    RichterLFOPair LFOPair1, LFOPair2;
    
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
    
    float getMasterVol() const { return masterVol; }
        
    
    
    
    void setStereo(bool val) { isStereo = val; }
    
    void setMasterVol(float val) { masterVol = val; }
    
    
    
private:
    float   masterVol;
    
    enum    { sampleLimit = (int) 10E6 };
    
    bool    isStereo;
    
};



#endif  // RICHTER_H_INCLUDED
