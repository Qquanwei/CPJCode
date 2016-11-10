//主要打开摄像头，并显示采集到的图像

#include <iostream>
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using std::cout;
using std::endl;

int main()
{
    VideoCapture cap(0);
    if(!cap.isOpened())
    {
        cout << "can't open camera." <<endl;
        return -1;
    }
    namedWindow("my camera");
    Mat frame;
    while(cap.read(frame)
    {
        imshow("my camera",frame);
        waitKey(30);
    }

    return 0;
}

