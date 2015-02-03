#include "opencv2/opencv.hpp"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <sstream>

#include "AlterImage.h"
#include "BasicPixelShift.h"

std::string toString(int number)
{
	std::stringstream ss;
	ss << number;
	std::string temp;
	ss >> temp;
	return temp;
}


int main()
{
    AlterImage alterImage("testingImage.jpg");

	int everyNumberX, everyNumberY, moveX, moveY;

	std::cout << "How often do you want x's to change? "; std::cin >> everyNumberX;
	std::cout << "How often do you want y's to change? "; std::cin >> everyNumberY;

	std::cout << "How much do you want x's to change? "; std::cin >> moveX;
	std::cout << "How much do you want y's to change? "; std::cin >> moveY;

    BasicPixelShift shift(moveX, moveY, everyNumberX, everyNumberY);
	
    cv::Mat image = alterImage.CreateShiftedImage(&shift);

	std::string saveName = toString(moveX) + "  " + toString(moveY) + "  " + toString(everyNumberX) + " " + toString(everyNumberY) + ".jpg";

    std::cout << "Save name: " << saveName << '\n';
    imwrite(saveName, image);

    // cvReleaseImage
	return 0;
}

