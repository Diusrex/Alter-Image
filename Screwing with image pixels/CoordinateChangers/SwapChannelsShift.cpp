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
