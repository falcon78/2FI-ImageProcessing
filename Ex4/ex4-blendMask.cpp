#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(void)
{
    float horizontal = 640;
    int vertical = 480;
    cv::Mat image(cv::Size(horizontal, vertical), CV_8UC1);

    for (int y = 0; y < image.rows; y++)
    {
        uchar *p = image.ptr(y);
        for (int x = 0; x < image.cols; x++)
        {
            p[x] = (float)x / 640 * 255;
        }
    }
    cv::imshow("out", image);
    cv::waitKey();
    return 0;
}