#ifndef ALTERIMAGE_H
#define ALTERIMAGE_H

#include "Coordinate.h"

#include <opencv2/highgui/highgui.hpp>

class PixelShift;

class AlterImage {
public:
    // Will take ownership of the given image
    AlterImage(const cv::Mat &mainImage);
    AlterImage(const std::string &fileName);

    cv::Mat CreateShiftedImage(PixelShift *shift) const;

    ~AlterImage();

private:

    void ChangePixel(cv::Mat &currentShiftedRow, const Coordinate &pixelToChange, PixelShift *shift) const;
    void CopyPixelFromOrigional(cv::Mat &currentShiftedImage, const Coordinate &pixelToChange, const Coordinate& pixelToCopyFrom) const;

    int CalculatePixelPosition(const Coordinate &pos, const cv::Mat &image) const;

    const cv::Mat mainImage;
    const Coordinate imageSize;
};

#endif