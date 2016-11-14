#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<stdio.h>
using namespace cv;

int main()
{
    Mat src,dst;
    Mat src_gray;
    Mat src_gray_hist;
    Mat dst_hist;
    int histSize=255;
    int dst_histSize=255;
    float range[]={0,255};
    const float* histRange={range};


    src=imread("/home/wenqing/pictures/erjiao.jpg");
  //  std::cout << "src channels is:" << src.channels() << std::endl;
  //  imshow("src",src);

    cvtColor(src,src_gray,CV_RGB2GRAY);
    imshow("src_gray",src_gray);
   // imwrite("/home/wenqing/pictures/erjiao_gray.jpg",src_gray);
    calcHist(&src_gray,1,0,Mat(),src_gray_hist,1,&histSize,&histRange,true,false);

    int hist_w=600;
    int hist_h=600;
    int bin_w=cvRound((double) hist_w/histSize);
    Mat histImage(hist_w,hist_h,CV_8UC3,Scalar(0,0,0));

    normalize(src_gray_hist,src_gray_hist,0,histImage.rows,NORM_MINMAX,-1,Mat() );
    for( int i = 1; i < histSize; i++ )
       {
         line( histImage, Point( bin_w*(i-1), hist_h - cvRound(src_gray_hist.at<float>(i-1)) ) ,
                          Point( bin_w*(i), hist_h - cvRound(src_gray_hist.at<float>(i)) ),
                          Scalar(0,0,255), 2, 8, 0  );

       }
    namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE );
    imshow("calcHist Demo", histImage );

    equalizeHist(src_gray,dst);
    imshow("dst",dst);
    imwrite("/home/wenqing/pictures/erjiao_enhance.jpg",dst);
    calcHist(&dst,1,0,Mat(),dst_hist,1,&histSize,&histRange,true,false);

    int dst_hist_w=600;
    int dst_hist_h=600;
    int dst_bin_w=cvRound((double) hist_w/histSize);
    Mat dst_histImage(dst_hist_w,dst_hist_h,CV_8UC3,Scalar(255,255,255));
    normalize(dst_hist,dst_hist,0,dst_histImage.rows,NORM_MINMAX,-1,Mat() );
    for( int i = 1; i < dst_histSize; i++ )
       {
         line(dst_histImage, Point( dst_bin_w*(i-1), dst_hist_h - cvRound(dst_hist.at<float>(i-1)) ) ,
                          Point( dst_bin_w*(i), dst_hist_h - cvRound(dst_hist.at<float>(i)) ),
                          Scalar(0,255,255), 2, 8, 0  );

       }
    namedWindow("dst_calcHist Demo", CV_WINDOW_AUTOSIZE );
    imshow("dst_calcHist Demo", dst_histImage );


    waitKey(0);
    return 0;
}

