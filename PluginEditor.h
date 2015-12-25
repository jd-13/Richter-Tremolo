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
    ScopedPointer<Slider> DepthLFO1Sld;
    ScopedPointer<Slider> FreqLFO1Sld;
    ScopedPointer<ComboBox> WaveLFO1Cmb;
    ScopedPointer<Slider> DepthModLFO1Sld;
    ScopedPointer<Slider> FreqModLFO1Sld;
    ScopedPointer<Slider> MasterVolSld;
    ScopedPointer<Label> DbgLbl;
    ScopedPointer<TextButton> BypassLFO1Btn;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RichterAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_E9D89E8D1CC926CC__