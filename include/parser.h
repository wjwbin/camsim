/*
 * =====================================================================================
 *
 *       Filename:  parser.h
 *
 *    Description:  N/A
 *
 *        Version:  1.0
 *        Created:  07/07/2016 12:38:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wenbin Wang
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _PARSER_H_
#define _PARSER_H_

#include "core.hpp"
#include "string"

using namespace cv;
using namespace std;

typedef enum {
  RAW_FMT_RGGB = 0x01,
  RAW_FMT_GRBG,
  RAW_FMT_BGGR,
  RAW_FMT_GBRG,
  RAW_FMT_INVALID
} RawFmtType;

Mat read_raw(const string& filename, const Size& size, RawFmtType fmt);

#endif

