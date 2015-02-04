#include "PixelCoordinate.h"

#include <opencv2/highgui/highgui.hpp>


PixelCoordinate::PixelCoordinate(const int &x, const int &y, int channel)
    : coord(x, y),
    channel(channel)
{
}

PixelCoordinate::PixelCoordinate(const Coordinate &pos, int channel)
    : coord(pos),
    channel(channel)
{
}

int PixelCoordinate::CalculatePixelPosition(const cv::Mat &image) const
{
    return CalculatePixelPosition(coord, channel, image);
}

int PixelCoordinate::CalculatePixelPosition(const Coordinate &pos, const int &channel, const cv::Mat &image)
{
    return image.step[0] * pos.y + image.step[1] * pos.x + channel;
}
