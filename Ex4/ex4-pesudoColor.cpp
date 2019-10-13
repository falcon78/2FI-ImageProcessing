#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;


int main(void)
{
    cv::Mat image = cv::imread("../bin/imageB.jpg");
    cv::Mat gray;

    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

    cv::Mat output(cv::Size(image.cols, image.rows), CV_8UC3);

    for (int y = 0; y < output.rows; y++)
    {
        uchar *src = gray.ptr(y);
        uchar *p = output.ptr(y);
        for (int x = 0; x < output.cols; x++)
        {
            uchar *blue = &p[x * 3];
            uchar *green = &p[x * 3 + 1];
            uchar *red = &p[x * 3 + 2];

            if (src[x] < 64)
            {
                *blue = 255;
            }
            else if (x < 128)
            {
                *blue = -4 * (*blue) + 512;
            }
            else
            {
                *blue = 0;
            }

            if (src[x] < 64)
            {
                *green = 4 * (*green);
            }
            else if (src[x] < 192)
            {
                *green = 255;
            }
            else
            {
                *green = -4 * (*green) + 512;
            }

            if (src[x] < 128)
            {
                *red = 0;
            }
            else if (src[x] < 192)
            {
                *red = 4 + (*red);
            }
            else
            {
                *red = 255;
            }
        }
    }

    cv::resize(gray, gray, cv::Size(), 0.5, 0.5);
    cv::resize(output, output, cv::Size(), 0.5, 0.5);

    cv::imshow("original", gray);
    cv::imshow("out", output);
    cv::waitKey();
    return 0;
}