/*
 *  File:       RichterMOD.h
 *
 *  Version:    2.0.0
 *
 *  Created:    05/02/2015
 *
 *	This file is part of the Richter Tremolo.
 *
 *  The Richter Tremolo is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  The Richter Tremolo is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with the Richter.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef Richter_RichterMOD_h
#define Richter_RichterMOD_h

#include "RichterLFOBase.h"


class RichterMOD : public RichterLFOBase {
    
public:
    RichterMOD();
    
    float getGain() const { return gain; }
    
};


#endif
