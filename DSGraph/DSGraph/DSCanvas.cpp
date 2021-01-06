#include "pch.h"
#include "DSGraph.h"

DSOBJECT_INIT_0(DSCanvas)
DSOBJECT_AUTOFUNC_REG(DSCanvas, SetWnd, 0);
DSOBJECT_AUTOFUNC_REG(DSCanvas, GetWnd, 1);
DSOBJECT_AUTOFUNC_REG(DSCanvas, SetPoint, 3);
DSOBJECT_AUTOFUNC_REG(DSCanvas, DrawEnd, 5);
DSOBJECT_AUTOFUNC_REG(DSCanvas, DrawBegin, 6);
DSOBJECT_AUTOFUNC_REG(DSCanvas, GetRenderTarget, 8);
DSOBJECT_AUTOFUNC_REG(DSCanvas, SetRect, 9);
DSOBJECT_AUTOFUNC_REG(DSCanvas, SetSize, 10);
DSOBJECT_INIT_1(DSCanvas)
DSOBJECT_AUTOFUNC_CASE_1(DSCanvas, DSGraph, SetWnd, 0)
DSOBJECT_AUTOFUNC_CASE_1(DSCanvas, DSGraph, GetWnd, 1)
DSOBJECT_AUTOFUNC_CASE_1(DSCanvas, DSGraph, SetPoint, 3)
DSOBJECT_AUTOFUNC_CASE_0(DSCanvas, DSGraph, DrawEnd, 5)
DSOBJECT_AUTOFUNC_CASE_0(DSCanvas, DSGraph, DrawBegin, 6)
DSOBJECT_AUTOFUNC_CASE_1(DSCanvas, DSGraph, GetRenderTarget, 8)
DSOBJECT_AUTOFUNC_CASE_1(DSCanvas, DSGraph, SetRect, 9)
DSOBJECT_AUTOFUNC_CASE_1(DSCanvas, DSGraph, SetSize, 10)
DSOBJECT_INIT_2(DSCanvas, DSGraph);

DeepSpace::DSCanvas::DSCanvas()
{
	DSCODELOCK(this);
	
	myWnd = nullptr;
	myDrawLock = 0;
	myHwndRenderTarget = nullptr;
}

DeepSpace::DSCanvas::~DSCanvas()
{
	DSCODELOCK(this);
	SafeRelease(myHwndRenderTarget);
}

DSReturn DeepSpace::DSCanvas::Clone(DSBase** ret)
{
	DSCODELOCK(this);
	*ret = new DSCanvas;
	((DSCanvas*)*ret)->SetRect(&myRect);
	((DSCanvas*)*ret)->SetWnd(myWnd);
	return DSFINE;
}

DSBase& DeepSpace::DSCanvas::operator=(DSBase& rhs)
{
	DSCODELOCK(this);
	// TODO: 在此处插入 return 语句
	return *this;
}

BOOL DeepSpace::DSCanvas::operator==(DSBase& rhs)
{
	DSCODELOCK(this);
	return 0;
}

DSReturn DeepSpace::DSCanvas::SetWnd(HWND set)
{
	DSCODELOCK(this);
	if (!myWnd)
	{
		myWnd = set;
		DSSize tSize;
		myRect.GetSize(&tSize);
		if (DS_FAILED(DSID2D1HwndRenderTarget(&myHwndRenderTarget, myWnd, &tSize)))
		{
			myWnd = nullptr;
			SafeRelease(myHwndRenderTarget);
			return DSFAIL;
		}
		return DSFINE;
	}
	return DSFAIL;
}

DSReturn DeepSpace::DSCanvas::GetWnd(HWND* ret)
{
	DSCODELOCK(this);
	*ret = myWnd;
	return DSFINE;
}

DSReturn DeepSpace::DSCanvas::ResetRenderTarget()
{
	if (myWnd)
	{
		SafeRelease(myHwndRenderTarget);
		DSSize tSize;
		myRect.GetSize(&tSize);
		DSID2D1HwndRenderTarget(&myHwndRenderTarget, myWnd, &tSize);
		return DSFINE;
	}
	return DSFAIL;
}

DSReturn DeepSpace::DSCanvas::DrawEnd()
{
	DSCODELOCK(this);
	if (myHwndRenderTarget)
	{
		if (DS_SECCESS(myHwndRenderTarget->EndDraw()))
		{
			myDrawLock--;
			return DSFINE;
		}
	}
	return DSFAIL;
}

DSReturn DeepSpace::DSCanvas::DrawBegin()
{
	DSCODELOCK(this);
	if (myHwndRenderTarget)
	{
		myDrawLock++;
		myHwndRenderTarget->BeginDraw();
		myHwndRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Red));
	}
	return DSFINE;
}

DSReturn DeepSpace::DSCanvas::GetRenderTarget(ID2D1RenderTarget** ret)
{
	DSCODELOCK(this);
	*ret = myHwndRenderTarget;
	return DSFINE;
}

DSReturn DeepSpace::DSCanvas::SetRect(DSRect* set)
{
	DSCODELOCK(this);
	if (!myDrawLock)
	{
		myRect = *set;
		ResetRenderTarget();
		return DSFINE;
	}
	return DSFAIL;
}

DSReturn DeepSpace::DSCanvas::SetSize(DSSize* set)
{
	DSCODELOCK(this);
	if (!myDrawLock)
	{
		myRect.SetSize(set);
		ResetRenderTarget();
		return DSFINE;
	}
	return DSFAIL;
}
