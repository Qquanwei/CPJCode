#include <iostream>
#include <stdio.h>
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main()
{
   Mat src,dst,src_gray;
   Mat src_rang,hsv;

   src=imread("/home/wenqing/Pictures/PandD.jpg");
   if(!src.data)
   {
       cout << "can't imread picture" <<endl;
       return -1;
   }
   imshow("src",src);

   cvtColor(src,hsv,CV_RGB2HSV);
   inRange(hsv,Scalar(0,43,46),Scalar(20,255,255),src_rang);
   imshow ("blue line",src_rang);

   cvtColor(src,src_gray,CV_RGB2GRAY);
   imshow ("src_gray",src_gray);
   GaussianBlur(src_gray,src_gray,Size(9,9),2,2);


   vector<Vec3f> circles;
   HoughCircles(src_gray,circles,CV_HOUGH_GRADIENT,1,src_gray.rows/10,123,25,0,100);
   cout << "hough is success"<<endl;
   cout <<"The number of the coin is:"<< circles.size() << endl;
   for(unsigned int i=0;i<circles.size();i++)
   {
       Point center(cvRound(circles[i][0]) , cvRound(circles[i][1]));
       int radius =cvRound(circles[i][2]);
       circle(src,center,3,Scalar(0,255,0),-1,8,0);
       circle (src,center,radius,Scalar(0,0,255),3,8,0);
   }

   imshow("circles",src);

   waitKey(0);
   return 0;
}

