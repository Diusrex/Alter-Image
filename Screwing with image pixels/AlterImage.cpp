#include "AlterImage.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


#include "Coordinate.h"
#include "PixelCoordinate.h"
#include "CoordinateChangers/PixelShift.h"


AlterImage::AlterImage(const cv::Mat &mainImage)
    : mainImage(mainImage),
    imageSize(mainImage.cols, mainImage.rows)
{
}

AlterImage::AlterImage(const std::string &fileName)
    : mainImage(cv::imread(fileName)),
    imageSize(mainImage.cols, mainImage.rows)
{
}

AlterImage::~AlterImage()
{

}

cv::Mat AlterImage::CreateShiftedImage(CoordinateChanger::PixelShift *shift) const
{
    cv::Mat currentShiftedImage = mainImage.clone();

    for (int x = 0; x < imageSize.x; x++)
        for (int y = 0; y < imageSize.y; y++)
            ChangePixel(currentShiftedImage, Coordinate(x, y), shift);

    return currentShiftedImage;
}

void AlterImage::ChangePixel(cv::Mat &currentShiftedImage, const Coordinate &pixelToChange, CoordinateChanger::PixelShift *shift) const
{
    for (int channel = 0; channel < mainImage.channels(); channel++)
    {
        PixelCoordinate pixelToCopyFrom = shift->GetShiftedPosition(pixelToChange, channel, imageSize);
        currentShiftedImage.data[PixelCoordinate::CalculatePixelPosition(pixelToChange, channel, currentShiftedImage)] = mainImage.data[pixelToCopyFrom.CalculatePixelPosition(mainImage)];
    }
}
