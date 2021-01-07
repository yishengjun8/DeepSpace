#include "pch.h"
#include "DSBase.h"

using namespace DeepSpace;
using namespace __DeepSpace;

std::map<DSStr, DSFactoryHand*> DSFactoryMap;
typedef std::map<DSStr, DSFactoryHand*>::value_type DSFactoryValue;

DSReturn DeepSpace::DSBaseFactory(DSStr object, DSBase** ret)
{
	auto iter = DSFactoryMap.find(object);
	if (iter != DSFactoryMap.end())
	{
		return iter->second->Creat(ret);
	}
	return DSFAIL;
}

DSReturn __DeepSpace::DSRegisterObject(DSStr object, DSFactoryHand* hand)
{
	auto ret = DSFactoryMap.insert(DSFactoryValue(object, hand));
	return ret.second ? DSFINE : DSFAIL;
}

DeepSpace::DSBase::DSBase()
{
	InitializeCriticalSection(&myCriticalSection);
	myFloor = 0;
}

DeepSpace::DSBase::~DSBase()
{
	DSCODELOCK(this);
	DeleteCriticalSection(&myCriticalSection);
}

DSReturn DeepSpace::DSBase::Clone(DSBase** ret)
{
	DSCODELOCK(this);
	*ret = new DSBase;
	(*ret)->myFloor = myFloor;
	return DSFINE;
}

DSBase& DeepSpace::DSBase::operator=(DSBase& rhs)
{
	DSCODELOCK(this);
	myFloor = rhs.myFloor;
	return *this;
}

BOOL DeepSpace::DSBase::operator==(DSBase& rhs)
{
	return myFloor == rhs.myFloor;
}

DSReturn DeepSpace::DSBase::AutoFunc(DSStr func ...)
{
	return DSFINE;
}

DSReturn DeepSpace::DSBase::FuncName(DSStr* ret)
{
	DSCODELOCK(this);
	*ret = L"";
	return DSFINE;
}

DSReturn DeepSpace::DSBase::FuncInfor(DSStr* ret)
{
	DSCODELOCK(this);
	*ret = L"";
	return DSFINE;
}

DSReturn DeepSpace::DSBase::ObjectName(DSStr* ret)
{
	DSCODELOCK(this);
	*ret = L"DSBase";
	return DSFINE;
}

DSReturn DeepSpace::DSBase::ObjectFloor(UINT* ret)
{
	DSCODELOCK(this);
	*ret = myFloor;
	return DSFINE;
}

__DeepSpace::DSFactoryHand::DSFactoryHand(DSStr object)
{
	DSRegisterObject(object, this);
}

DeepSpace::DSLock::DSLock(DSBase* object)
{
	myCriticalSection = &object->myCriticalSection;
	EnterCriticalSection(myCriticalSection);
}

DeepSpace::DSLock::~DSLock()
{
	LeaveCriticalSection(myCriticalSection);
}
