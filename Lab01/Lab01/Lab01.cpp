// test_open.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Converter.h"
#include "ColorTransformer.h"
int main()
{


	Mat image = imread("D:\\test.jpg", CV_LOAD_IMAGE_COLOR);
	Mat des_grayscale = Mat(image.rows, image.cols, CV_8UC1);
	Mat des_histogram = Mat(image.rows, image.cols, CV_8UC1);
	Converter C;
	ColorTransformer T;
	int res_c = C.Convert(image, des_grayscale, 0);

	int res_t = T.HistogramEqualization(des_grayscale, des_histogram);

	//namedWindow("Show Destination Image Transform");  imshow("Show Destination Image Transform", des_histogram);
	//waitKey(0);

	return 0;

}

