/*
 *  File:       RichterLFOMeter.h
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

#pragma once

#include "JuceHeader.h"

class RichterLFOMeter: public Component {
public:
    explicit RichterLFOMeter(bool isMod) : _isMod(isMod) {}
    virtual ~RichterLFOMeter() = default;

    virtual void paint(Graphics& g) override;

    void setMeterValue(float meterValue) { _meterValue = meterValue; }

    enum ColourIds
    {
        mainColourId = 0x1201200
    };

private:
    float _meterValue;
    bool _isMod;
};