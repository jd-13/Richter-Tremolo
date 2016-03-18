/*
  ==============================================================================

    Richter.h
    Created: 24 Nov 2015 6:56:33pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef RICHTER_H_INCLUDED
#define RICHTER_H_INCLUDED

#include "RichterLFO.h"
#include "RichterMOD.h"
#include "../JuceLibraryCode/JuceHeader.h"

class Richter {
public:
    Richter();
    ~Richter();
    
    RichterLFO LFO1, LFO2;
    RichterMOD MOD1, MOD2;
    
    /* ClockProcess1in1out
     *
     * Performs the effect processing on inSample. Use for mono in->mono out signals.
     *
     * args: inSample   Pointer to the sample to be processed
     *       index      Current position in the current buffer of samples
     */
    void ClockProcess1in1out(float* inSample, int index);
    
    /* ClockProcess1in2out
     *
     * Performs the effect processing on inLeftSample. Provides stereo processing for
     * mono in->stereo out signals by processing inLeftSample differently for the left
     * and right samples.
     *
     * args: inLeftSample    Pointer to the sample to be processed
     *       inRightSample   Pointer to a location in an empty sample buffer
     *       index           Current position in the current buffer of samples
     */
    void ClockProcess1in2out(float* inLeftSample, float* inRightSample, int index);
    
    /* ClockProcess2in2out
     *
     * Performs the effect processing on inLeftSample and inRightSample. Use for
     * stereo in->stereo out signals.
     *
     * args: inLeftSample    Pointer to the left sample to be processed
     *       inRightSample   Pointer to the right sample to be processed
     *       index           Current position in the current buffer of samples
     */
    void ClockProcess2in2out(float* inLeftSample, float* inRightSample, int index);
    
    
    /* resetSamplesProcessed
     *
     * Resets the internal counter of the number of samples processed.
     */
    void resetSamplesProcessed() { samplesProcessed = 0; }

    
    
    
    float getStereo() const { return isStereo; }
    
    float getMasterVol() const { return masterVol; }
    
    float getSamplesProcessed() const { return samplesProcessed; }
    
    
    
    
    void setStereo(bool val) { isStereo = val; }
    
    void setMasterVol(float val) { masterVol = val; }
    
    
    
private:
    float   masterVol;
    
    long    samplesProcessed;
    
    enum    { sampleLimit = (int) 10E6 };
    
    bool    isStereo;
    
};



#endif  // RICHTER_H_INCLUDED
