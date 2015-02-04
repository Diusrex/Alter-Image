#ifndef SWAPCHANNELSSHIFT_H
#define SWAPCHANNELSSHIFT_H

#include "PixelShift.h"

struct Coordinate;
class PixelCoordinate;

namespace CoordinateChanger
{

class SwapChannelsShift : public PixelShift
{
public:

    SwapChannelsShift(int channelForRed, int channelForGreen, int channelForBlue);

    PixelCoordinate GetShiftedPosition(const Coordinate &origionalCoordinate, const int &channel, const Coordinate &imageSize) override;

private:
    const int channelForRed, channelForGreen, channelForBlue;

    SwapChannelsShift& operator=(const SwapChannelsShift &tmp) = delete;
};

} // CoordinateChanger

#endif