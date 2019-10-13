#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

//画像ファイルの表示
void readImage()
{
	cv::Mat image = cv::imread("../../bin/pic.jpg");	//画像の読み込み
	cv::Mat outputHsv;
	cv::Mat outputHsvChannels[3];

	

	cv::Mat hsvBlueGray;
	cv::Mat hsvGreenGray;
	cv::Mat hsvRedGray;

	if (image.empty())	//画像が正しく読み込めたのかを確認
	{
		cout << "画像ファイルを読み込めませんでした．" << endl;
		return;
	}

	cv::cvtColor(image, outputHsv, cv::COLOR_BGR2HSV);
	cv::split(outputHsv, outputHsvChannels);

	cv::Mat hsvBlue = outputHsvChannels[0];
	cv::Mat hsvGreen = outputHsvChannels[1];
	cv::Mat hsvRed = outputHsvChannels[2];

	cv::cvtColor(hsvBlue, hsvBlueGray , cv::COLOR_BGR2GRAY);
	cv::cvtColor(hsvGreen, hsvGreenGray , cv::COLOR_BGR2GRAY);
	cv::cvtColor(hsvRed, hsvRedGray , cv::COLOR_BGR2GRAY);

	cv::imshow("Output", image);	//画像の表示
	


	cv::waitKey();	//入力があるまで待機
}

int main(int argc, char** argv) 
{
	readImage();
	return 0;
}
