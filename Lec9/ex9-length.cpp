//
// Created by falcon on 2019/12/08.
//
#include <iostream>
#include <opencv2/opencv.hpp>

int countPixels(const std::string &filename) {
    cv::Mat img = cv::imread("../bin/" + filename, cv::IMREAD_GRAYSCALE);
    int black = 0;

    for (int x = 0; x < img.cols; x++) {
        cv::Mat col = img.col(x);
        black += img.rows - cv::countNonZero(col);
    }
    return black;
}


int main(int argv, char *argc[]) {
    if (argv < 2) {
        std::cout << "ファイルを指定してください。";
        return 1;
    }
    std::string filename(argc[1]);
    int pixels = countPixels(filename);
    std::cout << "画素数: ";
    std::cout << pixels;
    std::cout << "\n";
    return 0;
}