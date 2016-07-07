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

private:
    int width;
	int height;
	RawFmtType format;
};

#endif
