#pragma once
#include "MfxAppFramework.h"

namespace MicroFlakeX
{
	class MFX_APPFRAMEWORKDLL_IMPORT MfxPaper;
}

//Mfxö��
namespace MicroFlakeX
{
	enum MfxMfxPaper_Message
	{

	};
}

namespace MicroFlakeX
{
    class MfxPaper
        : public MfxControl
    {
	protected:
		void RegDefFunc();
		void InitData();
	public:
		MfxPaper();
		virtual ~MfxPaper();


    };
}

