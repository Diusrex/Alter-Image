/*
   Copyright 2015 Morgan Redshaw
  
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at
  
      http://www.apache.org/licenses/LICENSE-2.0
  
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 */
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
