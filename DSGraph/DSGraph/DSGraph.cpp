#include "pch.h"
#include "DSGraph.h"
using namespace DeepSpace;

DSOBJECT_INIT_0(DSGraph)
DSOBJECT_INIT_1(DSGraph)
DSOBJECT_INIT_2(DSGraph, DSBase);

DeepSpace::DSGraph::DSGraph()
{
	DSCODELOCK(this);
}

DeepSpace::DSGraph::~DSGraph()
{
	DSCODELOCK(this);
}

DSReturn DeepSpace::DSGraph::Clone(DSBase** ret)
{
	DSCODELOCK(this);
	return DSFINE;
}

DSBase& DeepSpace::DSGraph::operator=(DSBase& rhs)
{
	DSCODELOCK(this);
	return *this;
}

bool DeepSpace::DSGraph::operator==(DSBase& rhs)
{
	return false;
}
