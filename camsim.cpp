/*
 * =====================================================================================
 *
 *       Filename:  camsim.cpp
 *
 *    Description:  N/A
 *
 *        Version:  1.0
 *        Created:  07/04/2016 05:17:25 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Wenbin Wang
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <string>

#include "core.hpp"
#include "imgcodecs.hpp"

#include "test.h"

#include "isp.h"
#include "parser.h"

using namespace std;
using namespace cv;

//this value specif the scale ratio from 16bit to 8bit = 2^8 / 2^12
#define SCALERATIO (0.0625)

int main(int argc, char *argv[])
{
  //Test::run();
  string raw_file = "/usr2/wenbinw/workspace/private/camsim/test/pics/IMG_19700503_214147.raw";
  cv::Mat rawImage = read_raw(raw_file, Size(4208, 3120), RAW_FMT_GRBG);
  if (!rawImage.data) {
    cout << "Could not open or load file" << endl;
    return -1;
  }
  cv::Mat rawImageDump;
  rawImage.convertTo(rawImageDump, CV_8UC3, SCALERATIO);
  imwrite("/usr2/wenbinw/workspace/private/camsim/test/pics/IMG_19700503_214147.jpg", rawImageDump);

  //out = isp_process_raw(in);
  //imwrite("/usr2/wenbinw/workspace/private/camsim/test/pics/RAW_01_out.jpg", out);
  return 0;
}

