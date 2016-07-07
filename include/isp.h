/*
 * =====================================================================================
 *
 *       Filename:  isp.h
 *
 *    Description:  N/A
 *
 *        Version:  1.0
 *        Created:  07/07/2016 11:20:04 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wenbin Wang
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _ISP_H_
#define _ISP_H_

#include "core.hpp"

using namespace cv;

#define ISP_DEMOSAIC
#define ISP_CHROMAENHAN
#define ISP_ROLLOFF
//#define ISP_WHITEBALANCE

Mat process_raw(Mat input);

#endif
