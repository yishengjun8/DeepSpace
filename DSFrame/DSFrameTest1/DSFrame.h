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

	class DS_PORT DSModule;
	class DS_PORT DSModuleServe;
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

	protected:
		HINSTANCE myInstance;
		HWND myWnd;
	public:
		DSReturn Init(DSRect* set, DSStr setName);
		DSReturn Run();

		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	};
}

namespace DeepSpace
{
	class DSModule
		: public DSBase
	{
		DSOBJECT(DSModule);
	public:
		DSModule();
		~DSModule();
		DSReturn Clone(DSBase** ret);
		DSBase& operator=(DSBase& rhs);

	};
}

namespace DeepSpace
{
	class DSModuleServe
		: public DSBase
	{
		DSOBJECT(DSModuleServe);
	public:
		DSModuleServe();
		~DSModuleServe();
		DSReturn Clone(DSBase** ret);
		DSBase& operator=(DSBase& rhs);

	};
}


