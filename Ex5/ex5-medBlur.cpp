#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;

// 引数の画像ファイルを読み込みネガポジ反転して表示する
void medBlur(std::string fileName, int kernelSize)
{
    cv::Mat image = cv::imread("../bin/" + fileName);
    cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
    cv::Mat blur;

    cv::medianBlur(image, blur, kernelSize);

    cv::imshow("input", image);
    cv::imshow("Median Output" , blur);

    cv::waitKey();
}

int main(int argc, char *argv[])
{

    if (argc < 3)
        medBlur("sample.jpg", 3); //default画像
    else
    {
        std::string fileName(argv[1]);
        int kernel = atoi(argv[2]);
        medBlur(fileName, kernel);
    }

    return 0;
}