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

enum	{kWaveArraySize = 2000};

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
            TEMPODENOM_DEFAULT = TEMPODENOM_MIN,

            PHASE_MIN = 0,
            PHASE_MAX = kWaveArraySize,
            PHASE_DEFAULT = PHASE_MIN;

const float DEPTH_DEFAULT = 0.5,
            DEPTH_MIN = 0,
            DEPTH_MAX = 1,

            DEPTHMOD_DEFAULT = 0,
            DEPTHMOD_MIN = 0,
            DEPTHMOD_MAX = 1,

            FREQ_DEFAULT = 2,
            FREQ_MIN = 0.5,
            FREQ_MAX = 20,

            FREQMOD_DEFAULT = 0,
            FREQMOD_MIN = 0,
            FREQMOD_MAX = 1,
            
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
            STEREO_DEFAULT = STEREO_OFF;


const String    SWITCHLFO1_STR = "LFO1Bypass",
                SWITCHLFO2_STR = "LFO2Bypass",
                SWITCHMOD1_STR = "MOD1Bypass",
                SWITCHMOD2_STR = "MOD2Bypass",
                PHASESYNCLFO1_STR = "LFO1PhaseSync",
                PHASESYNCLFO2_STR = "LFO2PhaseSync",
                PHASESYNCMOD1_STR = "MOD1PhaseSync",
                PHASESYNCMOD2_STR = "MOD2PhaseSync",
                PHASELFO1_STR = "LFO1Phase",
                PHASELFO2_STR = "LFO2Phase",
                PHASEMOD1_STR = "MOD1Phase",
                PHASEMOD2_STR = "MOD2Phase",
                TEMPOSYNCLFO1_STR = "LFO1TempoSync",
                TEMPOSYNCLFO2_STR = "LFO2TempoSync",
                TEMPOSYNCMOD1_STR = "MOD1TempoSync",
                TEMPOSYNCMOD2_STR = "MOD2TempoSync",
                WAVELFO1_STR = "LFO1Wave",
                WAVELFO2_STR = "LFO2Wave",
                WAVEMOD1_STR = "MOD1Wave",
                WAVEMOD2_STR = "MOD2Wave",
                DEPTHLFO1_STR = "LFO1Depth",
                DEPTHLFO2_STR = "LFO2Depth",
                DEPTHMOD1_STR = "MOD1Depth",
                DEPTHMOD2_STR = "MOD2Depth",
                DEPTHMODLFO1_STR = "LFO1DepthMod",
                DEPTHMODLFO2_STR = "LFO2DepthMod",
                FREQLFO1_STR = "LFO1Frequency",
                FREQLFO2_STR = "LFO2Frequency",
                FREQMOD1_STR = "MOD1Frequency",
                FREQMOD2_STR = "MOD2Frequency",
                FREQMODLFO1_STR = "LFO1FrequencyMod",
                FREQMODLFO2_STR = "LFO2FrequencyMod",
                TEMPONUMERLFO1_STR = "LFO1TempoNumerator",
                TEMPONUMERLFO2_STR = "LFO2TempoNumerator",
                TEMPONUMERMOD1_STR = "MOD1TempoNumerator",
                TEMPONUMERMOD2_STR = "MOD2TempoNumerator",
                TEMPODENOMLFO1_STR = "LFO1TempoDenominator",
                TEMPODENOMLFO2_STR = "LFO2TempoDenominator",
                TEMPODENOMMOD1_STR = "MOD1TempoDenominator",
                TEMPODENOMMOD2_STR = "MOD2TempoDenominator",
                STEREO_STR = "Stereo",
                MASTERVOL_STR = "MasterVol",
                GROUP_LFO1 = "LFO1",
                GROUP_LFO2 = "LFO2",
                GROUP_MOD1 = "MOD1",
                GROUP_MOD2 = "MOD2";


// Translates betweeen the normalised 0 - 1 range used by VSTs and the ranges used by the plugin internally
inline float TranslateParam_Norm2Inter(float val, float min, float max) {
    return val * (max - min) + min;
}

inline float TranslateParam_Inter2Norm(float val, float min, float max) {
    return (val - min) / (max - min);
}


#endif  // PARAMETERDATA_H_INCLUDED
