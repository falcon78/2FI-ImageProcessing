//
// Created by falcon on 2019/12/08.
//

#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat quantizeImage(const cv::Mat &inputImage, int convertBit) {
    cv::Mat outputImage = inputImage.clone();

    uchar mask = 0xFF;

    mask = mask << (8 - convertBit);

    for (int j = 0; j < outputImage.rows; j++)
        for (int i = 0; i < outputImage.cols; i++) {
            cv::Vec3b valVec = outputImage.at<cv::Vec3b>(j, i);
            valVec[0] = valVec[0] & mask;
            valVec[1] = valVec[1] & mask;
            valVec[2] = valVec[2] & mask;
            outputImage.at<cv::Vec3b>(j, i) = valVec;
        }
    return outputImage;
}

int main(int argv, char *argc[]) {
    cv::Mat inputImage;
    inputImage = cv::imread("../bin/color.jpg");
    int convertBit = 4;
    if (argv > 1) {
        convertBit = std::stoi(argc[1]);
    }
    if (convertBit == 1) {
        cv::imshow("input", inputImage);
        cv::waitKey(0);
        return 0;
    } else if (convertBit >= 2 && convertBit <= 128) {
        cv::Mat quantizedImage = quantizeImage(inputImage, convertBit);
        cv::imshow("output", quantizedImage);
        cv::waitKey(0);
        return 0;
    } else {
        std::cout << convertBit;
        std::cout << "エラー: 入力値2〜128の範囲外です。";
    }
}
