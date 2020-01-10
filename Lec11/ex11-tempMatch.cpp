#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;

void templateMatch(char *fileName, char *templName) {
    cv::Mat image = cv::imread(fileName);
    if (image.empty()) {
        std::cout << "入力画像読み込み失敗" << std::endl;
        return;
    }
    cv::Mat templ = cv::imread(templName);
    if (image.empty()) {
        std::cout << "テンプレート画像読み込み失敗" << std::endl;
        return;
    }

    cv::Mat simula;
    cv::Mat simulaout;

    cv::Mat ccorr_normed;
    cv::Mat ccoeff_normed;

    // cv::cvtColor(image,gray,CV_BGR2GRAY);
    cv::matchTemplate(image, templ, simula, cv::TM_SQDIFF_NORMED);
    cv::matchTemplate(image, templ, ccorr_normed, cv::TM_CCORR_NORMED);
    cv::matchTemplate(image, templ, ccoeff_normed, cv::TM_CCOEFF_NORMED);
    // または CV_TM_CCORR_NORMED

    // 評価データsimula の32Fから8Uへの型変換
    // 引数は，出力Mat，型(ビット深度)，
    // α(スケールファクタ), β(足される値)
    simula.convertTo(simulaout, CV_8U, -255, 255);
    ccorr_normed.convertTo(ccorr_normed, CV_8U, -255, 255);
    ccoeff_normed.convertTo(ccoeff_normed, CV_8U, -255, 255);
    // -255,255 は0～1を 255～0 に値域変換
    // 255,0 は0～1を 0～255 に値域変換
    // 127.5, 128 は-1～1を 0～255 に値域変換

    applyColorMap(simulaout, simulaout, cv::COLORMAP_HSV);
    applyColorMap(ccorr_normed, ccorr_normed, cv::COLORMAP_HSV);
    applyColorMap(ccoeff_normed, ccoeff_normed, cv::COLORMAP_HSV);

    // 入力Mat,出力Mat,閾値,maxVal,閾値処理手法
    cv::imshow("Input", image);
    cv::imshow("Template", templ);
    cv::imshow("SQDIFF_NORMED", simulaout);
    cv::imshow("CCORR_NORMED", ccorr_normed);
    cv::imshow("CCOEFF_NORMED", ccoeff_normed);
    cv::waitKey();
    return;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "agrs: filename template" << endl;
    } else {
        templateMatch(argv[1], argv[2]);
    }
    return 0;
}