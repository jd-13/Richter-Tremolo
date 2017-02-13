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
#include "ParameterDefinition.h"

const ParameterDefinition::RangedParameter<float>   MASTERVOL(0, 2, 1);

const bool  STEREO_OFF = false,
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


#endif  // PARAMETERDATA_H_INCLUDED
