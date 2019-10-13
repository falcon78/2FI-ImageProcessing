#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main (void) {
    cv::Mat input = cv::imread("../bin/sample.jpg");
    cv::Mat image;

    cv::cvtColor(input, image, cv::COLOR_BGR2GRAY);

     for (int y = 0; y < image.rows; y++) {
        uchar *p = image.ptr(y);
        for (int x = 0; x < image.cols; x++) {
            if (p[x] <= 85) {
                p[x] *= 2;
            } else {
                p[x] = 0.5 * p[x] + 128;
            }
        }
    }

    cv::imshow("out", image);
    cv::waitKey();
    return 0;

}