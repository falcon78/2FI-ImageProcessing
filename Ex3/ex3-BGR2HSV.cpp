#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

//画像ファイルの表示
void test()
{
	cv::Mat originalImage = cv::imread("../../bin/sleepingCat.jpg"); //画像の読み込み
	cv::Mat hsvOutput;
	cv::Mat inputChannels[3];
	cv::Mat outputChannels[3];

	if (originalImage.empty()) //画像が正しく読み込めたのかを確認
	{
		cout << "画像ファイルを読み込めませんでした．" << endl;
		return;
	}

	cv::cvtColor(originalImage, hsvOutput, cv::COLOR_BGR2HSV);
	cv::split(originalImage, inputChannels);

	cv::cvtColor(inputChannels[0], outputChannels[0], cv::COLOR_HSV2BGR);

	cv::imshow("Output", originalImage); //画像の表示
	cv::imshow("HSV", hsvOutput);

	cv::imshow("Blue", outputChannels[0]);

	cv::waitKey(); //入力があるまで待機
}

int main(int argc, char **argv)
{
	test();
	return 0;
}
