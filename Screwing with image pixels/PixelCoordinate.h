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