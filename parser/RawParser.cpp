#include "RawParser.h"

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>


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
  if (fmt <= 0 || fmt >= RAW_FMT_INVALID) {
  	cout << "Invalid format" << endl;
	return;
  }

  format = fmt;
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

  int fd = open(filename.c_str(), O_RDONLY);
  if (fd < 0) {
  	cout << "Can not open file" << endl;
	return cv::Mat();
  }
  char temp[5];
  unsigned short p0, p1, p2, p3;
  int rc = 0;
  for (int row = 0; row < height; row++) {
  	for (int col = 0; col < width; col += 4) {
	  rc = read(fd, temp, 5);
	  if (rc < 0) {
	  	cout << "read pix failed" << endl;
		return cv::Mat();
	  }
	  unsigned short b0 = temp[0] & 0xFF;
	  unsigned short b1 = temp[1] & 0xFF;
	  unsigned short b2 = temp[2] & 0xFF;
	  unsigned short b3 = temp[3] & 0xFF;
	  unsigned short b4 = temp[4] & 0xFF;
	  p0 = ((b0 << 2) | ((b4 & 0x03) >> 0)) << 2;
	  p1 = ((b1 << 2) | ((b4 & 0x0C) >> 2)) << 2;
	  p2 = ((b2 << 2) | ((b4 & 0x30) >> 4)) << 2;
	  p3 = ((b3 << 2) | ((b4 & 0xC0) >> 6)) << 2;

      if (row % 2 == 0) {
	    image.at<Vec3w>(row, col+0) = Vec3w(0, p0 << 4, 0); //G
	    image.at<Vec3w>(row, col+1) = Vec3w(0, 0, p1 << 4); //R
        image.at<Vec3w>(row, col+2) = Vec3w(0, p2 << 4, 0); //G
	    image.at<Vec3w>(row, col+3) = Vec3w(0, 0, p3 << 4); //R
      } else {
	    image.at<Vec3w>(row, col+0) = Vec3w(p0 << 4, 0, 0); //B
	    image.at<Vec3w>(row, col+1) = Vec3w(0, p1 << 4, 0); //G
	    image.at<Vec3w>(row, col+2) = Vec3w(p2 << 4, 0, 0); //B
	    image.at<Vec3w>(row, col+3) = Vec3w(0, p3 << 4, 0); //G
      }
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
