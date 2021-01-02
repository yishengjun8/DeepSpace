#include "pch.h"
#include "DSBase.h"

using namespace DeepSpace;
using namespace __DeepSpace;

std::map<DSStr, DSFactoryHand*> DSFactoryMap;
typedef std::map<DSStr, DSFactoryHand*>::value_type DSFactoryValue;

DSReturn DeepSpace::DSFactory(DSStr object, DSBase** ret)
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
}

DeepSpace::DSBase::~DSBase()
{
	DSCODELOCK(this);
	DeleteCriticalSection(&myCriticalSection);
}

DSReturn DeepSpace::DSBase::Clone(DSBase** ret)
{
	*ret = new DSBase;
	return DSFINE;
}

DSBase& DeepSpace::DSBase::operator=(DSBase& rhs)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

bool DeepSpace::DSBase::operator==(DSBase& rhs)
{
	return true;
}

DSReturn DeepSpace::DSBase::AutoFunc(DSStr func ...)
{
	return DSFINE;
}

DSReturn DeepSpace::DSBase::FuncName(DSStr* ret)
{
	return DSFINE;
}

DSReturn DeepSpace::DSBase::FuncInfor(DSStr* ret)
{
	return DSFINE;
}

DSReturn DeepSpace::DSBase::ObjectName(DSStr* ret)
{
	*ret = L"DSBase";
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
