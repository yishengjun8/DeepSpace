#include "pch.h"
#include "DSGraph.h"
using namespace DeepSpace;

DSOBJECT_INIT_0(DSWorld)
DSOBJECT_INIT_1(DSWorld)
DSOBJECT_INIT_2(DSWorld, DSGraph);

DeepSpace::DSWorld::DSWorld()
{
}

DeepSpace::DSWorld::~DSWorld()
{
}

DSReturn DeepSpace::DSWorld::Clone(DSBase** ret)
{
	return DSReturn();
}

DSBase& DeepSpace::DSWorld::operator=(DSBase& rhs)
{
	// TODO: �ڴ˴����� return ���
	return *this;
}

BOOL DeepSpace::DSWorld::operator==(DSBase& rhs)
{
	return 0;
}
