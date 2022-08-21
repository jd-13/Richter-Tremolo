/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "PluginProcessor.h"
#include "JuceHeader.h"
#include "CoreJUCEPlugin/CoreProcessorEditor.h"
#include "CoreJUCEPlugin/LabelReadoutSlider.h"
#include "CoreJUCEPlugin/TooltipLabelUpdater.h"
#include "RichterLFOCache.h"
#include "RichterLFOMeter.h"
#include "RichterLookAndFeel.h"
#include "RichterLFO/UI/RichterWaveViewer.h"
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
                                     public juce::Slider::Listener,
                                     public juce::ComboBox::Listener,
                                     public juce::Button::Listener
{
public:
    //==============================================================================
    RichterAudioProcessorEditor (RichterAudioProcessor& ownerFilter);
    ~RichterAudioProcessorEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback() override;
    RichterAudioProcessor* getProcessor() const {
        return static_cast<RichterAudioProcessor*>(getAudioProcessor());
    }
    void sliderDragStarted(Slider* slider) override;
    void sliderDragEnded(Slider* slider) override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    RichterLookAndFeel customLookAndFeel;
    RichterTempoButtonLookAndFeel tempoLookAndFeel;
    Colour _highlightColour;
    WECore::JUCEPlugin::TooltipLabelUpdater _tooltipLabelUpdater;

    virtual void _onParameterUpdate() override;
    void _enableDoubleClickToDefault();
    void _startSliderReadouts();
    void _stopSliderReadouts();
    void _updateTempoToggles(bool forceUpdate);
    void _setSliderRanges();
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::GroupComponent> LFO1Group;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> DepthLFO1Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> FreqLFO1Sld;
    std::unique_ptr<juce::ComboBox> WaveLFO1Cmb;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> DepthModLFO1Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> FreqModLFO1Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> OutputGainSld;
    std::unique_ptr<juce::TextButton> BypassLFO1Btn;
    std::unique_ptr<juce::Label> FreqLFO1Lbl;
    std::unique_ptr<juce::Label> DepthLFO1Lbl;
    std::unique_ptr<juce::GroupComponent> LFO2Group;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> DepthLFO2Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> FreqLFO2Sld;
    std::unique_ptr<juce::ComboBox> WaveLFO2Cmb;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> DepthModLFO2Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> FreqModLFO2Sld;
    std::unique_ptr<juce::TextButton> BypassLFO2Btn;
    std::unique_ptr<juce::Label> FreqLFO2Lbl;
    std::unique_ptr<juce::Label> DepthLFO2Lbl;
    std::unique_ptr<juce::TextButton> TempoSyncLFO1Btn;
    std::unique_ptr<juce::TextButton> TempoSyncLFO2Btn;
    std::unique_ptr<juce::Slider> TempoNumerLFO1Sld;
    std::unique_ptr<juce::Slider> TempoDenomLFO1Sld;
    std::unique_ptr<juce::Slider> TempoNumerLFO2Sld;
    std::unique_ptr<juce::Slider> TempoDenomLFO2Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> PhaseLFO1Sld;
    std::unique_ptr<juce::Label> PhaseLFO1Lbl;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> PhaseLFO2Sld;
    std::unique_ptr<juce::Label> PhaseLFO2Lbl;
    std::unique_ptr<juce::GroupComponent> MOD1Group;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> DepthMOD1Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> FreqMOD1Sld;
    std::unique_ptr<juce::ComboBox> WaveMOD1Cmb;
    std::unique_ptr<juce::TextButton> BypassMOD1Btn;
    std::unique_ptr<juce::Label> FreqMOD1Lbl;
    std::unique_ptr<juce::Label> DepthMOD1Lbl;
    std::unique_ptr<juce::TextButton> TempoSyncMOD1Btn;
    std::unique_ptr<juce::Slider> TempoNumerMOD1Sld;
    std::unique_ptr<juce::Slider> TempoDenomMOD1Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> PhaseMOD1Sld;
    std::unique_ptr<juce::Label> PhaseMOD1Lbl;
    std::unique_ptr<juce::GroupComponent> MOD2Group;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> DepthMOD2Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> FreqMOD2Sld;
    std::unique_ptr<juce::ComboBox> WaveMOD2Cmb;
    std::unique_ptr<juce::TextButton> BypassMOD2Btn;
    std::unique_ptr<juce::Label> FreqMOD2Lbl;
    std::unique_ptr<juce::Label> DepthMOD2Lbl;
    std::unique_ptr<juce::TextButton> TempoSyncMOD2Btn;
    std::unique_ptr<juce::Slider> TempoNumerMOD2Sld;
    std::unique_ptr<juce::Slider> TempoDenomMOD2Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> PhaseMOD2Sld;
    std::unique_ptr<juce::Label> PhaseMOD2Lbl;
    std::unique_ptr<juce::TextButton> StereoBtn;
    std::unique_ptr<juce::Label> OutputGainLbl;
    std::unique_ptr<juce::Label> MODLFO1LeftLbl;
    std::unique_ptr<juce::Label> MODLFO2LeftLbl;
    std::unique_ptr<RichterLFOMeter> MeterLFO1;
    std::unique_ptr<RichterLFOMeter> MeterLFO2;
    std::unique_ptr<RichterLFOMeter> MeterMOD1;
    std::unique_ptr<RichterLFOMeter> MeterMOD2;
    std::unique_ptr<juce::Label> MODLFO1RightLbl;
    std::unique_ptr<juce::Label> MODLFO2RightLbl;
    std::unique_ptr<WECore::Richter::WaveViewer> WaveViewLFO1;
    std::unique_ptr<WECore::Richter::WaveViewer> WaveViewMOD1;
    std::unique_ptr<WECore::Richter::WaveViewer> WaveViewLFO2;
    std::unique_ptr<WECore::Richter::WaveViewer> WaveViewMOD2;
    std::unique_ptr<juce::TextButton> InvertLFO1Btn;
    std::unique_ptr<juce::TextButton> InvertLFO2Btn;
    std::unique_ptr<juce::TextButton> InvertMOD1Btn;
    std::unique_ptr<juce::TextButton> InvertMOD2Btn;
    std::unique_ptr<juce::Label> tooltipLbl;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RichterAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

