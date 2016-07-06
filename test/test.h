/*
 * =====================================================================================
 *
 *       Filename:  test.h
 *
 *    Description:  N/A
 *
 *        Version:  1.0
 *        Created:  07/05/2016 10:09:05 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Wenbin Wang
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _TEST_H_
#define _TEST_H_

#include "core.hpp"
#include <string>

class Test {
public:
  Test();
  virtual ~Test();

  bool loadImage(const std::string& filename);
  bool optImage();
  bool saveImage(const std::string& filename);

  static void run();
private:
  cv::Mat image;
  cv::Mat outImg;
};

#endif
