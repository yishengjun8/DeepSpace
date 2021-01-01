#include "pch.h"
#include "DSBaseTest00.h"

DSOBJECT_INIT_0(DSBaseTest00)
DSOBJECT_AUTOFUNC_REG(DSBaseTest00, SayHello, 1)
DSOBJECT_AUTOFUNC_REG(DSBaseTest00, SayGoodBy, 2)
DSOBJECT_INIT_1(DSBaseTest00)
DSOBJECT_AUTOFUNC_CASE_1(DSBaseTest00, DSBase, SayHello, 1)
DSOBJECT_AUTOFUNC_CASE_0(DSBaseTest00, DSBase, SayGoodBy, 2)
DSOBJECT_INIT_2(DSBaseTest00, DSBase);

DeepSpace::DSBaseTest00::DSBaseTest00()
{
	DSCODELOCK(this);
	myData = 0;
}

DeepSpace::DSBaseTest00::~DSBaseTest00()
{
	DSCODELOCK(this);
}

DSReturn DeepSpace::DSBaseTest00::Clone(DSBase** ret)
{
	DSCODELOCK(this);
	return DSFINE;
}

DSBase& DeepSpace::DSBaseTest00::operator=(DSBase& rhs)
{
	DSCODELOCK(this);
	rhs.AutoFunc(L"SetData", myData);
	return *this;
}

DSReturn DeepSpace::DSBaseTest00::SayHello(int set)
{
	DSCODELOCK(this);
	std::cout << "Hello DSBaseTest00 SayHello!" << myData << std::endl;
	return DSFINE;
}

DSReturn DeepSpace::DSBaseTest00::SayGoodBy()
{
	DSCODELOCK(this);
	std::cout << "Hello DSBaseTest00 SayGoodBy!" << myData << std::endl;
	return DSFINE;
}

DSReturn DeepSpace::DSBaseTest00::SetData(int set)
{
	DSCODELOCK(this);
	myData = set;
	return DSFINE;
}
