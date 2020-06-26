/*
 *  File:       RichterLFOCache.h
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

#pragma once

/**
 * Stores the output values of the 4 Richter oscillators.
 */
class RichterLFOCache {
public:
    RichterLFOCache() : lfo1(0), lfo2(0), mod1(0), mod2(0) {}
    ~RichterLFOCache() = default;

    float lfo1;
    float lfo2;
    float mod1;
    float mod2;
};