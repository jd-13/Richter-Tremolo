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
    
    void ClockProcess1in1out(float* inSample, int index);
    void ClockProcess1in2out(float* inLeftSample, float* inRightSample, int index);
    void ClockProcess2in2out(float* inLeftSample, float* inRightSample, int index);
    
    
    
    float getStereo() const { return isStereo; }
    
    float getMasterVol() const { return masterVol; }
    
    float getSamplesProcessed() const { return samplesProcessed; }
    
    
    
    
    void setStereo(bool val) { isStereo = val; }
    
    void setMasterVol(float val) { masterVol = val; }
    
    void resetSamplesProcessed() { samplesProcessed = 0; }
    
    
private:
    float   masterVol;
    
    long    samplesProcessed;
    
    enum    { sampleLimit = (int) 10E6 };
    
    bool    isStereo;
    
};



#endif  // RICHTER_H_INCLUDED
