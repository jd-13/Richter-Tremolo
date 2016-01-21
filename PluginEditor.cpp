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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
RichterAudioProcessorEditor::RichterAudioProcessorEditor (RichterAudioProcessor& ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (LFO1Group = new GroupComponent ("LFO 1 Group",
                                                       TRANS("LFO1")));
    LFO1Group->setColour (GroupComponent::textColourId, Colours::black);

    addAndMakeVisible (DepthLFO1Sld = new Slider ("LFO 1 Depth Slider"));
    DepthLFO1Sld->setRange (0, 1, 0.01);
    DepthLFO1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    DepthLFO1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DepthLFO1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    DepthLFO1Sld->addListener (this);

    addAndMakeVisible (FreqLFO1Sld = new Slider ("LFO 1 Freq Slider"));
    FreqLFO1Sld->setRange (0, 1, 0.01);
    FreqLFO1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    FreqLFO1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FreqLFO1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    FreqLFO1Sld->addListener (this);

    addAndMakeVisible (WaveLFO1Cmb = new ComboBox ("LFO 1 Wave"));
    WaveLFO1Cmb->setEditableText (false);
    WaveLFO1Cmb->setJustificationType (Justification::centredLeft);
    WaveLFO1Cmb->setTextWhenNothingSelected (String::empty);
    WaveLFO1Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    WaveLFO1Cmb->addItem (TRANS("Sine"), 1);
    WaveLFO1Cmb->addItem (TRANS("Square"), 2);
    WaveLFO1Cmb->addItem (TRANS("Saw"), 3);
    WaveLFO1Cmb->addListener (this);

    addAndMakeVisible (DepthModLFO1Sld = new Slider ("LFO 1 Depth Mod Slider"));
    DepthModLFO1Sld->setRange (0, 1, 0.01);
    DepthModLFO1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    DepthModLFO1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DepthModLFO1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    DepthModLFO1Sld->addListener (this);

    addAndMakeVisible (FreqModLFO1Sld = new Slider ("LFO 1 Freq Mod Slider"));
    FreqModLFO1Sld->setRange (0, 1, 0.01);
    FreqModLFO1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    FreqModLFO1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FreqModLFO1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    FreqModLFO1Sld->addListener (this);

    addAndMakeVisible (MasterVolSld = new Slider ("new slider"));
    MasterVolSld->setRange (0, 1, 0.01);
    MasterVolSld->setSliderStyle (Slider::LinearHorizontal);
    MasterVolSld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    MasterVolSld->addListener (this);

    addAndMakeVisible (BypassLFO1Btn = new TextButton ("LFO 1 Bypass Button"));
    BypassLFO1Btn->setButtonText (TRANS("LFO 1"));
    BypassLFO1Btn->addListener (this);

    addAndMakeVisible (FreqLFO1Lbl = new Label ("LFO 1 Freq Label",
                                                TRANS("Rate")));
    FreqLFO1Lbl->setFont (Font (15.00f, Font::plain));
    FreqLFO1Lbl->setJustificationType (Justification::centredLeft);
    FreqLFO1Lbl->setEditable (false, false, false);
    FreqLFO1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    FreqLFO1Lbl->setColour (TextEditor::textColourId, Colours::black);
    FreqLFO1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (DepthLFO1Lbl = new Label ("LFO 1 Depth Label",
                                                 TRANS("Depth")));
    DepthLFO1Lbl->setFont (Font (15.00f, Font::plain));
    DepthLFO1Lbl->setJustificationType (Justification::centredLeft);
    DepthLFO1Lbl->setEditable (false, false, false);
    DepthLFO1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    DepthLFO1Lbl->setColour (TextEditor::textColourId, Colours::black);
    DepthLFO1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (WaveLFO1Lbl = new Label ("LFO 1 Wave Label",
                                                TRANS("Wave\n")));
    WaveLFO1Lbl->setFont (Font (15.00f, Font::plain));
    WaveLFO1Lbl->setJustificationType (Justification::centredLeft);
    WaveLFO1Lbl->setEditable (false, false, false);
    WaveLFO1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    WaveLFO1Lbl->setColour (TextEditor::textColourId, Colours::black);
    WaveLFO1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (LFO2Group = new GroupComponent ("LFO 2 Group",
                                                       TRANS("LFO2")));

    addAndMakeVisible (DepthLFO2Sld = new Slider ("LFO 2 Depth Slider"));
    DepthLFO2Sld->setRange (0, 1, 0.01);
    DepthLFO2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    DepthLFO2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DepthLFO2Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    DepthLFO2Sld->addListener (this);

    addAndMakeVisible (FreqLFO2Sld = new Slider ("LFO 2 Freq Slider"));
    FreqLFO2Sld->setRange (0, 1, 0.01);
    FreqLFO2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    FreqLFO2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FreqLFO2Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    FreqLFO2Sld->addListener (this);

    addAndMakeVisible (WaveLFO2Cmb = new ComboBox ("LFO 2 Wave"));
    WaveLFO2Cmb->setEditableText (false);
    WaveLFO2Cmb->setJustificationType (Justification::centredLeft);
    WaveLFO2Cmb->setTextWhenNothingSelected (String::empty);
    WaveLFO2Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    WaveLFO2Cmb->addItem (TRANS("Sine"), 1);
    WaveLFO2Cmb->addItem (TRANS("Square"), 2);
    WaveLFO2Cmb->addItem (TRANS("Saw"), 3);
    WaveLFO2Cmb->addListener (this);

    addAndMakeVisible (DepthModLFO2Sld = new Slider ("LFO 2 Depth Mod Slider"));
    DepthModLFO2Sld->setRange (0, 1, 0.01);
    DepthModLFO2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    DepthModLFO2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DepthModLFO2Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    DepthModLFO2Sld->addListener (this);

    addAndMakeVisible (FreqModLFO2Sld = new Slider ("LFO 2 Freq Mod Slider"));
    FreqModLFO2Sld->setRange (0, 1, 0.01);
    FreqModLFO2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    FreqModLFO2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FreqModLFO2Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    FreqModLFO2Sld->addListener (this);

    addAndMakeVisible (BypassLFO2Btn = new TextButton ("LFO 2 Bypass Button"));
    BypassLFO2Btn->setButtonText (TRANS("LFO 2"));
    BypassLFO2Btn->addListener (this);

    addAndMakeVisible (FreqLFO2Lbl = new Label ("LFO 2 Freq Label",
                                                TRANS("Rate")));
    FreqLFO2Lbl->setFont (Font (15.00f, Font::plain));
    FreqLFO2Lbl->setJustificationType (Justification::centredLeft);
    FreqLFO2Lbl->setEditable (false, false, false);
    FreqLFO2Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    FreqLFO2Lbl->setColour (TextEditor::textColourId, Colours::black);
    FreqLFO2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (DepthLFO2Lbl = new Label ("LFO 2 Depth Label",
                                                 TRANS("Depth")));
    DepthLFO2Lbl->setFont (Font (15.00f, Font::plain));
    DepthLFO2Lbl->setJustificationType (Justification::centredLeft);
    DepthLFO2Lbl->setEditable (false, false, false);
    DepthLFO2Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    DepthLFO2Lbl->setColour (TextEditor::textColourId, Colours::black);
    DepthLFO2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (WaveLFO2Lbl = new Label ("LFO 2 Wave Label",
                                                TRANS("Wave\n")));
    WaveLFO2Lbl->setFont (Font (15.00f, Font::plain));
    WaveLFO2Lbl->setJustificationType (Justification::centredLeft);
    WaveLFO2Lbl->setEditable (false, false, false);
    WaveLFO2Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    WaveLFO2Lbl->setColour (TextEditor::textColourId, Colours::black);
    WaveLFO2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (TempoSyncLFO1Btn = new TextButton ("LFO 1 Tempo Sync Button"));
    TempoSyncLFO1Btn->setButtonText (TRANS("Tempo Sync"));
    TempoSyncLFO1Btn->addListener (this);

    addAndMakeVisible (TempoSyncLFO2Btn = new TextButton ("LFO 2 Tempo Sync Button"));
    TempoSyncLFO2Btn->setButtonText (TRANS("Tempo Sync"));
    TempoSyncLFO2Btn->addListener (this);

    addAndMakeVisible (TempoNumerLFO1Sld = new Slider ("LFO 1 Tempo Numer Slider"));
    TempoNumerLFO1Sld->setRange (1, 4, 1);
    TempoNumerLFO1Sld->setSliderStyle (Slider::IncDecButtons);
    TempoNumerLFO1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoNumerLFO1Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0xffc8c8c8));
    TempoNumerLFO1Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    TempoNumerLFO1Sld->addListener (this);

    addAndMakeVisible (TempoDenomLFO1Sld = new Slider ("LFO 1 Tempo Denom Slider"));
    TempoDenomLFO1Sld->setRange (1, 32, 1);
    TempoDenomLFO1Sld->setSliderStyle (Slider::IncDecButtons);
    TempoDenomLFO1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoDenomLFO1Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0xffc8c8c8));
    TempoDenomLFO1Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    TempoDenomLFO1Sld->addListener (this);

    addAndMakeVisible (TempoNumerLFO2Sld = new Slider ("LFO 2 Tempo Numer Slider"));
    TempoNumerLFO2Sld->setRange (1, 4, 1);
    TempoNumerLFO2Sld->setSliderStyle (Slider::IncDecButtons);
    TempoNumerLFO2Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoNumerLFO2Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0xffc8c8c8));
    TempoNumerLFO2Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    TempoNumerLFO2Sld->addListener (this);

    addAndMakeVisible (TempoDenomLFO2Sld = new Slider ("LFO 2 Tempo Denom Slider"));
    TempoDenomLFO2Sld->setRange (1, 32, 1);
    TempoDenomLFO2Sld->setSliderStyle (Slider::IncDecButtons);
    TempoDenomLFO2Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoDenomLFO2Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0xffc8c8c8));
    TempoDenomLFO2Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    TempoDenomLFO2Sld->addListener (this);

    addAndMakeVisible (PhaseSyncLFO1Btn = new TextButton ("LFO 1 Phase Sync Button"));
    PhaseSyncLFO1Btn->setButtonText (TRANS("Phase Sync"));
    PhaseSyncLFO1Btn->addListener (this);

    addAndMakeVisible (PhaseSyncLFO2Btn = new TextButton ("LFO 2 Phase Sync Button"));
    PhaseSyncLFO2Btn->setButtonText (TRANS("Phase Sync"));
    PhaseSyncLFO2Btn->addListener (this);

    addAndMakeVisible (PhaseLFO1Sld = new Slider ("LFO 1 Phase Slider"));
    PhaseLFO1Sld->setRange (0, 1, 0.01);
    PhaseLFO1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PhaseLFO1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    PhaseLFO1Sld->setColour (Slider::thumbColourId, Colour (0xffbdffbb));
    PhaseLFO1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    PhaseLFO1Sld->addListener (this);

    addAndMakeVisible (PhaseLFO1Lbl = new Label ("LFO 1 Phase Label",
                                                 TRANS("Phase")));
    PhaseLFO1Lbl->setFont (Font (15.00f, Font::plain));
    PhaseLFO1Lbl->setJustificationType (Justification::centredLeft);
    PhaseLFO1Lbl->setEditable (false, false, false);
    PhaseLFO1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    PhaseLFO1Lbl->setColour (TextEditor::textColourId, Colours::black);
    PhaseLFO1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (PhaseLFO2Sld = new Slider ("LFO 2 Phase Slider"));
    PhaseLFO2Sld->setRange (0, 1, 0.01);
    PhaseLFO2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PhaseLFO2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    PhaseLFO2Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    PhaseLFO2Sld->addListener (this);

    addAndMakeVisible (PhaseLFO2Lbl = new Label ("LFO 2 Phase Label",
                                                 TRANS("Phase")));
    PhaseLFO2Lbl->setFont (Font (15.00f, Font::plain));
    PhaseLFO2Lbl->setJustificationType (Justification::centredLeft);
    PhaseLFO2Lbl->setEditable (false, false, false);
    PhaseLFO2Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    PhaseLFO2Lbl->setColour (TextEditor::textColourId, Colours::black);
    PhaseLFO2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (MOD1Group = new GroupComponent ("MOD 1 Group",
                                                       TRANS("MOD1")));

    addAndMakeVisible (DepthMOD1Sld = new Slider ("MOD 1 Depth Slider"));
    DepthMOD1Sld->setRange (0, 1, 0.01);
    DepthMOD1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    DepthMOD1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DepthMOD1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff0d));
    DepthMOD1Sld->addListener (this);

    addAndMakeVisible (FreqMOD1Sld = new Slider ("MOD 1 Freq Slider"));
    FreqMOD1Sld->setRange (0, 1, 0.01);
    FreqMOD1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    FreqMOD1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FreqMOD1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    FreqMOD1Sld->addListener (this);

    addAndMakeVisible (WaveMOD1Cmb = new ComboBox ("MOD 1 Wave"));
    WaveMOD1Cmb->setEditableText (false);
    WaveMOD1Cmb->setJustificationType (Justification::centredLeft);
    WaveMOD1Cmb->setTextWhenNothingSelected (String::empty);
    WaveMOD1Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    WaveMOD1Cmb->addItem (TRANS("Sine"), 1);
    WaveMOD1Cmb->addItem (TRANS("Square"), 2);
    WaveMOD1Cmb->addItem (TRANS("Saw"), 3);
    WaveMOD1Cmb->addListener (this);

    addAndMakeVisible (BypassMOD1Btn = new TextButton ("MOD 1 Bypass Button"));
    BypassMOD1Btn->setButtonText (TRANS("MOD 1"));
    BypassMOD1Btn->addListener (this);

    addAndMakeVisible (FreqMOD1Lbl = new Label ("MOD 1 Freq Label",
                                                TRANS("Rate")));
    FreqMOD1Lbl->setFont (Font (15.00f, Font::plain));
    FreqMOD1Lbl->setJustificationType (Justification::centredLeft);
    FreqMOD1Lbl->setEditable (false, false, false);
    FreqMOD1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    FreqMOD1Lbl->setColour (TextEditor::textColourId, Colours::black);
    FreqMOD1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (DepthMOD1Lbl = new Label ("MOD 1 Depth Label",
                                                 TRANS("Depth")));
    DepthMOD1Lbl->setFont (Font (15.00f, Font::plain));
    DepthMOD1Lbl->setJustificationType (Justification::centredLeft);
    DepthMOD1Lbl->setEditable (false, false, false);
    DepthMOD1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    DepthMOD1Lbl->setColour (TextEditor::textColourId, Colours::black);
    DepthMOD1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (WaveMOD1Lbl = new Label ("MOD 1 Wave Label",
                                                TRANS("Wave\n")));
    WaveMOD1Lbl->setFont (Font (15.00f, Font::plain));
    WaveMOD1Lbl->setJustificationType (Justification::centredLeft);
    WaveMOD1Lbl->setEditable (false, false, false);
    WaveMOD1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    WaveMOD1Lbl->setColour (TextEditor::textColourId, Colours::black);
    WaveMOD1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (TempoSyncMOD1Btn = new TextButton ("MOD 1 Tempo Sync Button"));
    TempoSyncMOD1Btn->setButtonText (TRANS("Tempo Sync"));
    TempoSyncMOD1Btn->addListener (this);

    addAndMakeVisible (TempoNumerMOD1Sld = new Slider ("MOD 1 Tempo Numer Slider"));
    TempoNumerMOD1Sld->setRange (1, 4, 1);
    TempoNumerMOD1Sld->setSliderStyle (Slider::IncDecButtons);
    TempoNumerMOD1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoNumerMOD1Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0xffc8c8c8));
    TempoNumerMOD1Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    TempoNumerMOD1Sld->addListener (this);

    addAndMakeVisible (TempoDenomMOD1Sld = new Slider ("MOD 1 Tempo Denom Slider"));
    TempoDenomMOD1Sld->setRange (1, 32, 1);
    TempoDenomMOD1Sld->setSliderStyle (Slider::IncDecButtons);
    TempoDenomMOD1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoDenomMOD1Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0xffc8c8c8));
    TempoDenomMOD1Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    TempoDenomMOD1Sld->addListener (this);

    addAndMakeVisible (PhaseSyncMOD1Btn = new TextButton ("MOD 1 Phase Sync Button"));
    PhaseSyncMOD1Btn->setButtonText (TRANS("Phase Sync"));
    PhaseSyncMOD1Btn->addListener (this);

    addAndMakeVisible (PhaseMOD1Sld = new Slider ("MOD 1 Phase Slider"));
    PhaseMOD1Sld->setRange (0, 1, 0.01);
    PhaseMOD1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PhaseMOD1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    PhaseMOD1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    PhaseMOD1Sld->addListener (this);

    addAndMakeVisible (PhaseMOD1Lbl = new Label ("MOD 1 Phase Label",
                                                 TRANS("Phase")));
    PhaseMOD1Lbl->setFont (Font (15.00f, Font::plain));
    PhaseMOD1Lbl->setJustificationType (Justification::centredLeft);
    PhaseMOD1Lbl->setEditable (false, false, false);
    PhaseMOD1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    PhaseMOD1Lbl->setColour (TextEditor::textColourId, Colours::black);
    PhaseMOD1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (MOD2Group = new GroupComponent ("MOD 2 Group",
                                                       TRANS("MOD2")));

    addAndMakeVisible (DepthMOD2Sld = new Slider ("MOD 2 Depth Slider"));
    DepthMOD2Sld->setRange (0, 1, 0.01);
    DepthMOD2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    DepthMOD2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DepthMOD2Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    DepthMOD2Sld->addListener (this);

    addAndMakeVisible (FreqMOD2Sld = new Slider ("MOD 2 Freq Slider"));
    FreqMOD2Sld->setRange (0, 1, 0.01);
    FreqMOD2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    FreqMOD2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FreqMOD2Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    FreqMOD2Sld->addListener (this);

    addAndMakeVisible (WaveMOD2Cmb = new ComboBox ("MOD 2 Wave"));
    WaveMOD2Cmb->setEditableText (false);
    WaveMOD2Cmb->setJustificationType (Justification::centredLeft);
    WaveMOD2Cmb->setTextWhenNothingSelected (String::empty);
    WaveMOD2Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    WaveMOD2Cmb->addItem (TRANS("Sine"), 1);
    WaveMOD2Cmb->addItem (TRANS("Square"), 2);
    WaveMOD2Cmb->addItem (TRANS("Saw"), 3);
    WaveMOD2Cmb->addListener (this);

    addAndMakeVisible (BypassMOD2Btn = new TextButton ("MOD 2 Bypass Button"));
    BypassMOD2Btn->setButtonText (TRANS("MOD 2"));
    BypassMOD2Btn->addListener (this);

    addAndMakeVisible (FreqMOD2Lbl = new Label ("MOD 2 Freq Label",
                                                TRANS("Rate")));
    FreqMOD2Lbl->setFont (Font (15.00f, Font::plain));
    FreqMOD2Lbl->setJustificationType (Justification::centredLeft);
    FreqMOD2Lbl->setEditable (false, false, false);
    FreqMOD2Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    FreqMOD2Lbl->setColour (TextEditor::textColourId, Colours::black);
    FreqMOD2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (DepthMOD2Lbl = new Label ("MOD 2 Depth Label",
                                                 TRANS("Depth")));
    DepthMOD2Lbl->setFont (Font (15.00f, Font::plain));
    DepthMOD2Lbl->setJustificationType (Justification::centredLeft);
    DepthMOD2Lbl->setEditable (false, false, false);
    DepthMOD2Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    DepthMOD2Lbl->setColour (TextEditor::textColourId, Colours::black);
    DepthMOD2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (WaveMOD2Lbl = new Label ("MOD 2 Wave Label",
                                                TRANS("Wave\n")));
    WaveMOD2Lbl->setFont (Font (15.00f, Font::plain));
    WaveMOD2Lbl->setJustificationType (Justification::centredLeft);
    WaveMOD2Lbl->setEditable (false, false, false);
    WaveMOD2Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    WaveMOD2Lbl->setColour (TextEditor::textColourId, Colours::black);
    WaveMOD2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (TempoSyncMOD2Btn = new TextButton ("MOD 2 Tempo Sync Button"));
    TempoSyncMOD2Btn->setButtonText (TRANS("Tempo Sync"));
    TempoSyncMOD2Btn->addListener (this);

    addAndMakeVisible (TempoNumerMOD2Sld = new Slider ("MOD 2 Tempo Numer Slider"));
    TempoNumerMOD2Sld->setRange (1, 4, 1);
    TempoNumerMOD2Sld->setSliderStyle (Slider::IncDecButtons);
    TempoNumerMOD2Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoNumerMOD2Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0xffc8c8c8));
    TempoNumerMOD2Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x09808080));
    TempoNumerMOD2Sld->addListener (this);

    addAndMakeVisible (TempoDenomMOD2Sld = new Slider ("MOD 2 Tempo Denom Slider"));
    TempoDenomMOD2Sld->setRange (1, 32, 1);
    TempoDenomMOD2Sld->setSliderStyle (Slider::IncDecButtons);
    TempoDenomMOD2Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoDenomMOD2Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0xffc8c8c8));
    TempoDenomMOD2Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    TempoDenomMOD2Sld->addListener (this);

    addAndMakeVisible (PhaseSyncMOD2Btn = new TextButton ("MOD 2 Phase Sync Button"));
    PhaseSyncMOD2Btn->setButtonText (TRANS("Phase Sync"));
    PhaseSyncMOD2Btn->addListener (this);

    addAndMakeVisible (PhaseMOD2Sld = new Slider ("MOD 2 Phase Slider"));
    PhaseMOD2Sld->setRange (0, 1, 0.01);
    PhaseMOD2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PhaseMOD2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    PhaseMOD2Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    PhaseMOD2Sld->addListener (this);

    addAndMakeVisible (PhaseMOD2Lbl = new Label ("MOD 2 Phase Label",
                                                 TRANS("Phase")));
    PhaseMOD2Lbl->setFont (Font (15.00f, Font::plain));
    PhaseMOD2Lbl->setJustificationType (Justification::centredLeft);
    PhaseMOD2Lbl->setEditable (false, false, false);
    PhaseMOD2Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    PhaseMOD2Lbl->setColour (TextEditor::textColourId, Colours::black);
    PhaseMOD2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (StereoBtn = new TextButton ("Stereo Button"));
    StereoBtn->setButtonText (TRANS("Stereo"));
    StereoBtn->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (675, 340);


    //[Constructor] You can add your own custom stuff here..
    startTimer(200);

    LookAndFeel::setDefaultLookAndFeel(&customLookAndFeel);

    TempoNumerLFO1Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);
    TempoDenomLFO1Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);

    TempoNumerLFO2Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);
    TempoDenomLFO2Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);

    TempoNumerMOD1Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);
    TempoDenomMOD1Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);

    TempoNumerMOD2Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);
    TempoDenomMOD2Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);

    RichterAudioProcessor* ourProcessor {getProcessor()};
    StereoBtn->setEnabled(ourProcessor->getNumOutputChannels() == 2);
    //[/Constructor]
}

RichterAudioProcessorEditor::~RichterAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    LFO1Group = nullptr;
    DepthLFO1Sld = nullptr;
    FreqLFO1Sld = nullptr;
    WaveLFO1Cmb = nullptr;
    DepthModLFO1Sld = nullptr;
    FreqModLFO1Sld = nullptr;
    MasterVolSld = nullptr;
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


    //[Destructor]. You can add your own custom destruction code here..
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

    LFO1Group->setBounds (56, 72, 280, 128);
    DepthLFO1Sld->setBounds (136, 120, 32, 24);
    FreqLFO1Sld->setBounds (80, 120, 32, 24);
    WaveLFO1Cmb->setBounds (240, 128, 80, 24);
    DepthModLFO1Sld->setBounds (144, 168, 16, 16);
    FreqModLFO1Sld->setBounds (88, 168, 16, 16);
    MasterVolSld->setBounds (56, 48, 480, 24);
    BypassLFO1Btn->setBounds (264, 88, 56, 24);
    FreqLFO1Lbl->setBounds (78, 144, 40, 24);
    DepthLFO1Lbl->setBounds (130, 144, 46, 24);
    WaveLFO1Lbl->setBounds (256, 160, 46, 24);
    LFO2Group->setBounds (344, 72, 280, 128);
    DepthLFO2Sld->setBounds (424, 120, 32, 24);
    FreqLFO2Sld->setBounds (368, 120, 32, 24);
    WaveLFO2Cmb->setBounds (528, 128, 80, 24);
    DepthModLFO2Sld->setBounds (432, 168, 16, 16);
    FreqModLFO2Sld->setBounds (376, 168, 16, 16);
    BypassLFO2Btn->setBounds (552, 88, 56, 24);
    FreqLFO2Lbl->setBounds (366, 144, 40, 24);
    DepthLFO2Lbl->setBounds (418, 144, 46, 24);
    WaveLFO2Lbl->setBounds (544, 160, 46, 24);
    TempoSyncLFO1Btn->setBounds (72, 96, 56, 16);
    TempoSyncLFO2Btn->setBounds (360, 96, 56, 16);
    TempoNumerLFO1Sld->setBounds (72, 128, 56, 16);
    TempoDenomLFO1Sld->setBounds (72, 160, 56, 16);
    TempoNumerLFO2Sld->setBounds (360, 128, 56, 16);
    TempoDenomLFO2Sld->setBounds (360, 160, 56, 16);
    PhaseSyncLFO1Btn->setBounds (184, 96, 56, 16);
    PhaseSyncLFO2Btn->setBounds (472, 96, 56, 16);
    PhaseLFO1Sld->setBounds (192, 120, 32, 24);
    PhaseLFO1Lbl->setBounds (184, 144, 46, 24);
    PhaseLFO2Sld->setBounds (480, 120, 32, 24);
    PhaseLFO2Lbl->setBounds (472, 144, 46, 24);
    MOD1Group->setBounds (56, 200, 280, 128);
    DepthMOD1Sld->setBounds (136, 248, 32, 24);
    FreqMOD1Sld->setBounds (80, 248, 32, 24);
    WaveMOD1Cmb->setBounds (240, 256, 80, 24);
    BypassMOD1Btn->setBounds (264, 216, 56, 24);
    FreqMOD1Lbl->setBounds (78, 272, 40, 24);
    DepthMOD1Lbl->setBounds (130, 272, 46, 24);
    WaveMOD1Lbl->setBounds (256, 288, 46, 24);
    TempoSyncMOD1Btn->setBounds (72, 224, 56, 16);
    TempoNumerMOD1Sld->setBounds (72, 256, 56, 16);
    TempoDenomMOD1Sld->setBounds (72, 288, 56, 16);
    PhaseSyncMOD1Btn->setBounds (184, 224, 56, 16);
    PhaseMOD1Sld->setBounds (192, 248, 32, 24);
    PhaseMOD1Lbl->setBounds (184, 272, 46, 24);
    MOD2Group->setBounds (344, 200, 280, 128);
    DepthMOD2Sld->setBounds (424, 248, 32, 24);
    FreqMOD2Sld->setBounds (368, 248, 32, 24);
    WaveMOD2Cmb->setBounds (528, 256, 80, 24);
    BypassMOD2Btn->setBounds (552, 216, 56, 24);
    FreqMOD2Lbl->setBounds (366, 272, 40, 24);
    DepthMOD2Lbl->setBounds (418, 272, 46, 24);
    WaveMOD2Lbl->setBounds (544, 288, 46, 24);
    TempoSyncMOD2Btn->setBounds (360, 224, 56, 16);
    TempoNumerMOD2Sld->setBounds (360, 256, 56, 16);
    TempoDenomMOD2Sld->setBounds (360, 288, 56, 16);
    PhaseSyncMOD2Btn->setBounds (472, 224, 56, 16);
    PhaseMOD2Sld->setBounds (480, 248, 32, 24);
    PhaseMOD2Lbl->setBounds (472, 272, 46, 24);
    StereoBtn->setBounds (544, 48, 72, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void RichterAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    RichterAudioProcessor* ourProcessor {getProcessor()};
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == DepthLFO1Sld)
    {
        //[UserSliderCode_DepthLFO1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::depthLFO1, static_cast<float>(DepthLFO1Sld->getValue()));
        //[/UserSliderCode_DepthLFO1Sld]
    }
    else if (sliderThatWasMoved == FreqLFO1Sld)
    {
        //[UserSliderCode_FreqLFO1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::freqLFO1, static_cast<float>(FreqLFO1Sld->getValue()));
        //[/UserSliderCode_FreqLFO1Sld]
    }
    else if (sliderThatWasMoved == DepthModLFO1Sld)
    {
        //[UserSliderCode_DepthModLFO1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::depthModLFO1, static_cast<float>(DepthModLFO1Sld->getValue()));
        //[/UserSliderCode_DepthModLFO1Sld]
    }
    else if (sliderThatWasMoved == FreqModLFO1Sld)
    {
        //[UserSliderCode_FreqModLFO1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::freqModLFO1, static_cast<float>(FreqModLFO1Sld->getValue()));
        //[/UserSliderCode_FreqModLFO1Sld]
    }
    else if (sliderThatWasMoved == MasterVolSld)
    {
        //[UserSliderCode_MasterVolSld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::masterVol, static_cast<float>(MasterVolSld->getValue()));
        //[/UserSliderCode_MasterVolSld]
    }
    else if (sliderThatWasMoved == DepthLFO2Sld)
    {
        //[UserSliderCode_DepthLFO2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::depthLFO2, static_cast<float>(DepthLFO2Sld->getValue()));
        //[/UserSliderCode_DepthLFO2Sld]
    }
    else if (sliderThatWasMoved == FreqLFO2Sld)
    {
        //[UserSliderCode_FreqLFO2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::freqLFO2, static_cast<float>(FreqLFO2Sld->getValue()));
        //[/UserSliderCode_FreqLFO2Sld]
    }
    else if (sliderThatWasMoved == DepthModLFO2Sld)
    {
        //[UserSliderCode_DepthModLFO2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::depthModLFO2, static_cast<float>(DepthModLFO2Sld->getValue()));
        //[/UserSliderCode_DepthModLFO2Sld]
    }
    else if (sliderThatWasMoved == FreqModLFO2Sld)
    {
        //[UserSliderCode_FreqModLFO2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::freqModLFO2, static_cast<float>(FreqModLFO2Sld->getValue()));
        //[/UserSliderCode_FreqModLFO2Sld]
    }
    else if (sliderThatWasMoved == TempoNumerLFO1Sld)
    {
        //[UserSliderCode_TempoNumerLFO1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoNumerLFO1, static_cast<float>(TempoNumerLFO1Sld->getValue()));
        //[/UserSliderCode_TempoNumerLFO1Sld]
    }
    else if (sliderThatWasMoved == TempoDenomLFO1Sld)
    {
        //[UserSliderCode_TempoDenomLFO1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoDenomLFO1, static_cast<float>(TempoDenomLFO1Sld->getValue()));
        //[/UserSliderCode_TempoDenomLFO1Sld]
    }
    else if (sliderThatWasMoved == TempoNumerLFO2Sld)
    {
        //[UserSliderCode_TempoNumerLFO2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoNumerLFO2, static_cast<float>(TempoNumerLFO2Sld->getValue()));
        //[/UserSliderCode_TempoNumerLFO2Sld]
    }
    else if (sliderThatWasMoved == TempoDenomLFO2Sld)
    {
        //[UserSliderCode_TempoDenomLFO2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoDenomLFO2, static_cast<float>(TempoDenomLFO2Sld->getValue()));
        //[/UserSliderCode_TempoDenomLFO2Sld]
    }
    else if (sliderThatWasMoved == PhaseLFO1Sld)
    {
        //[UserSliderCode_PhaseLFO1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::phaseLFO1, static_cast<float>(PhaseLFO1Sld->getValue()));
        //[/UserSliderCode_PhaseLFO1Sld]
    }
    else if (sliderThatWasMoved == PhaseLFO2Sld)
    {
        //[UserSliderCode_PhaseLFO2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::phaseLFO2, static_cast<float>(PhaseLFO2Sld->getValue()));
        //[/UserSliderCode_PhaseLFO2Sld]
    }
    else if (sliderThatWasMoved == DepthMOD1Sld)
    {
        //[UserSliderCode_DepthMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::depthMOD1, static_cast<float>(DepthMOD1Sld->getValue()));
        //[/UserSliderCode_DepthMOD1Sld]
    }
    else if (sliderThatWasMoved == FreqMOD1Sld)
    {
        //[UserSliderCode_FreqMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::freqMOD1, static_cast<float>(FreqMOD1Sld->getValue()));
        //[/UserSliderCode_FreqMOD1Sld]
    }
    else if (sliderThatWasMoved == TempoNumerMOD1Sld)
    {
        //[UserSliderCode_TempoNumerMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoNumerMOD1, static_cast<float>(TempoNumerMOD1Sld->getValue()));
        //[/UserSliderCode_TempoNumerMOD1Sld]
    }
    else if (sliderThatWasMoved == TempoDenomMOD1Sld)
    {
        //[UserSliderCode_TempoDenomMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoDenomMOD1, static_cast<float>(TempoDenomMOD1Sld->getValue()));
        //[/UserSliderCode_TempoDenomMOD1Sld]
    }
    else if (sliderThatWasMoved == PhaseMOD1Sld)
    {
        //[UserSliderCode_PhaseMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::phaseMOD1, static_cast<float>(PhaseMOD1Sld->getValue()));
        //[/UserSliderCode_PhaseMOD1Sld]
    }
    else if (sliderThatWasMoved == DepthMOD2Sld)
    {
        //[UserSliderCode_DepthMOD2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::depthMOD2, static_cast<float>(DepthMOD2Sld->getValue()));
        //[/UserSliderCode_DepthMOD2Sld]
    }
    else if (sliderThatWasMoved == FreqMOD2Sld)
    {
        //[UserSliderCode_FreqMOD2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::freqMOD2, static_cast<float>(FreqMOD2Sld->getValue()));
        //[/UserSliderCode_FreqMOD2Sld]
    }
    else if (sliderThatWasMoved == TempoNumerMOD2Sld)
    {
        //[UserSliderCode_TempoNumerMOD2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoNumerMOD2, static_cast<float>(TempoNumerMOD2Sld->getValue()));
        //[/UserSliderCode_TempoNumerMOD2Sld]
    }
    else if (sliderThatWasMoved == TempoDenomMOD2Sld)
    {
        //[UserSliderCode_TempoDenomMOD2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoDenomMOD1, static_cast<float>(TempoDenomMOD2Sld->getValue()));
        //[/UserSliderCode_TempoDenomMOD2Sld]
    }
    else if (sliderThatWasMoved == PhaseMOD2Sld)
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

    if (comboBoxThatHasChanged == WaveLFO1Cmb)
    {
        //[UserComboBoxCode_WaveLFO1Cmb] -- add your combo box handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::waveLFO1, static_cast<float>(WaveLFO1Cmb->getSelectedId()));
        //[/UserComboBoxCode_WaveLFO1Cmb]
    }
    else if (comboBoxThatHasChanged == WaveLFO2Cmb)
    {
        //[UserComboBoxCode_WaveLFO2Cmb] -- add your combo box handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::waveLFO2, static_cast<float>(WaveLFO2Cmb->getSelectedId()));
        //[/UserComboBoxCode_WaveLFO2Cmb]
    }
    else if (comboBoxThatHasChanged == WaveMOD1Cmb)
    {
        //[UserComboBoxCode_WaveMOD1Cmb] -- add your combo box handling code here..
        ourProcessor->setParameter(RichterAudioProcessor::waveMOD1, static_cast<float>(WaveMOD1Cmb->getSelectedId()));
        //[/UserComboBoxCode_WaveMOD1Cmb]
    }
    else if (comboBoxThatHasChanged == WaveMOD2Cmb)
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

    if (buttonThatWasClicked == BypassLFO1Btn)
    {
        //[UserButtonCode_BypassLFO1Btn] -- add your button handler code here..
        Logger::outputDebugString("getToggleState: " + String(BypassLFO1Btn->getToggleState()));
        ourProcessor->setParameter(RichterAudioProcessor::bypassSwitchLFO1, static_cast<float>(BypassLFO1Btn->getToggleState()));
        //[/UserButtonCode_BypassLFO1Btn]
    }
    else if (buttonThatWasClicked == BypassLFO2Btn)
    {
        //[UserButtonCode_BypassLFO2Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::bypassSwitchLFO2, static_cast<float>(BypassLFO2Btn->getToggleState()));
        //[/UserButtonCode_BypassLFO2Btn]
    }
    else if (buttonThatWasClicked == TempoSyncLFO1Btn)
    {
        //[UserButtonCode_TempoSyncLFO1Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoSyncLFO1, static_cast<float>(TempoSyncLFO1Btn->getToggleState()));
        //[/UserButtonCode_TempoSyncLFO1Btn]
    }
    else if (buttonThatWasClicked == TempoSyncLFO2Btn)
    {
        //[UserButtonCode_TempoSyncLFO2Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoSyncLFO2, static_cast<float>(TempoSyncLFO2Btn->getToggleState()));
        //[/UserButtonCode_TempoSyncLFO2Btn]
    }
    else if (buttonThatWasClicked == PhaseSyncLFO1Btn)
    {
        //[UserButtonCode_PhaseSyncLFO1Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::phaseSyncLFO1, static_cast<float>(PhaseSyncLFO1Btn->getToggleState()));
        //[/UserButtonCode_PhaseSyncLFO1Btn]
    }
    else if (buttonThatWasClicked == PhaseSyncLFO2Btn)
    {
        //[UserButtonCode_PhaseSyncLFO2Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::phaseSyncLFO2, static_cast<float>(PhaseSyncLFO2Btn->getToggleState()));
        //[/UserButtonCode_PhaseSyncLFO2Btn]
    }
    else if (buttonThatWasClicked == BypassMOD1Btn)
    {
        //[UserButtonCode_BypassMOD1Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::bypassSwitchMOD1, static_cast<float>(BypassMOD1Btn->getToggleState()));
        //[/UserButtonCode_BypassMOD1Btn]
    }
    else if (buttonThatWasClicked == TempoSyncMOD1Btn)
    {
        //[UserButtonCode_TempoSyncMOD1Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoSyncMOD1, static_cast<float>(TempoSyncMOD1Btn->getToggleState()));
        //[/UserButtonCode_TempoSyncMOD1Btn]
    }
    else if (buttonThatWasClicked == PhaseSyncMOD1Btn)
    {
        //[UserButtonCode_PhaseSyncMOD1Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::phaseSyncMOD1, static_cast<float>(PhaseSyncMOD1Btn->getToggleState()));
        //[/UserButtonCode_PhaseSyncMOD1Btn]
    }
    else if (buttonThatWasClicked == BypassMOD2Btn)
    {
        //[UserButtonCode_BypassMOD2Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::bypassSwitchMOD2, static_cast<float>(BypassMOD2Btn->getToggleState()));
        //[/UserButtonCode_BypassMOD2Btn]
    }
    else if (buttonThatWasClicked == TempoSyncMOD2Btn)
    {
        //[UserButtonCode_TempoSyncMOD2Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::tempoSyncMOD2, static_cast<float>(TempoSyncMOD2Btn->getToggleState()));
        //[/UserButtonCode_TempoSyncMOD2Btn]
    }
    else if (buttonThatWasClicked == PhaseSyncMOD2Btn)
    {
        //[UserButtonCode_PhaseSyncMOD2Btn] -- add your button handler code here..
        ourProcessor->setParameter(RichterAudioProcessor::phaseSyncMOD2, static_cast<float>(PhaseSyncMOD2Btn->getToggleState()));
        //[/UserButtonCode_PhaseSyncMOD2Btn]
    }
    else if (buttonThatWasClicked == StereoBtn)
    {
        //[UserButtonCode_StereoBtn] -- add your button handler code here..
        Logger::outputDebugString("onclick getToggleState: " + String(StereoBtn->getToggleState()));
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

    if (ourProcessor->NeedsUIUpdate()) {
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
        MasterVolSld->setValue(ourProcessor->getParameter(RichterAudioProcessor::masterVol), dontSendNotification);


        Logger::outputDebugString("refresh getToggleState: " + String(StereoBtn->getToggleState()));

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

        // Toggle visibility for rate controls depending on tempo sync
        if (TempoSyncLFO1Btn->getToggleState()) {
            FreqLFO1Sld->setVisible(false);
            FreqModLFO1Sld->setVisible(false);
            FreqLFO1Lbl->setVisible(false);
            TempoNumerLFO1Sld->setVisible(true);
            TempoDenomLFO1Sld->setVisible(true);
        } else {
            FreqLFO1Sld->setVisible(true);
            FreqModLFO1Sld->setVisible(true);
            FreqLFO1Lbl->setVisible(true);
            TempoNumerLFO1Sld->setVisible(false);
            TempoDenomLFO1Sld->setVisible(false);
        }

        if (TempoSyncLFO2Btn->getToggleState()) {
            FreqLFO2Sld->setVisible(false);
            FreqModLFO2Sld->setVisible(false);
            FreqLFO2Lbl->setVisible(false);
            TempoNumerLFO2Sld->setVisible(true);
            TempoDenomLFO2Sld->setVisible(true);
        } else {
            FreqLFO2Sld->setVisible(true);
            FreqModLFO2Sld->setVisible(true);
            FreqLFO2Lbl->setVisible(true);
            TempoNumerLFO2Sld->setVisible(false);
            TempoDenomLFO2Sld->setVisible(false);
        }

        if (TempoSyncMOD1Btn->getToggleState()) {
            FreqMOD1Sld->setVisible(false);
            FreqMOD1Lbl->setVisible(false);
            TempoNumerMOD1Sld->setVisible(true);
            TempoDenomMOD1Sld->setVisible(true);
        } else {
            FreqMOD1Sld->setVisible(true);
            FreqMOD1Lbl->setVisible(true);
            TempoNumerMOD1Sld->setVisible(false);
            TempoDenomMOD1Sld->setVisible(false);
        }

        if (TempoSyncMOD2Btn->getToggleState()) {
            FreqMOD2Sld->setVisible(false);
            FreqMOD2Lbl->setVisible(false);
            TempoNumerMOD2Sld->setVisible(true);
            TempoDenomMOD2Sld->setVisible(true);
        } else {
            FreqMOD2Sld->setVisible(true);
            FreqMOD2Lbl->setVisible(true);
            TempoNumerMOD2Sld->setVisible(false);
            TempoDenomMOD2Sld->setVisible(false);
        }
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="RichterAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="RichterAudioProcessor&amp; ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="675" initialHeight="340">
  <BACKGROUND backgroundColour="ffffffff"/>
  <GROUPCOMPONENT name="LFO 1 Group" id="2a8643bc712454bf" memberName="LFO1Group"
                  virtualName="" explicitFocusOrder="0" pos="56 72 280 128" textcol="ff000000"
                  title="LFO1"/>
  <SLIDER name="LFO 1 Depth Slider" id="98ad3308f709f25c" memberName="DepthLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="136 120 32 24" rotarysliderfill="7f00ff03"
          min="0" max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="LFO 1 Freq Slider" id="94530d5c05e4a382" memberName="FreqLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="80 120 32 24" rotarysliderfill="7f00ff03"
          min="0" max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="LFO 1 Wave" id="6343a9cc42a2eda5" memberName="WaveLFO1Cmb"
            virtualName="" explicitFocusOrder="0" pos="240 128 80 24" editable="0"
            layout="33" items="Sine&#10;Square&#10;Saw" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="LFO 1 Depth Mod Slider" id="9a3f86cb168e586e" memberName="DepthModLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="144 168 16 16" rotarysliderfill="7f00ff03"
          min="0" max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="LFO 1 Freq Mod Slider" id="b0488ea613d92dcf" memberName="FreqModLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="88 168 16 16" rotarysliderfill="7f00ff03"
          min="0" max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="65acc0b358aa2541" memberName="MasterVolSld"
          virtualName="" explicitFocusOrder="0" pos="56 48 480 24" min="0"
          max="1" int="0.010000000000000000208" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="LFO 1 Bypass Button" id="27660ce1c9366ec3" memberName="BypassLFO1Btn"
              virtualName="" explicitFocusOrder="0" pos="264 88 56 24" buttonText="LFO 1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="LFO 1 Freq Label" id="29836e1fe4622869" memberName="FreqLFO1Lbl"
         virtualName="" explicitFocusOrder="0" pos="78 144 40 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="LFO 1 Depth Label" id="fa48be8976dad123" memberName="DepthLFO1Lbl"
         virtualName="" explicitFocusOrder="0" pos="130 144 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Depth" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="LFO 1 Wave Label" id="75dbcd5f6a0cc700" memberName="WaveLFO1Lbl"
         virtualName="" explicitFocusOrder="0" pos="256 160 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Wave&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <GROUPCOMPONENT name="LFO 2 Group" id="35e8ad61c86b603a" memberName="LFO2Group"
                  virtualName="" explicitFocusOrder="0" pos="344 72 280 128" title="LFO2"/>
  <SLIDER name="LFO 2 Depth Slider" id="2596adc2e61cd58e" memberName="DepthLFO2Sld"
          virtualName="" explicitFocusOrder="0" pos="424 120 32 24" rotarysliderfill="7f00ff03"
          min="0" max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="LFO 2 Freq Slider" id="f5dbcdc53c502e69" memberName="FreqLFO2Sld"
          virtualName="" explicitFocusOrder="0" pos="368 120 32 24" rotarysliderfill="7f00ff03"
          min="0" max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="LFO 2 Wave" id="b76d5189aafe8e3f" memberName="WaveLFO2Cmb"
            virtualName="" explicitFocusOrder="0" pos="528 128 80 24" editable="0"
            layout="33" items="Sine&#10;Square&#10;Saw" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="LFO 2 Depth Mod Slider" id="4a524c9e1974186c" memberName="DepthModLFO2Sld"
          virtualName="" explicitFocusOrder="0" pos="432 168 16 16" rotarysliderfill="7f00ff03"
          min="0" max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="LFO 2 Freq Mod Slider" id="e49bd74bef8aaca1" memberName="FreqModLFO2Sld"
          virtualName="" explicitFocusOrder="0" pos="376 168 16 16" rotarysliderfill="7f00ff03"
          min="0" max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="LFO 2 Bypass Button" id="74a3a05dda891f9c" memberName="BypassLFO2Btn"
              virtualName="" explicitFocusOrder="0" pos="552 88 56 24" buttonText="LFO 2"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="LFO 2 Freq Label" id="5463cd286934c4bc" memberName="FreqLFO2Lbl"
         virtualName="" explicitFocusOrder="0" pos="366 144 40 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="LFO 2 Depth Label" id="39dd59a998ec443" memberName="DepthLFO2Lbl"
         virtualName="" explicitFocusOrder="0" pos="418 144 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Depth" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="LFO 2 Wave Label" id="e01fc09efde6d339" memberName="WaveLFO2Lbl"
         virtualName="" explicitFocusOrder="0" pos="544 160 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Wave&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="LFO 1 Tempo Sync Button" id="95825bc0b3290b8b" memberName="TempoSyncLFO1Btn"
              virtualName="" explicitFocusOrder="0" pos="72 96 56 16" buttonText="Tempo Sync"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="LFO 2 Tempo Sync Button" id="3a20b52dc2308f55" memberName="TempoSyncLFO2Btn"
              virtualName="" explicitFocusOrder="0" pos="360 96 56 16" buttonText="Tempo Sync"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="LFO 1 Tempo Numer Slider" id="ae3b2cb5fc40f879" memberName="TempoNumerLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="72 128 56 16" textboxbkgd="ffc8c8c8"
          textboxoutline="808080" min="1" max="4" int="1" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="LFO 1 Tempo Denom Slider" id="79fb8b0e645e1976" memberName="TempoDenomLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="72 160 56 16" textboxbkgd="ffc8c8c8"
          textboxoutline="808080" min="1" max="32" int="1" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="LFO 2 Tempo Numer Slider" id="7ef07d530a2439f7" memberName="TempoNumerLFO2Sld"
          virtualName="" explicitFocusOrder="0" pos="360 128 56 16" textboxbkgd="ffc8c8c8"
          textboxoutline="808080" min="1" max="4" int="1" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="LFO 2 Tempo Denom Slider" id="684fae94c6ad39f8" memberName="TempoDenomLFO2Sld"
          virtualName="" explicitFocusOrder="0" pos="360 160 56 16" textboxbkgd="ffc8c8c8"
          textboxoutline="808080" min="1" max="32" int="1" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="LFO 1 Phase Sync Button" id="1df73348199bbe85" memberName="PhaseSyncLFO1Btn"
              virtualName="" explicitFocusOrder="0" pos="184 96 56 16" buttonText="Phase Sync"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="LFO 2 Phase Sync Button" id="6956f3f885f5801d" memberName="PhaseSyncLFO2Btn"
              virtualName="" explicitFocusOrder="0" pos="472 96 56 16" buttonText="Phase Sync"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="LFO 1 Phase Slider" id="1fa393dc85f550ee" memberName="PhaseLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="192 120 32 24" thumbcol="ffbdffbb"
          rotarysliderfill="7f00ff03" min="0" max="1" int="0.010000000000000000208"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="LFO 1 Phase Label" id="e8d899c4a3a19f8" memberName="PhaseLFO1Lbl"
         virtualName="" explicitFocusOrder="0" pos="184 144 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Phase" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="LFO 2 Phase Slider" id="df30ce6c91b8975b" memberName="PhaseLFO2Sld"
          virtualName="" explicitFocusOrder="0" pos="480 120 32 24" rotarysliderfill="7f00ff03"
          min="0" max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="LFO 2 Phase Label" id="5fd532cc21a16f51" memberName="PhaseLFO2Lbl"
         virtualName="" explicitFocusOrder="0" pos="472 144 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Phase" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <GROUPCOMPONENT name="MOD 1 Group" id="a2c7412d0fb46a58" memberName="MOD1Group"
                  virtualName="" explicitFocusOrder="0" pos="56 200 280 128" title="MOD1"/>
  <SLIDER name="MOD 1 Depth Slider" id="499f6451911662cc" memberName="DepthMOD1Sld"
          virtualName="" explicitFocusOrder="0" pos="136 248 32 24" rotarysliderfill="7f00ff0d"
          min="0" max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="MOD 1 Freq Slider" id="1d9800ca18cf5bba" memberName="FreqMOD1Sld"
          virtualName="" explicitFocusOrder="0" pos="80 248 32 24" rotarysliderfill="7f00ff03"
          min="0" max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="MOD 1 Wave" id="370e5062e67cf738" memberName="WaveMOD1Cmb"
            virtualName="" explicitFocusOrder="0" pos="240 256 80 24" editable="0"
            layout="33" items="Sine&#10;Square&#10;Saw" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="MOD 1 Bypass Button" id="cd667ff923e74db5" memberName="BypassMOD1Btn"
              virtualName="" explicitFocusOrder="0" pos="264 216 56 24" buttonText="MOD 1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="MOD 1 Freq Label" id="dabfca26c640fd58" memberName="FreqMOD1Lbl"
         virtualName="" explicitFocusOrder="0" pos="78 272 40 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="MOD 1 Depth Label" id="77092a4a55225c68" memberName="DepthMOD1Lbl"
         virtualName="" explicitFocusOrder="0" pos="130 272 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Depth" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="MOD 1 Wave Label" id="7eb50c1a44463588" memberName="WaveMOD1Lbl"
         virtualName="" explicitFocusOrder="0" pos="256 288 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Wave&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="MOD 1 Tempo Sync Button" id="b43affdb8ac7bb90" memberName="TempoSyncMOD1Btn"
              virtualName="" explicitFocusOrder="0" pos="72 224 56 16" buttonText="Tempo Sync"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="MOD 1 Tempo Numer Slider" id="6c49dac77f3e6f4b" memberName="TempoNumerMOD1Sld"
          virtualName="" explicitFocusOrder="0" pos="72 256 56 16" textboxbkgd="ffc8c8c8"
          textboxoutline="808080" min="1" max="4" int="1" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="MOD 1 Tempo Denom Slider" id="a116d9c60bf4c7b5" memberName="TempoDenomMOD1Sld"
          virtualName="" explicitFocusOrder="0" pos="72 288 56 16" textboxbkgd="ffc8c8c8"
          textboxoutline="808080" min="1" max="32" int="1" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="MOD 1 Phase Sync Button" id="4509e154e4918174" memberName="PhaseSyncMOD1Btn"
              virtualName="" explicitFocusOrder="0" pos="184 224 56 16" buttonText="Phase Sync"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="MOD 1 Phase Slider" id="3f1ef3d10c303bac" memberName="PhaseMOD1Sld"
          virtualName="" explicitFocusOrder="0" pos="192 248 32 24" rotarysliderfill="7f00ff03"
          min="0" max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="MOD 1 Phase Label" id="af1abf98d305cb5c" memberName="PhaseMOD1Lbl"
         virtualName="" explicitFocusOrder="0" pos="184 272 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Phase" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <GROUPCOMPONENT name="MOD 2 Group" id="384e0ba59bb5f2ff" memberName="MOD2Group"
                  virtualName="" explicitFocusOrder="0" pos="344 200 280 128" title="MOD2"/>
  <SLIDER name="MOD 2 Depth Slider" id="8c1762ee0dd0d28a" memberName="DepthMOD2Sld"
          virtualName="" explicitFocusOrder="0" pos="424 248 32 24" rotarysliderfill="7f00ff03"
          min="0" max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="MOD 2 Freq Slider" id="362166b8c676eba4" memberName="FreqMOD2Sld"
          virtualName="" explicitFocusOrder="0" pos="368 248 32 24" rotarysliderfill="7f00ff03"
          min="0" max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="MOD 2 Wave" id="c85d4543a533be92" memberName="WaveMOD2Cmb"
            virtualName="" explicitFocusOrder="0" pos="528 256 80 24" editable="0"
            layout="33" items="Sine&#10;Square&#10;Saw" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="MOD 2 Bypass Button" id="7773dc0327675392" memberName="BypassMOD2Btn"
              virtualName="" explicitFocusOrder="0" pos="552 216 56 24" buttonText="MOD 2"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="MOD 2 Freq Label" id="f37a78a0ec1cab07" memberName="FreqMOD2Lbl"
         virtualName="" explicitFocusOrder="0" pos="366 272 40 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="MOD 2 Depth Label" id="c19bf3a6d5ab63f9" memberName="DepthMOD2Lbl"
         virtualName="" explicitFocusOrder="0" pos="418 272 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Depth" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="MOD 2 Wave Label" id="1bdb7eca9ab250c8" memberName="WaveMOD2Lbl"
         virtualName="" explicitFocusOrder="0" pos="544 288 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Wave&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="MOD 2 Tempo Sync Button" id="bfc616fbcdb92b04" memberName="TempoSyncMOD2Btn"
              virtualName="" explicitFocusOrder="0" pos="360 224 56 16" buttonText="Tempo Sync"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="MOD 2 Tempo Numer Slider" id="2bcaaa8e6b75d2b9" memberName="TempoNumerMOD2Sld"
          virtualName="" explicitFocusOrder="0" pos="360 256 56 16" textboxbkgd="ffc8c8c8"
          textboxoutline="9808080" min="1" max="4" int="1" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="MOD 2 Tempo Denom Slider" id="255bbe43957852ba" memberName="TempoDenomMOD2Sld"
          virtualName="" explicitFocusOrder="0" pos="360 288 56 16" textboxbkgd="ffc8c8c8"
          textboxoutline="808080" min="1" max="32" int="1" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="MOD 2 Phase Sync Button" id="7b0a4004498f92b3" memberName="PhaseSyncMOD2Btn"
              virtualName="" explicitFocusOrder="0" pos="472 224 56 16" buttonText="Phase Sync"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="MOD 2 Phase Slider" id="54fd5481a5970106" memberName="PhaseMOD2Sld"
          virtualName="" explicitFocusOrder="0" pos="480 248 32 24" rotarysliderfill="7f00ff03"
          min="0" max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="MOD 2 Phase Label" id="d3b9d517ecdfe1bc" memberName="PhaseMOD2Lbl"
         virtualName="" explicitFocusOrder="0" pos="472 272 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Phase" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="Stereo Button" id="91683bb4fa1cc3c7" memberName="StereoBtn"
              virtualName="" explicitFocusOrder="0" pos="544 48 72 24" buttonText="Stereo"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
