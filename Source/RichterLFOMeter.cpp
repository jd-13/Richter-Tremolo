/*
 *  File:       RichterLFOMeter.h
 *
 *  Version:    2.0.0
 *
 *  Created:    24/06/2020
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

#include "RichterLFOMeter.h"

void RichterLFOMeter::paint(Graphics& g) {
    constexpr float XPOS {0};
    const float WIDTH {static_cast<float>(getWidth())};
    float YPOS {0};
    float HEIGHT {0};

    if (_isMod) {
        // Mod oscs output values between -1 and 1
        const float meterMidpoint {static_cast<float>(getHeight()) / 2.0f};
        const float halfValueHeight {getHeight() * _meterValue / 2.0f};

        if (_meterValue >= 0) {
            YPOS = meterMidpoint - halfValueHeight;
            HEIGHT = halfValueHeight;
        } else {
            YPOS = meterMidpoint;
            HEIGHT = -halfValueHeight;
        }
    } else {
        // LFO oscs output values between 0 and 1
        const float valueHeight {getHeight() * _meterValue};

        YPOS = static_cast<float>(getHeight() - valueHeight);
        HEIGHT = valueHeight;
    }

    g.setColour(findColour(mainColourId));
    g.fillRect(XPOS, YPOS, WIDTH, HEIGHT);
}
