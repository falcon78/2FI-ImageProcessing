#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

//カメラ入力の表示
void readCamera()
{
	cv::VideoCapture cap(0);	//カメラ入力の読み込み

	if (!cap.isOpened())	//カメラ入力の読み込みに失敗したら終了
	{
		cout << "カメラ入力を読み込めませんでした．" << endl;
		return;
	}

	while (true)
	{
		cv::Mat cameraInput;
		cap >> cameraInput;	//カメラからの画像を取得

		if (cameraInput.empty())	//画像が正しく読み込めたのかを確認
		{
			cout << "カメラ入力のために待機" << endl;
			continue;
		}

		cv::Mat greyScaleImage;
		cv::Mat	blackWhiteInvert;
		cv::cvtColor(cameraInput, greyScaleImage ,cv::COLOR_BGR2GRAY );
		blackWhiteInvert = ~greyScaleImage;

		cv::imshow("Output", cameraInput);	//画像の表示
		cv::imshow("GreyScale", greyScaleImage);
		cv::imshow("NegaPosInvert", blackWhiteInvert);

		if (cv::waitKey(33) >= 0)	//33ms待機後、入力があればbreak
			break;
	}
}

int main(int argc, char** argv)
{
	readCamera();
	return 0;
}