/*
 *	File:		ParameterData.h
 *
 *	Version:	2.0.0
 *
 *	Created:	20/10/2015
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
 *  along with Richter.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef PARAMETERDATA_H_INCLUDED
#define PARAMETERDATA_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


const int   WAVE_SINE = 1,
            WAVE_SQUARE = 2,
            WAVE_SAW = 3,
            WAVE_DEFAULT = WAVE_SINE,
            WAVE_MIN = WAVE_SINE,
            WAVE_MAX = WAVE_SAW,

            TEMPONUMER_MIN = 1,
            TEMPONUMER_MAX = 4,
            TEMPONUMER_DEFAULT = TEMPONUMER_MIN,

            TEMPODENOM_MIN = 1,
            TEMPODENOM_MAX = 32,
            TEMPODENOM_DEFAULT = TEMPODENOM_MIN;

const float DEPTH_DEFAULT = 0.5,
            DEPTH_MIN = 0,
            DEPTH_MAX = 1,

            DEPTHMOD_DEFAULT = 0,
            DEPTHMOD_MIN = -0.5,
            DEPTHMOD_MAX = 0.5,

            FREQ_DEFAULT = 2,
            FREQ_MIN = 0.5,
            FREQ_MAX = 20,

            FREQMOD_DEFAULT = 0,
            FREQMOD_MIN = -0.5,
            FREQMOD_MAX = 0.5,
            
            MASTERVOL_DEFAULT = 1,
            MASTERVOL_MIN = 0,
            MASTERVOL_MAX = 2;

const bool  LFOSWITCH_OFF = false,
            LFOSWITCH_ON = true,
            LFOSWITCH_DEFAULT = LFOSWITCH_OFF,

            TEMPOSYNC_OFF = false,
            TEMPOSYNC_ON = true,
            TEMPOSYNC_DEFAULT = TEMPOSYNC_OFF,

            PHASESYNC_OFF = false,
            PHASESYNC_ON = true,
            PHASESYNC_DEFAULT = PHASESYNC_OFF,

            STEREO_OFF = false,
            STEREO_ON = true,
            STEREO_DEFAULT = STEREO_OFF,

            DEBUGGING_MODE = true;         // Enables debugging output label
                                            // Check sliderValueChanged_Post (or equivalent)
                                            // is set to display the required value

const String    SWITCHLFO1_STR = "LFO 1 Bypass",
                SWITCHLFO2_STR = "LFO 2 Bypass",
                SWITCHMOD1_STR = "MOD 1 Bypass",
                SWITCHMOD2_STR = "MOD 2 Bypass",
                PHASESYNCLFO1_STR = "LFO 1 Phase Sync",
                PHASESYNCLFO2_STR = "LFO 2 Phase Sync",
                PHASESYNCMOD1_STR = "MOD 1 Phase Sync",
                PHASESYNCMOD2_STR = "MOD 2 Phase Sync",
                TEMPOSYNCLFO1_STR = "LFO 1 Tempo Sync",
                TEMPOSYNCLFO2_STR = "LFO 2 Tempo Sync",
                TEMPOSYNCMOD1_STR = "MOD 1 Tempo Sync",
                TEMPOSYNCMOD2_STR = "MOD 2 Tempo Sync",
                WAVELFO1_STR = "LFO 1 Wave",
                WAVELFO2_STR = "LFO 2 Wave",
                WAVEMOD1_STR = "MOD 1 Wave",
                WAVEMOD2_STR = "MOD 2 Wave",
                DEPTHLFO1_STR = "LFO 1 Depth",
                DEPTHLFO2_STR = "LFO 2 Depth",
                DEPTHMOD1_STR = "MOD 1 Depth",
                DEPTHMOD2_STR = "MOD 2 Depth",
                DEPTHMODLFO1_STR = "LFO 1 Depth Mod",
                DEPTHMODLFO2_STR = "LFO 2 Depth Mod",
                FREQLFO1_STR = "LFO 1 Frequency",
                FREQLFO2_STR = "LFO 2 Frequency",
                FREQMOD1_STR = "MOD 1 Frequency",
                FREQMOD2_STR = "MOD 2 Frequency",
                FREQMODLFO1_STR = "LFO 1 Frequency Mod",
                FREQMODLFO2_STR = "LFO 2 Frequency Mod",
                TEMPONUMERLFO1_STR = "LFO 1 Tempo Numerator",
                TEMPONUMERLFO2_STR = "LFO 2 Tempo Numerator",
                TEMPONUMERMOD1_STR = "MOD 1 Tempo Numerator",
                TEMPONUMERMOD2_STR = "MOD 2 Tempo Numerator",
                TEMPODENOMLFO1_STR = "LFO 1 Tempo Denominator",
                TEMPODENOMLFO2_STR = "LFO 2 Tempo Denominator",
                TEMPODENOMMOD1_STR = "MOD 1 Tempo Denominator",
                TEMPODENOMMOD2_STR = "MOD 2 Tempo Denominator",
                MASTERVOL_STR = "Master Vol",
                GROUP_LFO1 = "LFO 1",
                GROUP_LFO2 = "LFO 2",
                GROUP_MOD1 = "MOD 1",
                GROUP_MOD2 = "MOD 2";


// Translates betweeen the normalised 0 - 1 range used by VSTs and the ranges used by the plugin internally
inline float TranslateParam_Norm2Inter(float val, float min, float max) {
    return val * (max - min) + min;
}

inline float TranslateParam_Inter2Norm(float val, float min, float max) {
    return (val - min) / (max - min);
}


#endif  // PARAMETERDATA_H_INCLUDED
