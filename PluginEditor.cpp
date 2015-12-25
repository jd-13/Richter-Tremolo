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
                                                       String::empty));

    addAndMakeVisible (DepthLFO1Sld = new Slider ("LFO 1 Depth Slider"));
    DepthLFO1Sld->setRange (0, 1, 0.01);
    DepthLFO1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    DepthLFO1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DepthLFO1Sld->addListener (this);

    addAndMakeVisible (FreqLFO1Sld = new Slider ("LFO 1 Freq Slider"));
    FreqLFO1Sld->setRange (0, 1, 0.01);
    FreqLFO1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    FreqLFO1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
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
    DepthModLFO1Sld->addListener (this);

    addAndMakeVisible (FreqModLFO1Sld = new Slider ("LFO 1 Freq Mod Slider"));
    FreqModLFO1Sld->setRange (0, 1, 0.01);
    FreqModLFO1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    FreqModLFO1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FreqModLFO1Sld->addListener (this);

    addAndMakeVisible (MasterVolSld = new Slider ("new slider"));
    MasterVolSld->setRange (0, 1, 0.01);
    MasterVolSld->setSliderStyle (Slider::LinearHorizontal);
    MasterVolSld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    MasterVolSld->addListener (this);

    addAndMakeVisible (DbgLbl = new Label ("Debugging Label",
                                           TRANS("label text")));
    DbgLbl->setFont (Font (15.00f, Font::plain));
    DbgLbl->setJustificationType (Justification::centredLeft);
    DbgLbl->setEditable (false, false, false);
    DbgLbl->setColour (TextEditor::textColourId, Colours::black);
    DbgLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (BypassLFO1Btn = new TextButton ("LFO 1 Bypass Button"));
    BypassLFO1Btn->setButtonText (TRANS("LFO 1"));
    BypassLFO1Btn->addListener (this);

    addAndMakeVisible (FreqLFO1Lbl = new Label ("LFO 1 Freq Label",
                                                TRANS("Rate")));
    FreqLFO1Lbl->setFont (Font (15.00f, Font::plain));
    FreqLFO1Lbl->setJustificationType (Justification::centredLeft);
    FreqLFO1Lbl->setEditable (false, false, false);
    FreqLFO1Lbl->setColour (TextEditor::textColourId, Colours::black);
    FreqLFO1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (DepthLFO1Lbl = new Label ("LFO 1 Depth Label",
                                                 TRANS("Depth")));
    DepthLFO1Lbl->setFont (Font (15.00f, Font::plain));
    DepthLFO1Lbl->setJustificationType (Justification::centredLeft);
    DepthLFO1Lbl->setEditable (false, false, false);
    DepthLFO1Lbl->setColour (TextEditor::textColourId, Colours::black);
    DepthLFO1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (WaveLFO1Lbl = new Label ("LFO 1 Wave Label",
                                                TRANS("Wave\n")));
    WaveLFO1Lbl->setFont (Font (15.00f, Font::plain));
    WaveLFO1Lbl->setJustificationType (Justification::centredLeft);
    WaveLFO1Lbl->setEditable (false, false, false);
    WaveLFO1Lbl->setColour (TextEditor::textColourId, Colours::black);
    WaveLFO1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (LFO2Group = new GroupComponent ("LFO 2 Group",
                                                       String::empty));

    addAndMakeVisible (DepthLFO2Sld = new Slider ("LFO 2 Depth Slider"));
    DepthLFO2Sld->setRange (0, 1, 0.01);
    DepthLFO2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    DepthLFO2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DepthLFO2Sld->addListener (this);

    addAndMakeVisible (FreqLFO2Sld = new Slider ("LFO 2 Freq Slider"));
    FreqLFO2Sld->setRange (0, 1, 0.01);
    FreqLFO2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    FreqLFO2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
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
    DepthModLFO2Sld->addListener (this);

    addAndMakeVisible (FreqModLFO2Sld = new Slider ("LFO 2 Freq Mod Slider"));
    FreqModLFO2Sld->setRange (0, 1, 0.01);
    FreqModLFO2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    FreqModLFO2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FreqModLFO2Sld->addListener (this);

    addAndMakeVisible (BypassLFO2Btn = new TextButton ("LFO 2 Bypass Button"));
    BypassLFO2Btn->setButtonText (TRANS("LFO 2"));
    BypassLFO2Btn->addListener (this);

    addAndMakeVisible (FreqLFO2Lbl = new Label ("LFO 2 Freq Label",
                                                TRANS("Rate")));
    FreqLFO2Lbl->setFont (Font (15.00f, Font::plain));
    FreqLFO2Lbl->setJustificationType (Justification::centredLeft);
    FreqLFO2Lbl->setEditable (false, false, false);
    FreqLFO2Lbl->setColour (TextEditor::textColourId, Colours::black);
    FreqLFO2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (DepthLFO2Lbl = new Label ("LFO 2 Depth Label",
                                                 TRANS("Depth")));
    DepthLFO2Lbl->setFont (Font (15.00f, Font::plain));
    DepthLFO2Lbl->setJustificationType (Justification::centredLeft);
    DepthLFO2Lbl->setEditable (false, false, false);
    DepthLFO2Lbl->setColour (TextEditor::textColourId, Colours::black);
    DepthLFO2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (WaveLFO2Lbl = new Label ("LFO 2 Wave Label",
                                                TRANS("Wave\n")));
    WaveLFO2Lbl->setFont (Font (15.00f, Font::plain));
    WaveLFO2Lbl->setJustificationType (Justification::centredLeft);
    WaveLFO2Lbl->setEditable (false, false, false);
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
    TempoNumerLFO1Sld->addListener (this);

    addAndMakeVisible (TempoDenomLFO1Sld = new Slider ("LFO 1 Tempo Denom Slider"));
    TempoDenomLFO1Sld->setRange (1, 32, 1);
    TempoDenomLFO1Sld->setSliderStyle (Slider::IncDecButtons);
    TempoDenomLFO1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoDenomLFO1Sld->addListener (this);

    addAndMakeVisible (TempoNumerLFO2Sld = new Slider ("LFO 2 Tempo Numer Slider"));
    TempoNumerLFO2Sld->setRange (1, 4, 1);
    TempoNumerLFO2Sld->setSliderStyle (Slider::IncDecButtons);
    TempoNumerLFO2Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoNumerLFO2Sld->addListener (this);

    addAndMakeVisible (TempoDenomLFO2Sld = new Slider ("LFO 2 Tempo Denom Slider"));
    TempoDenomLFO2Sld->setRange (1, 32, 1);
    TempoDenomLFO2Sld->setSliderStyle (Slider::IncDecButtons);
    TempoDenomLFO2Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoDenomLFO2Sld->addListener (this);

    addAndMakeVisible (PhaseSyncLFO1Btn = new TextButton ("LFO 1 Phase Sync Button"));
    PhaseSyncLFO1Btn->setButtonText (TRANS("Phase Sync"));
    PhaseSyncLFO1Btn->addListener (this);

    addAndMakeVisible (PhaseSyncLFO2Btn = new TextButton ("LFO 2 Phase Sync Button"));
    PhaseSyncLFO2Btn->setButtonText (TRANS("Phase Sync"));
    PhaseSyncLFO2Btn->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 400);


    //[Constructor] You can add your own custom stuff here..
    startTimer(200);
    if (!DEBUGGING_MODE) {
        DbgLbl->setText(" ", dontSendNotification);
    }
    TempoNumerLFO1Sld->setVisible(false);
    TempoNumerLFO1Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);
    TempoDenomLFO1Sld->setVisible(false);
    TempoDenomLFO1Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);
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
    DbgLbl = nullptr;
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
    //[/UserPaint]
}

void RichterAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    LFO1Group->setBounds (16, 64, 232, 128);
    DepthLFO1Sld->setBounds (96, 112, 32, 24);
    FreqLFO1Sld->setBounds (40, 112, 32, 24);
    WaveLFO1Cmb->setBounds (144, 120, 80, 24);
    DepthModLFO1Sld->setBounds (104, 160, 16, 16);
    FreqModLFO1Sld->setBounds (48, 160, 16, 16);
    MasterVolSld->setBounds (16, 40, 480, 24);
    DbgLbl->setBounds (16, 8, 150, 24);
    BypassLFO1Btn->setBounds (168, 80, 56, 24);
    FreqLFO1Lbl->setBounds (38, 136, 40, 24);
    DepthLFO1Lbl->setBounds (90, 136, 46, 24);
    WaveLFO1Lbl->setBounds (160, 152, 46, 24);
    LFO2Group->setBounds (264, 64, 232, 128);
    DepthLFO2Sld->setBounds (344, 112, 32, 24);
    FreqLFO2Sld->setBounds (288, 112, 32, 24);
    WaveLFO2Cmb->setBounds (392, 120, 80, 24);
    DepthModLFO2Sld->setBounds (352, 160, 16, 16);
    FreqModLFO2Sld->setBounds (296, 160, 16, 16);
    BypassLFO2Btn->setBounds (416, 80, 56, 24);
    FreqLFO2Lbl->setBounds (286, 136, 40, 24);
    DepthLFO2Lbl->setBounds (338, 136, 46, 24);
    WaveLFO2Lbl->setBounds (408, 152, 46, 24);
    TempoSyncLFO1Btn->setBounds (32, 88, 56, 16);
    TempoSyncLFO2Btn->setBounds (280, 88, 56, 16);
    TempoNumerLFO1Sld->setBounds (32, 120, 56, 16);
    TempoDenomLFO1Sld->setBounds (32, 152, 56, 16);
    TempoNumerLFO2Sld->setBounds (280, 120, 56, 16);
    TempoDenomLFO2Sld->setBounds (280, 152, 56, 16);
    PhaseSyncLFO1Btn->setBounds (96, 88, 56, 16);
    PhaseSyncLFO2Btn->setBounds (344, 88, 56, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void RichterAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    RichterAudioProcessor* ourProcessor = getProcessor();
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

    //[UsersliderValueChanged_Post]
    if (DEBUGGING_MODE) {
        float val = sliderThatWasMoved->getValue();
        DbgLbl->setText(String(val), dontSendNotification);
    }
    //[/UsersliderValueChanged_Post]
}

void RichterAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    RichterAudioProcessor* ourProcessor = getProcessor();
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

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void RichterAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    RichterAudioProcessor* ourProcessor = getProcessor();
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == BypassLFO1Btn)
    {
        //[UserButtonCode_BypassLFO1Btn] -- add your button handler code here..
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

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void RichterAudioProcessorEditor::timerCallback()
{
    RichterAudioProcessor* ourProcessor = getProcessor();

    if (ourProcessor->NeedsUIUpdate()) {
        BypassLFO1Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::bypassSwitchLFO1), dontSendNotification);
        PhaseSyncLFO1Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::phaseSyncLFO1), dontSendNotification);
        TempoSyncLFO1Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::tempoSyncLFO1), dontSendNotification);
        WaveLFO1Cmb->setSelectedId(ourProcessor->getParameter(RichterAudioProcessor::waveLFO1), dontSendNotification);
        DepthLFO1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::depthLFO1), dontSendNotification);
        DepthModLFO1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::depthModLFO1), dontSendNotification);
        FreqLFO1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::freqLFO1), dontSendNotification);
        FreqModLFO1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::freqModLFO1), dontSendNotification);
        TempoNumerLFO1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::tempoNumerLFO1), dontSendNotification);
        TempoDenomLFO1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::tempoDenomLFO1), dontSendNotification);

        BypassLFO2Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::bypassSwitchLFO2), dontSendNotification);
        PhaseSyncLFO2Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::phaseSyncLFO2), dontSendNotification);
        TempoSyncLFO2Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::tempoSyncLFO2), dontSendNotification);
        WaveLFO2Cmb->setSelectedId(ourProcessor->getParameter(RichterAudioProcessor::waveLFO2), dontSendNotification);
        DepthLFO2Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::depthLFO2), dontSendNotification);
        DepthModLFO2Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::depthModLFO2), dontSendNotification);
        FreqLFO2Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::freqLFO2), dontSendNotification);
        FreqModLFO2Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::freqModLFO2), dontSendNotification);
        TempoNumerLFO2Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::tempoNumerLFO2), dontSendNotification);
        TempoDenomLFO2Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::tempoDenomLFO2), dontSendNotification);

        MasterVolSld->setValue(ourProcessor->getParameter(RichterAudioProcessor::masterVol), dontSendNotification);

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
                 fixedSize="1" initialWidth="800" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <GROUPCOMPONENT name="LFO 1 Group" id="2a8643bc712454bf" memberName="LFO1Group"
                  virtualName="" explicitFocusOrder="0" pos="16 64 232 128" title=""/>
  <SLIDER name="LFO 1 Depth Slider" id="98ad3308f709f25c" memberName="DepthLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="96 112 32 24" min="0"
          max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="LFO 1 Freq Slider" id="94530d5c05e4a382" memberName="FreqLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="40 112 32 24" min="0"
          max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="LFO 1 Wave" id="6343a9cc42a2eda5" memberName="WaveLFO1Cmb"
            virtualName="" explicitFocusOrder="0" pos="144 120 80 24" editable="0"
            layout="33" items="Sine&#10;Square&#10;Saw" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="LFO 1 Depth Mod Slider" id="9a3f86cb168e586e" memberName="DepthModLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="104 160 16 16" min="0"
          max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="LFO 1 Freq Mod Slider" id="b0488ea613d92dcf" memberName="FreqModLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="48 160 16 16" min="0"
          max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="65acc0b358aa2541" memberName="MasterVolSld"
          virtualName="" explicitFocusOrder="0" pos="16 40 480 24" min="0"
          max="1" int="0.010000000000000000208" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Debugging Label" id="4e3323314b846bd7" memberName="DbgLbl"
         virtualName="" explicitFocusOrder="0" pos="16 8 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="LFO 1 Bypass Button" id="27660ce1c9366ec3" memberName="BypassLFO1Btn"
              virtualName="" explicitFocusOrder="0" pos="168 80 56 24" buttonText="LFO 1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="LFO 1 Freq Label" id="29836e1fe4622869" memberName="FreqLFO1Lbl"
         virtualName="" explicitFocusOrder="0" pos="38 136 40 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Rate" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="LFO 1 Depth Label" id="fa48be8976dad123" memberName="DepthLFO1Lbl"
         virtualName="" explicitFocusOrder="0" pos="90 136 46 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="LFO 1 Wave Label" id="75dbcd5f6a0cc700" memberName="WaveLFO1Lbl"
         virtualName="" explicitFocusOrder="0" pos="160 152 46 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Wave&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <GROUPCOMPONENT name="LFO 2 Group" id="35e8ad61c86b603a" memberName="LFO2Group"
                  virtualName="" explicitFocusOrder="0" pos="264 64 232 128" title=""/>
  <SLIDER name="LFO 2 Depth Slider" id="2596adc2e61cd58e" memberName="DepthLFO2Sld"
          virtualName="" explicitFocusOrder="0" pos="344 112 32 24" min="0"
          max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="LFO 2 Freq Slider" id="f5dbcdc53c502e69" memberName="FreqLFO2Sld"
          virtualName="" explicitFocusOrder="0" pos="288 112 32 24" min="0"
          max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="LFO 2 Wave" id="b76d5189aafe8e3f" memberName="WaveLFO2Cmb"
            virtualName="" explicitFocusOrder="0" pos="392 120 80 24" editable="0"
            layout="33" items="Sine&#10;Square&#10;Saw" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="LFO 2 Depth Mod Slider" id="4a524c9e1974186c" memberName="DepthModLFO2Sld"
          virtualName="" explicitFocusOrder="0" pos="352 160 16 16" min="0"
          max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="LFO 2 Freq Mod Slider" id="e49bd74bef8aaca1" memberName="FreqModLFO2Sld"
          virtualName="" explicitFocusOrder="0" pos="296 160 16 16" min="0"
          max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="LFO 2 Bypass Button" id="74a3a05dda891f9c" memberName="BypassLFO2Btn"
              virtualName="" explicitFocusOrder="0" pos="416 80 56 24" buttonText="LFO 2"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="LFO 2 Freq Label" id="5463cd286934c4bc" memberName="FreqLFO2Lbl"
         virtualName="" explicitFocusOrder="0" pos="286 136 40 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Rate" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="LFO 2 Depth Label" id="39dd59a998ec443" memberName="DepthLFO2Lbl"
         virtualName="" explicitFocusOrder="0" pos="338 136 46 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="LFO 2 Wave Label" id="e01fc09efde6d339" memberName="WaveLFO2Lbl"
         virtualName="" explicitFocusOrder="0" pos="408 152 46 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Wave&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="LFO 1 Tempo Sync Button" id="95825bc0b3290b8b" memberName="TempoSyncLFO1Btn"
              virtualName="" explicitFocusOrder="0" pos="32 88 56 16" buttonText="Tempo Sync"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="LFO 2 Tempo Sync Button" id="3a20b52dc2308f55" memberName="TempoSyncLFO2Btn"
              virtualName="" explicitFocusOrder="0" pos="280 88 56 16" buttonText="Tempo Sync"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="LFO 1 Tempo Numer Slider" id="ae3b2cb5fc40f879" memberName="TempoNumerLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="32 120 56 16" min="1"
          max="4" int="1" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="LFO 1 Tempo Denom Slider" id="79fb8b0e645e1976" memberName="TempoDenomLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="32 152 56 16" min="1"
          max="32" int="1" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="LFO 2 Tempo Numer Slider" id="7ef07d530a2439f7" memberName="TempoNumerLFO2Sld"
          virtualName="" explicitFocusOrder="0" pos="280 120 56 16" min="1"
          max="4" int="1" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="LFO 2 Tempo Denom Slider" id="684fae94c6ad39f8" memberName="TempoDenomLFO2Sld"
          virtualName="" explicitFocusOrder="0" pos="280 152 56 16" min="1"
          max="32" int="1" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="LFO 1 Phase Sync Button" id="1df73348199bbe85" memberName="PhaseSyncLFO1Btn"
              virtualName="" explicitFocusOrder="0" pos="96 88 56 16" buttonText="Phase Sync"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="LFO 2 Phase Sync Button" id="6956f3f885f5801d" memberName="PhaseSyncLFO2Btn"
              virtualName="" explicitFocusOrder="0" pos="344 88 56 16" buttonText="Phase Sync"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
