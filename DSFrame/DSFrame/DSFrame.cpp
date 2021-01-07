#include "pch.h"
#include "DSFrame.h"

DSOBJECT_INIT_0(DSFrame)
DSOBJECT_INIT_1(DSFrame)
DSOBJECT_INIT_2(DSFrame, DSBase);

DeepSpace::DSFrame::DSFrame()
{
	myWnd = nullptr;
	myInstance = GetModuleHandleW(NULL);
}

DeepSpace::DSFrame::~DSFrame()
{
}

DSReturn DeepSpace::DSFrame::Clone(DSBase** ret)
{
	return DSReturn();
}

DSBase& DeepSpace::DSFrame::operator=(DSBase& rhs)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

DSReturn DeepSpace::DSFrame::Init(DSRect* set, DSStr setName)
{
	WNDCLASSEX tempWC{ 0 };

	tempWC.cbSize = sizeof(WNDCLASSEX);
	tempWC.style = CS_HREDRAW | CS_VREDRAW;

	tempWC.lpfnWndProc = DSFrame::WndProc;
	tempWC.cbClsExtra = 0;               // no extra class memory 
	tempWC.cbWndExtra = 0;                // no extra window memory
	tempWC.hInstance = myInstance;		//获取程序实例句柄

	tempWC.hIcon = LoadIcon(NULL, IDI_APPLICATION);             // predefined app. icon 
	tempWC.hCursor = LoadCursor(NULL, IDC_ARROW);                // predefined arrow 
	tempWC.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);

	//tempWC.lpszMenuName = L"MainMenu";    // name of menu resource
	tempWC.lpszClassName = L"DSFrame";  // name of window class
	tempWC.hIconSm = LoadIconW(NULL, IDI_APPLICATION);  // small class icon 

	if (!RegisterClassEx(&tempWC))
	{
		return DSFAIL;
	}

	FLOAT wndX, wndY, wndWidth, wndHeight;
	set->GetX(&wndX);
	set->GetY(&wndY);
	set->GetWidth(&wndWidth);
	set->GetHeight(&wndHeight);
	myWnd = CreateWindowW(
		L"DSFrame",
		L"DSFrame",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		wndX,
		wndY,
		wndWidth,
		wndHeight,
		NULL,
		NULL,
		myInstance,
		this
	);

	if (!myWnd)
	{
		return DSFAIL;
	}

	return DSFINE;
}

DSReturn DeepSpace::DSFrame::Run()
{
	MSG appMsg;
	while (GetMessageW(&appMsg, NULL, 0, 0) > 0) {
		TranslateMessage(&appMsg);
		DispatchMessageW(&appMsg);
	}
	return appMsg.wParam;
}

LRESULT DeepSpace::DSFrame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, message, wParam, lParam);
}
