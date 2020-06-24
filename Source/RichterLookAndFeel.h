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
#include "CoreJUCEPlugin/CoreLookAndFeel.h"

class RichterLookAndFeel : public WECore::JUCEPlugin::CoreLookAndFeel {
public:
    RichterLookAndFeel();
    virtual ~RichterLookAndFeel() {}

    virtual void drawGroupComponentOutline(Graphics& g,
                                           int width,
                                           int height,
                                           const String& title,
                                           const Justification& justification,
                                           GroupComponent& groupComponent) override;

    virtual Typeface::Ptr getTypefaceForFont(const Font& font) override;

    void updateLFOState(String lfoName, bool val);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RichterLookAndFeel);

    bool    LFO1On,
            LFO2On,
            MOD1On,
            MOD2On;

    Font _regularFont;
};

// needed for the small buttons on the tempo sync ratio, they look weird with a border
class RichterTempoButtonLookAndFeel : public RichterLookAndFeel {
public:
    RichterTempoButtonLookAndFeel() : RichterLookAndFeel() {}
    virtual ~RichterTempoButtonLookAndFeel() {}

    virtual void drawButtonBackground(Graphics& /*g*/,
                                      Button& /*button*/,
                                      const Colour& /*backgroundColour*/,
                                      bool /*isMouseOverButton*/,
                                      bool /*isButtonDown*/) override {
        // do nothing
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RichterTempoButtonLookAndFeel);
};



#endif  // RICHTERLOOKANDFEEL_H_INCLUDED
