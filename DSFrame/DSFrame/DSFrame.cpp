#include "pch.h"
#include "DSFrame.h"

DSOBJECT_INIT_0(DSFrame)
DSOBJECT_INIT_1(DSFrame)
DSOBJECT_INIT_2(DSFrame, DSBase);

DeepSpace::DSFrame::DSFrame()
{
}

DeepSpace::DSFrame::~DSFrame()
{
}

DSReturn DeepSpace::DSFrame::Clone(DSBase** ret)
{
	return DSReturn();
}

DSBase& DeepSpace::DSFrame::operator=(DSBase& rhs)
{
	// TODO: �ڴ˴����� return ���
	return *this;
}
