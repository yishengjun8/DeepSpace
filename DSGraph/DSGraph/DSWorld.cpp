#include "pch.h"
#include "DSGraph.h"

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
	// TODO: 在此处插入 return 语句
	return *this;
}

BOOL DeepSpace::DSWorld::operator==(DSBase& rhs)
{
	return 0;
}

DSReturn DeepSpace::DSWorld::Draw()
{
	return DSReturn();
}

DSReturn DeepSpace::DSWorld::SetCanvas(DSCanvas* set)
{
	return DSReturn();
}

DSReturn DeepSpace::DSWorld::GetCanvas(DSCanvas** ret)
{
	return DSReturn();
}

DSReturn DeepSpace::DSWorld::SetText(DSStr set)
{
	return DSReturn();
}

DSReturn DeepSpace::DSWorld::GetText(DSStr* ret)
{
	return DSReturn();
}

DSReturn DeepSpace::DSWorld::SetTextSize(FLOAT set)
{
	return DSReturn();
}

DSReturn DeepSpace::DSWorld::GetTextSize(FLOAT* ret)
{
	return DSReturn();
}

DSReturn DeepSpace::DSWorld::SetTextColor(DSColor* set)
{
	return DSReturn();
}

DSReturn DeepSpace::DSWorld::GetTextColor(DSColor* ret)
{
	return DSReturn();
}

DSReturn DeepSpace::DSWorld::SetTextAlignment(UCHAR set)
{
	return DSReturn();
}

DSReturn DeepSpace::DSWorld::GetTextAlignment(UCHAR* ret)
{
	return DSReturn();
}

DSReturn DeepSpace::DSWorld::SetRect(DSRect* set)
{
	return DSReturn();
}

DSReturn DeepSpace::DSWorld::SetSize(DSSize* set)
{
	return DSReturn();
}

DSReturn DeepSpace::DSWorld::SetPoint(DSPoint* set)
{
	return DSReturn();
}

DSReturn DeepSpace::DSWorld::SetCollisionBlock(DSSize set)
{
	return DSReturn();
}