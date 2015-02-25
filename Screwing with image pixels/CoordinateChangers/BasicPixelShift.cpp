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
#include "BasicPixelShift.h"

#include "../PixelCoordinate.h"

namespace CoordinateChanger
{

BasicPixelShift::BasicPixelShift(const int xShift, const int yShift, const int xShiftEveryPixels, const int yShiftEveryPixels)
    : xShift(xShift), 
    yShift(yShift),
    xShiftEveryPixels(xShiftEveryPixels), 
    yShiftEveryPixels(yShiftEveryPixels)
{
}

PixelCoordinate BasicPixelShift::GetShiftedPosition(const Coordinate &origionalCoordinate, const int &channel, const Coordinate &imageSize)
{
    int newX, newY;
    if (ShouldShift(origionalCoordinate))
    {
        newX = (imageSize.x + origionalCoordinate.x + xShift) % imageSize.x;
        newY = (imageSize.y + origionalCoordinate.y + yShift) % imageSize.y;
    }

    else
    {
        newX = origionalCoordinate.x;
        newY = origionalCoordinate.y;
    }

    return PixelCoordinate(newX, newY, channel);
}

bool BasicPixelShift::ShouldShift(const Coordinate & origionalCoordinate)
{
    return origionalCoordinate.x % xShiftEveryPixels == 0 && origionalCoordinate.y % yShiftEveryPixels == 0;
}   

} // CoordinateChanger
