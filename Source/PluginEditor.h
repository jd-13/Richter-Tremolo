/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "PluginProcessor.h"
#include "JuceHeader.h"
#include "CoreJUCEPlugin/CoreProcessorEditor.h"
#include "CoreJUCEPlugin/LabelReadoutSlider.h"
#include "RichterLFOCache.h"
#include "RichterLFOMeter.h"
#include "RichterLookAndFeel.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class RichterAudioProcessorEditor  : public WECore::JUCEPlugin::CoreProcessorEditor,
                                     public Timer,
                                     public Slider::Listener,
                                     public ComboBox::Listener,
                                     public Button::Listener
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

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    RichterLookAndFeel customLookAndFeel;
    RichterTempoButtonLookAndFeel tempoLookAndFeel;
    Colour _highlightColour;

    void _enableDoubleClickToDefault();
    void _startSliderReadouts();
    void _stopSliderReadouts();
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<GroupComponent> LFO1Group;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> DepthLFO1Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> FreqLFO1Sld;
    std::unique_ptr<ComboBox> WaveLFO1Cmb;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> DepthModLFO1Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> FreqModLFO1Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<float>> OutputGainSld;
    std::unique_ptr<TextButton> BypassLFO1Btn;
    std::unique_ptr<Label> FreqLFO1Lbl;
    std::unique_ptr<Label> DepthLFO1Lbl;
    std::unique_ptr<Label> WaveLFO1Lbl;
    std::unique_ptr<GroupComponent> LFO2Group;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> DepthLFO2Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> FreqLFO2Sld;
    std::unique_ptr<ComboBox> WaveLFO2Cmb;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> DepthModLFO2Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> FreqModLFO2Sld;
    std::unique_ptr<TextButton> BypassLFO2Btn;
    std::unique_ptr<Label> FreqLFO2Lbl;
    std::unique_ptr<Label> DepthLFO2Lbl;
    std::unique_ptr<Label> WaveLFO2Lbl;
    std::unique_ptr<TextButton> TempoSyncLFO1Btn;
    std::unique_ptr<TextButton> TempoSyncLFO2Btn;
    std::unique_ptr<Slider> TempoNumerLFO1Sld;
    std::unique_ptr<Slider> TempoDenomLFO1Sld;
    std::unique_ptr<Slider> TempoNumerLFO2Sld;
    std::unique_ptr<Slider> TempoDenomLFO2Sld;
    std::unique_ptr<TextButton> PhaseSyncLFO1Btn;
    std::unique_ptr<TextButton> PhaseSyncLFO2Btn;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> PhaseLFO1Sld;
    std::unique_ptr<Label> PhaseLFO1Lbl;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> PhaseLFO2Sld;
    std::unique_ptr<Label> PhaseLFO2Lbl;
    std::unique_ptr<GroupComponent> MOD1Group;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> DepthMOD1Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> FreqMOD1Sld;
    std::unique_ptr<ComboBox> WaveMOD1Cmb;
    std::unique_ptr<TextButton> BypassMOD1Btn;
    std::unique_ptr<Label> FreqMOD1Lbl;
    std::unique_ptr<Label> DepthMOD1Lbl;
    std::unique_ptr<Label> WaveMOD1Lbl;
    std::unique_ptr<TextButton> TempoSyncMOD1Btn;
    std::unique_ptr<Slider> TempoNumerMOD1Sld;
    std::unique_ptr<Slider> TempoDenomMOD1Sld;
    std::unique_ptr<TextButton> PhaseSyncMOD1Btn;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> PhaseMOD1Sld;
    std::unique_ptr<Label> PhaseMOD1Lbl;
    std::unique_ptr<GroupComponent> MOD2Group;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> DepthMOD2Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> FreqMOD2Sld;
    std::unique_ptr<ComboBox> WaveMOD2Cmb;
    std::unique_ptr<TextButton> BypassMOD2Btn;
    std::unique_ptr<Label> FreqMOD2Lbl;
    std::unique_ptr<Label> DepthMOD2Lbl;
    std::unique_ptr<Label> WaveMOD2Lbl;
    std::unique_ptr<TextButton> TempoSyncMOD2Btn;
    std::unique_ptr<Slider> TempoNumerMOD2Sld;
    std::unique_ptr<Slider> TempoDenomMOD2Sld;
    std::unique_ptr<TextButton> PhaseSyncMOD2Btn;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> PhaseMOD2Sld;
    std::unique_ptr<Label> PhaseMOD2Lbl;
    std::unique_ptr<TextButton> StereoBtn;
    std::unique_ptr<Label> OutputGainLbl;
    std::unique_ptr<Label> MODLFO1Lbl;
    std::unique_ptr<Label> MODLFO2Lbl;
    std::unique_ptr<RichterLFOMeter> MeterLFO1;
    std::unique_ptr<RichterLFOMeter> MeterLFO2;
    std::unique_ptr<RichterLFOMeter> MeterMOD1;
    std::unique_ptr<RichterLFOMeter> MeterMOD2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RichterAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
