#pragma once

#include "DSBase.h"

#ifdef DS_BUILDING
#define DS_PORT __declspec(dllexport)
#else
#define DS_PORT __declspec(dllimport)
#pragma comment(lib, "DSFrame.lib")
/**/
#endif

//���� �� - ģ��
namespace DeepSpace
{
	class DS_PORT DSConfig;
	//DSģ��
}
//���� ������
namespace DeepSpace
{
	class DSConfig
	{


	public:

	};
}


