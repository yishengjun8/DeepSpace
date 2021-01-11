#include "pch.h"
#include "DSFrame.h"

DSOBJECT_INIT_0(DSModuleServe)
DSOBJECT_INIT_1(DSModuleServe)
DSOBJECT_INIT_2(DSModuleServe, DSBase);

DeepSpace::DSModuleServe::DSModuleServe()
{
}

DeepSpace::DSModuleServe::~DSModuleServe()
{
}

DSReturn DeepSpace::DSModuleServe::Clone(DSBase** ret)
{
	return DSReturn();
}

DSBase& DeepSpace::DSModuleServe::operator=(DSBase& rhs)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

