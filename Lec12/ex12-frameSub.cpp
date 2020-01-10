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
            if (redDiff + greenDiff + blueDiff < pow(threshold, 2)) {
                outputImageRgb[0] = 0;
                outputImageRgb[1] = 0;
                outputImageRgb[2] = 0;
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
    auto delay = 1.0;
    cv::Mat referenceImage;
    cv::Mat referenceImage2;
    cv::Mat capturedFrame;
    cap >> referenceImage;
    cap >> capturedFrame;

    while (true) {
        std::cout << "threshold: ";
        std::cout << threshold;
        std::cout << "\n";
        std::cout << "delay: ";
        std::cout << delay;
        std::cout << "\n";
        cap >> referenceImage;
        cv::waitKey(delay * 1000);
        cap >> referenceImage2;
        cv::waitKey(delay * 1000);
        cap >> capturedFrame;
        cv::Mat diff1 = motionDetection(capturedFrame, referenceImage, threshold);
        cv::Mat diff2 = motionDetection(capturedFrame, referenceImage2, threshold);
        cv::Mat andMaskResult;
        cv::bitwise_and(diff1, diff2, andMaskResult);
        cv::bitwise_and(capturedFrame, andMaskResult, andMaskResult);
        cv::imshow("Motion Detection", andMaskResult);
        switch (cv::waitKey(33)) {
            case 'q':
                return 0;
            case 'u':
                threshold++;
                continue;
            case 'd':
                threshold--;
                continue;
            case 'U':
                delay += 0.5;
                continue;
            case 'D':
                delay -= 0.5;
                continue;
            default:
                continue;
        }

    }
}

