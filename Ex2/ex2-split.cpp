#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

//画像ファイルの表示
void readImage()
{
	cv::Mat image = cv::imread("sample_split.jpg");	//画像の読み込み
	cv::Mat channels[3];

	if (image.empty())	//画像が正しく読み込めたのかを確認
	{
		cout << "画像ファイルを読み込めませんでした．" << endl;
		return;
	}

	cv::split(image, channels);

	cv::imshow("Output", image);	//画像の表示
	cv::imshow("Blue", channels[0]);
	cv::imshow("Green", channels[1]);
	cv::imshow("Red", channels[2]);

	cv::waitKey();	//入力があるまで待機
}

int main(int argc, char** argv)
{
	readImage();
	return 0;
}
