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

    addAndMakeVisible (DepthLFO1Sld = new Slider ("LFO 1 Depth Slider"));
    DepthLFO1Sld->setRange (0, 1, 0);
    DepthLFO1Sld->setSliderStyle (Slider::LinearHorizontal);
    DepthLFO1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    DepthLFO1Sld->addListener (this);

    addAndMakeVisible (FreqLFO1Sld = new Slider ("LFO 1 Freq Slider"));
    FreqLFO1Sld->setRange (0, 1, 0);
    FreqLFO1Sld->setSliderStyle (Slider::LinearHorizontal);
    FreqLFO1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
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
    DepthModLFO1Sld->setRange (0, 1, 0);
    DepthModLFO1Sld->setSliderStyle (Slider::LinearHorizontal);
    DepthModLFO1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    DepthModLFO1Sld->addListener (this);

    addAndMakeVisible (FreqModLFO1Sld = new Slider ("LFO 1 Freq Mod Slider"));
    FreqModLFO1Sld->setRange (0, 1, 0);
    FreqModLFO1Sld->setSliderStyle (Slider::LinearHorizontal);
    FreqModLFO1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    FreqModLFO1Sld->addListener (this);

    addAndMakeVisible (MasterVolSld = new Slider ("new slider"));
    MasterVolSld->setRange (0, 1, 0);
    MasterVolSld->setSliderStyle (Slider::LinearHorizontal);
    MasterVolSld->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    MasterVolSld->addListener (this);

    addAndMakeVisible (DbgLbl = new Label ("Debugging Label",
                                           TRANS("label text")));
    DbgLbl->setFont (Font (15.00f, Font::plain));
    DbgLbl->setJustificationType (Justification::centredLeft);
    DbgLbl->setEditable (false, false, false);
    DbgLbl->setColour (TextEditor::textColourId, Colours::black);
    DbgLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (BypassLFO1Btn = new TextButton ("LFO1"));
    BypassLFO1Btn->setButtonText (TRANS("LFO 1"));
    BypassLFO1Btn->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    startTimer(200);
    if (!DEBUGGING_MODE) {
        DbgLbl->setText(" ", dontSendNotification);
    }
    //[/Constructor]
}

RichterAudioProcessorEditor::~RichterAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    DepthLFO1Sld = nullptr;
    FreqLFO1Sld = nullptr;
    WaveLFO1Cmb = nullptr;
    DepthModLFO1Sld = nullptr;
    FreqModLFO1Sld = nullptr;
    MasterVolSld = nullptr;
    DbgLbl = nullptr;
    BypassLFO1Btn = nullptr;


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

    DepthLFO1Sld->setBounds (24, 96, 150, 24);
    FreqLFO1Sld->setBounds (24, 144, 150, 24);
    WaveLFO1Cmb->setBounds (24, 48, 150, 24);
    DepthModLFO1Sld->setBounds (192, 96, 150, 24);
    FreqModLFO1Sld->setBounds (192, 144, 150, 24);
    MasterVolSld->setBounds (112, 320, 150, 24);
    DbgLbl->setBounds (192, 16, 150, 24);
    BypassLFO1Btn->setBounds (72, 216, 150, 24);
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

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void RichterAudioProcessorEditor::timerCallback()
{
    RichterAudioProcessor* ourProcessor = getProcessor();

    if (ourProcessor->NeedsUIUpdate()) {
        BypassLFO1Btn->setToggleState(ourProcessor->getParameter(RichterAudioProcessor::bypassSwitchLFO1), dontSendNotification);
        WaveLFO1Cmb->setSelectedId(ourProcessor->getParameter(RichterAudioProcessor::waveLFO1), dontSendNotification);
        DepthLFO1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::depthLFO1), dontSendNotification);
        DepthModLFO1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::depthModLFO1), dontSendNotification);
        FreqLFO1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::freqLFO1), dontSendNotification);
        FreqModLFO1Sld->setValue(ourProcessor->getParameter(RichterAudioProcessor::freqModLFO1), dontSendNotification);



        MasterVolSld->setValue(ourProcessor->getParameter(RichterAudioProcessor::masterVol), dontSendNotification);
    }

    DbgLbl->setText(ourProcessor->getParameterText(RichterAudioProcessor::bypassSwitchLFO1), dontSendNotification);
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
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="LFO 1 Depth Slider" id="98ad3308f709f25c" memberName="DepthLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="24 96 150 24" min="0"
          max="1" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="LFO 1 Freq Slider" id="94530d5c05e4a382" memberName="FreqLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="24 144 150 24" min="0"
          max="1" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="LFO 1 Wave" id="6343a9cc42a2eda5" memberName="WaveLFO1Cmb"
            virtualName="" explicitFocusOrder="0" pos="24 48 150 24" editable="0"
            layout="33" items="Sine&#10;Square&#10;Saw" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="LFO 1 Depth Mod Slider" id="9a3f86cb168e586e" memberName="DepthModLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="192 96 150 24" min="0"
          max="1" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="LFO 1 Freq Mod Slider" id="b0488ea613d92dcf" memberName="FreqModLFO1Sld"
          virtualName="" explicitFocusOrder="0" pos="192 144 150 24" min="0"
          max="1" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="65acc0b358aa2541" memberName="MasterVolSld"
          virtualName="" explicitFocusOrder="0" pos="112 320 150 24" min="0"
          max="1" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Debugging Label" id="4e3323314b846bd7" memberName="DbgLbl"
         virtualName="" explicitFocusOrder="0" pos="192 16 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="LFO1" id="27660ce1c9366ec3" memberName="BypassLFO1Btn"
              virtualName="" explicitFocusOrder="0" pos="72 216 150 24" buttonText="LFO 1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
