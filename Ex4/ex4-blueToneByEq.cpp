#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(void)
{
    cv::Mat image = cv::imread("../bin/sample.jpg");

    for (int y = 0; y < image.rows; y++)
    {
        uchar *p = image.ptr(y);
        for (int x = 0; x < image.cols; x++)
        {
            uchar *blueChannel = &p[x*3];
            if (*blueChannel <= 85)
            {
                *blueChannel *= 2;
            }
            else
            {
                *blueChannel = 0.5 * ( *blueChannel ) + 128;
            }
        }
    }
    cv::imshow("out", image);
    cv::waitKey();
    return 0;
}