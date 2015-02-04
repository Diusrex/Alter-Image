#include "RandomGenerators.h"

#include <cstdlib>

#include "../Coordinate.h"
#include "../PixelCoordinate.h"
#include "../StandardInformation.h"

namespace CoordinateChanger
{

PixelCoordinate RandomPixelSelected::GetShiftedPosition(const Coordinate &, const int &channel, const Coordinate &imageSize)
{
    return PixelCoordinate(rand() % imageSize.x, rand() % imageSize.y, channel);
}


PixelCoordinate RandomChannelSelector::GetShiftedPosition(const Coordinate &origionalCoordinate, const int &, const Coordinate &)
{
    return PixelCoordinate(origionalCoordinate, rand() % NUMBER_OF_CHANNELS);
}

PixelCoordinate CompletelyRandom::GetShiftedPosition(const Coordinate &, const int &, const Coordinate &imageSize)
{
    return PixelCoordinate(rand() % imageSize.x, rand() % imageSize.y, rand() % NUMBER_OF_CHANNELS);
}

} // CoordinateChanger
