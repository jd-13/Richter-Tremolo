/*
 *  File:       RichterWaveViewer.h
 *
 *  Version:    2.0.0
 *
 *  Created:    12/07/2020
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
#include "RichterLFO/RichterWavetables.h"

class RichterWaveViewer : public Component {
public:
    RichterWaveViewer();

    void setWave(const double* pointer) { _waveArrayPointer = pointer; }

    virtual void paint(Graphics& g);

    void stop() { _waveArrayPointer = nullptr; }

    enum ColourIds
    {
        highlightColourId = 0x1201201
    };

private:
    const double* _waveArrayPointer;
};
