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

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
  Mat img;
  string img_path("/local/mnt/workspace/private/camsim/test/pics/IMG_01.jpg");

  img = imread(img_path.c_str(), CV_LOAD_IMAGE_COLOR);
  if (img.data == NULL) {
    cout << "Could not open or find the image!" << endl;
    return -1;
  }

  cout << img.size << endl;

  return 0;
}

