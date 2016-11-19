#include <iostream>
#include <stdio.h>
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/objdetect/objdetect.hpp"

using namespace cv;
using namespace std;

void detectAndDisplay(Mat frame);

string face_cascade_name="/home/wenqing/Download/haarcascade_frontalface_alt.xml";
CascadeClassifier face_cascade;
string window_name="face_detcet";

int main()
{
    if(!face_cascade.load(face_cascade_name))
    {
        printf("can not loading !");
        return -1;
    }

    VideoCapture cap(0);
    if(!cap.isOpened())
    {
        cout << "can't open camera." <<endl;
        return -1;
    }

    while(1)
    {
        Mat frame;
        if(!cap.read(frame))
        {
            return -2;
        }
     detectAndDisplay(frame);
     waitKey(30);
    }

    return 0;
}

void detectAndDisplay(Mat frame)
{
    vector<Rect> faces;
    Mat frame_gray;
    cvtColor(frame,frame_gray,CV_BGR2GRAY);
    equalizeHist(frame_gray,frame_gray);
    face_cascade.detectMultiScale(frame_gray,faces,1.1,2,0|CV_HAAR_SCALE_IMAGE,Size(30,30));
    for(int i;i<faces.size();i++)
    {
        Point center(faces[i].x+faces[i].width*0.5,faces[i].y+faces[i].height*0.5);
        ellipse( frame, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 0, 0, 255 ), 4, 8, 0 );

    }


    imshow(window_name,frame);
}






