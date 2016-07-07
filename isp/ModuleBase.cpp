/*
 * =====================================================================================
 *
 *       Filename:  ModuleBase.cpp
 *
 *    Description:  N/A
 *
 *        Version:  1.0
 *        Created:  07/07/2016 09:44:48 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wenbin Wang
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include "ModuleBase.h"

ModuleBase::ModuleBase(int index, const string& name)
  : moduleIndex(index), moduleName(name)
{

}

ModuleBase::~ModuleBase()
{

}

int ModuleBase::getModuleIndex() const
{
  return moduleIndex;
}


string ModuleBase::getModuleName() const
{
  return moduleName;
}