#pragma once
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;

class Converter
{
	/*
	Hàm chuyển đổi không gian màu của ảnh từ RGB sang GrayScale
	sourceImage: ảnh input
	destinationImage: ảnh output
	Hàm trả về
	0: nếu chuyển thành công
	1: nếu chuyển thất bại (không đọc được ảnh input,...)
	*/
	int RGB2GrayScale(const Mat& sourceImage, Mat& destinationImage)
	{
		if (!sourceImage.data)
		{
			return 1;
		}
		int nl = sourceImage.rows;
		int nc = sourceImage.cols;
		for (int i = 0; i < nl; i++)
		{

			const cv::Vec3b* p_src = sourceImage.ptr<cv::Vec3b>(i);
			uchar* p_des = destinationImage.ptr<uchar>(i);
			for (int j = 0; j < nc; j++)
			{
				p_des[j] = p_src[j][0] * 0.11 + p_src[j][1] * 0.59 + p_src[j][2] * 0.3;
			}
		}
		return 0;
	}

	/*
	Hàm chuyển đổi không gian màu của ảnh từ GrayScale sang RGB
	sourceImage: ảnh input
	destinationImage: ảnh output
	Hàm trả về
	0: nếu chuyển thành công
	1: nếu chuyển thất bại (không đọc được ảnh input,...)
	*/
	int GrayScale2RGB(const Mat& sourceImage, Mat& destinationImage);


	/*
	Hàm chuyển đổi không gian màu của ảnh từ RGB sang HSV
	sourceImage: ảnh input
	destinationImage: ảnh output
	Hàm trả về
	0: nếu chuyển thành công
	1: nếu chuyển thất bại (không đọc được ảnh input,...)
	*/
	int RGB2HSV(const Mat& sourceImage, Mat& destinationImage);



	/*
	Hàm chuyển đổi không gian màu của ảnh từ HSV sang RGB
	sourceImage: ảnh input
	destinationImage: ảnh output
	Hàm trả về
	0: nếu chuyển thành công
	1: nếu chuyển thất bại (không đọc được ảnh input,...)
	*/
	int HSV2RGB(const Mat& sourceImage, Mat& destinationImage);



public:
	/*
	Hàm chuyển đổi không gian màu của ảnh
	sourceImage: ảnh input
	destinationImage: ảnh output cùng kích thước, cùng loại với ảnh input
	type: loại chuyển đổi
		0,1: chuyển từ RGB sang GrayScale và ngược lại
		2,3: chuyển từ RGB sang HSV và ngược lại
	Hàm trả về
		0: nếu chuyển thành công
		1: nếu chuyển thất bại (không đọc được ảnh input hay type không chính xác,...)
	*/
	int Convert(Mat& sourceImage, Mat& destinationImage, int type)
	{
		if (type == 0 )
			return RGB2GrayScale(sourceImage, destinationImage);
	}
	//int Convert(IplImage* sourceImage, IplImage* destinationImage, int type);
	Converter();
	~Converter();
};

