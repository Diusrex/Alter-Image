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
#include "SwapChannelsShift.h"

#include "../Coordinate.h"
#include "../PixelCoordinate.h"
#include "../StandardInformation.h"

namespace CoordinateChanger
{

SwapChannelsShift::SwapChannelsShift(int channelForRed, int channelForGreen, int channelForBlue)
    : channelForRed(channelForRed),
    channelForGreen(channelForGreen),
    channelForBlue(channelForBlue)
{
}

PixelCoordinate SwapChannelsShift::GetShiftedPosition(const Coordinate &origionalCoordinate, const int &channel, const Coordinate &)
{
    int newChannel;
    switch (channel)
    {
    case RED:
        newChannel = channelForRed;
        break;

    case GREEN:
        newChannel = channelForGreen;
        break;

    case BLUE:
        newChannel = channelForBlue;
        break;

    default:
        // Should never get here
        newChannel = 0;
    }

    return PixelCoordinate(origionalCoordinate, newChannel);
}

} // CoordinateChanger
