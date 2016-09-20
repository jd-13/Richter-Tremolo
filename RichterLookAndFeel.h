/*
 *  File:       CustomLookAndFeel.h
 *
 *  Version:    2.0.0
 *
 *  Created:    09/01/2016
 *
 *	This file is part of Richter.
 *
 *  Richter is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Richter is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with the Richter.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef RICHTERLOOKANDFEEL_H_INCLUDED
#define RICHTERLOOKANDFEEL_H_INCLUDED

#define _USE_MATH_DEFINES

#include "../JuceLibraryCode/JuceHeader.h"
#include "ParameterData.h"
#include <string.h>
#include <memory>
#include "math.h"

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
    
    virtual void drawLinearSliderBackground(Graphics& g,
                                            int x,
                                            int y,
                                            int width,
                                            int height,
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
                                           int width,
                                           int height,
                                           const String& title,
                                           const Justification& justification,
                                           GroupComponent& groupComponent) override;
    
    virtual void drawTooltip(Graphics& g,
                             const String& text,
                             int width,
                             int height) override;
    
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
