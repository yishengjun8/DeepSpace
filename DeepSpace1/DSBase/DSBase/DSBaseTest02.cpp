#include "pch.h"
#include "DSBaseTest02.h"

DSOBJECT_INIT_0(DSBaseTest02)
DSOBJECT_AUTOFUNC_REG(DSBaseTest02, SayHello, 1)
DSOBJECT_AUTOFUNC_REG(DSBaseTest02, SayGoodBy, 2)
DSOBJECT_INIT_1(DSBaseTest02)
DSOBJECT_AUTOFUNC_CASE_1(DSBaseTest02, DSBaseTest01, SayHello, 1)
DSOBJECT_AUTOFUNC_CASE_0(DSBaseTest02, DSBaseTest01, SayGoodBy, 2)
DSOBJECT_INIT_2(DSBaseTest02, DSBaseTest01);

DeepSpace::DSBaseTest02::DSBaseTest02()
{
	DSCODELOCK(this);
	myData = 200;
}

DeepSpace::DSBaseTest02::~DSBaseTest02()
{
	DSCODELOCK(this);
}

DSReturn DeepSpace::DSBaseTest02::Clone(DSBase** ret)
{
	DSCODELOCK(this);
	return DSReturn();
}

DSBase& DeepSpace::DSBaseTest02::operator=(DSBase& rhs)
{
	// TODO: 在此处插入 return 语句
	DSCODELOCK(this);
	rhs.AutoFunc(L"SetData", myData);
	return *this;
}

BOOL DeepSpace::DSBaseTest02::operator==(DSBase& rhs)
{
	return 0;
}

DSReturn DeepSpace::DSBaseTest02::SayHello(int set)
{
	DSCODELOCK(this);
	std::cout << "Hello DSBaseTest02 SayHello!" << myData << std::endl;
	return DSFINE;
}

DSReturn DeepSpace::DSBaseTest02::SayGoodBy()
{
	DSCODELOCK(this);
	std::cout << "Hello DSBaseTest02 SayGoodBy!" << myData << std::endl;
	return DSFINE;
}

DSReturn DeepSpace::DSBaseTest02::SetData(int set)
{
	DSCODELOCK(this);
	myData = set;
	return DSFINE;
}
