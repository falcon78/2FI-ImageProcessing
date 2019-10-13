#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

void calcToneCurve(vector<int> &toneCurve)
{
    for (int i = 0; i < toneCurve.size(); i++)
    {
        toneCurve[i] = 255 - i;
    }
}

int main(void)
{
    cv::Mat input = cv::imread("../bin/sample.jpg");
    cv::Mat image;

    vector<int> toneCurve;
    toneCurve.resize(255);
    calcToneCurve(toneCurve);

    cv::cvtColor(input, image, cv::COLOR_BGR2GRAY);

    for (int y = 0; y < image.rows; y++)
    {
        uchar *p = image.ptr(y);
        for (int x = 0; x < image.cols; x++)
        {
            p[x] = toneCurve[p[x]];
        }
    }

    cv::imshow("Out", image);
    cv::waitKey();
    return 0;
}

