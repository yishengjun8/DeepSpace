#include "pch.h"
#include "DSGraph.h"
using namespace DeepSpace;

DSOBJECT_INIT_0(DSImage)
DSOBJECT_INIT_1(DSImage)
DSOBJECT_INIT_2(DSImage, DSGraph);

DeepSpace::DSImage::DSImage()
{
}

DeepSpace::DSImage::~DSImage()
{
}

DSReturn DeepSpace::DSImage::Clone(DSBase** ret)
{
	return DSReturn();
}

DSBase& DeepSpace::DSImage::operator=(DSBase& rhs)
{
	// TODO: �ڴ˴����� return ���
	return *this;
}

bool DeepSpace::DSImage::operator==(DSBase& rhs)
{
	return false;
}
