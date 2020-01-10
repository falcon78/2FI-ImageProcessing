//
// Created by falcon on 2019/12/08.
//
#include <iostream>
#include <vector>

#include <opencv2/opencv.hpp>

// quantize the image to convertBit
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
    if (argv < 1) {
        inputImage = cv::imread("../bin/color.jpg");
    } else {
        std::string filename(argc[1]);
        inputImage = cv::imread("../bin/" + filename);
    }
    cv::Mat quantizedImage = quantizeImage(inputImage, 4);
    cv::imshow("output", quantizedImage);
    cv::waitKey(0);
    return 0;
}