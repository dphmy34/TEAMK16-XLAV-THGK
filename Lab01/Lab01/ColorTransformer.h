#pragma once
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;

class ColorTransformer
{
public:
	/*
	Hàm nhận vào một ảnh, thay đổi độ sáng của ảnh này và lưu kết quả vào ảnh mới
	Tham so:
		sourceImage	: ảnh ban đầu
		destinationImage: ảnh kết quả
		b	: giá trị số nguyên dùng để thay đổi độ sáng của ảnh
	Hàm trả về:
		1: Nếu thành công thì trả về ảnh kết quả (ảnh gốc vẫn giữ nguyên giá trị)
		0: Nếu không tạo được ảnh kết quả hoặc ảnh input không tồn tại
	*/
	int ChangeBrighness(const Mat& sourceImage, Mat& destinationImage, short b);

	/*
	Hàm nhận vào một ảnh, thay đổi độ tương phản của ảnh này và lưu kết quả vào ảnh mới
	Tham so :
		sourceImage : ảnh ban đầu
		destinationImage : ảnh kết quả
		c	: giá trị số thực dùng để thay đổi độ tương phản của ảnh
	Hàm trả về:
		1: Nếu thành công thì trả về ảnh kết quả (ảnh gốc vẫn giữ nguyên giá trị)
		0: Nếu không tạo được ảnh kết quả hoặc ảnh input không tồn tại
	*/
	int ChangeContrast(const Mat& sourceImage, Mat& destinationImage, float c);


	/*
	Hàm cân bằng lược đồ màu tổng quát cho ảnh bất kỳ
	Tham so :
		sourceImage : ảnh ban đầu
		destinationImage : ảnh kết quả
	Hàm trả về:
		1: Nếu thành công thì trả về ảnh kết quả (ảnh gốc vẫn giữ nguyên giá trị)
		0: Nếu không tạo được ảnh kết quả hoặc ảnh input không tồn tại
	*/
	int HistogramEqualization(const Mat& sourceImage, Mat& destinationImage)
	{
		if (!sourceImage.data)
		{
			return 1;
		}
		int nl = sourceImage.rows;
		int nc = sourceImage.cols;
		int H[256] = {};
		int TR[256] = {};
		//Tinh histogram cua anh
		for (int i = 0; i < nl; i++)
		{
			const uchar*p_src = sourceImage.ptr<uchar>(i);
			for (int j = 0; j < nc; j++)
			{
				H[p_src[j]] += 1;
			}
		}


		//Luot do xam tich luy, Chuan hoa ve doan [0;255]
		TR[0] = round(((256 - 1) / (nl*nc))*H[0]);
		for (int k = 1; k < 256; k++)
		{
			H[k] = H[k - 1] + H[k];
			TR[k] = round((float(256 - 1) / (nl*nc*1.0))*H[k]);
		}


		// tao anh ket qua
		for (int i = 0; i < nl; i++)
		{
			const uchar*p_src = sourceImage.ptr<uchar>(i);
			uchar*p_des = destinationImage.ptr<uchar>(i);

			for (int j = 0; j < nc; j++)
			{
				p_des[j] = TR[p_src[j]];
			}
		}

		return 0;
	}

	/*
	Hàm so sánh hai ảnh
	Tham so :
		image1 : ảnh thứ nhất
		image2 : ảnh thứ hai
	Hàm trả về:
		độ đo sự tương đồng giữa hai ảnh
	*/
	float CompareImage(const Mat& image1, Mat& image2);


	ColorTransformer();
	~ColorTransformer();
};

