#include "ChannelShift.h"

#include "../PixelCoordinate.h"
#include "../StandardInformation.h"
namespace CoordinateChanger
{

ChannelShift::ChannelShift(Coordinate redShift, Coordinate greenShift, Coordinate blueShift, int everyX, int everyY)
    : redShift(redShift),
    greenShift(greenShift),
    blueShift(blueShift),
    everyX(everyX),
    everyY(everyY)
{
}

void ChannelShift::SetNewShift(Coordinate redShift, Coordinate greenShift, Coordinate blueShift, int everyX, int everyY)
{
    this->redShift = redShift;
    this->greenShift = greenShift;
    this->blueShift = blueShift;
    this->everyX = everyX;
    this->everyY = everyY;
}

PixelCoordinate ChannelShift::GetShiftedPosition(const Coordinate &origionalCoordinate, const int &channel, const Coordinate &imageSize)
{
    if (ShouldShift(origionalCoordinate))
        return Shifted(origionalCoordinate, channel, imageSize);

    else
        return PixelCoordinate(origionalCoordinate, channel);
}

PixelCoordinate ChannelShift::Shifted(const Coordinate & origionalCoordinate, const int & channel, const Coordinate & imageSize)
{
    Coordinate *shiftAmount;

    switch (channel)
    {
    case RED:
        shiftAmount = &redShift;
        break;

    case GREEN:
        shiftAmount = &greenShift;
        break;

    case BLUE:
        shiftAmount = &blueShift;
        break;

    default:
        // Should never get here
        return PixelCoordinate(origionalCoordinate, channel);
    }

    int newX = (imageSize.x + origionalCoordinate.x + shiftAmount->x) % imageSize.x;
    int newY = (imageSize.y + origionalCoordinate.y + shiftAmount->y) % imageSize.y;

    return PixelCoordinate(newX, newY, channel);
}

bool ChannelShift::ShouldShift(const Coordinate & origionalCoordinate)
{
    return origionalCoordinate.x % everyX == 0 && origionalCoordinate.y % everyY == 0;
}

} // CoordinateChanger