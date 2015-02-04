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
