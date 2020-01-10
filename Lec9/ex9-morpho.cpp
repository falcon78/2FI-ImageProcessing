#include <opencv2/opencv.hpp>
#include <iostream>

void dilateErode(const std::string &filename) {
    cv::Mat originalImage = cv::imread("../bin/" + filename);
    cv::Mat convertedImage = originalImage.clone();
    while (true) {
        switch (cv::waitKey(33)) {
            case 'q':
                std::cout << "quitting \n";
                return;
            case 'r':
                std::cout << "file reset \n";
                convertedImage = originalImage.clone();
                continue;
            case 's':
                std::cout << "file saved \n";
                cv::imwrite("../bin/dilateErode_" + filename, convertedImage);
                continue;
            case 'e':
                std::cout << "erode \n";
                cv::erode(convertedImage, convertedImage, cv::Mat());
                continue;
            case 'd':
                std::cout << "dilate \n";
                cv::dilate(convertedImage, convertedImage, cv::Mat());
                continue;
        };
        cv::imshow("Input", originalImage);
        cv::imshow("Output", convertedImage);
    }
}

int main(int argv, char *argc[]) {
    if (argv < 2) {
        std::cout << "ファイル名を指定してください。\n";
        return 1;
    }
    std::string filename(argc[1]);
    dilateErode(filename);
}
