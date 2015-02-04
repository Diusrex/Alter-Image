#ifndef RANDOMPIXELSELECTED_H
#define RANDOMPIXELSELECTED_H

#include "PixelShift.h"

class PixelCoordinate;

namespace CoordinateChanger
{

class RandomPixelSelected : public PixelShift
{
public:
    PixelCoordinate GetShiftedPosition(const Coordinate &origionalCoordinate, const int &channel, const Coordinate &imageSize) override;
};

class RandomChannelSelector : public PixelShift
{
public:
    PixelCoordinate GetShiftedPosition(const Coordinate &origionalCoordinate, const int &channel, const Coordinate &imageSize) override;
};

class CompletelyRandom : public PixelShift
{
public:
    PixelCoordinate GetShiftedPosition(const Coordinate &origionalCoordinate, const int &channel, const Coordinate &imageSize) override;
};

} // CoordinateChanger

#endif