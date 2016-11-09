#include <iostream>
//#include "opencv2/opencv.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main()
{
    VideoCapture cap(0);
    if(!cap.isOpened())
    {
        cout << "can't open camera." <<endl;
        return -1;
    }
    namedWindow("my camera");
    while(1)
    {
        Mat frame;
        if(!cap.read(frame))
        {
            return -2;
        }
        imshow("my camera",frame);
        waitKey(30);
    }

    return 0;
}

