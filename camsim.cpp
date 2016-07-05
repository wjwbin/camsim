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

#include "core.hpp"
#include "imgcodecs.hpp"
#include "imgcodecs/imgcodecs_c.h"

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
  Mat img;
  img = imread("/data/test.jpg", CV_LOAD_IMAGE_COLOR);
  if (! img.data) {
    cout << "Could not open or find the image!" << endl;
    return -1;
  }

  return 0;
}

