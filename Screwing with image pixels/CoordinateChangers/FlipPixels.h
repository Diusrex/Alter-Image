#ifndef FLIPPIXELS_H
#define FLIPPIXELS_H

#include "PixelShift.h"

struct Coordinate;
class PixelCoordinate;

namespace CoordinateChanger
{

class FlipPixels : public PixelShift
{
public:
    FlipPixels(bool flipHorizontal, bool flipVertical);
    PixelCoordinate GetShiftedPosition(const Coordinate &origionalCoordinate, const int &channel, const Coordinate &imageSize);

private:
    bool flipHorizontal, flipVertical;
};

} // CoordinateChanger

#endif