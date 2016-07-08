/*
 * =====================================================================================
 *
 *       Filename:  IspPipeline.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/07/2016 09:14:28 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>

#include "core.hpp"

#include "ModuleBase.h"
#include "ModuleRolloff.h"
#include "ModuleChromaEnhan.h"
#include "ModuleDemosaic.h"

#include "isp.h"

using namespace std;
using namespace cv;

bool moduleComp(IspModule left, IspModule right)
{
  return left->getModuleIndex() < right->getModuleIndex();
}

struct IspPipeline
{
  IspPipeline() {
#ifdef ISP_DEMOSAIC
    curModules.push_back( makePtr<ModuleDemosaic>() );
#endif
#ifdef ISP_CHROMAENHAN
    curModules.push_back( makePtr<ModuleChromaEnhan>() );
#endif 
#ifdef ISP_ROLLOFF
    curModules.push_back( makePtr<ModuleRolloff>() );
#endif
#ifdef ISP_CCM
    curModules.push_back( makePtr<ModuleXXX>() );
#endif
#ifdef ISP_WHITEBALANCE
    curModules.push_back( makePtr<ModuleXXX>() );
#endif
	sort(curModules.begin(), curModules.end(), moduleComp);
	//showPipeline();
  }

  void showPipeline() {
    for(vector<IspModule>::iterator item = curModules.begin(); item != curModules.end(); item++)
	  cout << "ISP Module: " << (*item)->getModuleName() << endl;
  }

  std::vector<IspModule> curModules;
};

static IspPipeline isp;

Mat isp_process_raw(Mat input)
{
  Mat output(input);
  return output;
}

