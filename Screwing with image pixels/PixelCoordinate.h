#ifndef PIXELCOORDINATE_H
#define PIXELCOORDINATE_H


#include "Coordinate.h"

namespace cv
{
class Mat;
}

class PixelCoordinate
{
public:
    PixelCoordinate(const int &x, const int &y, int channel);
    PixelCoordinate(const Coordinate &pos, int channel);

    int CalculatePixelPosition(const cv::Mat &image) const;

    static int CalculatePixelPosition(const Coordinate &pos, const int &channel, const cv::Mat &image);

private:
    Coordinate coord;
    int channel;
};

#endif