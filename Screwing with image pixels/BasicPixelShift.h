#ifndef BASICPIXELSHIFT_H
#define BASICPIXELSHIFT_H

#include "Coordinate.h"
#include "PixelShift.h"

class BasicPixelShift : public PixelShift
{
public:
    BasicPixelShift(const int xShift, const int yShift, const int xShiftEveryPixels, const int yShiftEveryPixels);

    Coordinate GetShiftedPosition(const Coordinate &origionalCoordinate, const Coordinate &imageSize) override;

private:
    bool ShouldShift(const Coordinate & origionalCoordinate);

    const int xShift, yShift;
    const int xShiftEveryPixels, yShiftEveryPixels;
};

#endif