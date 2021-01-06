#pragma once
#include "DSGraph.h"

#ifdef DS_BUILDING
#define DS_PORT __declspec(dllexport)
#else
#define DS_PORT __declspec(dllimport)
#pragma comment(lib, "DSFrame.lib")
/**/
#endif
namespace DeepSpace
{
	class DS_PORT DSFrame;
}

//公开 类 - 模板
namespace DeepSpace
{
	class DSFrame
		: public DSBase
	{
		DSOBJECT(DSFrame);
	public:
		DSFrame();
		~DSFrame();
		DSReturn Clone(DSBase** ret);
		DSBase& operator=(DSBase& rhs);

	};
}

