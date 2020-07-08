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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
RichterAudioProcessorEditor::RichterAudioProcessorEditor (RichterAudioProcessor& ownerFilter)
    : CoreProcessorEditor(ownerFilter), _highlightColour(0x7f00ff03)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    LFO1Group.reset (new GroupComponent ("LFO 1 Group",
                                         TRANS("LFO1")));
    addAndMakeVisible (LFO1Group.get());
    LFO1Group->setColour (GroupComponent::textColourId, Colours::black);

    LFO1Group->setBounds (48, 72, 288, 128);

    DepthLFO1Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("LFO 1 Depth Slider"));
    addAndMakeVisible (DepthLFO1Sld.get());
    DepthLFO1Sld->setTooltip (TRANS("Depth of the LFO"));
    DepthLFO1Sld->setRange (0, 1, 0.01);
    DepthLFO1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    DepthLFO1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DepthLFO1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    DepthLFO1Sld->addListener (this);

    DepthLFO1Sld->setBounds (128, 120, 32, 24);

    FreqLFO1Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("LFO 1 Freq Slider"));
    addAndMakeVisible (FreqLFO1Sld.get());
    FreqLFO1Sld->setTooltip (TRANS("Frequency of the LFO, from 2Hz to 20Hz"));
    FreqLFO1Sld->setRange (0, 1, 0.01);
    FreqLFO1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    FreqLFO1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FreqLFO1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    FreqLFO1Sld->addListener (this);

    FreqLFO1Sld->setBounds (72, 120, 32, 24);

    WaveLFO1Cmb.reset (new ComboBox ("LFO 1 Wave"));
    addAndMakeVisible (WaveLFO1Cmb.get());
    WaveLFO1Cmb->setTooltip (TRANS("LFO wave shape"));
    WaveLFO1Cmb->setEditableText (false);
    WaveLFO1Cmb->setJustificationType (Justification::centredLeft);
    WaveLFO1Cmb->setTextWhenNothingSelected (String());
    WaveLFO1Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    WaveLFO1Cmb->addItem (TRANS("Sine"), 1);
    WaveLFO1Cmb->addItem (TRANS("Square"), 2);
    WaveLFO1Cmb->addItem (TRANS("Saw"), 3);
    WaveLFO1Cmb->addListener (this);

    WaveLFO1Cmb->setBounds (232, 128, 80, 24);

    DepthModLFO1Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("LFO 1 Depth Mod Slider"));
    addAndMakeVisible (DepthModLFO1Sld.get());
    DepthModLFO1Sld->setTooltip (TRANS("Amount of depth modulation from MOD 1"));
    DepthModLFO1Sld->setRange (0, 1, 0.01);
    DepthModLFO1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    DepthModLFO1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DepthModLFO1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    DepthModLFO1Sld->addListener (this);

    DepthModLFO1Sld->setBounds (136, 168, 16, 16);

    FreqModLFO1Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("LFO 1 Freq Mod Slider"));
    addAndMakeVisible (FreqModLFO1Sld.get());
    FreqModLFO1Sld->setTooltip (TRANS("Amount of rate modulation from MOD 1"));
    FreqModLFO1Sld->setRange (0, 1, 0.01);
    FreqModLFO1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    FreqModLFO1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FreqModLFO1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    FreqModLFO1Sld->addListener (this);

    FreqModLFO1Sld->setBounds (80, 168, 16, 16);

    OutputGainSld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<float> ("Output Gain Slider"));
    addAndMakeVisible (OutputGainSld.get());
    OutputGainSld->setTooltip (TRANS("Output gain"));
    OutputGainSld->setRange (0, 1, 0.01);
    OutputGainSld->setSliderStyle (Slider::LinearHorizontal);
    OutputGainSld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    OutputGainSld->addListener (this);

    OutputGainSld->setBounds (56, 48, 392, 24);

    BypassLFO1Btn.reset (new TextButton ("LFO 1 Bypass Button"));
    addAndMakeVisible (BypassLFO1Btn.get());
    BypassLFO1Btn->setTooltip (TRANS("Bypass button for LFO 1. LFO 1 operates directly on sound."));
    BypassLFO1Btn->setButtonText (TRANS("LFO 1"));
    BypassLFO1Btn->addListener (this);

    BypassLFO1Btn->setBounds (256, 88, 56, 24);

    FreqLFO1Lbl.reset (new Label ("LFO 1 Freq Label",
                                  TRANS("Rate")));
    addAndMakeVisible (FreqLFO1Lbl.get());
    FreqLFO1Lbl->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    FreqLFO1Lbl->setJustificationType (Justification::centred);
    FreqLFO1Lbl->setEditable (false, false, false);
    FreqLFO1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    FreqLFO1Lbl->setColour (TextEditor::textColourId, Colours::black);
    FreqLFO1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    FreqLFO1Lbl->setBounds (68, 144, 40, 24);

    DepthLFO1Lbl.reset (new Label ("LFO 1 Depth Label",
                                   TRANS("Depth")));
    addAndMakeVisible (DepthLFO1Lbl.get());
    DepthLFO1Lbl->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    DepthLFO1Lbl->setJustificationType (Justification::centred);
    DepthLFO1Lbl->setEditable (false, false, false);
    DepthLFO1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    DepthLFO1Lbl->setColour (TextEditor::textColourId, Colours::black);
    DepthLFO1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    DepthLFO1Lbl->setBounds (121, 144, 46, 24);

    WaveLFO1Lbl.reset (new Label ("LFO 1 Wave Label",
                                  TRANS("Wave\n")));
    addAndMakeVisible (WaveLFO1Lbl.get());
    WaveLFO1Lbl->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    WaveLFO1Lbl->setJustificationType (Justification::centredLeft);
    WaveLFO1Lbl->setEditable (false, false, false);
    WaveLFO1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    WaveLFO1Lbl->setColour (TextEditor::textColourId, Colours::black);
    WaveLFO1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    WaveLFO1Lbl->setBounds (248, 160, 46, 24);

    LFO2Group.reset (new GroupComponent ("LFO 2 Group",
                                         TRANS("LFO2")));
    addAndMakeVisible (LFO2Group.get());

    LFO2Group->setBounds (340, 72, 288, 128);

    DepthLFO2Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("LFO 2 Depth Slider"));
    addAndMakeVisible (DepthLFO2Sld.get());
    DepthLFO2Sld->setTooltip (TRANS("Depth of the LFO"));
    DepthLFO2Sld->setRange (0, 1, 0.01);
    DepthLFO2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    DepthLFO2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DepthLFO2Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    DepthLFO2Sld->addListener (this);

    DepthLFO2Sld->setBounds (428, 120, 32, 24);

    FreqLFO2Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("LFO 2 Freq Slider"));
    addAndMakeVisible (FreqLFO2Sld.get());
    FreqLFO2Sld->setTooltip (TRANS("Frequency of the LFO, from 2Hz to 20Hz"));
    FreqLFO2Sld->setRange (0, 1, 0.01);
    FreqLFO2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    FreqLFO2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FreqLFO2Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    FreqLFO2Sld->addListener (this);

    FreqLFO2Sld->setBounds (372, 120, 32, 24);

    WaveLFO2Cmb.reset (new ComboBox ("LFO 2 Wave"));
    addAndMakeVisible (WaveLFO2Cmb.get());
    WaveLFO2Cmb->setTooltip (TRANS("LFO wave shape"));
    WaveLFO2Cmb->setEditableText (false);
    WaveLFO2Cmb->setJustificationType (Justification::centredLeft);
    WaveLFO2Cmb->setTextWhenNothingSelected (String());
    WaveLFO2Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    WaveLFO2Cmb->addItem (TRANS("Sine"), 1);
    WaveLFO2Cmb->addItem (TRANS("Square"), 2);
    WaveLFO2Cmb->addItem (TRANS("Saw"), 3);
    WaveLFO2Cmb->addListener (this);

    WaveLFO2Cmb->setBounds (532, 128, 80, 24);

    DepthModLFO2Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("LFO 2 Depth Mod Slider"));
    addAndMakeVisible (DepthModLFO2Sld.get());
    DepthModLFO2Sld->setTooltip (TRANS("Amount of depth modulation from MOD 1"));
    DepthModLFO2Sld->setRange (0, 1, 0.01);
    DepthModLFO2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    DepthModLFO2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DepthModLFO2Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    DepthModLFO2Sld->addListener (this);

    DepthModLFO2Sld->setBounds (438, 168, 16, 16);

    FreqModLFO2Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("LFO 2 Freq Mod Slider"));
    addAndMakeVisible (FreqModLFO2Sld.get());
    FreqModLFO2Sld->setTooltip (TRANS("Amount of rate modulation from MOD 2"));
    FreqModLFO2Sld->setRange (0, 1, 0.01);
    FreqModLFO2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    FreqModLFO2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FreqModLFO2Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    FreqModLFO2Sld->addListener (this);

    FreqModLFO2Sld->setBounds (380, 168, 16, 16);

    BypassLFO2Btn.reset (new TextButton ("LFO 2 Bypass Button"));
    addAndMakeVisible (BypassLFO2Btn.get());
    BypassLFO2Btn->setTooltip (TRANS("Bypass button for LFO 2. LFO 2 operates directly on sound."));
    BypassLFO2Btn->setButtonText (TRANS("LFO 2"));
    BypassLFO2Btn->addListener (this);

    BypassLFO2Btn->setBounds (556, 88, 56, 24);

    FreqLFO2Lbl.reset (new Label ("LFO 2 Freq Label",
                                  TRANS("Rate")));
    addAndMakeVisible (FreqLFO2Lbl.get());
    FreqLFO2Lbl->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    FreqLFO2Lbl->setJustificationType (Justification::centred);
    FreqLFO2Lbl->setEditable (false, false, false);
    FreqLFO2Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    FreqLFO2Lbl->setColour (TextEditor::textColourId, Colours::black);
    FreqLFO2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    FreqLFO2Lbl->setBounds (368, 144, 40, 24);

    DepthLFO2Lbl.reset (new Label ("LFO 2 Depth Label",
                                   TRANS("Depth")));
    addAndMakeVisible (DepthLFO2Lbl.get());
    DepthLFO2Lbl->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    DepthLFO2Lbl->setJustificationType (Justification::centred);
    DepthLFO2Lbl->setEditable (false, false, false);
    DepthLFO2Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    DepthLFO2Lbl->setColour (TextEditor::textColourId, Colours::black);
    DepthLFO2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    DepthLFO2Lbl->setBounds (421, 144, 46, 24);

    WaveLFO2Lbl.reset (new Label ("LFO 2 Wave Label",
                                  TRANS("Wave\n")));
    addAndMakeVisible (WaveLFO2Lbl.get());
    WaveLFO2Lbl->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    WaveLFO2Lbl->setJustificationType (Justification::centredLeft);
    WaveLFO2Lbl->setEditable (false, false, false);
    WaveLFO2Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    WaveLFO2Lbl->setColour (TextEditor::textColourId, Colours::black);
    WaveLFO2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    WaveLFO2Lbl->setBounds (548, 160, 46, 24);

    TempoSyncLFO1Btn.reset (new TextButton ("LFO 1 Tempo Sync Button"));
    addAndMakeVisible (TempoSyncLFO1Btn.get());
    TempoSyncLFO1Btn->setTooltip (TRANS("Tempo sync LFO frequency"));
    TempoSyncLFO1Btn->setButtonText (TRANS("Tempo"));
    TempoSyncLFO1Btn->addListener (this);

    TempoSyncLFO1Btn->setBounds (64, 96, 56, 16);

    TempoSyncLFO2Btn.reset (new TextButton ("LFO 2 Tempo Sync Button"));
    addAndMakeVisible (TempoSyncLFO2Btn.get());
    TempoSyncLFO2Btn->setTooltip (TRANS("Tempo sync LFO frequency"));
    TempoSyncLFO2Btn->setButtonText (TRANS("Tempo"));
    TempoSyncLFO2Btn->addListener (this);

    TempoSyncLFO2Btn->setBounds (364, 96, 56, 16);

    TempoNumerLFO1Sld.reset (new Slider ("LFO 1 Tempo Numer Slider"));
    addAndMakeVisible (TempoNumerLFO1Sld.get());
    TempoNumerLFO1Sld->setRange (1, 4, 1);
    TempoNumerLFO1Sld->setSliderStyle (Slider::IncDecButtons);
    TempoNumerLFO1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoNumerLFO1Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0xffc8c8c8));
    TempoNumerLFO1Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    TempoNumerLFO1Sld->addListener (this);

    TempoNumerLFO1Sld->setBounds (64, 128, 56, 16);

    TempoDenomLFO1Sld.reset (new Slider ("LFO 1 Tempo Denom Slider"));
    addAndMakeVisible (TempoDenomLFO1Sld.get());
    TempoDenomLFO1Sld->setRange (1, 32, 1);
    TempoDenomLFO1Sld->setSliderStyle (Slider::IncDecButtons);
    TempoDenomLFO1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoDenomLFO1Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0xffc8c8c8));
    TempoDenomLFO1Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    TempoDenomLFO1Sld->addListener (this);

    TempoDenomLFO1Sld->setBounds (64, 160, 56, 16);

    TempoNumerLFO2Sld.reset (new Slider ("LFO 2 Tempo Numer Slider"));
    addAndMakeVisible (TempoNumerLFO2Sld.get());
    TempoNumerLFO2Sld->setRange (1, 4, 1);
    TempoNumerLFO2Sld->setSliderStyle (Slider::IncDecButtons);
    TempoNumerLFO2Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoNumerLFO2Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0xffc8c8c8));
    TempoNumerLFO2Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    TempoNumerLFO2Sld->addListener (this);

    TempoNumerLFO2Sld->setBounds (364, 128, 56, 16);

    TempoDenomLFO2Sld.reset (new Slider ("LFO 2 Tempo Denom Slider"));
    addAndMakeVisible (TempoDenomLFO2Sld.get());
    TempoDenomLFO2Sld->setRange (1, 32, 1);
    TempoDenomLFO2Sld->setSliderStyle (Slider::IncDecButtons);
    TempoDenomLFO2Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoDenomLFO2Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0xffc8c8c8));
    TempoDenomLFO2Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    TempoDenomLFO2Sld->addListener (this);

    TempoDenomLFO2Sld->setBounds (364, 160, 56, 16);

    PhaseSyncLFO1Btn.reset (new TextButton ("LFO 1 Phase Sync Button"));
    addAndMakeVisible (PhaseSyncLFO1Btn.get());
    PhaseSyncLFO1Btn->setTooltip (TRANS("Enable phase sync to ensure the phase of the LFO is consistent regardless of where the DAW playhead starts from"));
    PhaseSyncLFO1Btn->setButtonText (TRANS("Phase"));
    PhaseSyncLFO1Btn->addListener (this);

    PhaseSyncLFO1Btn->setBounds (176, 96, 56, 16);

    PhaseSyncLFO2Btn.reset (new TextButton ("LFO 2 Phase Sync Button"));
    addAndMakeVisible (PhaseSyncLFO2Btn.get());
    PhaseSyncLFO2Btn->setTooltip (TRANS("Enable phase sync to ensure the phase of the LFO is consistent regardless of where the DAW playhead starts from"));
    PhaseSyncLFO2Btn->setButtonText (TRANS("Phase"));
    PhaseSyncLFO2Btn->addListener (this);

    PhaseSyncLFO2Btn->setBounds (476, 96, 56, 16);

    PhaseLFO1Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("LFO 1 Phase Slider"));
    addAndMakeVisible (PhaseLFO1Sld.get());
    PhaseLFO1Sld->setTooltip (TRANS("Phase shift the LFO by up to 360 degrees"));
    PhaseLFO1Sld->setRange (0, 1, 0.01);
    PhaseLFO1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PhaseLFO1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    PhaseLFO1Sld->setColour (Slider::thumbColourId, Colour (0xffbdffbb));
    PhaseLFO1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    PhaseLFO1Sld->addListener (this);

    PhaseLFO1Sld->setBounds (184, 120, 32, 24);

    PhaseLFO1Lbl.reset (new Label ("LFO 1 Phase Label",
                                   TRANS("Phase")));
    addAndMakeVisible (PhaseLFO1Lbl.get());
    PhaseLFO1Lbl->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    PhaseLFO1Lbl->setJustificationType (Justification::centred);
    PhaseLFO1Lbl->setEditable (false, false, false);
    PhaseLFO1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    PhaseLFO1Lbl->setColour (TextEditor::textColourId, Colours::black);
    PhaseLFO1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    PhaseLFO1Lbl->setBounds (177, 144, 46, 24);

    PhaseLFO2Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("LFO 2 Phase Slider"));
    addAndMakeVisible (PhaseLFO2Sld.get());
    PhaseLFO2Sld->setTooltip (TRANS("Changes the phase of the LFO by up to 360 degrees"));
    PhaseLFO2Sld->setRange (0, 1, 0.01);
    PhaseLFO2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PhaseLFO2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    PhaseLFO2Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    PhaseLFO2Sld->addListener (this);

    PhaseLFO2Sld->setBounds (484, 120, 32, 24);

    PhaseLFO2Lbl.reset (new Label ("LFO 2 Phase Label",
                                   TRANS("Phase")));
    addAndMakeVisible (PhaseLFO2Lbl.get());
    PhaseLFO2Lbl->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    PhaseLFO2Lbl->setJustificationType (Justification::centred);
    PhaseLFO2Lbl->setEditable (false, false, false);
    PhaseLFO2Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    PhaseLFO2Lbl->setColour (TextEditor::textColourId, Colours::black);
    PhaseLFO2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    PhaseLFO2Lbl->setBounds (477, 144, 46, 24);

    MOD1Group.reset (new GroupComponent ("MOD 1 Group",
                                         TRANS("MOD1")));
    addAndMakeVisible (MOD1Group.get());

    MOD1Group->setBounds (48, 200, 288, 128);

    DepthMOD1Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("MOD 1 Depth Slider"));
    addAndMakeVisible (DepthMOD1Sld.get());
    DepthMOD1Sld->setTooltip (TRANS("Depth of the LFO"));
    DepthMOD1Sld->setRange (0, 1, 0.01);
    DepthMOD1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    DepthMOD1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DepthMOD1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff0d));
    DepthMOD1Sld->addListener (this);

    DepthMOD1Sld->setBounds (128, 248, 32, 24);

    FreqMOD1Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("MOD 1 Freq Slider"));
    addAndMakeVisible (FreqMOD1Sld.get());
    FreqMOD1Sld->setTooltip (TRANS("Frequency of the LFO, from 2Hz to 20Hz"));
    FreqMOD1Sld->setRange (0, 1, 0.01);
    FreqMOD1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    FreqMOD1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FreqMOD1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    FreqMOD1Sld->addListener (this);

    FreqMOD1Sld->setBounds (72, 248, 32, 24);

    WaveMOD1Cmb.reset (new ComboBox ("MOD 1 Wave"));
    addAndMakeVisible (WaveMOD1Cmb.get());
    WaveMOD1Cmb->setTooltip (TRANS("LFO wave shape"));
    WaveMOD1Cmb->setEditableText (false);
    WaveMOD1Cmb->setJustificationType (Justification::centredLeft);
    WaveMOD1Cmb->setTextWhenNothingSelected (String());
    WaveMOD1Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    WaveMOD1Cmb->addItem (TRANS("Sine"), 1);
    WaveMOD1Cmb->addItem (TRANS("Square"), 2);
    WaveMOD1Cmb->addItem (TRANS("Saw"), 3);
    WaveMOD1Cmb->addListener (this);

    WaveMOD1Cmb->setBounds (232, 256, 80, 24);

    BypassMOD1Btn.reset (new TextButton ("MOD 1 Bypass Button"));
    addAndMakeVisible (BypassMOD1Btn.get());
    BypassMOD1Btn->setTooltip (TRANS("Bypass button for MOD 1. MOD 1 modulates the rate and depth of LFO 1."));
    BypassMOD1Btn->setButtonText (TRANS("MOD 1"));
    BypassMOD1Btn->addListener (this);

    BypassMOD1Btn->setBounds (256, 216, 56, 24);

    FreqMOD1Lbl.reset (new Label ("MOD 1 Freq Label",
                                  TRANS("Rate")));
    addAndMakeVisible (FreqMOD1Lbl.get());
    FreqMOD1Lbl->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    FreqMOD1Lbl->setJustificationType (Justification::centred);
    FreqMOD1Lbl->setEditable (false, false, false);
    FreqMOD1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    FreqMOD1Lbl->setColour (TextEditor::textColourId, Colours::black);
    FreqMOD1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    FreqMOD1Lbl->setBounds (68, 272, 40, 24);

    DepthMOD1Lbl.reset (new Label ("MOD 1 Depth Label",
                                   TRANS("Depth")));
    addAndMakeVisible (DepthMOD1Lbl.get());
    DepthMOD1Lbl->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    DepthMOD1Lbl->setJustificationType (Justification::centred);
    DepthMOD1Lbl->setEditable (false, false, false);
    DepthMOD1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    DepthMOD1Lbl->setColour (TextEditor::textColourId, Colours::black);
    DepthMOD1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    DepthMOD1Lbl->setBounds (121, 272, 46, 24);

    WaveMOD1Lbl.reset (new Label ("MOD 1 Wave Label",
                                  TRANS("Wave\n")));
    addAndMakeVisible (WaveMOD1Lbl.get());
    WaveMOD1Lbl->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    WaveMOD1Lbl->setJustificationType (Justification::centredLeft);
    WaveMOD1Lbl->setEditable (false, false, false);
    WaveMOD1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    WaveMOD1Lbl->setColour (TextEditor::textColourId, Colours::black);
    WaveMOD1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    WaveMOD1Lbl->setBounds (248, 288, 46, 24);

    TempoSyncMOD1Btn.reset (new TextButton ("MOD 1 Tempo Sync Button"));
    addAndMakeVisible (TempoSyncMOD1Btn.get());
    TempoSyncMOD1Btn->setTooltip (TRANS("Tempo sync LFO frequency"));
    TempoSyncMOD1Btn->setButtonText (TRANS("Tempo"));
    TempoSyncMOD1Btn->addListener (this);

    TempoSyncMOD1Btn->setBounds (64, 224, 56, 16);

    TempoNumerMOD1Sld.reset (new Slider ("MOD 1 Tempo Numer Slider"));
    addAndMakeVisible (TempoNumerMOD1Sld.get());
    TempoNumerMOD1Sld->setRange (1, 4, 1);
    TempoNumerMOD1Sld->setSliderStyle (Slider::IncDecButtons);
    TempoNumerMOD1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoNumerMOD1Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0xffc8c8c8));
    TempoNumerMOD1Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    TempoNumerMOD1Sld->addListener (this);

    TempoNumerMOD1Sld->setBounds (64, 256, 56, 16);

    TempoDenomMOD1Sld.reset (new Slider ("MOD 1 Tempo Denom Slider"));
    addAndMakeVisible (TempoDenomMOD1Sld.get());
    TempoDenomMOD1Sld->setRange (1, 32, 1);
    TempoDenomMOD1Sld->setSliderStyle (Slider::IncDecButtons);
    TempoDenomMOD1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoDenomMOD1Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0xffc8c8c8));
    TempoDenomMOD1Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    TempoDenomMOD1Sld->addListener (this);

    TempoDenomMOD1Sld->setBounds (64, 288, 56, 16);

    PhaseSyncMOD1Btn.reset (new TextButton ("MOD 1 Phase Sync Button"));
    addAndMakeVisible (PhaseSyncMOD1Btn.get());
    PhaseSyncMOD1Btn->setTooltip (TRANS("Enable phase sync to ensure the phase of the LFO is consistent regardless of where the DAW playhead starts from"));
    PhaseSyncMOD1Btn->setButtonText (TRANS("Phase"));
    PhaseSyncMOD1Btn->addListener (this);

    PhaseSyncMOD1Btn->setBounds (176, 224, 56, 16);

    PhaseMOD1Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("MOD 1 Phase Slider"));
    addAndMakeVisible (PhaseMOD1Sld.get());
    PhaseMOD1Sld->setTooltip (TRANS("Phase shift the LFO by up to 360 degrees"));
    PhaseMOD1Sld->setRange (0, 1, 0.01);
    PhaseMOD1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PhaseMOD1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    PhaseMOD1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    PhaseMOD1Sld->addListener (this);

    PhaseMOD1Sld->setBounds (184, 248, 32, 24);

    PhaseMOD1Lbl.reset (new Label ("MOD 1 Phase Label",
                                   TRANS("Phase")));
    addAndMakeVisible (PhaseMOD1Lbl.get());
    PhaseMOD1Lbl->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    PhaseMOD1Lbl->setJustificationType (Justification::centred);
    PhaseMOD1Lbl->setEditable (false, false, false);
    PhaseMOD1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    PhaseMOD1Lbl->setColour (TextEditor::textColourId, Colours::black);
    PhaseMOD1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    PhaseMOD1Lbl->setBounds (177, 272, 46, 24);

    MOD2Group.reset (new GroupComponent ("MOD 2 Group",
                                         TRANS("MOD2")));
    addAndMakeVisible (MOD2Group.get());

    MOD2Group->setBounds (340, 200, 288, 128);

    DepthMOD2Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("MOD 2 Depth Slider"));
    addAndMakeVisible (DepthMOD2Sld.get());
    DepthMOD2Sld->setTooltip (TRANS("Depth of the LFO"));
    DepthMOD2Sld->setRange (0, 1, 0.01);
    DepthMOD2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    DepthMOD2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DepthMOD2Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    DepthMOD2Sld->addListener (this);

    DepthMOD2Sld->setBounds (428, 248, 32, 24);

    FreqMOD2Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("MOD 2 Freq Slider"));
    addAndMakeVisible (FreqMOD2Sld.get());
    FreqMOD2Sld->setTooltip (TRANS("Frequency of the LFO, from 2Hz to 20Hz"));
    FreqMOD2Sld->setRange (0, 1, 0.01);
    FreqMOD2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    FreqMOD2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FreqMOD2Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    FreqMOD2Sld->addListener (this);

    FreqMOD2Sld->setBounds (372, 248, 32, 24);

    WaveMOD2Cmb.reset (new ComboBox ("MOD 2 Wave"));
    addAndMakeVisible (WaveMOD2Cmb.get());
    WaveMOD2Cmb->setTooltip (TRANS("LFO wave shape"));
    WaveMOD2Cmb->setEditableText (false);
    WaveMOD2Cmb->setJustificationType (Justification::centredLeft);
    WaveMOD2Cmb->setTextWhenNothingSelected (String());
    WaveMOD2Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    WaveMOD2Cmb->addItem (TRANS("Sine"), 1);
    WaveMOD2Cmb->addItem (TRANS("Square"), 2);
    WaveMOD2Cmb->addItem (TRANS("Saw"), 3);
    WaveMOD2Cmb->addListener (this);

    WaveMOD2Cmb->setBounds (532, 256, 80, 24);

    BypassMOD2Btn.reset (new TextButton ("MOD 2 Bypass Button"));
    addAndMakeVisible (BypassMOD2Btn.get());
    BypassMOD2Btn->setTooltip (TRANS("Bypass button for MOD 2. MOD 2 modulates the rate and depth of LFO 2."));
    BypassMOD2Btn->setButtonText (TRANS("MOD 2"));
    BypassMOD2Btn->addListener (this);

    BypassMOD2Btn->setBounds (556, 216, 56, 24);

    FreqMOD2Lbl.reset (new Label ("MOD 2 Freq Label",
                                  TRANS("Rate")));
    addAndMakeVisible (FreqMOD2Lbl.get());
    FreqMOD2Lbl->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    FreqMOD2Lbl->setJustificationType (Justification::centred);
    FreqMOD2Lbl->setEditable (false, false, false);
    FreqMOD2Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    FreqMOD2Lbl->setColour (TextEditor::textColourId, Colours::black);
    FreqMOD2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    FreqMOD2Lbl->setBounds (368, 272, 40, 24);

    DepthMOD2Lbl.reset (new Label ("MOD 2 Depth Label",
                                   TRANS("Depth")));
    addAndMakeVisible (DepthMOD2Lbl.get());
    DepthMOD2Lbl->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    DepthMOD2Lbl->setJustificationType (Justification::centredLeft);
    DepthMOD2Lbl->setEditable (false, false, false);
    DepthMOD2Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    DepthMOD2Lbl->setColour (TextEditor::textColourId, Colours::black);
    DepthMOD2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    DepthMOD2Lbl->setBounds (421, 272, 46, 24);

    WaveMOD2Lbl.reset (new Label ("MOD 2 Wave Label",
                                  TRANS("Wave\n")));
    addAndMakeVisible (WaveMOD2Lbl.get());
    WaveMOD2Lbl->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    WaveMOD2Lbl->setJustificationType (Justification::centredLeft);
    WaveMOD2Lbl->setEditable (false, false, false);
    WaveMOD2Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    WaveMOD2Lbl->setColour (TextEditor::textColourId, Colours::black);
    WaveMOD2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    WaveMOD2Lbl->setBounds (548, 288, 46, 24);

    TempoSyncMOD2Btn.reset (new TextButton ("MOD 2 Tempo Sync Button"));
    addAndMakeVisible (TempoSyncMOD2Btn.get());
    TempoSyncMOD2Btn->setTooltip (TRANS("Tempo sync LFO frequency"));
    TempoSyncMOD2Btn->setButtonText (TRANS("Tempo"));
    TempoSyncMOD2Btn->addListener (this);

    TempoSyncMOD2Btn->setBounds (364, 224, 56, 16);

    TempoNumerMOD2Sld.reset (new Slider ("MOD 2 Tempo Numer Slider"));
    addAndMakeVisible (TempoNumerMOD2Sld.get());
    TempoNumerMOD2Sld->setRange (1, 4, 1);
    TempoNumerMOD2Sld->setSliderStyle (Slider::IncDecButtons);
    TempoNumerMOD2Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoNumerMOD2Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0xffc8c8c8));
    TempoNumerMOD2Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x09808080));
    TempoNumerMOD2Sld->addListener (this);

    TempoNumerMOD2Sld->setBounds (364, 256, 56, 16);

    TempoDenomMOD2Sld.reset (new Slider ("MOD 2 Tempo Denom Slider"));
    addAndMakeVisible (TempoDenomMOD2Sld.get());
    TempoDenomMOD2Sld->setRange (1, 32, 1);
    TempoDenomMOD2Sld->setSliderStyle (Slider::IncDecButtons);
    TempoDenomMOD2Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoDenomMOD2Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0xffc8c8c8));
    TempoDenomMOD2Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    TempoDenomMOD2Sld->addListener (this);

    TempoDenomMOD2Sld->setBounds (364, 288, 56, 16);

    PhaseSyncMOD2Btn.reset (new TextButton ("MOD 2 Phase Sync Button"));
    addAndMakeVisible (PhaseSyncMOD2Btn.get());
    PhaseSyncMOD2Btn->setTooltip (TRANS("Enable phase sync to ensure the phase of the LFO is consistent regardless of where the DAW playhead starts from"));
    PhaseSyncMOD2Btn->setButtonText (TRANS("Phase"));
    PhaseSyncMOD2Btn->addListener (this);

    PhaseSyncMOD2Btn->setBounds (476, 224, 56, 16);

    PhaseMOD2Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("MOD 2 Phase Slider"));
    addAndMakeVisible (PhaseMOD2Sld.get());
    PhaseMOD2Sld->setTooltip (TRANS("Phase shift the LFO by up to 360 degrees"));
    PhaseMOD2Sld->setRange (0, 1, 0.01);
    PhaseMOD2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PhaseMOD2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    PhaseMOD2Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    PhaseMOD2Sld->addListener (this);

    PhaseMOD2Sld->setBounds (484, 248, 32, 24);

    PhaseMOD2Lbl.reset (new Label ("MOD 2 Phase Label",
                                   TRANS("Phase")));
    addAndMakeVisible (PhaseMOD2Lbl.get());
    PhaseMOD2Lbl->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    PhaseMOD2Lbl->setJustificationType (Justification::centredLeft);
    PhaseMOD2Lbl->setEditable (false, false, false);
    PhaseMOD2Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    PhaseMOD2Lbl->setColour (TextEditor::textColourId, Colours::black);
    PhaseMOD2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    PhaseMOD2Lbl->setBounds (477, 272, 46, 24);

    StereoBtn.reset (new TextButton ("Stereo Button"));
    addAndMakeVisible (StereoBtn.get());
    StereoBtn->setTooltip (TRANS("Enables LFO 1 and LFO 2 to operate on the left and right channels independently"));
    StereoBtn->setButtonText (TRANS("Stereo"));
    StereoBtn->addListener (this);

    StereoBtn->setBounds (542, 48, 72, 24);

    OutputGainLbl.reset (new Label ("Output Gain Label",
                                    TRANS("Output Gain")));
    addAndMakeVisible (OutputGainLbl.get());
    OutputGainLbl->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    OutputGainLbl->setJustificationType (Justification::centredLeft);
    OutputGainLbl->setEditable (false, false, false);
    OutputGainLbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    OutputGainLbl->setColour (TextEditor::textColourId, Colours::black);
    OutputGainLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    OutputGainLbl->setBounds (448, 48, 88, 24);

    MODLFO1LeftLbl.reset (new Label ("MOD LFO1 Left Label",
                                     TRANS("- MOD -")));
    addAndMakeVisible (MODLFO1LeftLbl.get());
    MODLFO1LeftLbl->setFont (Font (10.0f, Font::plain).withTypefaceStyle ("Regular"));
    MODLFO1LeftLbl->setJustificationType (Justification::centred);
    MODLFO1LeftLbl->setEditable (false, false, false);
    MODLFO1LeftLbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    MODLFO1LeftLbl->setColour (TextEditor::textColourId, Colours::black);
    MODLFO1LeftLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    MODLFO1LeftLbl->setBounds (97, 164, 38, 24);

    MODLFO2LeftLbl.reset (new Label ("MOD LFO2 Left Label",
                                     TRANS("- MOD -")));
    addAndMakeVisible (MODLFO2LeftLbl.get());
    MODLFO2LeftLbl->setFont (Font (10.0f, Font::plain).withTypefaceStyle ("Regular"));
    MODLFO2LeftLbl->setJustificationType (Justification::centred);
    MODLFO2LeftLbl->setEditable (false, false, false);
    MODLFO2LeftLbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    MODLFO2LeftLbl->setColour (TextEditor::textColourId, Colours::black);
    MODLFO2LeftLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    MODLFO2LeftLbl->setBounds (399, 164, 38, 24);

    MeterLFO1.reset (new RichterLFOMeter (false));
    addAndMakeVisible (MeterLFO1.get());
    MeterLFO1->setName ("LFO 1 Meter");

    MeterLFO1->setBounds (322, 90, 4, 96);

    MeterLFO2.reset (new RichterLFOMeter (false));
    addAndMakeVisible (MeterLFO2.get());
    MeterLFO2->setName ("LFO 2 Meter");

    MeterLFO2->setBounds (350, 90, 4, 96);

    MeterMOD1.reset (new RichterLFOMeter (true));
    addAndMakeVisible (MeterMOD1.get());
    MeterMOD1->setName ("MOD 1 Meter");

    MeterMOD1->setBounds (322, 218, 4, 96);

    MeterMOD2.reset (new RichterLFOMeter (true));
    addAndMakeVisible (MeterMOD2.get());
    MeterMOD2->setName ("MOD 2 Meter");

    MeterMOD2->setBounds (350, 218, 4, 96);

    MODLFO1RightLbl.reset (new Label ("MOD LFO1 Right Label",
                                      TRANS("- MOD")));
    addAndMakeVisible (MODLFO1RightLbl.get());
    MODLFO1RightLbl->setFont (Font (10.0f, Font::plain).withTypefaceStyle ("Regular"));
    MODLFO1RightLbl->setJustificationType (Justification::centred);
    MODLFO1RightLbl->setEditable (false, false, false);
    MODLFO1RightLbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    MODLFO1RightLbl->setColour (TextEditor::textColourId, Colours::black);
    MODLFO1RightLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    MODLFO1RightLbl->setBounds (153, 164, 38, 24);

    MODLFO2RightLbl.reset (new Label ("MOD LFO2 Right Label",
                                      TRANS("- MOD")));
    addAndMakeVisible (MODLFO2RightLbl.get());
    MODLFO2RightLbl->setFont (Font (10.0f, Font::plain).withTypefaceStyle ("Regular"));
    MODLFO2RightLbl->setJustificationType (Justification::centred);
    MODLFO2RightLbl->setEditable (false, false, false);
    MODLFO2RightLbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    MODLFO2RightLbl->setColour (TextEditor::textColourId, Colours::black);
    MODLFO2RightLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    MODLFO2RightLbl->setBounds (455, 164, 38, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (675, 340);


    //[Constructor] You can add your own custom stuff here..
    startTimer(20);

    _assignLookAndFeelToAllChildren(customLookAndFeel);
    customLookAndFeel.setHighlightColour(Colour(0, 250, 0));
    tempoLookAndFeel.setHighlightColour(Colour(0, 250, 0));

    TempoNumerLFO1Sld->setLookAndFeel(&tempoLookAndFeel);
    TempoDenomLFO1Sld->setLookAndFeel(&tempoLookAndFeel);

    TempoNumerLFO2Sld->setLookAndFeel(&tempoLookAndFeel);
    TempoDenomLFO2Sld->setLookAndFeel(&tempoLookAndFeel);

    TempoNumerMOD1Sld->setLookAndFeel(&tempoLookAndFeel);
    TempoDenomMOD1Sld->setLookAndFeel(&tempoLookAndFeel);

    TempoNumerMOD2Sld->setLookAndFeel(&tempoLookAndFeel);
    TempoDenomMOD2Sld->setLookAndFeel(&tempoLookAndFeel);

    // This is needed for the fonts to be applied
    RichterLookAndFeel::setDefaultLookAndFeel(&customLookAndFeel);

    // Meter colour
    customLookAndFeel.setColour(RichterLFOMeter::ColourIds::mainColourId,
                                _highlightColour);

    // make tempo sync buttons draggable
    TempoNumerLFO1Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);
    TempoDenomLFO1Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);

    TempoNumerLFO2Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);
    TempoDenomLFO2Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);

    TempoNumerMOD1Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);
    TempoDenomMOD1Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);

    TempoNumerMOD2Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);
    TempoDenomMOD2Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);

    // check if stereo mode should be available
    RichterAudioProcessor* ourProcessor {getProcessor()};
    StereoBtn->setEnabled(ourProcessor->getNumOutputChannels() == 2);

    _enableDoubleClickToDefault();

    _startSliderReadouts();
    //[/Constructor]
}

RichterAudioProcessorEditor::~RichterAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    _stopSliderReadouts();
    //[/Destructor_pre]

    LFO1Group = nullptr;
    DepthLFO1Sld = nullptr;
    FreqLFO1Sld = nullptr;
    WaveLFO1Cmb = nullptr;
    DepthModLFO1Sld = nullptr;
    FreqModLFO1Sld = nullptr;
    OutputGainSld = nullptr;
    BypassLFO1Btn = nullptr;
    FreqLFO1Lbl = nullptr;
    DepthLFO1Lbl = nullptr;
    WaveLFO1Lbl = nullptr;
    LFO2Group = nullptr;
    DepthLFO2Sld = nullptr;
    FreqLFO2Sld = nullptr;
    WaveLFO2Cmb = nullptr;
    DepthModLFO2Sld = nullptr;
    FreqModLFO2Sld = nullptr;
    BypassLFO2Btn = nullptr;
    FreqLFO2Lbl = nullptr;
    DepthLFO2Lbl = nullptr;
    WaveLFO2Lbl = nullptr;
    TempoSyncLFO1Btn = nullptr;
    TempoSyncLFO2Btn = nullptr;
    TempoNumerLFO1Sld = nullptr;
    TempoDenomLFO1Sld = nullptr;
    TempoNumerLFO2Sld = nullptr;
    TempoDenomLFO2Sld = nullptr;
    PhaseSyncLFO1Btn = nullptr;
    PhaseSyncLFO2Btn = nullptr;
    PhaseLFO1Sld = nullptr;
    PhaseLFO1Lbl = nullptr;
    PhaseLFO2Sld = nullptr;
    PhaseLFO2Lbl = nullptr;
    MOD1Group = nullptr;
    DepthMOD1Sld = nullptr;
    FreqMOD1Sld = nullptr;
    WaveMOD1Cmb = nullptr;
    BypassMOD1Btn = nullptr;
    FreqMOD1Lbl = nullptr;
    DepthMOD1Lbl = nullptr;
    WaveMOD1Lbl = nullptr;
    TempoSyncMOD1Btn = nullptr;
    TempoNumerMOD1Sld = nullptr;
    TempoDenomMOD1Sld = nullptr;
    PhaseSyncMOD1Btn = nullptr;
    PhaseMOD1Sld = nullptr;
    PhaseMOD1Lbl = nullptr;
    MOD2Group = nullptr;
    DepthMOD2Sld = nullptr;
    FreqMOD2Sld = nullptr;
    WaveMOD2Cmb = nullptr;
    BypassMOD2Btn = nullptr;
    FreqMOD2Lbl = nullptr;
    DepthMOD2Lbl = nullptr;
    WaveMOD2Lbl = nullptr;
    TempoSyncMOD2Btn = nullptr;
    TempoNumerMOD2Sld = nullptr;
    TempoDenomMOD2Sld = nullptr;
    PhaseSyncMOD2Btn = nullptr;
    PhaseMOD2Sld = nullptr;
    PhaseMOD2Lbl = nullptr;
    StereoBtn = nullptr;
    OutputGainLbl = nullptr;
    MODLFO1LeftLbl = nullptr;
    MODLFO2LeftLbl = nullptr;
    MeterLFO1 = nullptr;
    MeterLFO2 = nullptr;
    MeterMOD1 = nullptr;
    MeterMOD2 = nullptr;
    MODLFO1RightLbl = nullptr;
    MODLFO2RightLbl = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    _removeLookAndFeelFromAllChildren();
    //[/Destructor]
}

//==============================================================================
void RichterAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    Image bg {ImageCache::getFromMemory(BinaryData::Richter_Background_png, BinaryData::Richter_Background_pngSize)};
    g.drawImage(bg, 0, 0, 675, 340, 0, 0, 5 * 675, 5 * 340);
    //[/UserPaint]
}

void RichterAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void RichterAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    RichterAudioProcessor* ourProcessor {getProcessor()};
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == DepthLFO1Sld.get())
    {
        //[UserSliderCode_DepthLFO1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::depthLFO1, static_cast<float>(DepthLFO1Sld->getValue()));
        //[/UserSliderCode_DepthLFO1Sld]
    }
    else if (sliderThatWasMoved == FreqLFO1Sld.get())
    {
        //[UserSliderCode_FreqLFO1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::freqLFO1, static_cast<float>(FreqLFO1Sld->getValue()));
        //[/UserSliderCode_FreqLFO1Sld]
    }
    else if (sliderThatWasMoved == DepthModLFO1Sld.get())
    {
        //[UserSliderCode_DepthModLFO1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::depthModLFO1, static_cast<float>(DepthModLFO1Sld->getValue()));
        //[/UserSliderCode_DepthModLFO1Sld]
    }
    else if (sliderThatWasMoved == FreqModLFO1Sld.get())
    {
        //[UserSliderCode_FreqModLFO1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::freqModLFO1, static_cast<float>(FreqModLFO1Sld->getValue()));
        //[/UserSliderCode_FreqModLFO1Sld]
    }
    else if (sliderThatWasMoved == OutputGainSld.get())
    {
        //[UserSliderCode_OutputGainSld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::outputGain, static_cast<float>(OutputGainSld->getValue()));
        //[/UserSliderCode_OutputGainSld]
    }
    else if (sliderThatWasMoved == DepthLFO2Sld.get())
    {
        //[UserSliderCode_DepthLFO2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::depthLFO2, static_cast<float>(DepthLFO2Sld->getValue()));
        //[/UserSliderCode_DepthLFO2Sld]
    }
    else if (sliderThatWasMoved == FreqLFO2Sld.get())
    {
        //[UserSliderCode_FreqLFO2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::freqLFO2, static_cast<float>(FreqLFO2Sld->getValue()));
        //[/UserSliderCode_FreqLFO2Sld]
    }
    else if (sliderThatWasMoved == DepthModLFO2Sld.get())
    {
        //[UserSliderCode_DepthModLFO2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::depthModLFO2, static_cast<float>(DepthModLFO2Sld->getValue()));
        //[/UserSliderCode_DepthModLFO2Sld]
    }
    else if (sliderThatWasMoved == FreqModLFO2Sld.get())
    {
        //[UserSliderCode_FreqModLFO2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::freqModLFO2, static_cast<float>(FreqModLFO2Sld->getValue()));
        //[/UserSliderCode_FreqModLFO2Sld]
    }
    else if (sliderThatWasMoved == TempoNumerLFO1Sld.get())
    {
        //[UserSliderCode_TempoNumerLFO1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoNumerLFO1, static_cast<float>(TempoNumerLFO1Sld->getValue()));
        //[/UserSliderCode_TempoNumerLFO1Sld]
    }
    else if (sliderThatWasMoved == TempoDenomLFO1Sld.get())
    {
        //[UserSliderCode_TempoDenomLFO1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoDenomLFO1, static_cast<float>(TempoDenomLFO1Sld->getValue()));
        //[/UserSliderCode_TempoDenomLFO1Sld]
    }
    else if (sliderThatWasMoved == TempoNumerLFO2Sld.get())
    {
        //[UserSliderCode_TempoNumerLFO2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoNumerLFO2, static_cast<float>(TempoNumerLFO2Sld->getValue()));
        //[/UserSliderCode_TempoNumerLFO2Sld]
    }
    else if (sliderThatWasMoved == TempoDenomLFO2Sld.get())
    {
        //[UserSliderCode_TempoDenomLFO2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoDenomLFO2, static_cast<float>(TempoDenomLFO2Sld->getValue()));
        //[/UserSliderCode_TempoDenomLFO2Sld]
    }
    else if (sliderThatWasMoved == PhaseLFO1Sld.get())
    {
        //[UserSliderCode_PhaseLFO1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::phaseLFO1, static_cast<float>(PhaseLFO1Sld->getValue()));
        //[/UserSliderCode_PhaseLFO1Sld]
    }
    else if (sliderThatWasMoved == PhaseLFO2Sld.get())
    {
        //[UserSliderCode_PhaseLFO2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::phaseLFO2, static_cast<float>(PhaseLFO2Sld->getValue()));
        //[/UserSliderCode_PhaseLFO2Sld]
    }
    else if (sliderThatWasMoved == DepthMOD1Sld.get())
    {
        //[UserSliderCode_DepthMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::depthMOD1, static_cast<float>(DepthMOD1Sld->getValue()));
        //[/UserSliderCode_DepthMOD1Sld]
    }
    else if (sliderThatWasMoved == FreqMOD1Sld.get())
    {
        //[UserSliderCode_FreqMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::freqMOD1, static_cast<float>(FreqMOD1Sld->getValue()));
        //[/UserSliderCode_FreqMOD1Sld]
    }
    else if (sliderThatWasMoved == TempoNumerMOD1Sld.get())
    {
        //[UserSliderCode_TempoNumerMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoNumerMOD1, static_cast<float>(TempoNumerMOD1Sld->getValue()));
        //[/UserSliderCode_TempoNumerMOD1Sld]
    }
    else if (sliderThatWasMoved == TempoDenomMOD1Sld.get())
    {
        //[UserSliderCode_TempoDenomMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoDenomMOD1, static_cast<float>(TempoDenomMOD1Sld->getValue()));
        //[/UserSliderCode_TempoDenomMOD1Sld]
    }
    else if (sliderThatWasMoved == PhaseMOD1Sld.get())
    {
        //[UserSliderCode_PhaseMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::phaseMOD1, static_cast<float>(PhaseMOD1Sld->getValue()));
        //[/UserSliderCode_PhaseMOD1Sld]
    }
    else if (sliderThatWasMoved == DepthMOD2Sld.get())
    {
        //[UserSliderCode_DepthMOD2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::depthMOD2, static_cast<float>(DepthMOD2Sld->getValue()));
        //[/UserSliderCode_DepthMOD2Sld]
    }
    else if (sliderThatWasMoved == FreqMOD2Sld.get())
    {
        //[UserSliderCode_FreqMOD2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::freqMOD2, static_cast<float>(FreqMOD2Sld->getValue()));
        //[/UserSliderCode_FreqMOD2Sld]
    }
    else if (sliderThatWasMoved == TempoNumerMOD2Sld.get())
    {
        //[UserSliderCode_TempoNumerMOD2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoNumerMOD2, static_cast<float>(TempoNumerMOD2Sld->getValue()));
        //[/UserSliderCode_TempoNumerMOD2Sld]
    }
    else if (sliderThatWasMoved == TempoDenomMOD2Sld.get())
    {
        //[UserSliderCode_TempoDenomMOD2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoDenomMOD2, static_cast<float>(TempoDenomMOD2Sld->getValue()));
        //[/UserSliderCode_TempoDenomMOD2Sld]
    }
    else if (sliderThatWasMoved == PhaseMOD2Sld.get())
    {
        //[UserSliderCode_PhaseMOD2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::phaseMOD2, static_cast<float>(PhaseMOD2Sld->getValue()));
        //[/UserSliderCode_PhaseMOD2Sld]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void RichterAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    RichterAudioProcessor* ourProcessor {getProcessor()};
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == WaveLFO1Cmb.get())
    {
        //[UserComboBoxCode_WaveLFO1Cmb] -- add your combo box handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::waveLFO1, static_cast<float>(WaveLFO1Cmb->getSelectedId()));
        //[/UserComboBoxCode_WaveLFO1Cmb]
    }
    else if (comboBoxThatHasChanged == WaveLFO2Cmb.get())
    {
        //[UserComboBoxCode_WaveLFO2Cmb] -- add your combo box handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::waveLFO2, static_cast<float>(WaveLFO2Cmb->getSelectedId()));
        //[/UserComboBoxCode_WaveLFO2Cmb]
    }
    else if (comboBoxThatHasChanged == WaveMOD1Cmb.get())
    {
        //[UserComboBoxCode_WaveMOD1Cmb] -- add your combo box handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::waveMOD1, static_cast<float>(WaveMOD1Cmb->getSelectedId()));
        //[/UserComboBoxCode_WaveMOD1Cmb]
    }
    else if (comboBoxThatHasChanged == WaveMOD2Cmb.get())
    {
        //[UserComboBoxCode_WaveMOD2Cmb] -- add your combo box handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::waveMOD2, static_cast<float>(WaveMOD2Cmb->getSelectedId()));
        //[/UserComboBoxCode_WaveMOD2Cmb]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void RichterAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    RichterAudioProcessor* ourProcessor {getProcessor()};
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == BypassLFO1Btn.get())
    {
        //[UserButtonCode_BypassLFO1Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::bypassSwitchLFO1, static_cast<float>(BypassLFO1Btn->getToggleState()));
        //[/UserButtonCode_BypassLFO1Btn]
    }
    else if (buttonThatWasClicked == BypassLFO2Btn.get())
    {
        //[UserButtonCode_BypassLFO2Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::bypassSwitchLFO2, static_cast<float>(BypassLFO2Btn->getToggleState()));
        //[/UserButtonCode_BypassLFO2Btn]
    }
    else if (buttonThatWasClicked == TempoSyncLFO1Btn.get())
    {
        //[UserButtonCode_TempoSyncLFO1Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoSyncLFO1, static_cast<float>(TempoSyncLFO1Btn->getToggleState()));
        //[/UserButtonCode_TempoSyncLFO1Btn]
    }
    else if (buttonThatWasClicked == TempoSyncLFO2Btn.get())
    {
        //[UserButtonCode_TempoSyncLFO2Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoSyncLFO2, static_cast<float>(TempoSyncLFO2Btn->getToggleState()));
        //[/UserButtonCode_TempoSyncLFO2Btn]
    }
    else if (buttonThatWasClicked == PhaseSyncLFO1Btn.get())
    {
        //[UserButtonCode_PhaseSyncLFO1Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::phaseSyncLFO1, static_cast<float>(PhaseSyncLFO1Btn->getToggleState()));
        //[/UserButtonCode_PhaseSyncLFO1Btn]
    }
    else if (buttonThatWasClicked == PhaseSyncLFO2Btn.get())
    {
        //[UserButtonCode_PhaseSyncLFO2Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::phaseSyncLFO2, static_cast<float>(PhaseSyncLFO2Btn->getToggleState()));
        //[/UserButtonCode_PhaseSyncLFO2Btn]
    }
    else if (buttonThatWasClicked == BypassMOD1Btn.get())
    {
        //[UserButtonCode_BypassMOD1Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::bypassSwitchMOD1, static_cast<float>(BypassMOD1Btn->getToggleState()));
        //[/UserButtonCode_BypassMOD1Btn]
    }
    else if (buttonThatWasClicked == TempoSyncMOD1Btn.get())
    {
        //[UserButtonCode_TempoSyncMOD1Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoSyncMOD1, static_cast<float>(TempoSyncMOD1Btn->getToggleState()));
        //[/UserButtonCode_TempoSyncMOD1Btn]
    }
    else if (buttonThatWasClicked == PhaseSyncMOD1Btn.get())
    {
        //[UserButtonCode_PhaseSyncMOD1Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::phaseSyncMOD1, static_cast<float>(PhaseSyncMOD1Btn->getToggleState()));
        //[/UserButtonCode_PhaseSyncMOD1Btn]
    }
    else if (buttonThatWasClicked == BypassMOD2Btn.get())
    {
        //[UserButtonCode_BypassMOD2Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::bypassSwitchMOD2, static_cast<float>(BypassMOD2Btn->getToggleState()));
        //[/UserButtonCode_BypassMOD2Btn]
    }
    else if (buttonThatWasClicked == TempoSyncMOD2Btn.get())
    {
        //[UserButtonCode_TempoSyncMOD2Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoSyncMOD2, static_cast<float>(TempoSyncMOD2Btn->getToggleState()));
        //[/UserButtonCode_TempoSyncMOD2Btn]
    }
    else if (buttonThatWasClicked == PhaseSyncMOD2Btn.get())
    {
        //[UserButtonCode_PhaseSyncMOD2Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::phaseSyncMOD2, static_cast<float>(PhaseSyncMOD2Btn->getToggleState()));
        //[/UserButtonCode_PhaseSyncMOD2Btn]
    }
    else if (buttonThatWasClicked == StereoBtn.get())
    {
        //[UserButtonCode_StereoBtn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::stereo, static_cast<float>(StereoBtn->getToggleState()));
        //[/UserButtonCode_StereoBtn]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void RichterAudioProcessorEditor::timerCallback()
{
    RichterAudioProcessor* ourProcessor {getProcessor()};

    if (ourProcessor->needsUIUpdate()) {
        // LFO 1
        BypassLFO1Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::bypassSwitchLFO1), dontSendNotification);
        PhaseSyncLFO1Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::phaseSyncLFO1), dontSendNotification);
        TempoSyncLFO1Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::tempoSyncLFO1), dontSendNotification);
        WaveLFO1Cmb->setSelectedId(ourProcessor->getParameter(RichterAudioProcessor::waveLFO1), dontSendNotification);
        DepthLFO1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::depthLFO1), dontSendNotification);
        DepthModLFO1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::depthModLFO1), dontSendNotification);
        FreqLFO1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::freqLFO1), dontSendNotification);
        FreqModLFO1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::freqModLFO1), dontSendNotification);
        PhaseLFO1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::phaseLFO1), dontSendNotification);
        TempoNumerLFO1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::tempoNumerLFO1), dontSendNotification);
        TempoDenomLFO1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::tempoDenomLFO1), dontSendNotification);


        // LFO 2
        BypassLFO2Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::bypassSwitchLFO2), dontSendNotification);
        PhaseSyncLFO2Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::phaseSyncLFO2), dontSendNotification);
        TempoSyncLFO2Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::tempoSyncLFO2), dontSendNotification);
        WaveLFO2Cmb->setSelectedId(ourProcessor->getParameter(RichterAudioProcessor::waveLFO2), dontSendNotification);
        DepthLFO2Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::depthLFO2), dontSendNotification);
        DepthModLFO2Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::depthModLFO2), dontSendNotification);
        FreqLFO2Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::freqLFO2), dontSendNotification);
        FreqModLFO2Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::freqModLFO2), dontSendNotification);
        PhaseLFO2Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::phaseLFO2), dontSendNotification);
        TempoNumerLFO2Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::tempoNumerLFO2), dontSendNotification);
        TempoDenomLFO2Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::tempoDenomLFO2), dontSendNotification);


        // MOD 1
        BypassMOD1Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::bypassSwitchMOD1), dontSendNotification);
        PhaseSyncMOD1Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::phaseSyncMOD1), dontSendNotification);
        TempoSyncMOD1Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::tempoSyncMOD1), dontSendNotification);
        WaveMOD1Cmb->setSelectedId(ourProcessor->getParameter(RichterAudioProcessor::waveMOD1), dontSendNotification);
        DepthMOD1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::depthMOD1), dontSendNotification);
        FreqMOD1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::freqMOD1), dontSendNotification);
        PhaseMOD1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::phaseMOD1), dontSendNotification);
        TempoNumerMOD1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::tempoNumerMOD1), dontSendNotification);
        TempoDenomMOD1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::tempoDenomMOD1), dontSendNotification);


        // MOD2
        BypassMOD2Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::bypassSwitchMOD2), dontSendNotification);
        PhaseSyncMOD2Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::phaseSyncMOD2), dontSendNotification);
        TempoSyncMOD2Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::tempoSyncMOD2), dontSendNotification);
        WaveMOD2Cmb->setSelectedId(ourProcessor->getParameter(RichterAudioProcessor::waveMOD2), dontSendNotification);
        DepthMOD2Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::depthMOD2), dontSendNotification);
        FreqMOD2Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::freqMOD2), dontSendNotification);
        PhaseMOD2Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::phaseMOD2), dontSendNotification);
        TempoNumerMOD2Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::tempoNumerMOD2), dontSendNotification);
        TempoDenomMOD2Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::tempoDenomMOD2), dontSendNotification);



        StereoBtn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::stereo), dontSendNotification);
        OutputGainSld->setValue(ourProcessor->getParameter(RichterAudioProcessor::outputGain), dontSendNotification);


        // Change LFO names if stereo
        if (StereoBtn->getToggleState()) {
            BypassLFO1Btn->setButtonText("LFO L");
            BypassLFO2Btn->setButtonText("LFO R");
            BypassMOD1Btn->setButtonText("MOD L");
            BypassMOD2Btn->setButtonText("MOD R");
        } else {
            BypassLFO1Btn->setButtonText("LFO 1");
            BypassLFO2Btn->setButtonText("LFO 2");
            BypassMOD1Btn->setButtonText("MOD 1");
            BypassMOD2Btn->setButtonText("MOD 2");
        }

        // Change outline colour based on whether LFO is active
        customLookAndFeel.updateLFOState(GROUP_LFO1, BypassLFO1Btn->getToggleState());
        customLookAndFeel.updateLFOState(GROUP_LFO2, BypassLFO2Btn->getToggleState());
        customLookAndFeel.updateLFOState(GROUP_MOD1, BypassMOD1Btn->getToggleState());
        customLookAndFeel.updateLFOState(GROUP_MOD2, BypassMOD2Btn->getToggleState());
        LFO1Group->repaint();
        LFO2Group->repaint();
        MOD1Group->repaint();
        MOD2Group->repaint();

        // Activate/Deactivale phase control depending on phase sync
        PhaseLFO1Sld->setEnabled(PhaseSyncLFO1Btn->getToggleState());
        PhaseLFO2Sld->setEnabled(PhaseSyncLFO2Btn->getToggleState());
        PhaseMOD1Sld->setEnabled(PhaseSyncMOD1Btn->getToggleState());
        PhaseMOD2Sld->setEnabled(PhaseSyncMOD2Btn->getToggleState());

        _updateTempoToggles();

        // Update meters
        const RichterLFOCache& lfoCache = ourProcessor->getLFOCache();
        auto updateMeter = [](RichterLFOMeter* meter, float value) {
            meter->setMeterValue(value);
            meter->repaint();
        };

        updateMeter(MeterLFO1.get(), lfoCache.lfo1);
        updateMeter(MeterLFO2.get(), lfoCache.lfo2);
        updateMeter(MeterMOD1.get(), lfoCache.mod1);
        updateMeter(MeterMOD2.get(), lfoCache.mod2);
    }
}

void RichterAudioProcessorEditor::_enableDoubleClickToDefault() {
    FreqLFO1Sld->setDoubleClickReturnValue(true, WECore::Richter::Parameters::FREQ.InteralToNormalised(WECore::Richter::Parameters::FREQ.defaultValue));
    FreqModLFO1Sld->setDoubleClickReturnValue(true, WECore::Richter::Parameters::FREQMOD.InteralToNormalised(WECore::Richter::Parameters::FREQMOD.defaultValue));
    DepthLFO1Sld->setDoubleClickReturnValue(true, WECore::Richter::Parameters::DEPTH.InteralToNormalised(WECore::Richter::Parameters::DEPTH.defaultValue));
    DepthModLFO1Sld->setDoubleClickReturnValue(true, WECore::Richter::Parameters::DEPTHMOD.InteralToNormalised(WECore::Richter::Parameters::DEPTHMOD.defaultValue));
    PhaseLFO1Sld->setDoubleClickReturnValue(true, WECore::Richter::Parameters::PHASE.InteralToNormalised(WECore::Richter::Parameters::PHASE.defaultValue));

    FreqLFO2Sld->setDoubleClickReturnValue(true, WECore::Richter::Parameters::FREQ.InteralToNormalised(WECore::Richter::Parameters::FREQ.defaultValue));
    FreqModLFO2Sld->setDoubleClickReturnValue(true, WECore::Richter::Parameters::FREQMOD.InteralToNormalised(WECore::Richter::Parameters::FREQMOD.defaultValue));
    DepthLFO2Sld->setDoubleClickReturnValue(true, WECore::Richter::Parameters::DEPTH.InteralToNormalised(WECore::Richter::Parameters::DEPTH.defaultValue));
    DepthModLFO2Sld->setDoubleClickReturnValue(true, WECore::Richter::Parameters::DEPTHMOD.InteralToNormalised(WECore::Richter::Parameters::DEPTHMOD.defaultValue));
    PhaseLFO2Sld->setDoubleClickReturnValue(true, WECore::Richter::Parameters::PHASE.InteralToNormalised(WECore::Richter::Parameters::PHASE.defaultValue));

    FreqMOD1Sld->setDoubleClickReturnValue(true, WECore::Richter::Parameters::FREQ.InteralToNormalised(WECore::Richter::Parameters::FREQ.defaultValue));
    DepthMOD1Sld->setDoubleClickReturnValue(true, WECore::Richter::Parameters::DEPTH.InteralToNormalised(WECore::Richter::Parameters::DEPTH.defaultValue));
    PhaseMOD1Sld->setDoubleClickReturnValue(true, WECore::Richter::Parameters::PHASE.InteralToNormalised(WECore::Richter::Parameters::PHASE.defaultValue));

    FreqMOD2Sld->setDoubleClickReturnValue(true, WECore::Richter::Parameters::FREQ.InteralToNormalised(WECore::Richter::Parameters::FREQ.defaultValue));
    DepthMOD2Sld->setDoubleClickReturnValue(true, WECore::Richter::Parameters::DEPTH.InteralToNormalised(WECore::Richter::Parameters::DEPTH.defaultValue));
    PhaseMOD2Sld->setDoubleClickReturnValue(true, WECore::Richter::Parameters::PHASE.InteralToNormalised(WECore::Richter::Parameters::PHASE.defaultValue));

    OutputGainSld->setDoubleClickReturnValue(true, OUTPUTGAIN.InteralToNormalised(OUTPUTGAIN.defaultValue));
}

void RichterAudioProcessorEditor::_startSliderReadouts() {
    // DepthModLFO1Sld is configured in _updateTempoToggles
    FreqLFO1Sld->start(FreqLFO1Lbl.get(), FreqLFO1Lbl->getText(), &WECore::Richter::Parameters::FREQ);
    FreqModLFO1Sld->start(MODLFO1LeftLbl.get(), MODLFO1LeftLbl->getText(), &WECore::Richter::Parameters::FREQMOD);
    DepthLFO1Sld->start(DepthLFO1Lbl.get(), DepthLFO1Lbl->getText(), &WECore::Richter::Parameters::DEPTH);
    PhaseLFO1Sld->start(PhaseLFO1Lbl.get(), PhaseLFO1Lbl->getText(), &WECore::Richter::Parameters::PHASE);

    // DepthModLFO2Sld is configured in _updateTempoToggles
    FreqLFO2Sld->start(FreqLFO2Lbl.get(), FreqLFO2Lbl->getText(), &WECore::Richter::Parameters::FREQ);
    FreqModLFO2Sld->start(MODLFO2LeftLbl.get(), MODLFO2LeftLbl->getText(), &WECore::Richter::Parameters::FREQMOD);
    DepthLFO2Sld->start(DepthLFO2Lbl.get(), DepthLFO2Lbl->getText(), &WECore::Richter::Parameters::DEPTH);
    PhaseLFO2Sld->start(PhaseLFO2Lbl.get(), PhaseLFO2Lbl->getText(), &WECore::Richter::Parameters::PHASE);

    FreqMOD1Sld->start(FreqMOD1Lbl.get(), FreqMOD1Lbl->getText(), &WECore::Richter::Parameters::FREQ);
    DepthMOD1Sld->start(DepthMOD1Lbl.get(), DepthMOD1Lbl->getText(), &WECore::Richter::Parameters::DEPTH);
    PhaseMOD1Sld->start(PhaseMOD1Lbl.get(), PhaseMOD1Lbl->getText(), &WECore::Richter::Parameters::PHASE);

    FreqMOD2Sld->start(FreqMOD2Lbl.get(), FreqMOD2Lbl->getText(), &WECore::Richter::Parameters::FREQ);
    DepthMOD2Sld->start(DepthMOD2Lbl.get(), DepthMOD2Lbl->getText(), &WECore::Richter::Parameters::DEPTH);
    PhaseMOD2Sld->start(PhaseMOD2Lbl.get(), PhaseMOD2Lbl->getText(), &WECore::Richter::Parameters::PHASE);

    OutputGainSld->start(OutputGainLbl.get(), OutputGainLbl->getText(), &OUTPUTGAIN);
}

void RichterAudioProcessorEditor::_stopSliderReadouts() {
    FreqLFO1Sld->stop();
    FreqModLFO1Sld->stop();
    DepthLFO1Sld->stop();
    DepthModLFO1Sld->stop();
    PhaseLFO1Sld->stop();

    FreqLFO2Sld->stop();
    FreqModLFO2Sld->stop();
    DepthLFO2Sld->stop();
    DepthModLFO2Sld->stop();
    PhaseLFO2Sld->stop();

    FreqMOD1Sld->stop();
    DepthMOD1Sld->stop();
    PhaseMOD1Sld->stop();

    FreqMOD2Sld->stop();
    DepthMOD2Sld->stop();
    PhaseMOD2Sld->stop();

    OutputGainSld->stop();
}

void RichterAudioProcessorEditor::_updateTempoToggles() {

    // Initialise these to the opposite of the real value to force them to be updated the first time
    // around
    static bool tempoSyncLFO1 {!TempoSyncLFO1Btn->getToggleState()};
    static bool tempoSyncLFO2 {!TempoSyncLFO2Btn->getToggleState()};
    static bool tempoSyncMOD1 {!TempoSyncMOD1Btn->getToggleState()};
    static bool tempoSyncMOD2 {!TempoSyncMOD2Btn->getToggleState()};


    // Toggle visibility for rate controls and move MOD labels depending on tempo sync
    auto updateTempoButton = [](bool toggleState,
                                Slider* freqSld,
                                WECore::JUCEPlugin::LabelReadoutSlider<double>* freqModSld,
                                Label* freqLbl,
                                WECore::JUCEPlugin::LabelReadoutSlider<double>* depthModSld,
                                Slider* tempoNumerSld,
                                Slider* tempoDenomSld,
                                Label* modLeftLabel,
                                Label* modRightLabel) {

        if (toggleState) {
            freqSld->setVisible(false);
            freqLbl->setVisible(false);
            tempoNumerSld->setVisible(true);
            tempoDenomSld->setVisible(true);

            if (freqModSld != nullptr) {
                freqModSld->setVisible(false);
            }

            if (modLeftLabel != nullptr) {
                modLeftLabel->setVisible(false);
                modRightLabel->setVisible(true);
                depthModSld->start(modRightLabel, modRightLabel->getText(), &WECore::Richter::Parameters::FREQMOD);
            }

        } else {
            freqSld->setVisible(true);
            freqLbl->setVisible(true);
            tempoNumerSld->setVisible(false);
            tempoDenomSld->setVisible(false);

            if (freqModSld != nullptr) {
                freqModSld->setVisible(true);
            }

            if (modLeftLabel != nullptr) {
                modLeftLabel->setVisible(true);
                modRightLabel->setVisible(false);
                depthModSld->start(modLeftLabel, modLeftLabel->getText(), &WECore::Richter::Parameters::FREQMOD);
            }
        }

    };

    // Check if the toggle state has changed since it was last cache and update if needed
    if (TempoSyncLFO1Btn->getToggleState() != tempoSyncLFO1) {
        tempoSyncLFO1 = TempoSyncLFO1Btn->getToggleState();

        updateTempoButton(tempoSyncLFO1,
                          FreqLFO1Sld.get(),
                          FreqModLFO1Sld.get(),
                          FreqLFO1Lbl.get(),
                          DepthModLFO1Sld.get(),
                          TempoNumerLFO1Sld.get(),
                          TempoDenomLFO1Sld.get(),
                          MODLFO1LeftLbl.get(),
                          MODLFO1RightLbl.get());
    }

    if (TempoSyncLFO2Btn->getToggleState() != tempoSyncLFO2) {
        tempoSyncLFO2 = TempoSyncLFO2Btn->getToggleState();

        updateTempoButton(tempoSyncLFO2,
                          FreqLFO2Sld.get(),
                          FreqModLFO2Sld.get(),
                          FreqLFO2Lbl.get(),
                          DepthModLFO2Sld.get(),
                          TempoNumerLFO2Sld.get(),
                          TempoDenomLFO2Sld.get(),
                          MODLFO2LeftLbl.get(),
                          MODLFO2RightLbl.get());
    }

    if (TempoSyncMOD1Btn->getToggleState() != tempoSyncMOD1) {
        tempoSyncMOD1 = TempoSyncMOD1Btn->getToggleState();

        updateTempoButton(tempoSyncMOD1,
                          FreqMOD1Sld.get(),
                          nullptr,
                          FreqMOD1Lbl.get(),
                          nullptr,
                          TempoNumerMOD1Sld.get(),
                          TempoDenomMOD1Sld.get(),
                          nullptr,
                          nullptr);
    }

    if (TempoSyncMOD2Btn->getToggleState() != tempoSyncMOD2) {
        tempoSyncMOD2 = TempoSyncMOD2Btn->getToggleState();

        updateTempoButton(tempoSyncMOD2,
                          FreqMOD2Sld.get(),
                          nullptr,
                          FreqMOD2Lbl.get(),
                          nullptr,
                          TempoNumerMOD2Sld.get(),
                          TempoDenomMOD2Sld.get(),
                          nullptr,
                          nullptr);
    }


}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="RichterAudioProcessorEditor"
                 componentName="" parentClasses="public WECore::JUCEPlugin::CoreProcessorEditor, public Timer"
                 constructorParams="RichterAudioProcessor&amp; ownerFilter" variableInitialisers="CoreProcessorEditor(ownerFilter), _highlightColour(0x7f00ff03)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.33"
                 fixedSize="1" initialWidth="675" initialHeight="340">
  <BACKGROUND backgroundColour="ffffffff"/>
  <GROUPCOMPONENT name="LFO 1 Group" id="2a8643bc712454bf" memberName="LFO1Group"
                  virtualName="" explicitFocusOrder="0" pos="48 72 288 128" textcol="ff000000"
                  title="LFO1"/>
  <SLIDER name="LFO 1 Depth Slider" id="98ad3308f709f25c" memberName="DepthLFO1Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="128 120 32 24" tooltip="Depth of the LFO"
          rotarysliderfill="7f00ff03" min="0.0" max="1.0" int="0.01000000000000000021"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="LFO 1 Freq Slider" id="94530d5c05e4a382" memberName="FreqLFO1Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="72 120 32 24" tooltip="Frequency of the LFO, from 2Hz to 20Hz"
          rotarysliderfill="7f00ff03" min="0.0" max="1.0" int="0.01000000000000000021"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <COMBOBOX name="LFO 1 Wave" id="6343a9cc42a2eda5" memberName="WaveLFO1Cmb"
            virtualName="" explicitFocusOrder="0" pos="232 128 80 24" tooltip="LFO wave shape"
            editable="0" layout="33" items="Sine&#10;Square&#10;Saw" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="LFO 1 Depth Mod Slider" id="9a3f86cb168e586e" memberName="DepthModLFO1Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="136 168 16 16" tooltip="Amount of depth modulation from MOD 1"
          rotarysliderfill="7f00ff03" min="0.0" max="1.0" int="0.01000000000000000021"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="LFO 1 Freq Mod Slider" id="b0488ea613d92dcf" memberName="FreqModLFO1Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="80 168 16 16" tooltip="Amount of rate modulation from MOD 1"
          rotarysliderfill="7f00ff03" min="0.0" max="1.0" int="0.01000000000000000021"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="Output Gain Slider" id="65acc0b358aa2541" memberName="OutputGainSld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;float&gt;"
          explicitFocusOrder="0" pos="56 48 392 24" tooltip="Output gain"
          min="0.0" max="1.0" int="0.01000000000000000021" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <TEXTBUTTON name="LFO 1 Bypass Button" id="27660ce1c9366ec3" memberName="BypassLFO1Btn"
              virtualName="" explicitFocusOrder="0" pos="256 88 56 24" tooltip="Bypass button for LFO 1. LFO 1 operates directly on sound."
              buttonText="LFO 1" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="LFO 1 Freq Label" id="29836e1fe4622869" memberName="FreqLFO1Lbl"
         virtualName="" explicitFocusOrder="0" pos="68 144 40 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="LFO 1 Depth Label" id="fa48be8976dad123" memberName="DepthLFO1Lbl"
         virtualName="" explicitFocusOrder="0" pos="121 144 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Depth" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="LFO 1 Wave Label" id="75dbcd5f6a0cc700" memberName="WaveLFO1Lbl"
         virtualName="" explicitFocusOrder="0" pos="248 160 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Wave&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <GROUPCOMPONENT name="LFO 2 Group" id="35e8ad61c86b603a" memberName="LFO2Group"
                  virtualName="" explicitFocusOrder="0" pos="340 72 288 128" title="LFO2"/>
  <SLIDER name="LFO 2 Depth Slider" id="2596adc2e61cd58e" memberName="DepthLFO2Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="428 120 32 24" tooltip="Depth of the LFO"
          rotarysliderfill="7f00ff03" min="0.0" max="1.0" int="0.01000000000000000021"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="LFO 2 Freq Slider" id="f5dbcdc53c502e69" memberName="FreqLFO2Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="372 120 32 24" tooltip="Frequency of the LFO, from 2Hz to 20Hz"
          rotarysliderfill="7f00ff03" min="0.0" max="1.0" int="0.01000000000000000021"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <COMBOBOX name="LFO 2 Wave" id="b76d5189aafe8e3f" memberName="WaveLFO2Cmb"
            virtualName="" explicitFocusOrder="0" pos="532 128 80 24" tooltip="LFO wave shape"
            editable="0" layout="33" items="Sine&#10;Square&#10;Saw" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="LFO 2 Depth Mod Slider" id="4a524c9e1974186c" memberName="DepthModLFO2Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="438 168 16 16" tooltip="Amount of depth modulation from MOD 1"
          rotarysliderfill="7f00ff03" min="0.0" max="1.0" int="0.01000000000000000021"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="LFO 2 Freq Mod Slider" id="e49bd74bef8aaca1" memberName="FreqModLFO2Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="380 168 16 16" tooltip="Amount of rate modulation from MOD 2"
          rotarysliderfill="7f00ff03" min="0.0" max="1.0" int="0.01000000000000000021"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <TEXTBUTTON name="LFO 2 Bypass Button" id="74a3a05dda891f9c" memberName="BypassLFO2Btn"
              virtualName="" explicitFocusOrder="0" pos="556 88 56 24" tooltip="Bypass button for LFO 2. LFO 2 operates directly on sound."
              buttonText="LFO 2" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="LFO 2 Freq Label" id="5463cd286934c4bc" memberName="FreqLFO2Lbl"
         virtualName="" explicitFocusOrder="0" pos="368 144 40 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="LFO 2 Depth Label" id="39dd59a998ec443" memberName="DepthLFO2Lbl"
         virtualName="" explicitFocusOrder="0" pos="421 144 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Depth" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="LFO 2 Wave Label" id="e01fc09efde6d339" memberName="WaveLFO2Lbl"
         virtualName="" explicitFocusOrder="0" pos="548 160 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Wave&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="LFO 1 Tempo Sync Button" id="95825bc0b3290b8b" memberName="TempoSyncLFO1Btn"
              virtualName="" explicitFocusOrder="0" pos="64 96 56 16" tooltip="Tempo sync LFO frequency"
              buttonText="Tempo" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="LFO 2 Tempo Sync Button" id="3a20b52dc2308f55" memberName="TempoSyncLFO2Btn"
              virtualName="" explicitFocusOrder="0" pos="364 96 56 16" tooltip="Tempo sync LFO frequency"
              buttonText="Tempo" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="LFO 1 Tempo Numer Slider" id="ae3b2cb5fc40f879" memberName="TempoNumerLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="64 128 56 16" textboxbkgd="ffc8c8c8"
          textboxoutline="808080" min="1.0" max="4.0" int="1.0" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="LFO 1 Tempo Denom Slider" id="79fb8b0e645e1976" memberName="TempoDenomLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="64 160 56 16" textboxbkgd="ffc8c8c8"
          textboxoutline="808080" min="1.0" max="32.0" int="1.0" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="LFO 2 Tempo Numer Slider" id="7ef07d530a2439f7" memberName="TempoNumerLFO2Sld"
          virtualName="" explicitFocusOrder="0" pos="364 128 56 16" textboxbkgd="ffc8c8c8"
          textboxoutline="808080" min="1.0" max="4.0" int="1.0" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="LFO 2 Tempo Denom Slider" id="684fae94c6ad39f8" memberName="TempoDenomLFO2Sld"
          virtualName="" explicitFocusOrder="0" pos="364 160 56 16" textboxbkgd="ffc8c8c8"
          textboxoutline="808080" min="1.0" max="32.0" int="1.0" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <TEXTBUTTON name="LFO 1 Phase Sync Button" id="1df73348199bbe85" memberName="PhaseSyncLFO1Btn"
              virtualName="" explicitFocusOrder="0" pos="176 96 56 16" tooltip="Enable phase sync to ensure the phase of the LFO is consistent regardless of where the DAW playhead starts from"
              buttonText="Phase" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="LFO 2 Phase Sync Button" id="6956f3f885f5801d" memberName="PhaseSyncLFO2Btn"
              virtualName="" explicitFocusOrder="0" pos="476 96 56 16" tooltip="Enable phase sync to ensure the phase of the LFO is consistent regardless of where the DAW playhead starts from"
              buttonText="Phase" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="LFO 1 Phase Slider" id="1fa393dc85f550ee" memberName="PhaseLFO1Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="184 120 32 24" tooltip="Phase shift the LFO by up to 360 degrees"
          thumbcol="ffbdffbb" rotarysliderfill="7f00ff03" min="0.0" max="1.0"
          int="0.01000000000000000021" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="LFO 1 Phase Label" id="e8d899c4a3a19f8" memberName="PhaseLFO1Lbl"
         virtualName="" explicitFocusOrder="0" pos="177 144 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Phase" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="LFO 2 Phase Slider" id="df30ce6c91b8975b" memberName="PhaseLFO2Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="484 120 32 24" tooltip="Changes the phase of the LFO by up to 360 degrees"
          rotarysliderfill="7f00ff03" min="0.0" max="1.0" int="0.01000000000000000021"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="LFO 2 Phase Label" id="5fd532cc21a16f51" memberName="PhaseLFO2Lbl"
         virtualName="" explicitFocusOrder="0" pos="477 144 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Phase" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <GROUPCOMPONENT name="MOD 1 Group" id="a2c7412d0fb46a58" memberName="MOD1Group"
                  virtualName="" explicitFocusOrder="0" pos="48 200 288 128" title="MOD1"/>
  <SLIDER name="MOD 1 Depth Slider" id="499f6451911662cc" memberName="DepthMOD1Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="128 248 32 24" tooltip="Depth of the LFO"
          rotarysliderfill="7f00ff0d" min="0.0" max="1.0" int="0.01000000000000000021"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="MOD 1 Freq Slider" id="1d9800ca18cf5bba" memberName="FreqMOD1Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="72 248 32 24" tooltip="Frequency of the LFO, from 2Hz to 20Hz"
          rotarysliderfill="7f00ff03" min="0.0" max="1.0" int="0.01000000000000000021"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <COMBOBOX name="MOD 1 Wave" id="370e5062e67cf738" memberName="WaveMOD1Cmb"
            virtualName="" explicitFocusOrder="0" pos="232 256 80 24" tooltip="LFO wave shape"
            editable="0" layout="33" items="Sine&#10;Square&#10;Saw" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="MOD 1 Bypass Button" id="cd667ff923e74db5" memberName="BypassMOD1Btn"
              virtualName="" explicitFocusOrder="0" pos="256 216 56 24" tooltip="Bypass button for MOD 1. MOD 1 modulates the rate and depth of LFO 1."
              buttonText="MOD 1" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="MOD 1 Freq Label" id="dabfca26c640fd58" memberName="FreqMOD1Lbl"
         virtualName="" explicitFocusOrder="0" pos="68 272 40 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="MOD 1 Depth Label" id="77092a4a55225c68" memberName="DepthMOD1Lbl"
         virtualName="" explicitFocusOrder="0" pos="121 272 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Depth" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="MOD 1 Wave Label" id="7eb50c1a44463588" memberName="WaveMOD1Lbl"
         virtualName="" explicitFocusOrder="0" pos="248 288 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Wave&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="MOD 1 Tempo Sync Button" id="b43affdb8ac7bb90" memberName="TempoSyncMOD1Btn"
              virtualName="" explicitFocusOrder="0" pos="64 224 56 16" tooltip="Tempo sync LFO frequency"
              buttonText="Tempo" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="MOD 1 Tempo Numer Slider" id="6c49dac77f3e6f4b" memberName="TempoNumerMOD1Sld"
          virtualName="" explicitFocusOrder="0" pos="64 256 56 16" textboxbkgd="ffc8c8c8"
          textboxoutline="808080" min="1.0" max="4.0" int="1.0" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="MOD 1 Tempo Denom Slider" id="a116d9c60bf4c7b5" memberName="TempoDenomMOD1Sld"
          virtualName="" explicitFocusOrder="0" pos="64 288 56 16" textboxbkgd="ffc8c8c8"
          textboxoutline="808080" min="1.0" max="32.0" int="1.0" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <TEXTBUTTON name="MOD 1 Phase Sync Button" id="4509e154e4918174" memberName="PhaseSyncMOD1Btn"
              virtualName="" explicitFocusOrder="0" pos="176 224 56 16" tooltip="Enable phase sync to ensure the phase of the LFO is consistent regardless of where the DAW playhead starts from"
              buttonText="Phase" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="MOD 1 Phase Slider" id="3f1ef3d10c303bac" memberName="PhaseMOD1Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="184 248 32 24" tooltip="Phase shift the LFO by up to 360 degrees"
          rotarysliderfill="7f00ff03" min="0.0" max="1.0" int="0.01000000000000000021"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="MOD 1 Phase Label" id="af1abf98d305cb5c" memberName="PhaseMOD1Lbl"
         virtualName="" explicitFocusOrder="0" pos="177 272 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Phase" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <GROUPCOMPONENT name="MOD 2 Group" id="384e0ba59bb5f2ff" memberName="MOD2Group"
                  virtualName="" explicitFocusOrder="0" pos="340 200 288 128" title="MOD2"/>
  <SLIDER name="MOD 2 Depth Slider" id="8c1762ee0dd0d28a" memberName="DepthMOD2Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="428 248 32 24" tooltip="Depth of the LFO"
          rotarysliderfill="7f00ff03" min="0.0" max="1.0" int="0.01000000000000000021"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="MOD 2 Freq Slider" id="362166b8c676eba4" memberName="FreqMOD2Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="372 248 32 24" tooltip="Frequency of the LFO, from 2Hz to 20Hz"
          rotarysliderfill="7f00ff03" min="0.0" max="1.0" int="0.01000000000000000021"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <COMBOBOX name="MOD 2 Wave" id="c85d4543a533be92" memberName="WaveMOD2Cmb"
            virtualName="" explicitFocusOrder="0" pos="532 256 80 24" tooltip="LFO wave shape"
            editable="0" layout="33" items="Sine&#10;Square&#10;Saw" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="MOD 2 Bypass Button" id="7773dc0327675392" memberName="BypassMOD2Btn"
              virtualName="" explicitFocusOrder="0" pos="556 216 56 24" tooltip="Bypass button for MOD 2. MOD 2 modulates the rate and depth of LFO 2."
              buttonText="MOD 2" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="MOD 2 Freq Label" id="f37a78a0ec1cab07" memberName="FreqMOD2Lbl"
         virtualName="" explicitFocusOrder="0" pos="368 272 40 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="MOD 2 Depth Label" id="c19bf3a6d5ab63f9" memberName="DepthMOD2Lbl"
         virtualName="" explicitFocusOrder="0" pos="421 272 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Depth" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="MOD 2 Wave Label" id="1bdb7eca9ab250c8" memberName="WaveMOD2Lbl"
         virtualName="" explicitFocusOrder="0" pos="548 288 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Wave&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="MOD 2 Tempo Sync Button" id="bfc616fbcdb92b04" memberName="TempoSyncMOD2Btn"
              virtualName="" explicitFocusOrder="0" pos="364 224 56 16" tooltip="Tempo sync LFO frequency"
              buttonText="Tempo" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="MOD 2 Tempo Numer Slider" id="2bcaaa8e6b75d2b9" memberName="TempoNumerMOD2Sld"
          virtualName="" explicitFocusOrder="0" pos="364 256 56 16" textboxbkgd="ffc8c8c8"
          textboxoutline="9808080" min="1.0" max="4.0" int="1.0" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="MOD 2 Tempo Denom Slider" id="255bbe43957852ba" memberName="TempoDenomMOD2Sld"
          virtualName="" explicitFocusOrder="0" pos="364 288 56 16" textboxbkgd="ffc8c8c8"
          textboxoutline="808080" min="1.0" max="32.0" int="1.0" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <TEXTBUTTON name="MOD 2 Phase Sync Button" id="7b0a4004498f92b3" memberName="PhaseSyncMOD2Btn"
              virtualName="" explicitFocusOrder="0" pos="476 224 56 16" tooltip="Enable phase sync to ensure the phase of the LFO is consistent regardless of where the DAW playhead starts from"
              buttonText="Phase" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="MOD 2 Phase Slider" id="54fd5481a5970106" memberName="PhaseMOD2Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="484 248 32 24" tooltip="Phase shift the LFO by up to 360 degrees"
          rotarysliderfill="7f00ff03" min="0.0" max="1.0" int="0.01000000000000000021"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="MOD 2 Phase Label" id="d3b9d517ecdfe1bc" memberName="PhaseMOD2Lbl"
         virtualName="" explicitFocusOrder="0" pos="477 272 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Phase" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="Stereo Button" id="91683bb4fa1cc3c7" memberName="StereoBtn"
              virtualName="" explicitFocusOrder="0" pos="542 48 72 24" tooltip="Enables LFO 1 and LFO 2 to operate on the left and right channels independently"
              buttonText="Stereo" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="Output Gain Label" id="431abe2cd3bfe0c4" memberName="OutputGainLbl"
         virtualName="" explicitFocusOrder="0" pos="448 48 88 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Output Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="MOD LFO1 Left Label" id="486fb1a75ad5862e" memberName="MODLFO1LeftLbl"
         virtualName="" explicitFocusOrder="0" pos="97 164 38 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="- MOD -" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="MOD LFO2 Left Label" id="b1a4c6d32abd91a5" memberName="MODLFO2LeftLbl"
         virtualName="" explicitFocusOrder="0" pos="399 164 38 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="- MOD -" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <GENERICCOMPONENT name="LFO 1 Meter" id="2f1bc98394348a09" memberName="MeterLFO1"
                    virtualName="" explicitFocusOrder="0" pos="322 90 4 96" class="RichterLFOMeter"
                    params="false"/>
  <GENERICCOMPONENT name="LFO 2 Meter" id="5a489bf0841a15f0" memberName="MeterLFO2"
                    virtualName="" explicitFocusOrder="0" pos="350 90 4 96" class="RichterLFOMeter"
                    params="false"/>
  <GENERICCOMPONENT name="MOD 1 Meter" id="fab3ea7c3ef52c33" memberName="MeterMOD1"
                    virtualName="" explicitFocusOrder="0" pos="322 218 4 96" class="RichterLFOMeter"
                    params="true"/>
  <GENERICCOMPONENT name="MOD 2 Meter" id="3dca6948277dd87e" memberName="MeterMOD2"
                    virtualName="" explicitFocusOrder="0" pos="350 218 4 96" class="RichterLFOMeter"
                    params="true"/>
  <LABEL name="MOD LFO1 Right Label" id="1c4c09a386c3c562" memberName="MODLFO1RightLbl"
         virtualName="" explicitFocusOrder="0" pos="153 164 38 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="- MOD" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="MOD LFO2 Right Label" id="7de3f2db4c2a8590" memberName="MODLFO2RightLbl"
         virtualName="" explicitFocusOrder="0" pos="455 164 38 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="- MOD" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10.0" kerning="0.0" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
