#include "pch.h"
#include "DSBaseTest00.h"

DSOBJECT_INIT_0(DSBaseTest00)
DSOBJECT_AUTOFUNC_REG(DSBaseTest00, SayHello, 1)
DSOBJECT_AUTOFUNC_REG(DSBaseTest00, SayGoodBy, 2)
DSOBJECT_INIT_1(DSBaseTest00)
DSOBJECT_AUTOFUNC_CASE_1(DSBaseTest00, DSBase, SayHello, 1)
DSOBJECT_AUTOFUNC_CASE_0(DSBaseTest00, DSBase, SayGoodBy, 2)
DSOBJECT_INIT_2(DSBaseTest00);

DeepSpace::DSBaseTest00::DSBaseTest00()
{
	myData = 10;
}

DeepSpace::DSBaseTest00::~DSBaseTest00()
{
}

DSReturn DeepSpace::DSBaseTest00::Clone(DSBase** ret)
{
	return DSReturn();
}

DSBase& DeepSpace::DSBaseTest00::operator=(DSBase& rhs)
{
	rhs.AutoFunc(L"SetData", myData);
	return *this;
}

DSReturn DeepSpace::DSBaseTest00::SayHello(int set)
{
	std::cout << "Hello DSBaseTest00 SayHello!" << myData << std::endl;
	return DSFINE;
}

DSReturn DeepSpace::DSBaseTest00::SayGoodBy()
{
	std::cout << "Hello DSBaseTest00 SayGoodBy!" << myData << std::endl;
	return DSFINE;
}

DSReturn DeepSpace::DSBaseTest00::SetData(int set)
{
	myData = set;
	return DSFINE;
}
