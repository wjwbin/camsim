#ifndef _RAW_PARSER_H_
#define _RAW_PARSER_H_

#include <string>
#include <iostream>
#include <algorithm>

#include "parser.h"
#include "core.hpp"

using namespace std;
using namespace cv;

class RawParser {
public:
	RawParser();
	void setSize(int w, int h);
	void setFormat(RawFmtType fmt);
	Mat readRaw(const string& filename);
    enum {
	  MAT_CHANNEL_B = 0,
	  MAT_CHANNEL_G = 1,
	  MAT_CHANNEL_R = 2
	};

private:
    int width;
	int height;
	RawFmtType format;
    int odd_ch0, odd_ch1, odd_ch2, odd_ch3;
    int evn_ch0, evn_ch1, evn_ch2, evn_ch3;
};

#endif
