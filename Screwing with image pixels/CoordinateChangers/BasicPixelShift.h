#ifndef BASICPIXELSHIFT_H
#define BASICPIXELSHIFT_H

#include "../Coordinate.h"
#include "PixelShift.h"

class PixelCoordinate;

namespace CoordinateChanger
{

class BasicPixelShift : public PixelShift
{
public:
    BasicPixelShift(const int xShift, const int yShift, const int xShiftEveryPixels, const int yShiftEveryPixels);

    PixelCoordinate GetShiftedPosition(const Coordinate &origionalCoordinate, const int &channel, const Coordinate &imageSize) override;

private:
    bool ShouldShift(const Coordinate & origionalCoordinate);

    const int xShift, yShift;
    const int xShiftEveryPixels, yShiftEveryPixels;

    BasicPixelShift& operator=(const BasicPixelShift &tmp) = delete;
};

} // CoordinateChanger

#endif