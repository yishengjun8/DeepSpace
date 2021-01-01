#pragma once

/*
* DSBase.h提供了关于构造DeepSpace的基础类
* 
* DeepSpace编码规范:
* 
* 强制
* 1、所有的类必须继承于 DSBase
* 2、所有的类必须实现 'operator=' 和 'Clone' 
* 3、所有的类的构造函数不允许出现参数
* 4、所有的 DSBase 子类，都必须使用 DSOBJECT(obj) 声明
* 5、所有的方法、函数返回值必须为 DSReturn，
* 6、形参如果是输入值，必须以 set 开头；如果是返回值，必须以 ret 开头
* 7、任何添加到 AutoFunc 的方法，不允许重载、不允许使用右值引用、不允许使用引用传递。
* 
* 
* 可选
* 1、每次调用方法之后，都判断 DSReturn，是否成功
* 2、
* 
* 
* 必要知识
* 1、关于继承
*		如果子类实现了一个和父类同名的方法，并且都注册了 AutoFunc，
*	那么，通过 AutoFunc 调用该方法的顺序为：父类->子类，如果父类失
*	败，那么将不会执行子类方法，直接返回 DSFAIL 。
*		如果继承方式为：基类->类0->类1->类2，并且类0 、类2都注册了
*	'Hello()'，调用顺序为：类0::Hello()->类2::Hello()。
*/
#ifdef DS_BUILDING
#define DS_PORT __declspec(dllexport)
#else
#define DS_PORT __declspec(dllimport)
#pragma comment(lib, "DSBase.lib")

/* Windows 头文件 */
#include <windows.h>
/**/

/* 可变参数 - 类型获取 */
#include <stdarg.h>
#include <typeinfo>
/**/

/* 数学库 */
#include <cmath>
/**/

/* STL模板库 */
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
/**/

/* Direct2D1 */
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#include <dwmapi.h>

#pragma comment(lib, "D2D1.lib")
#pragma comment(lib, "DWrite.lib")
/**/
#endif

//公开 类型
namespace DeepSpace
{
	//DS_PORT typedef unsigned char ParaCount;
	DS_PORT typedef long DSReturn;
	DS_PORT typedef std::wstring DSStr;
}

//公开 类 - 函数 - 模板
namespace DeepSpace
{
	//基类
	class DS_PORT DSBase;
	//线程锁
	class DS_PORT DSLock;

	//DS工厂
	DS_PORT DSReturn DSFactory(DSStr object, DSBase** ret);

	//DS重要模板
	template<typename Func>
	struct DSArgNum_;
	template<typename R, class O, typename... Args>
	struct DSArgNum_<R(O::*)(Args...)> { static const int num = sizeof...(Args); };
	template<typename Func>
	int DSArgNum(Func) { return DSArgNum_<Func>::num; };

	template <class R, class O, class A1, class... Args>
	A1 DSArg1(R(O::*)(A1, Args...)) { return A1(); };
	template <class R, class O, class A1, class A2, class... Args>
	A2 DSArg2(R(O::*)(A1, A2, Args...)) { return A2(); };
	template <class R, class O, class A1, class A2, class A3, class... Args>
	A3 DSArg3(R(O::*)(A1, A2, A3, Args...)) { return A3(); };
	template <class R, class O, class A1, class A2, class A3, class A4, class... Args>
	A4 DSArg4(R(O::*)(A1, A2, A3, A4, Args...)) { return A4(); };
	template <class R, class O, class A1, class A2, class A3, class A4, class A5, class... Args>
	A5 DSArg5(R(O::*)(A1, A2, A3, A4, A5, Args...)) { return A5(); };
	template <class R, class O, class A1, class A2, class A3, class A4, class A5, class A6, class... Args>
	A6 DSArg6(R(O::*)(A1, A2, A3, A4, A5, A6, Args...)) { return A6(); };
	template <class R, class O, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class... Args>
	A7 DSArg7(R(O::*)(A1, A2, A3, A4, A5, A6, A7, Args...)) { return A7(); };
	template <class R, class O, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class... Args>
	A8 DSArg8(R(O::*)(A1, A2, A3, A4, A5, A6, A7, A8, Args...)) { return A8(); };
}

//公开 宏
namespace DeepSpace
{
	//强制 DSReturn必须选择下列一项返回
#define DSFINE	0
#define DSFAIL	-1
#define DS_GOODEND	return 0;
#define DS_BADEND	return -1;

	//可选 检查DSReturn
#define DS_SECCESS(DR)	__DS_OK(DR)
#define DS_FAILED(DR)	__DS_NO(DR)

	//强制 所有子类都需要声明
#define DSOBJECT(obj) __DSOBJECT(obj)

	//强制 所有的方法在使用前必须使用，以保证线程安全
#define DSCODELOCK(obj) __DSCODELOCK(obj)

	//强制 所有的子类必须在其.cpp中优先顺序调用下列三个初始化
#define DSOBJECT_INIT_0(obj) __DSOBJECT_INIT_0(obj)
#define DSOBJECT_INIT_1(obj) __DSOBJECT_INIT_1(obj)
#define DSOBJECT_INIT_2(obj, father) __DSOBJECT_INIT_2(obj, father)

	//可选 注册反射调用 -强制 只能在INIT_0-INIT_1之间使用
#define DSOBJECT_AUTOFUNC_REG(obj, func, id) __DSOBJECT_AUTOFUNC_REG(obj, func, id) 
	//可选 实现反射调用 -强制 只能在INIT_1-INIT_2之间使用
#define DSOBJECT_AUTOFUNC_CASE_0(obj, father, func, id) __DSOBJECT_AUTOFUNC_CASE_0(obj, father, func, id) 
#define DSOBJECT_AUTOFUNC_CASE_1(obj, father, func, id) __DSOBJECT_AUTOFUNC_CASE_1(obj, father, func, id) 
#define DSOBJECT_AUTOFUNC_CASE_2(obj, father, func, id) __DSOBJECT_AUTOFUNC_CASE_2(obj, father, func, id) 
#define DSOBJECT_AUTOFUNC_CASE_3(obj, father, func, id) __DSOBJECT_AUTOFUNC_CASE_3(obj, father, func, id) 
#define DSOBJECT_AUTOFUNC_CASE_4(obj, father, func, id) __DSOBJECT_AUTOFUNC_CASE_4(obj, father, func, id) 
#define DSOBJECT_AUTOFUNC_CASE_5(obj, father, func, id) __DSOBJECT_AUTOFUNC_CASE_5(obj, father, func, id) 
#define DSOBJECT_AUTOFUNC_CASE_6(obj, father, func, id) __DSOBJECT_AUTOFUNC_CASE_6(obj, father, func, id) 
#define DSOBJECT_AUTOFUNC_CASE_7(obj, father, func, id) __DSOBJECT_AUTOFUNC_CASE_7(obj, father, func, id) 
#define DSOBJECT_AUTOFUNC_CASE_8(obj, father, func, id) __DSOBJECT_AUTOFUNC_CASE_8(obj, father, func, id) 
}

//内部 类型 - 类 - 函数 - 模板 - 宏
namespace __DeepSpace
{
	class DS_PORT DSFactoryHand;
	DS_PORT DeepSpace::DSReturn DSRegisterObject(DeepSpace::DSStr object, DSFactoryHand* hand);

}

//公开 类声明
namespace DeepSpace
{
	class DSBase
	{
		friend class DSLock;
	public:
		DSBase();
		virtual ~DSBase();
		virtual DSReturn Clone(DSBase** ret) = 0;
		virtual DSBase& operator=(DSBase& rhs) = 0;

	public: 
		virtual DSReturn AutoFunc(DSStr func...);
		virtual DSReturn FuncName(DSStr* ret);
		virtual DSReturn FuncInfor(DSStr* ret);
		virtual DSReturn ObjectName(DSStr* ret);
	protected:
		CRITICAL_SECTION myCriticalSection;
	};

	class DSLock
	{
	protected:
		CRITICAL_SECTION* myCriticalSection;
	public:
		DSLock(DSBase* object);
		~DSLock();
	};
}

//内部 类声明
namespace __DeepSpace
{
	class DS_PORT DSFactoryHand
	{
	public:
		DSFactoryHand(DeepSpace::DSStr object);
		virtual DeepSpace::DSReturn Creat(DeepSpace::DSBase** ret) = 0;
	};
}

//公开 模板实现
namespace DeepSpace
{


}

#define __DS_OK(DR)	(((DSReturn)(DR)) >= 0)
#define __DS_NO(DR)	(((DSReturn)(DR)) < 0)

#define __DSCODELOCK(obj) \
	DSLock tLock(obj);

#define __DSOBJECT(obj) \
protected:\
	DSReturn obj##Init();\
public:\
	DSReturn AutoFunc(DSStr func...);\
	DSReturn FuncName(DSStr* ret);\
	DSReturn FuncInfor(DSStr* ret);\
	DSReturn ObjectName(DSStr* ret);

#define __DSOBJECT_INIT_0(obj) \
using namespace DeepSpace;\
using namespace __DeepSpace;\
using DeepSpace::obj;\
struct obj##DSAutoFuncInfor\
{\
	int myID = 0;\
	std::wstring  myName;\
	std::wstring myAllName;\
};\
std::map<DSStr, obj##DSAutoFuncInfor*> obj##DSAutoFuncMap;\
typedef std::map<DSStr,obj##DSAutoFuncInfor*>::value_type obj##DSAutoFuncValue;\
typedef std::map<DSStr,obj##DSAutoFuncInfor*>::iterator obj##DSAutoFuncIterator;\
DSReturn obj::FuncName(DSStr* ret)\
{\
	*ret = L"";\
	for(auto i : obj##DSAutoFuncMap)\
	{\
		*ret += i.second->myName;\
		*ret += L"\n";\
	}\
	return DSFINE;\
}\
DSReturn obj::FuncInfor(DSStr* ret)\
{\
	*ret = L"";\
	for(auto i : obj##DSAutoFuncMap)\
	{\
		*ret += i.second->myAllName;\
		*ret += L"\n";\
	}\
	return DSFINE;\
}\
DSReturn obj::ObjectName(DSStr* ret)\
{\
	*ret = L#obj;\
	return DSFINE;\
}\
class obj##FactoryHand\
	: public DSFactoryHand\
{\
public:\
	obj##FactoryHand(DSStr object)\
		: DSFactoryHand(object)\
	{\
		obj##DSAutoFuncInfor* infor = nullptr;\
		WCHAR typeName[1024]; size_t n = 0;\
		DSOBJECT_AUTOFUNC_REG(obj, AutoFunc, -1)

#define __DSOBJECT_INIT_1(obj) \
	};\
	DSReturn Creat(DSBase** ret)\
	{\
		*ret = new obj;\
		return DSFINE;\
	}\
};\
auto obj##Hand = new obj##FactoryHand(L#obj);\
DSReturn obj::AutoFunc(DSStr func...)\
{\
	DSReturn ret = DSFAIL;\
	va_list argc;\
	va_start(argc, func);\
	obj##DSAutoFuncIterator iter = obj##DSAutoFuncMap.end();\
	BeginSwitch:\
	iter = obj##DSAutoFuncMap.find(func); \
	if (iter != obj##DSAutoFuncMap.end())\
	{\
		int caID = iter->second->myID;\
		switch (caID)\
		{

#define __DSOBJECT_INIT_2(obj, father) \
		case -1:\
		{\
			func = va_arg(argc, DSStr);\
			argc = va_arg(argc, va_list);\
			goto BeginSwitch;\
			break;\
		}\
		}\
	}\
	else\
	{\
		ret = father::AutoFunc(L"AutoFunc", func, argc); \
	}\
	return ret;\
}

#define __DSOBJECT_AUTOFUNC_REG(obj, func, id) \
infor = new obj##DSAutoFuncInfor;\
infor->myID = id;\
infor->myName = L#func;\
mbstowcs_s(&n, typeName, 1024,\
	typeid(&obj::func).name(), 1023);\
infor->myAllName = typeName;\
obj##DSAutoFuncMap.insert(obj##DSAutoFuncValue(L#func, infor));

#define __DSOBJECT_AUTOFUNC_CASE_0(obj, father, func, id) \
case id:\
{\
	ret = father::AutoFunc(L#func);\
	if (DS_FAILED(ret)) { return DSFAIL; };\
	ret = func();\
	break;\
}

#define __DSOBJECT_AUTOFUNC_CASE_1(obj, father, func, id) \
case id:\
{\
	auto A1 = va_arg(argc, decltype(DSArg1(&obj::func)));\
	ret = father::AutoFunc(L#func, A1);\
	if (DS_FAILED(ret)) { return DSFAIL; };\
	ret = func(A1);\
	break;\
}

#define __DSOBJECT_AUTOFUNC_CASE_2(obj, father, func, id) \
case id:\
{\
	auto A1 = va_arg(argc, decltype(DSArg1(&obj::func)));\
	auto A2 = va_arg(argc, decltype(DSArg2(&obj::func)));\
	ret = father::AutoFunc(L#func, A1, A2);\
	if (DS_FAILED(ret)) { return DSFAIL; };\
	ret = func(A1, A2);\
	break;\
}

#define __DSOBJECT_AUTOFUNC_CASE_3(obj, father, func, id) \
case id:\
{\
	auto A1 = va_arg(argc, decltype(DSArg1(&obj::func)));\
	auto A2 = va_arg(argc, decltype(DSArg2(&obj::func)));\
	auto A3 = va_arg(argc, decltype(DSArg3(&obj::func)));\
	ret = father::AutoFunc(L#func, A1, A2, A3);\
	if (DS_FAILED(ret)) { return DSFAIL; };\
	ret = func(A1, A2, A3);\
	break;\
}

#define __DSOBJECT_AUTOFUNC_CASE_4(obj, father, func, id) \
case id:\
{\
	auto A1 = va_arg(argc, decltype(DSArg1(&obj::func)));\
	auto A2 = va_arg(argc, decltype(DSArg2(&obj::func)));\
	auto A3 = va_arg(argc, decltype(DSArg3(&obj::func)));\
	auto A4 = va_arg(argc, decltype(DSArg4(&obj::func)));\
	ret = father::AutoFunc(L#func, A1, A2, A3, A4);\
	if (DS_FAILED(ret)) { return DSFAIL; };\
	ret = func(A1, A2, A3, A4);\
	break;\
}

#define __DSOBJECT_AUTOFUNC_CASE_5(obj, father, func, id) \
case id:\
{\
	auto A1 = va_arg(argc, decltype(DSArg1(&obj::func)));\
	auto A2 = va_arg(argc, decltype(DSArg2(&obj::func)));\
	auto A3 = va_arg(argc, decltype(DSArg3(&obj::func)));\
	auto A4 = va_arg(argc, decltype(DSArg4(&obj::func)));\
	auto A5 = va_arg(argc, decltype(DSArg5(&obj::func)));\
	ret = father::AutoFunc(L#func, A1, A2, A3, A4, A5);\
	if (DS_FAILED(ret)) { return DSFAIL; };\
	ret = func(A1, A2, A3, A4, A5);\
	break;\
}

#define __DSOBJECT_AUTOFUNC_CASE_6(obj, father, func, id) \
case id:\
{\
	auto A1 = va_arg(argc, decltype(DSArg1(&obj::func)));\
	auto A2 = va_arg(argc, decltype(DSArg2(&obj::func)));\
	auto A3 = va_arg(argc, decltype(DSArg3(&obj::func)));\
	auto A4 = va_arg(argc, decltype(DSArg4(&obj::func)));\
	auto A5 = va_arg(argc, decltype(DSArg5(&obj::func)));\
	auto A6 = va_arg(argc, decltype(DSArg6(&obj::func)));\
	ret = father::AutoFunc(L#func, A1, A2, A3, A4, A5, A6);\
	if (DS_FAILED(ret)) { return DSFAIL; };\
	ret = func(A1, A2, A3, A4, A5, A6);\
	break;\
}

#define __DSOBJECT_AUTOFUNC_CASE_7(obj, father, func, id) \
case id:\
{\
	auto A1 = va_arg(argc, decltype(DSArg1(&obj::func)));\
	auto A2 = va_arg(argc, decltype(DSArg2(&obj::func)));\
	auto A3 = va_arg(argc, decltype(DSArg3(&obj::func)));\
	auto A4 = va_arg(argc, decltype(DSArg4(&obj::func)));\
	auto A5 = va_arg(argc, decltype(DSArg5(&obj::func)));\
	auto A6 = va_arg(argc, decltype(DSArg6(&obj::func)));\
	auto A7 = va_arg(argc, decltype(DSArg7(&obj::func)));\
	ret = father::AutoFunc(L#func, A1, A2, A3, A4, A5, A6, A7);\
	if (DS_FAILED(ret)) { return DSFAIL; };\
	ret = func(A1, A2, A3, A4, A5, A6, A7);\
	break;\
}

#define __DSOBJECT_AUTOFUNC_CASE_8(obj, father, func, id) \
case id:\
{\
	auto A1 = va_arg(argc, decltype(DSArg1(&obj::func)));\
	auto A2 = va_arg(argc, decltype(DSArg2(&obj::func)));\
	auto A3 = va_arg(argc, decltype(DSArg3(&obj::func)));\
	auto A4 = va_arg(argc, decltype(DSArg4(&obj::func)));\
	auto A5 = va_arg(argc, decltype(DSArg5(&obj::func)));\
	auto A6 = va_arg(argc, decltype(DSArg6(&obj::func)));\
	auto A7 = va_arg(argc, decltype(DSArg7(&obj::func)));\
	auto A8 = va_arg(argc, decltype(DSArg8(&obj::func)));\
	ret = father::AutoFunc(L#func, A1, A2, A3, A4, A5, A6, A7, A8);\
	if (DS_FAILED(ret)) { return DSFAIL; };\
	ret = func(A1, A2, A3, A4, A5, A6, A7, A8);\
	break;\
}

