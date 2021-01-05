#include "pch.h"
#include "DSGraph.h"
#include "DSGraphTypes.h"
using namespace DeepSpace;

DSOBJECT_INIT_0(DSCanvas)
DSOBJECT_AUTOFUNC_REG(DSCanvas, SetWnd, 0);
DSOBJECT_AUTOFUNC_REG(DSCanvas, GetWnd, 1);
DSOBJECT_AUTOFUNC_REG(DSCanvas, AddGraph, 2);
DSOBJECT_AUTOFUNC_REG(DSCanvas, SetPoint, 3);
DSOBJECT_AUTOFUNC_REG(DSCanvas, RemoveGraph, 4);
DSOBJECT_AUTOFUNC_REG(DSCanvas, DrawEnd, 5);
DSOBJECT_AUTOFUNC_REG(DSCanvas, DrawBegin, 6);
DSOBJECT_AUTOFUNC_REG(DSCanvas, IsDraw, 7);
DSOBJECT_AUTOFUNC_REG(DSCanvas, GetRenderTarget, 8);
DSOBJECT_AUTOFUNC_REG(DSCanvas, SetRect, 9);
DSOBJECT_AUTOFUNC_REG(DSCanvas, SetSize, 10);
DSOBJECT_INIT_1(DSCanvas)
DSOBJECT_AUTOFUNC_CASE_1(DSCanvas, DSGraph, SetWnd, 0)
DSOBJECT_AUTOFUNC_CASE_1(DSCanvas, DSGraph, GetWnd, 1)
DSOBJECT_AUTOFUNC_CASE_1(DSCanvas, DSGraph, AddGraph, 2)
DSOBJECT_AUTOFUNC_CASE_1(DSCanvas, DSGraph, SetPoint, 3)
DSOBJECT_AUTOFUNC_CASE_1(DSCanvas, DSGraph, RemoveGraph, 4)
DSOBJECT_AUTOFUNC_CASE_0(DSCanvas, DSGraph, DrawEnd, 5)
DSOBJECT_AUTOFUNC_CASE_0(DSCanvas, DSGraph, DrawBegin, 6)
DSOBJECT_AUTOFUNC_CASE_1(DSCanvas, DSGraph, IsDraw, 7)
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
	return DSFAIL;
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
		myRect->GetSize(&tSize);
		return DSID2D1HwndRenderTarget(&myHwndRenderTarget, myWnd, &tSize);
	}
	return DSFAIL;
}

DSReturn DeepSpace::DSCanvas::GetWnd(HWND* ret)
{
	DSCODELOCK(this);
	*ret = myWnd;
	return DSFINE;
}

DSReturn DeepSpace::DSCanvas::AddGraph(DSGraph* set)
{
	DSCODELOCK(this);
	myGraphVector.push_back(set);
	set->AutoFunc(L"SetCanvas", this);
	return DSFINE;
}

DSReturn DeepSpace::DSCanvas::RemoveGraph(DSGraph* set)
{
	DSCODELOCK(this);
	for (auto i = myGraphVector.begin(); i != myGraphVector.end(); i++)
	{
		if (*i == set)
		{
			myGraphVector.erase(i);
			return DSFINE;
		}
	}
	return DSFAIL;
}

DSReturn DeepSpace::DSCanvas::DrawEnd()
{
	DSCODELOCK(this);
	myDrawLock--;
	myHwndRenderTarget->EndDraw();
	return DSFINE;
}

DSReturn DeepSpace::DSCanvas::DrawBegin()
{
	DSCODELOCK(this);
	myDrawLock++;
	myHwndRenderTarget->BeginDraw();
	myHwndRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Red));
	return DSFINE;
}

DSReturn DeepSpace::DSCanvas::IsDraw(BOOL* ret)
{
	DSCODELOCK(this);
	*ret = myDrawLock;
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
	*myRect = *set;
	if (!myDrawLock && myWnd && myHwndRenderTarget)
	{
		SafeRelease(myHwndRenderTarget);
		DSSize tSize;
		myRect->GetSize(&tSize);
		DSID2D1HwndRenderTarget(&myHwndRenderTarget, myWnd, &tSize);
	}
	return DSFINE;
}

DSReturn DeepSpace::DSCanvas::SetSize(DSSize* set)
{
	DSCODELOCK(this);
	myRect->SetSize(set);
	if (!myDrawLock && myWnd && myHwndRenderTarget)
	{
		SafeRelease(myHwndRenderTarget);
		DSID2D1HwndRenderTarget(&myHwndRenderTarget, myWnd, set);
	}
	return DSFINE;
}
