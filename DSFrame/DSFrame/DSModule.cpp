#include "pch.h"
#include "DSFrame.h"

DSOBJECT_INIT_0(DSModule)
DSOBJECT_INIT_1(DSModule)
DSOBJECT_INIT_2(DSModule, DSBase);


DeepSpace::DSModule::DSModule()
{
}

DeepSpace::DSModule::~DSModule()
{
}

DSReturn DeepSpace::DSModule::Clone(DSBase** ret)
{
	return DSReturn();
}

DSBase& DeepSpace::DSModule::operator=(DSBase& rhs)
{
	// TODO: 在此处插入 return 语句
	return *this;
}
