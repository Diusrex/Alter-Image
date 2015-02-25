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
#ifndef FLIPPIXELS_H
#define FLIPPIXELS_H

#include "PixelShift.h"

struct Coordinate;
class PixelCoordinate;

namespace CoordinateChanger
{

class FlipPixels : public PixelShift
{
public:
    FlipPixels(bool flipHorizontal, bool flipVertical);
    PixelCoordinate GetShiftedPosition(const Coordinate &origionalCoordinate, const int &channel, const Coordinate &imageSize);

private:
    bool flipHorizontal, flipVertical;
};

} // CoordinateChanger

#endif