#ifndef PIXELSHIFT_H
#define PIXELSHIFT_H

class PixelShift
{
public:
    virtual Coordinate GetShiftedPosition(const Coordinate &origionalCoordinate, const Coordinate &imageSize) = 0;

protected:
    PixelShift() {}
};

#endif