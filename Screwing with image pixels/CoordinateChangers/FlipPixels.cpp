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
#include "FlipPixels.h"

#include "../Coordinate.h"
#include "../PixelCoordinate.h"

namespace CoordinateChanger
{

FlipPixels::FlipPixels(bool flipHorizontal, bool flipVertical)
    : flipHorizontal(flipHorizontal),
    flipVertical(flipVertical)
{

}

PixelCoordinate FlipPixels::GetShiftedPosition(const Coordinate &origionalCoordinate, const int &channel, const Coordinate &imageSize)
{
    int x, y;
    if (flipHorizontal)
        x = imageSize.x - origionalCoordinate.x - 1;
    else
        x = origionalCoordinate.x;

    if (flipVertical)
        y = imageSize.y - origionalCoordinate.y - 1;
    else
        y = origionalCoordinate.y;

    return PixelCoordinate(x, y, channel);
}

} // CoordinateChanger
