#ifndef PIXELSHIFT_H
#define PIXELSHIFT_H

class PixelCoordinate;
struct Coordinate;

namespace CoordinateChanger
{

class PixelShift
{
public:
    virtual PixelCoordinate GetShiftedPosition(const Coordinate &origionalCoordinate, const int &channel, const Coordinate &imageSize) = 0;

protected:
    PixelShift() {}
};

} // CoordinateChanger

#endif