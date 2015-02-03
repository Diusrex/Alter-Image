#include "BasicPixelShift.h"

#include <iostream>

BasicPixelShift::BasicPixelShift(const int xShift, const int yShift, const int xShiftEveryPixels, const int yShiftEveryPixels)
    : xShift(xShift), 
    yShift(yShift),
    xShiftEveryPixels(xShiftEveryPixels), 
    yShiftEveryPixels(yShiftEveryPixels)
{
    std::cout << xShift << "  " << yShift << " " << xShiftEveryPixels << " " << yShiftEveryPixels << '\n';
}

Coordinate BasicPixelShift::GetShiftedPosition(const Coordinate &origionalCoordinate, const Coordinate &imageSize)
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

    return Coordinate(newX, newY);
}

bool BasicPixelShift::ShouldShift(const Coordinate & origionalCoordinate)
{
    return origionalCoordinate.x % xShiftEveryPixels == 0 && origionalCoordinate.y % yShiftEveryPixels == 0;
}
