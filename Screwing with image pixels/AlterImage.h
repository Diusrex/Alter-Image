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