/*
  ==============================================================================

    ParameterTests.cpp
    Created: 13 Nov 2016 10:03:18am
    Author:  Jack Devlin

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "catch.hpp"
#include "Tests/CoreTestLib.h"

SCENARIO("Parameters can be set and retrieved correctly") {
    GIVEN("A new RichterAudioProcessor object") {
        RichterAudioProcessor mProcessor;
        
        WHEN("Nothing is changed") {
            THEN("Parameters have their default values") {
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::bypassSwitchLFO1) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::phaseSyncLFO1) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoSyncLFO1) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::waveLFO1) == 1);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::depthLFO1) == 0.5);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::depthModLFO1) == 0.0f);
                REQUIRE(CoreTestLib::compareFloats(mProcessor.getParameter(RichterAudioProcessor::freqLFO1), 0.07692f, CoreTestLib::TOLERANCE_4DP));
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::freqModLFO1) == 0.0f);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::phaseLFO1) == 0.0f);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoNumerLFO1) == 1);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoDenomLFO1) == 1);

                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::bypassSwitchLFO2) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::phaseSyncLFO2) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoSyncLFO2) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::waveLFO2) == 1);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::depthLFO2) == 0.5f);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::depthModLFO2) == 0.0f);
                REQUIRE(CoreTestLib::compareFloats(mProcessor.getParameter(RichterAudioProcessor::freqLFO2), 0.07692f, CoreTestLib::TOLERANCE_4DP));
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::freqModLFO2) == 0.0f);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::phaseLFO2) == 0.0f);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoNumerLFO2) == 1);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoDenomLFO2) == 1);

                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::bypassSwitchMOD1) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::phaseSyncMOD1) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoSyncMOD1) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::waveMOD1) == 1);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::depthMOD1) == 0.5);
                REQUIRE(CoreTestLib::compareFloats(mProcessor.getParameter(RichterAudioProcessor::freqMOD1), 0.07692f, CoreTestLib::TOLERANCE_4DP));
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::phaseMOD1) == 0.0f);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoNumerMOD1) == 1);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoDenomMOD1) == 1);
                
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::bypassSwitchMOD2) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::phaseSyncMOD2) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoSyncMOD2) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::waveMOD2) == 1);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::depthMOD2) == 0.5);
                REQUIRE(CoreTestLib::compareFloats(mProcessor.getParameter(RichterAudioProcessor::freqMOD2), 0.07692f, CoreTestLib::TOLERANCE_4DP));
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::phaseMOD2) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoNumerMOD2) == 1);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoDenomMOD2) == 1);

            }
        }
        
        WHEN("All parameters (except bools) are changed to unique values") {
            mProcessor.setParameter(RichterAudioProcessor::bypassSwitchLFO1, 0);
            mProcessor.setParameter(RichterAudioProcessor::phaseSyncLFO1, 0);
            mProcessor.setParameter(RichterAudioProcessor::tempoSyncLFO1, 0);
            mProcessor.setParameter(RichterAudioProcessor::waveLFO1, 1);
            mProcessor.setParameter(RichterAudioProcessor::depthLFO1, 0.01);
            mProcessor.setParameter(RichterAudioProcessor::depthModLFO1, 0.02);
            mProcessor.setParameter(RichterAudioProcessor::freqLFO1, 0.03);
            mProcessor.setParameter(RichterAudioProcessor::freqModLFO1, 0.04);
            mProcessor.setParameter(RichterAudioProcessor::phaseLFO1, 0.05);
            mProcessor.setParameter(RichterAudioProcessor::tempoNumerLFO1, 1);
            mProcessor.setParameter(RichterAudioProcessor::tempoDenomLFO1, 1);

            mProcessor.setParameter(RichterAudioProcessor::bypassSwitchLFO2, 1);
            mProcessor.setParameter(RichterAudioProcessor::phaseSyncLFO2, 1);
            mProcessor.setParameter(RichterAudioProcessor::tempoSyncLFO2, 1);
            mProcessor.setParameter(RichterAudioProcessor::waveLFO2, 2);
            mProcessor.setParameter(RichterAudioProcessor::depthLFO2, 0.11);
            mProcessor.setParameter(RichterAudioProcessor::depthModLFO2, 0.12);
            mProcessor.setParameter(RichterAudioProcessor::freqLFO2, 0.13);
            mProcessor.setParameter(RichterAudioProcessor::freqModLFO2, 0.14);
            mProcessor.setParameter(RichterAudioProcessor::phaseLFO2, 0.15);
            mProcessor.setParameter(RichterAudioProcessor::tempoNumerLFO2, 2);
            mProcessor.setParameter(RichterAudioProcessor::tempoDenomLFO2, 2);
            
            mProcessor.setParameter(RichterAudioProcessor::bypassSwitchMOD1, 0);
            mProcessor.setParameter(RichterAudioProcessor::phaseSyncMOD1, 0);
            mProcessor.setParameter(RichterAudioProcessor::tempoSyncMOD1, 0);
            mProcessor.setParameter(RichterAudioProcessor::waveMOD1, 3);
            mProcessor.setParameter(RichterAudioProcessor::depthMOD1, 0.21);
            mProcessor.setParameter(RichterAudioProcessor::freqMOD1, 0.22);
            mProcessor.setParameter(RichterAudioProcessor::phaseMOD1, 0.23);
            mProcessor.setParameter(RichterAudioProcessor::tempoNumerMOD1, 3);
            mProcessor.setParameter(RichterAudioProcessor::tempoDenomMOD1, 3);
            
            mProcessor.setParameter(RichterAudioProcessor::bypassSwitchMOD2, 1);
            mProcessor.setParameter(RichterAudioProcessor::phaseSyncMOD2, 1);
            mProcessor.setParameter(RichterAudioProcessor::tempoSyncMOD2, 1);
            mProcessor.setParameter(RichterAudioProcessor::waveMOD2, 1);
            mProcessor.setParameter(RichterAudioProcessor::depthMOD2, 0.31);
            mProcessor.setParameter(RichterAudioProcessor::freqMOD2, 0.32);
            mProcessor.setParameter(RichterAudioProcessor::phaseMOD2, 0.33);
            mProcessor.setParameter(RichterAudioProcessor::tempoNumerMOD2, 4);
            mProcessor.setParameter(RichterAudioProcessor::tempoDenomMOD2, 4);
            
            THEN("They all get their correct unique values") {
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::bypassSwitchLFO1) == 1);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::phaseSyncLFO1) == 1);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoSyncLFO1) == 1);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::waveLFO1) == 1);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::depthLFO1) == 0.01f);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::depthModLFO1) == 0.02f);
                REQUIRE(CoreTestLib::compareFloats(mProcessor.getParameter(RichterAudioProcessor::freqLFO1), 0.03f, CoreTestLib::TOLERANCE_6DP));
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::freqModLFO1) == 0.04f);
                //REQUIRE(mProcessor.getParameter(RichterAudioProcessor::phaseLFO1) == 0.05f);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoNumerLFO1) == 1);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoDenomLFO1) == 1);
                
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::bypassSwitchLFO2) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::phaseSyncLFO2) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoSyncLFO2) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::waveLFO2) == 2);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::depthLFO2) == 0.11f);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::depthModLFO2) == 0.12f);
                REQUIRE(CoreTestLib::compareFloats(mProcessor.getParameter(RichterAudioProcessor::freqLFO2), 0.13f, CoreTestLib::TOLERANCE_4DP));
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::freqModLFO2) == 0.14f);
                //REQUIRE(mProcessor.getParameter(RichterAudioProcessor::phaseLFO2) == 0.15f);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoNumerLFO2) == 2);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoDenomLFO2) == 2);
                
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::bypassSwitchMOD1) == 1);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::phaseSyncMOD1) == 1);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoSyncMOD1) == 1);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::waveMOD1) == 3);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::depthMOD1) == 0.21f);
                REQUIRE(CoreTestLib::compareFloats(mProcessor.getParameter(RichterAudioProcessor::freqMOD1), 0.22f, CoreTestLib::TOLERANCE_4DP));
                //REQUIRE(mProcessor.getParameter(RichterAudioProcessor::phaseMOD1) == 0.23f);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoNumerMOD1) == 3);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoDenomMOD1) == 3);
                
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::bypassSwitchMOD2) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::phaseSyncMOD2) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoSyncMOD2) == 0);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::waveMOD2) == 1);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::depthMOD2) == 0.31f);
                REQUIRE(CoreTestLib::compareFloats(mProcessor.getParameter(RichterAudioProcessor::freqMOD2), 0.32f, CoreTestLib::TOLERANCE_4DP));
                //REQUIRE(mProcessor.getParameter(RichterAudioProcessor::phaseMOD2) == 0.33f);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoNumerMOD2) == 4);
                REQUIRE(mProcessor.getParameter(RichterAudioProcessor::tempoDenomMOD2) == 4);
            }
        }
    }
}