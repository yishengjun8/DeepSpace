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
	// TODO: �ڴ˴����� return ���
	return *this;
}
