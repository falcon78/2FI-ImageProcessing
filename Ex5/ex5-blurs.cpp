#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;

// 引数の画像ファイルを読み込みネガポジ反転して表示する
void blur(std::string fileName)
{
    cv::Mat image = cv::imread("../bin/" + fileName);
	cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
	cv::Mat blur[2];
	cv::Mat gaussianBLur[2];

	cv::blur(image, blur[0], cv::Size(3,3));
	cv::GaussianBlur(image, gaussianBLur[0], cv::Size(3,3),2,0);

	cv::blur(image, blur[1], cv::Size(7,7));
	cv::GaussianBlur(image, gaussianBLur[1], cv::Size(7,7),2,0);

	cv::imshow("blur Kernel 3", blur[0]);
	cv::imshow("gaussian Kernel 3", gaussianBLur[0]);

	cv::imshow("blue kernel 7", blur[1]);
	cv::imshow("gaussian kernel 7", gaussianBLur[1]);

	cv::waitKey();

}

int main(int argc, char *argv[])
{

	if (argc < 2)
		blur("sample.jpg"); //default画像
	else
	{
		std::string fileName(argv[1]);
		blur(fileName);
	}

	return 0;
}