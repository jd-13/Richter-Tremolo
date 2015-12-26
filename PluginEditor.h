/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.2.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_E9D89E8D1CC926CC__
#define __JUCE_HEADER_E9D89E8D1CC926CC__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class RichterAudioProcessorEditor  : public AudioProcessorEditor,
                                     public Timer,
                                     public SliderListener,
                                     public ComboBoxListener,
                                     public ButtonListener
{
public:
    //==============================================================================
    RichterAudioProcessorEditor (RichterAudioProcessor& ownerFilter);
    ~RichterAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    RichterAudioProcessor* getProcessor() const {
        return static_cast<RichterAudioProcessor*>(getAudioProcessor());
    }
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupComponent> LFO1Group;
    ScopedPointer<Slider> DepthLFO1Sld;
    ScopedPointer<Slider> FreqLFO1Sld;
    ScopedPointer<ComboBox> WaveLFO1Cmb;
    ScopedPointer<Slider> DepthModLFO1Sld;
    ScopedPointer<Slider> FreqModLFO1Sld;
    ScopedPointer<Slider> MasterVolSld;
    ScopedPointer<TextButton> BypassLFO1Btn;
    ScopedPointer<Label> FreqLFO1Lbl;
    ScopedPointer<Label> DepthLFO1Lbl;
    ScopedPointer<Label> WaveLFO1Lbl;
    ScopedPointer<GroupComponent> LFO2Group;
    ScopedPointer<Slider> DepthLFO2Sld;
    ScopedPointer<Slider> FreqLFO2Sld;
    ScopedPointer<ComboBox> WaveLFO2Cmb;
    ScopedPointer<Slider> DepthModLFO2Sld;
    ScopedPointer<Slider> FreqModLFO2Sld;
    ScopedPointer<TextButton> BypassLFO2Btn;
    ScopedPointer<Label> FreqLFO2Lbl;
    ScopedPointer<Label> DepthLFO2Lbl;
    ScopedPointer<Label> WaveLFO2Lbl;
    ScopedPointer<TextButton> TempoSyncLFO1Btn;
    ScopedPointer<TextButton> TempoSyncLFO2Btn;
    ScopedPointer<Slider> TempoNumerLFO1Sld;
    ScopedPointer<Slider> TempoDenomLFO1Sld;
    ScopedPointer<Slider> TempoNumerLFO2Sld;
    ScopedPointer<Slider> TempoDenomLFO2Sld;
    ScopedPointer<TextButton> PhaseSyncLFO1Btn;
    ScopedPointer<TextButton> PhaseSyncLFO2Btn;
    ScopedPointer<Slider> PhaseLFO1Sld;
    ScopedPointer<Label> PhaseLFO1Lbl;
    ScopedPointer<Slider> PhaseLFO2Sld;
    ScopedPointer<Label> PhaseLFO2Lbl;
    ScopedPointer<GroupComponent> MOD1Group;
    ScopedPointer<Slider> DepthMOD1Sld;
    ScopedPointer<Slider> FreqMOD1Sld;
    ScopedPointer<ComboBox> WaveMOD1Cmb;
    ScopedPointer<TextButton> BypassMOD1Btn;
    ScopedPointer<Label> FreqMOD1Lbl;
    ScopedPointer<Label> DepthMOD1Lbl;
    ScopedPointer<Label> WaveMOD1Lbl;
    ScopedPointer<TextButton> TempoSyncMOD1Btn;
    ScopedPointer<Slider> TempoNumerMOD1Sld;
    ScopedPointer<Slider> TempoDenomMOD1Sld;
    ScopedPointer<TextButton> PhaseSyncMOD1Btn;
    ScopedPointer<Slider> PhaseMOD1Sld;
    ScopedPointer<Label> PhaseMOD1Lbl;
    ScopedPointer<GroupComponent> MOD2Group;
    ScopedPointer<Slider> DepthMOD2Sld;
    ScopedPointer<Slider> FreqMOD2Sld;
    ScopedPointer<ComboBox> WaveMOD2Cmb;
    ScopedPointer<TextButton> BypassMOD2Btn;
    ScopedPointer<Label> FreqMOD2Lbl;
    ScopedPointer<Label> DepthMOD2Lbl;
    ScopedPointer<Label> WaveMOD2Lbl;
    ScopedPointer<TextButton> TempoSyncMOD2Btn;
    ScopedPointer<Slider> TempoNumerMOD2Sld;
    ScopedPointer<Slider> TempoDenomMOD2Sld;
    ScopedPointer<TextButton> PhaseSyncMOD2Btn;
    ScopedPointer<Slider> PhaseMOD2Sld;
    ScopedPointer<Label> PhaseMOD2Lbl;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RichterAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_E9D89E8D1CC926CC__
