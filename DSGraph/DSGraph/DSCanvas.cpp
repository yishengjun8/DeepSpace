#include "pch.h"
#include "DSGraph.h"
using namespace DeepSpace;

DSOBJECT_INIT_0(DSCanvas)
DSOBJECT_INIT_1(DSCanvas)
DSOBJECT_INIT_2(DSCanvas, DSGraph);

DeepSpace::DSCanvas::DSCanvas()
{
}

DeepSpace::DSCanvas::~DSCanvas()
{
}

DSReturn DeepSpace::DSCanvas::Clone(DSBase** ret)
{
	return DSReturn();
}

DSBase& DeepSpace::DSCanvas::operator=(DSBase& rhs)
{
	// TODO: �ڴ˴����� return ���
	return *this;
}

BOOL DeepSpace::DSCanvas::operator==(DSBase& rhs)
{
	return 0;
}
