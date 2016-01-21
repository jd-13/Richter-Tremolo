/*
  ==============================================================================

    RichterLookAndFeel.h
    Created: 9 Jan 2016 4:33:29pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef RICHTERLOOKANDFEEL_H_INCLUDED
#define RICHTERLOOKANDFEEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "ParameterData.h"
#include <string.h>
#include <memory>

class RichterLookAndFeel : public LookAndFeel_V2 {
public:
    RichterLookAndFeel();
    virtual ~RichterLookAndFeel() {}
    
    virtual void drawButtonBackground(Graphics& g,
                                      Button& button,
                                      const Colour& backgroundColour,
                                      bool isMouseOverButton,
                                      bool isButtonDown) override;
    
    virtual void drawRotarySlider(Graphics& g,
                                  int x,
                                  int y,
                                  int width,
                                  int height,
                                  float sliderPosProportional,
                                  float rotaryStartAngle,
                                  float rotaryEndAngle,
                                  Slider& slider) override;
    
    virtual void drawLinearSliderThumb(Graphics& g,
                                       int x,
                                       int y,
                                       int width,
                                       int height,
                                       float sliderPos,
                                       float minSliderPos,
                                       float maxSliderPos,
                                       const Slider::SliderStyle style,
                                       Slider& slider) override;
    
    virtual void drawLinearSlider(Graphics& g,
                                  int x,
                                  int y,
                                  int w,
                                  int h,
                                  float sliderPos,
                                  float minSliderPos,
                                  float maxSliderPos,
                                  const Slider::SliderStyle style,
                                  Slider& slider) override;
    
    virtual void drawButtonText(Graphics& g,
                                TextButton& textButton,
                                bool isMouseOverButton,
                                bool isButtonDown) override;
    
    virtual void drawComboBox(Graphics& g,
                              int width,
                              int height,
                              const bool isButtonDown,
                              int buttonX,
                              int buttonY,
                              int buttonW,
                              int buttonH,
                              ComboBox& box) override;
    
    virtual void drawGroupComponentOutline(Graphics& g,
                                           int w,
                                           int h,
                                           const String& title,
                                           const Justification& justification,
                                           GroupComponent& groupComponent) override;
    
    void updateLFOState(String lfoName, bool val);
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RichterLookAndFeel);
    
    Colour  lightGrey,
            darkGrey,
            neonGreen;
    
    bool    LFO1On,
            LFO2On,
            MOD1On,
            MOD2On;

};



#endif  // RICHTERLOOKANDFEEL_H_INCLUDED
