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
#include "opencv2/opencv.hpp"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <time.h>
#include <cstdlib>
#include <sstream>

#include "AlterImage.h"
#include "Coordinate.h"
#include "StandardInformation.h"

#include "CoordinateChangers/BasicPixelShift.h"
#include "CoordinateChangers/ChannelShift.h"
#include "CoordinateChangers/FlipPixels.h"
#include "CoordinateChangers/RandomGenerators.h"
#include "CoordinateChangers/SwapChannelsShift.h"

const std::string DEFAULT_IMAGE = "testingImage.jpg";

std::string toString(int number);

std::string GetImageToChange(int argc, char ** argv);

void GenerateBasicPixelShift(const AlterImage &alterImage);
void GenerateChannelShift(const AlterImage &alterImage);

void GenerateAllFlipPixels(const AlterImage &alterImage);

void GenerateAllChannelSwaps(const AlterImage &alterImage);

void GenerateChannelSwaps(const AlterImage &alterImage);
void GenerateCompletelyRandom(const AlterImage &alterImage);

void SaveFile(const std::string & name, const cv::Mat & image);


std::string GetImageToChange(int argc, char ** argv);

int main(int argc, char **argv)
{
    srand(static_cast<unsigned int>(time(NULL)));

    std::string usedImage = GetImageToChange(argc, argv);

    AlterImage alterImage{ usedImage };

    // Add specific actions you want to do.
        // May add command line options
    GenerateChannelShift(alterImage);
}

std::string GetImageToChange(int argc, char ** argv)
{
    if (argc >= 2)
        return argv[1];
    else
        return DEFAULT_IMAGE;
}

void GenerateBasicPixelShift(const AlterImage &alterImage)
{
    int everyNumberX, everyNumberY, moveX, moveY;

    std::cout << "How often do you want x's to change? "; std::cin >> everyNumberX;
    std::cout << "How often do you want y's to change? "; std::cin >> everyNumberY;

    std::cout << "How much do you want x's to change? "; std::cin >> moveX;
    std::cout << "How much do you want y's to change? "; std::cin >> moveY;

    CoordinateChanger::BasicPixelShift shift(moveX, moveY, everyNumberX, everyNumberY);

    std::string saveName = toString(moveX) + "  " + toString(moveY) + "  " + toString(everyNumberX) + " " + toString(everyNumberY);

    std::cout << "Save name: " << saveName << '\n';

    SaveFile(saveName, alterImage.CreateShiftedImage(&shift));
}

void GenerateChannelShift(const AlterImage &alterImage)
{
    int everyX = 2, everyY = 2;
    Coordinate red, green, blue;

    int value = 25;
    int increase = 25;

    CoordinateChanger::ChannelShift shift(red, green, blue, everyX, everyY);

    for (red.x = -value; red.x <= value; red.x += increase)
    {
        for (red.y = -value; red.y <= value; red.y += increase)
        {
            for (green.x = -value; green.x <= value; green.x += increase)
            {
                for (green.y = -value; green.y <= value; green.y += increase)
                {
                    for (blue.x = -value; blue.x <= value; blue.x += increase)
                    {
                        for (blue.y = -value; blue.y <= value; blue.y += increase)
                        {
                            std::string fileName = "R" + toString(red.x) + ' ' + toString(red.y) + "G" + toString(green.x) + ' ' + toString(green.y) + "B" + toString(blue.x) + ' ' + toString(blue.y);

                            shift.SetNewShift(red, green, blue, everyX, everyY);

                            SaveFile(fileName, alterImage.CreateShiftedImage(&shift));
                        }
                    }
                }
            }
        }
    }

}

void GenerateAllFlipPixels(const AlterImage &alterImage)
{
    CoordinateChanger::FlipPixels flipPixels(true, true);
    SaveFile("Both", alterImage.CreateShiftedImage(&flipPixels));
    flipPixels = CoordinateChanger::FlipPixels(false, true);
    SaveFile("Vertical", alterImage.CreateShiftedImage(&flipPixels));
    flipPixels = CoordinateChanger::FlipPixels(true, false);
    SaveFile("Horizontal", alterImage.CreateShiftedImage(&flipPixels));
}

void GenerateAllChannelSwaps(const AlterImage &alterImage)
{
    for (int red = 0; red < NUMBER_OF_CHANNELS; ++red)
    {
        for (int green = 0; green < NUMBER_OF_CHANNELS; ++green)
        {
            for (int blue = 0; blue < NUMBER_OF_CHANNELS; ++blue)
            {
                std::string fileName = "R" + toString(red) + "G" + toString(green) + "B" + toString(blue);

                CoordinateChanger::SwapChannelsShift shift(red, green, blue);
                SaveFile(fileName, alterImage.CreateShiftedImage(&shift));
            }
        }
    }
}

void GenerateChannelSwaps(const AlterImage &alterImage)
{
    CoordinateChanger::RandomChannelSelector selector;
    for (int i = 0; i < 10; ++i)
    {
        SaveFile("ChannelSwap" + toString(i), alterImage.CreateShiftedImage(&selector));
    }
}

void GenerateCompletelyRandom(const AlterImage &alterImage)
{
    CoordinateChanger::CompletelyRandom random;
    for (int i = 0; i < 10; ++i)
    {
        SaveFile("CompletelyRandom" + toString(i), alterImage.CreateShiftedImage(&random));
    }
}

void SaveFile(const std::string & name, const cv::Mat & image)
{
    if (imwrite("converted\\" + name + ".jpg", image))
        std::cout << "Saving '" + name + "' succeeded.\n";
    else
        std::cout << "Saving '" + name + "' succeeded.\n";
}

std::string toString(int number)
{
    std::stringstream ss;
    ss << number;
    std::string temp;
    ss >> temp;
    return temp;
}