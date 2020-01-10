//
// Created by falcon on 2019/12/10.
//

#include <opencv2/opencv.hpp>
#include <iostream>

cv::Mat motionDetection(const cv::Mat &compareImage, const cv::Mat &referenceImage, int threshold) {
    cv::Mat outputImage = compareImage.clone();
    for (int y = 0; y < compareImage.rows; y++) {
        for (int x = 0; x < compareImage.cols; x++) {
            cv::Vec3b compareImageRgb = compareImage.at<cv::Vec3b>(y, x);
            cv::Vec3b referenceImageRgb = referenceImage.at<cv::Vec3b>(y, x);
            cv::Vec3b outputImageRgb = outputImage.at<cv::Vec3b>(y, x);
            auto redDiff = pow(compareImageRgb[0] - referenceImageRgb[0], 2);
            auto greenDiff = pow(compareImageRgb[1] - referenceImageRgb[1], 2);
            auto blueDiff = pow(compareImageRgb[2] - referenceImageRgb[2], 2);
            if (redDiff + greenDiff + blueDiff < pow(threshold,2)) {
                outputImageRgb[0] = 128;
                outputImageRgb[1] = 128;
                outputImageRgb[2] = 128;
                outputImage.at<cv::Vec3b>(y, x) = outputImageRgb;
            }
        }
    }
    return outputImage;
}

int main(int argv, char *argc[]) {
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cout << "カメラ入力を読み込めませんでした．\n";
        return 0;
    }

    int threshold = 30;
    cv::Mat referenceImage;
    cv::Mat capturedFrame;
    cap >> referenceImage;
    cap >> capturedFrame;

    while (true) {
        std::cout << "threshold: ";
        std::cout << threshold;
        std::cout << "\n";
        cap >> capturedFrame;
        cv::imshow("Input", capturedFrame);
        cv::imshow("Reference", referenceImage);
        cv::imshow("Motion Detection", motionDetection(capturedFrame, referenceImage, threshold));
        switch (cv::waitKey(33)) {
            case 's':
                cap >> referenceImage;
                continue;
            case 'q':
                return 0;
            case 'u':
                threshold++;
                continue;
            case 'd':
                threshold--;
                continue;
            default:
                continue;
        }

    }
}

