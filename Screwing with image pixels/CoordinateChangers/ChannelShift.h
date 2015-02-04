#ifndef CHANNELSHIFT_H
#define CHANNELSHIFT_H

#include "../Coordinate.h"
#include "PixelShift.h"


class PixelCoordinate;


namespace CoordinateChanger
{

class ChannelShift : public PixelShift
{
public:
    ChannelShift(Coordinate redShift, Coordinate greenShift, Coordinate blueShift, int everyX, int everyY);

    void SetNewShift(Coordinate redShift, Coordinate greenShift, Coordinate blueShift, int everyX, int everyY);

    PixelCoordinate GetShiftedPosition(const Coordinate &origionalCoordinate, const int &channel, const Coordinate &imageSize) override;

private:
    bool ShouldShift(const Coordinate & origionalCoordinate);
    PixelCoordinate Shifted(const Coordinate & origionalCoordinate, const int & channel, const Coordinate & imageSize);

    Coordinate redShift, greenShift, blueShift;
    int everyX, everyY;
};

} // CoordinateChanger

#endif