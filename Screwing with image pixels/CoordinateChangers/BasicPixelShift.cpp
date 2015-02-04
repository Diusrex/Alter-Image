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
