/*
 * =====================================================================================
 *
 *       Filename:  ModuleBase.h
 *
 *    Description:  N/A
 *
 *        Version:  1.0
 *        Created:  07/07/2016 09:11:29 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wenbin Wang
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _MODULE_BASE_H_
#define _MODULE_BASE_H_

#include <string>

class ModuleBase;

#include "core.hpp"

using namespace std;
using namespace cv;

enum {
  ISP_MODULE_LINEARZATION = 0x01,
  ISP_MDOULE_ROLLOFF,
  ISP_MODULE_STATS,
  ISP_MODULE_DEMOSAIC,
  ISP_MODULE_WB,
  ISP_MODULE_CCM,
  ISP_MODULE_GAMMA,
  ISP_MODULE_CHROMAENHAN,
  ISP_MODULE_LTM,
  ISP_MODULE_COLOR_XFORM,
  ISP_MODULE_SCALER,
  ISP_MODULE_FOVCROP,
  ISP_MODULE_CLAMP,
  ISP_MODULE_MAX
};

typedef Ptr<ModuleBase> IspModule;

class ModuleBase
{
public:
  ModuleBase(int index = 0, const string& name = "null");
  virtual ~ModuleBase();

  int getModuleIndex() const;
  string getModuleName() const;

protected:
  int moduleIndex;
  string moduleName;
};

#endif

