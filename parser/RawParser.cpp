#include "RawParser.h"

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

#define CAM_PAD_TO_8 8

RawParser::RawParser()
  :width(0), height(0), format(RAW_FMT_INVALID)
{
}

void RawParser::setSize(int w,int h)
{
  width = w;
  height = h;
}

void RawParser::setFormat(RawFmtType fmt)
{
  format = fmt;
  if(format == RAW_FMT_RGGB) {
	evn_ch0 = evn_ch2 = MAT_CHANNEL_R;
	evn_ch1 = evn_ch3 = MAT_CHANNEL_G;
    odd_ch0 = odd_ch2 = MAT_CHANNEL_G;
	odd_ch1 = odd_ch3 = MAT_CHANNEL_B;
  } else if (format == RAW_FMT_GRBG) {
	evn_ch0 = evn_ch2 = MAT_CHANNEL_G;
	evn_ch1 = evn_ch3 = MAT_CHANNEL_R;
    odd_ch0 = odd_ch2 = MAT_CHANNEL_B;
	odd_ch1 = odd_ch3 = MAT_CHANNEL_G;
  } else if (format == RAW_FMT_BGGR) {
	evn_ch0 = evn_ch2 = MAT_CHANNEL_B;
	evn_ch1 = evn_ch3 = MAT_CHANNEL_G;
    odd_ch0 = odd_ch2 = MAT_CHANNEL_G;
	odd_ch1 = odd_ch3 = MAT_CHANNEL_R;
  } else if (format == RAW_FMT_GBRG) {
	evn_ch0 = evn_ch2 = MAT_CHANNEL_G;
	evn_ch1 = evn_ch3 = MAT_CHANNEL_B;
    odd_ch0 = odd_ch2 = MAT_CHANNEL_R;
	odd_ch1 = odd_ch3 = MAT_CHANNEL_G;
  } else {
    cout << "Invalid format" << endl;
	format = RAW_FMT_INVALID;
  }
}

Mat RawParser::readRaw(const string& filename)
{
  if (width == 0 || height == 0) {
    cout << "Invalid image size" << endl;
    return Mat();
  }

  if (format == RAW_FMT_INVALID) {
    cout << "Invalid image format" << endl;
    return cv::Mat();
  }
  Mat image(height, width, CV_16UC3, Scalar(0,0,0));

  FILE *fp = fopen(filename.c_str(), "rb");
  if (fp == NULL) {
    cout << "Can not open file" << endl;
    return cv::Mat();
  }
  char temp[8];
  unsigned short p0, p1, p2, p3;
  int ch0, ch1, ch2, ch3;
  int rc = 0, pad_size;
  for (int row = 0; row < height; row++) {
    //specify the RGB channel for each 4 pixels
    ch0 = row % 2 ? odd_ch0 : evn_ch0;
    ch1 = row % 2 ? odd_ch1 : evn_ch1;
    ch2 = row % 2 ? odd_ch2 : evn_ch2;
    ch3 = row % 2 ? odd_ch3 : evn_ch3;
    for (int col = 0; col < width; col += 4) {
      rc = fread(temp, 5, 1, fp);
      if (rc < 0) {
        cout << "read pix failed" << endl;
        return cv::Mat();
      }
      image.at<Vec3w>(row, col+0)[ch0] =
	  	((((unsigned short)temp[0] & 0xFF) << 2) | ((temp[4] & 0x03) >> 0)) << 2;
      image.at<Vec3w>(row, col+1)[ch1] =
	  	((((unsigned short)temp[1] & 0xFF) << 2) | ((temp[4] & 0x03) >> 0)) << 2;
      image.at<Vec3w>(row, col+2)[ch2] =
	  	((((unsigned short)temp[2] & 0xFF) << 2) | ((temp[4] & 0x03) >> 0)) << 2;;
      image.at<Vec3w>(row, col+3)[ch3] =
	  	((((unsigned short)temp[3] & 0xFF) << 2) | ((temp[4] & 0x03) >> 0)) << 2;
    }
    //read the pading pixel
    pad_size =  CAM_PAD_TO_8 - (width / 4 * 5) % CAM_PAD_TO_8;
    rc = fread(temp, pad_size, 1, fp);
    if (rc < 0) {
      cout << "read pix failed" << endl;
      return cv::Mat();
    }
  }
  return image;
}

static RawParser rawParser;

Mat read_raw(const string& filename, const Size& size, RawFmtType fmt)
{
  rawParser.setSize(size.width, size.height);
  rawParser.setFormat(fmt);
  return rawParser.readRaw(filename);
}
