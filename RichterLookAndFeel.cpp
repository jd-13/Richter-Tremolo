/*
  ==============================================================================

    CustomLookAndFeel.cpp
    Created: 9 Jan 2016 4:33:29pm
    Author:  Jack Devlin

  ==============================================================================
*/

#include "RichterLookAndFeel.h"

RichterLookAndFeel::RichterLookAndFeel() :  LookAndFeel_V2(),
                                            lightGrey(200, 200, 200),
                                            darkGrey(107, 107, 107),
                                            neonGreen(0, 250, 0),
                                            LFO1On(false),
                                            LFO2On(false),
                                            MOD1On(false),
                                            MOD2On(false) {
    setColour(PopupMenu::highlightedBackgroundColourId, darkGrey);
    setColour(PopupMenu::backgroundColourId, lightGrey);
}

// Used as an interface between the LFO bypass buttons and drawGroupComponentOutline
void RichterLookAndFeel::updateLFOState(String lfoName, bool val) {
    if (lfoName == GROUP_LFO1) {
        LFO1On = val;
    } else if (lfoName == GROUP_LFO2) {
        LFO2On = val;
    } else if (lfoName == GROUP_MOD1) {
        MOD1On = val;
    } else if (lfoName == GROUP_MOD2) {
        MOD2On = val;
    }
}



void RichterLookAndFeel::drawLinearSliderThumb(Graphics& g,
                                             int x,
                                             int y,
                                             int width,
                                             int height,
                                             float sliderPos,
                                             float minSliderPos,
                                             float maxSliderPos,
                                             const Slider::SliderStyle style,
                                             Slider& slider) {
    
    const float sliderRadius = static_cast<float>(getSliderThumbRadius(slider) - 2);
    
    Colour* ring;
    
    if (slider.isEnabled()) {
        ring = &neonGreen;
    } else {
        ring = &lightGrey;
    }
    
    if (style == Slider::LinearHorizontal || style == Slider::LinearVertical)
    {
        float kx, ky;
        
        if (style == Slider::LinearVertical)
        {
            kx = x + width * 0.5f;
            ky = sliderPos;
        }
        else
        {
            kx = sliderPos;
            ky = y + height * 0.5f;
        }
        
        Path p;
        p.addEllipse(kx - sliderRadius, ky - sliderRadius, sliderRadius * 2, sliderRadius * 2);
        
        g.setColour(darkGrey);
        g.fillPath(p);
        
        g.setColour(*ring);
        g.strokePath(p, PathStrokeType(2.0f));
    }
    
}

void RichterLookAndFeel::drawLinearSlider(Graphics& g,
                                          int x,
                                          int y,
                                          int w,
                                          int h,
                                          float sliderPos,
                                          float minSliderPos,
                                          float maxSliderPos,
                                          const Slider::SliderStyle style,
                                          Slider& slider) {
    g.setColour(lightGrey);
    
    if (slider.isHorizontal()) {
        g.fillRect(x, y + h / 2, w, 2);
    }
    
    drawLinearSliderThumb(g, x, y, w, h, sliderPos, minSliderPos, maxSliderPos, style, slider);
}

void RichterLookAndFeel::drawButtonBackground(Graphics& g,
                                            Button& button,
                                            const Colour& backgroundColour,
                                            bool isMouseOverButton,
                                            bool isButtonDown) {
    const int width {button.getWidth()};
    const int height {button.getHeight()};
    
    const float indent {2.0f};
    const int cornerSize {jmin (roundToInt(width * 0.4f),
                                roundToInt(height * 0.4f))};
    
    Path p;
    PathStrokeType pStroke(1);
    Colour* bc {nullptr};
    
    

    // differentiates between the small button on the tempo sync ratio and larger buttons
    if (button.getWidth() > 24) {
        
        if (button.getToggleState()) {
            bc = &neonGreen;
        } else {
            bc = &lightGrey;
        }
        
        p.addRoundedRectangle(indent, indent, width - 2 * indent, height - 2 * indent, static_cast<float>(cornerSize));
        
        
        g.setColour(*bc);
        g.strokePath(p, pStroke);
    }
    
    
}

void RichterLookAndFeel::drawButtonText(Graphics& g,
                                        TextButton& textButton,
                                        bool isMouseOverButton,
                                        bool isButtonDown) {
    
    Colour* textColour {nullptr};
    
    if (textButton.getToggleState() || textButton.getWidth() < 24) {
        textColour = &neonGreen;
    } else {
        textColour = &lightGrey;
    }
    
    g.setColour(*textColour);
    int margin {0};
    
    // differentiates between the small button on the tempo sync ratio and larger buttons
    if (textButton.getWidth() > 24) {
        margin = 5;
    }
    
    g.drawFittedText(textButton.getButtonText(), margin, 0, textButton.getWidth() - 2 * margin, textButton.getHeight(), Justification::centred, 0);
}

void RichterLookAndFeel::drawRotarySlider(Graphics& g,
                                          int x,
                                          int y,
                                          int width,
                                          int height,
                                          float sliderPosProportional,
                                          float rotaryStartAngle,
                                          float rotaryEndAngle,
                                          Slider &slider) {
    // calculate useful constants
    const float rangeOfMotion {260 * (M_PI / 180)};
    const double rotation {((slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum())) * rangeOfMotion - rangeOfMotion / 2};
    
    const int margin {1};
    const float diameter {static_cast<float>(height - margin * 2)};
    
    // draw centre circle
    Path p;
    g.setColour(darkGrey);
    p.addEllipse(width / 2 - diameter / 2, height / 2 - diameter / 2, diameter, diameter);
    g.fillPath(p);
    
    // draw outer ring
    Colour* ringColour {&neonGreen};
    if (!slider.isEnabled()) {
        ringColour = &lightGrey;
    }
    
    g.setColour(*ringColour);
    p.clear();
    
    const float gap {0.4};
    p.addCentredArc(width / 2, height / 2, diameter / 2, diameter / 2, rotation, gap, 2 * M_PI - gap, true);
    
    g.strokePath(p, PathStrokeType(2.0f));
}

void RichterLookAndFeel::drawComboBox(Graphics& g,
                                      int width,
                                      int height,
                                      const bool isButtonDown,
                                      int buttonX,
                                      int buttonY,
                                      int buttonW,
                                      int buttonH,
                                      ComboBox& box) {
    
    g.fillAll(lightGrey);
    g.setColour(darkGrey);
    g.fillRect(buttonX, buttonY, buttonW, buttonH);
    
    const float arrowX {0.2f};
    const float arrowH {0.3f};
    
    if (box.isEnabled()) {
        Path p;
        p.addTriangle(buttonX + buttonW * 0.5f,                 buttonY + buttonH * (0.45f - arrowH),
                      buttonX + buttonW * (1.0f - arrowX),      buttonY + buttonH * 0.45f,
                      buttonX + buttonW * arrowX,               buttonY + buttonH * 0.45f);
        
        p.addTriangle(buttonX + buttonW * 0.5f,                 buttonY + buttonH * (0.55f + arrowH),
                      buttonX + buttonW * (1.0f -arrowX),       buttonY + buttonH * 0.55f,
                      buttonX + buttonW * arrowX,               buttonY + buttonH * 0.55f);
        
        g.setColour(box.isPopupActive() ? neonGreen : lightGrey);
        
        g.fillPath(p);
    }
}


void RichterLookAndFeel::drawGroupComponentOutline(Graphics& g,
                                                   int w,
                                                   int h,
                                                   const String& title,
                                                   const Justification& justification,
                                                   GroupComponent& groupComponent) {
    Path p;
    PathStrokeType pStroke(1);
    Colour* outlineColour {&lightGrey};
    
    // find which LFO this group is for and find if the lfo is active
    if (title == GROUP_LFO1) {
        if (LFO1On) {
            outlineColour = &neonGreen;
        }
    } else if (title == GROUP_LFO2) {
        if (LFO2On) {
            outlineColour = &neonGreen;
        }
    } else if (title == GROUP_MOD1) {
        if (MOD1On) {
            outlineColour = &neonGreen;
        }
    } else if (title == GROUP_MOD2) {
        if (MOD2On) {
            outlineColour = &neonGreen;
        }
    }
    
    const int indent {5};
    p.addRoundedRectangle(0 + indent, 0 + indent, groupComponent.getWidth() - 2 * indent, groupComponent.getHeight() - 2 * indent, 10);
    
    g.setColour(*outlineColour);
    g.strokePath(p, pStroke);
}
