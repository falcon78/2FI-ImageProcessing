#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;

// 引数で示す角度だけ反時計回りに回転する関数
void rotate(
        const std::string &fileName,
        double deg,
        double x,
        double y,
        double scale
) {
    cv::Mat image = cv::imread("../bin/" + fileName);
    if (image.empty()) {
        std::cout << "画像読み込み失敗" << std::endl;
        return;
    }
    cv::Point position;
    position.x = x;
    position.y = y;

    cv::Mat mapMatrix = cv::getRotationMatrix2D(position, deg, scale);

    cv::Mat result;
    cv::warpAffine(image, result, mapMatrix, cv::Size(image.cols, image.rows));
    cv::imshow("Input", image);
    cv::imshow("Rotated", result);
    cv::waitKey();
}

int main(int argc, char *argv[]) {
    if (argc == 5) {
        std::string fileName = "sample.jpg";
        double deg = atof(argv[2]);
        double x = atof(argv[3]);
        double y = atof(argv[4]);
        double scale = atof(argv[5]);
        rotate(fileName, deg, x, y, scale);
        return 0;
    } else if (argc < 6) {
        std::cout << "パラメターを正しく入力してください";
        return -1;
    }
    std::string fileName(argv[1]);
    double deg = atof(argv[2]);
    double x = atof(argv[3]);
    double y = atof(argv[4]);
    double scale = atof(argv[5]);

    rotate(fileName, deg, x, y, scale);
    return 0;
}