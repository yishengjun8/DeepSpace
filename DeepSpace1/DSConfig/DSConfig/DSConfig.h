#pragma once

#include "DSBase.h"

#ifdef DS_BUILDING
#define DS_PORT __declspec(dllexport)
#else
#define DS_PORT __declspec(dllimport)
#pragma comment(lib, "DSFrame.lib")
/**/
#endif

//公开 类 - 模板
namespace DeepSpace
{
	class DS_PORT DSConfig;
	//DS模板
}
//公开 类声明
namespace DeepSpace
{
	class DSConfig
	{


	public:

	};
}


