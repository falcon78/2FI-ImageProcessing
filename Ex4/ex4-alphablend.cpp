#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

cv::Mat generateAlphaMask(void)
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
    return image;
}

int main(void)
{
    cv::Mat image1 = cv::imread("../bin/red.jpg");
    cv::Mat image2 = cv::imread("../bin/blue.jpg");

    cv::Mat mask = generateAlphaMask();

    cv::Mat output(cv::Size(image1.cols, image1.rows), CV_8UC3);

    for (int y = 0; y < output.rows; y++)
    {
        uchar *src = mask.ptr(y);
        uchar *image1_pointer = image1.ptr(y);
        uchar *image2_pointer = image2.ptr(y);
        uchar *p = output.ptr(y);
        for (int x = 0; x < output.cols; x++)
        {

            uchar *maskValue = &src[x];

            uchar *outBlue = &p[x * 3];
            uchar *outGreen = &p[x * 3 + 1];
            uchar *outRed = &p[x * 3 + 2];

            uchar *image1Blue = &image1_pointer[x * 3];
            uchar *image1Green = &image1_pointer[x * 3 + 1];
            uchar *image1Red = &image1_pointer[x * 3 + 2];

            uchar *image2Blue = &image2_pointer[x * 3];
            uchar *image2Green = &image2_pointer[x * 3 + 1];
            uchar *image2Red = &image2_pointer[x * 3 + 2];

            *outBlue = (*image1Blue) * (*maskValue) / 255 + (*image2Blue) * (255 - *maskValue) / 255;
            *outGreen = (*image1Green) * (*maskValue) / 255 + (*image2Green) * (255 - *maskValue) / 255;
            *outRed = (*image1Red) * (*maskValue) / 255 + (*image2Red) * (255 - *maskValue) / 255;
        }
    }

    cv::resize(image1, image1, cv::Size(), 0.5, 0.5);
    cv::resize(image2, image2, cv::Size(), 0.5, 0.5);
    cv::resize(output, output, cv::Size(), 0.5, 0.5);

    cv::imshow("Input 1", image1);
    cv::imshow("Input 2", image2);
    cv::imshow("Output", output);
    cv::waitKey();
    return 0;
}