/*
   Copyright 2015 Morgan Redshaw
  
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at
  
      http://www.apache.org/licenses/LICENSE-2.0
  
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 */
#ifndef BASICPIXELSHIFT_H
#define BASICPIXELSHIFT_H

#include "../Coordinate.h"
#include "PixelShift.h"

class PixelCoordinate;

namespace CoordinateChanger
{

class BasicPixelShift : public PixelShift
{
public:
    BasicPixelShift(const int xShift, const int yShift, const int xShiftEveryPixels, const int yShiftEveryPixels);

    PixelCoordinate GetShiftedPosition(const Coordinate &origionalCoordinate, const int &channel, const Coordinate &imageSize) override;

private:
    bool ShouldShift(const Coordinate & origionalCoordinate);

    const int xShift, yShift;
    const int xShiftEveryPixels, yShiftEveryPixels;

    BasicPixelShift& operator=(const BasicPixelShift &tmp) = delete;
};

} // CoordinateChanger

#endif