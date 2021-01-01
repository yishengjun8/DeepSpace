#include "pch.h"
#include "DSBaseTest01.h"

DSOBJECT_INIT_0(DSBaseTest01)
DSOBJECT_INIT_1(DSBaseTest01)
DSOBJECT_INIT_2(DSBaseTest01, DSBaseTest00);

DeepSpace::DSBaseTest01::DSBaseTest01()
{
}

DeepSpace::DSBaseTest01::~DSBaseTest01()
{
}

DSReturn DeepSpace::DSBaseTest01::Clone(DSBase** ret)
{
	return DSReturn();
}

DSBase& DeepSpace::DSBaseTest01::operator=(DSBase& rhs)
{
	// TODO: 在此处插入 return 语句
	DSCODELOCK(this);
	rhs.AutoFunc(L"SetData", myData);
	return *this;
}

DSReturn DeepSpace::DSBaseTest01::SayHello(int set)
{
	DSCODELOCK(this);
	std::cout << "Hello DSBaseTest01 SayHello!" << myData << std::endl;
	return DSFINE;
}

DSReturn DeepSpace::DSBaseTest01::SayGoodBy()
{
	DSCODELOCK(this);
	std::cout << "Hello DSBaseTest01 SayGoodBy!" << myData << std::endl;
	return DSFINE;
}

DSReturn DeepSpace::DSBaseTest01::SetData(int set)
{
	DSCODELOCK(this);
	myData = set;
	return DSFINE;
}
