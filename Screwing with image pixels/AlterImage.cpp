#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "AlterImage.h"

#include "Coordinate.h"
#include "PixelShift.h"


AlterImage::AlterImage(const cv::Mat &mainImage)
    : mainImage(mainImage),
    imageSize(mainImage.cols, mainImage.rows)
{
}

AlterImage::AlterImage(const std::string &fileName)
    : mainImage(cv::imread("testingImage.jpg")),
    imageSize(mainImage.cols, mainImage.rows)
{
}

AlterImage::~AlterImage()
{

}

cv::Mat AlterImage::CreateShiftedImage(PixelShift *shift) const
{
    cv::Mat currentShiftedImage = mainImage.clone();

    for (int x = 0; x < imageSize.x; x++)
        for (int y = 0; y < imageSize.y; y++)
            ChangePixel(currentShiftedImage, Coordinate(x, y), shift);

    return currentShiftedImage;
}

void AlterImage::ChangePixel(cv::Mat &currentShiftedImage, const Coordinate &pixelToChange, PixelShift *shift) const
{
    Coordinate pixelToCopyFrom = shift->GetShiftedPosition(pixelToChange, imageSize);

    CopyPixelFromOrigional(currentShiftedImage, pixelToChange, pixelToCopyFrom);
}

void AlterImage::CopyPixelFromOrigional(cv::Mat &currentShiftedImage, const Coordinate &pixelToChange, const Coordinate& pixelToCopyFrom) const
{
    for (int channel = 0; channel < mainImage.channels(); channel++)
        currentShiftedImage.data[CalculatePixelPosition(pixelToChange, currentShiftedImage) + channel] = mainImage.data[CalculatePixelPosition(pixelToCopyFrom, mainImage) + channel];
}

int AlterImage::CalculatePixelPosition(const Coordinate &pos, const cv::Mat &image) const
{
    return image.step[0] * pos.y + image.step[1] * pos.x;
}
