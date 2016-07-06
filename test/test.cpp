/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  N/A
 *
 *        Version:  1.0
 *        Created:  07/05/2016 10:11:11 PM
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
#include "imgproc.hpp"

#include "test.h"

using namespace std;
using namespace cv;

Test::Test()
{
  cout << "This is Test Ctor" << endl;
}

Test::~Test()
{
  cout << "This is Test Dtor" << endl;
}

void Test::run()
{
  bool rc = true;

  Ptr<Test> pt = new Test();
  if(!pt) {
    cout << "Mem Allocate failed" << endl;
    return;
  }
  rc = pt->loadImage("/usr2/wenbinw/workspace/private/camsim/test/pics/IMG_01.jpg");
  if (rc == false) {
    return;
  }

  rc = pt->optImage();
  if (rc == false) {
    return;
  }

  rc = pt->saveImage("/usr2/wenbinw/workspace/private/camsim/test/pics/IMG_01_output.jpg");
  if (rc == false)
    return;
}

bool Test::loadImage(const string& filename)
{
  cout << "Load Image... " << filename << endl;
  if (filename.empty()) {
    cout << "filename is empty" << endl;
    return false;
  }

  image = imread(filename.c_str(), CV_LOAD_IMAGE_COLOR);
  if (!image.data) {
    cout << "could not open or load file" << endl;
    return false;
  }

  return true;
}

bool Test::optImage()
{
  cvtColor(image, outImg, CV_BGR2GRAY );
  return true;
}

bool Test::saveImage(const std::string& filename)
{
  cout << "Save Image... " << filename << endl;
  if (filename.empty()) {
    cout << "filename is empty" << endl;
    return false;
  }

  imwrite(filename, outImg);
  return true;
}

