#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;

// 引数の画像ファイルを読み込みネガポジ反転して表示する
void sharp(const std::string& fileName)
{

    cv::VideoCapture videoFile("../bin/" + fileName);	

	if (!videoFile.isOpened())	
	{
		cout << "動画ファイルを読み込めませんでした．" << endl;
		return;
	}

	while (true)
	{
        cv::Mat frame;
		videoFile >> frame;	//動画からの画像を取得

		if (frame.data == nullptr)	//動画からの画像を全て読み込んだら終了
			break;

		cv::imshow("Output", frame);
        
        switch(cv::waitKey()){
            case 1:
                cout << "test";
            case 2:
            case 3:
            case 4:
            case 5:
            case 'q':
                cout << "test";
                return;
            default: 
                return;
        }
		
	}
}

int main(int argc, char *argv[])
{

    if (argc < 2)
        sharp("sora.avi"); //default画像
    else
    {
        std::string fileName(argv[1]);
        sharp(fileName);
    }

    return 0;
}