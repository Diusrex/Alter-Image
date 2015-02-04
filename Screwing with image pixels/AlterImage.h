#ifndef ALTERIMAGE_H
#define ALTERIMAGE_H

#include "Coordinate.h"

#include <opencv2/highgui/highgui.hpp>

namespace CoordinateChanger
{
class PixelShift;
}

class AlterImage {
public:
    // Will take ownership of the given image
    AlterImage(const cv::Mat &mainImage);
    AlterImage(const std::string &fileName);

    cv::Mat CreateShiftedImage(CoordinateChanger::PixelShift *shift) const;

    ~AlterImage();

private:

    void ChangePixel(cv::Mat &currentShiftedRow, const Coordinate &pixelToChange, CoordinateChanger::PixelShift *shift) const;

    const cv::Mat mainImage;
    const Coordinate imageSize;

    AlterImage& operator=(const AlterImage &tmp) = delete;
};

#endif