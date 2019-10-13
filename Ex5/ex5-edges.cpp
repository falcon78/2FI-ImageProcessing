#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;

// 引数の画像ファイルを読み込みネガポジ反転して表示する
void edges(std::string fileName, int depth , int thresHold1, int thresHold2)
{
    cv::Mat image = cv::imread("../bin/" + fileName);
    cv::cvtColor(image, image, cv::COLOR_BGR2GRAY)
    cv::Mat laplacian;
    cv::Mat canny;

    cv::Laplacian(image, laplacian, CV_8U, depth);
    cv::Canny(image, canny, thresHold1, thresHold2);

    cv::imshow("original", image);
    cv::imshow("Laplacian", laplacian);
    cv::imshow("canny", canny);

    cv::waitKey();
}

int main(int argc, char *argv[])
{

    if (argc < 4)
        edges("sample.jpg", 3, 100, 200); //default画像
    else
    {
        std::string fileName(argv[1]);
        int depth = atoi(argv[2]);
        int thresHold1 = atoi(argv[3]);
        int thresHold2 = atoi(argv[4]);
        edges(fileName, depth, thresHold1, thresHold2);
    }

    return 0;
}