/*
 *  File:       CustomLookAndFeel.cpp
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

#include "RichterLookAndFeel.h"

RichterLookAndFeel::RichterLookAndFeel() :  LFO1On(false),
                                            LFO2On(false),
                                            MOD1On(false),
                                            MOD2On(false) {
    setColour(PopupMenu::highlightedBackgroundColourId, darkColour);
    setColour(PopupMenu::backgroundColourId, lightColour);

    _regularFont = Font(Typeface::createSystemTypefaceFor(BinaryData::MontserratRegular_ttf,
                                                          BinaryData::MontserratRegular_ttfSize));
    jassert(_regularFont.getTypefaceName().isNotEmpty());
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

void RichterLookAndFeel::drawGroupComponentOutline(Graphics& g,
                                                   int /*width*/,
                                                   int /*height*/,
                                                   const String& title,
                                                   const Justification& /*justification*/,
                                                   GroupComponent& groupComponent) {
    Path p;
    PathStrokeType pStroke(1);
    Colour* outlineColour {&lightColour};

    // find which LFO this group is for and find if the lfo is active
    if (title == GROUP_LFO1) {
        if (LFO1On) {
            outlineColour = &highlightColour;
        }
    } else if (title == GROUP_LFO2) {
        if (LFO2On) {
            outlineColour = &highlightColour;
        }
    } else if (title == GROUP_MOD1) {
        if (MOD1On) {
            outlineColour = &highlightColour;
        }
    } else if (title == GROUP_MOD2) {
        if (MOD2On) {
            outlineColour = &highlightColour;
        }
    }

    const int indent {5};
    p.addRoundedRectangle(0 + indent, 0 + indent, groupComponent.getWidth() - 2 * indent, groupComponent.getHeight() - 2 * indent, 10);

    g.setColour(*outlineColour);
    g.strokePath(p, pStroke);
}

Typeface::Ptr RichterLookAndFeel::getTypefaceForFont(const Font& /*font*/) {
    return _regularFont.getTypeface();
}
