#include "pch.h"
#include "DSGraph.h"

DSOBJECT_INIT_0(DSGraph)
DSOBJECT_AUTOFUNC_REG(DSGraph, SetRect, 0);
DSOBJECT_AUTOFUNC_REG(DSGraph, SetSize, 1);
DSOBJECT_AUTOFUNC_REG(DSGraph, SetPoint, 2);
DSOBJECT_AUTOFUNC_REG(DSGraph, GetRect, 3);
DSOBJECT_AUTOFUNC_REG(DSGraph, GetSize, 4);
DSOBJECT_AUTOFUNC_REG(DSGraph, GetPoint, 5);
DSOBJECT_AUTOFUNC_REG(DSGraph, Collision, 6);
DSOBJECT_INIT_1(DSGraph)
DSOBJECT_AUTOFUNC_CASE_1(DSGraph, DSBase, SetRect, 0)
DSOBJECT_AUTOFUNC_CASE_1(DSGraph, DSBase, SetSize, 1)
DSOBJECT_AUTOFUNC_CASE_1(DSGraph, DSBase, SetPoint, 2)
DSOBJECT_AUTOFUNC_CASE_1(DSGraph, DSBase, GetRect, 3)
DSOBJECT_AUTOFUNC_CASE_1(DSGraph, DSBase, GetSize, 4)
DSOBJECT_AUTOFUNC_CASE_1(DSGraph, DSBase, GetPoint, 5)
DSOBJECT_AUTOFUNC_CASE_2(DSGraph, DSBase, Collision, 6)
DSOBJECT_INIT_2(DSGraph, DSBase);

ID2D1Factory* gID2D1Factory = nullptr;
IDWriteFactory* gIDWriteFactory = nullptr;
IWICImagingFactory* gIWICImagingFactory = nullptr;

DeepSpace::DSGraph::DSGraph()
{
	DSCODELOCK(this);
}

DeepSpace::DSGraph::~DSGraph()
{
	DSCODELOCK(this);
}

DSReturn DeepSpace::DSGraph::Clone(DSBase** ret)
{
	DSCODELOCK(this);
	*ret = new DSGraph;
	((DSGraph*)(*ret))->SetRect(&myRect);
	return DSFINE;
}

DSBase& DeepSpace::DSGraph::operator=(DSBase& rhs)
{
	DSCODELOCK(this);
	FLOAT tX = 0, tY = 0, tW = 0, tH = 0;
	if (DS_SECCESS(rhs.AutoFunc(L"GetX", &tX)) &&
		DS_SECCESS(rhs.AutoFunc(L"GetY", &tY)) &&
		DS_SECCESS(rhs.AutoFunc(L"GetWidth", &tW)) &&
		DS_SECCESS(rhs.AutoFunc(L"GetHeight", &tH)) )
	{
		myRect.Init(tX, tY, tW, tH);
	}
	return *this;
}

BOOL DeepSpace::DSGraph::operator==(DSBase& rhs)
{
	DSCODELOCK(this);
	DSRect* tRect = nullptr;
	if (DS_SECCESS(rhs.AutoFunc(L"GetRect", &tRect)))
	{
		return myRect == (*tRect);
	}
	return false;
}

DSReturn DeepSpace::DSGraph::SetRect(DSRect* set)
{
	DSCODELOCK(this);
	myRect = *set;
	return DSFINE;
}

DSReturn DeepSpace::DSGraph::SetSize(DSSize* set)
{
	DSCODELOCK(this);
	return myRect.SetSize(set);
}

DSReturn DeepSpace::DSGraph::SetPoint(DSPoint* set)
{
	DSCODELOCK(this);
	return myRect.SetPoint(set);
}

DSReturn DeepSpace::DSGraph::GetRect(DSRect* ret)
{
	DSCODELOCK(this);
	*ret = myRect;
	return DSFINE;
}

DSReturn DeepSpace::DSGraph::GetSize(DSSize* ret)
{
	DSCODELOCK(this);
	return myRect.GetSize(ret);
}

DSReturn DeepSpace::DSGraph::GetPoint(DSPoint* ret)
{
	DSCODELOCK(this);
	return myRect.GetPoint(ret);
}

DSReturn DeepSpace::DSGraph::Collision(DSBase* set, BOOL* ret)
{
	DSCODELOCK(this);
	return myRect.Collision(set, ret);
}

/* ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！ */
/* ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！ */
/* ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！ */

ID2D1Factory* DeepSpace::DSID2D1Factory()
{
	if (!gID2D1Factory)
	{
		D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &gID2D1Factory);
	}
	return gID2D1Factory;
}

IDWriteFactory* DeepSpace::DSIDWriteFactory()
{
	if (!gIDWriteFactory)
	{
		DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(DSID2D1Factory()),
			reinterpret_cast<IUnknown**>(&gIDWriteFactory));
	}
	return gIDWriteFactory;
}

IWICImagingFactory* DeepSpace::DSIWICImagingFactory()
{
	if (!gIWICImagingFactory)
	{
		CoCreateInstance(CLSID_WICImagingFactory, NULL,
			CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&gIWICImagingFactory));
	}
	return gIWICImagingFactory;
}

DSReturn DeepSpace::DSID2D1DCRenderTarget(ID2D1DCRenderTarget** ret, HDC set, DSRect* setRect)
{
	if (set)
	{
		D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
			D2D1_RENDER_TARGET_TYPE_DEFAULT,
			D2D1::PixelFormat(
				DXGI_FORMAT_B8G8R8A8_UNORM,
				D2D1_ALPHA_MODE_IGNORE),
			0,
			0,
			D2D1_RENDER_TARGET_USAGE_NONE,
			D2D1_FEATURE_LEVEL_DEFAULT
		);

		if (SUCCEEDED(DSID2D1Factory()->CreateDCRenderTarget(&props, ret)))
		{
			RECT rc; FLOAT retFloat;
			setRect->GetTop(&retFloat);
			rc.top = retFloat;
			setRect->GetLeft(&retFloat);
			rc.left = retFloat;
			setRect->GetRight(&retFloat);
			rc.right = retFloat;
			setRect->GetBottom(&retFloat);
			rc.bottom = retFloat;
			(*ret)->BindDC(set, &rc);
			return DSFINE;
		}
	}
	return DSFAIL;
}

DSReturn DeepSpace::DSID2D1HwndRenderTarget(ID2D1HwndRenderTarget** ret, HWND set, DSSize* setSize)
{
	if (set)
	{
		D2D1_SIZE_U t_size;
		setSize->GetD2D1SizeU(&t_size);
		DSID2D1Factory()->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(set, t_size), ret);
		return DSFINE;
	}
	return DSFAIL;
}

DSReturn DeepSpace::DSIWICBitmapFromFile(IWICBitmap** ret, DSStr set, DSSize* setSize)
{
	IWICBitmapDecoder* pDecoder = NULL;
	IWICBitmapFrameDecode* pSource = NULL;
	//IWICImagingFactory::CreateBitmapFromSource(pSource)
	IWICBitmapScaler* pScaler = NULL;
	IWICFormatConverter* pConverter = NULL;

	// 紗墮了夕-------------------------------------------------
	if (FAILED(DSIWICImagingFactory()->CreateDecoderFromFilename(
		set.c_str(), NULL, GENERIC_READ,
		WICDecodeMetadataCacheOnLoad, &pDecoder)))
	{
		return DSFAIL;
	};

	pDecoder->GetFrame(0, &pSource);
	DSIWICImagingFactory()->CreateFormatConverter(&pConverter);

	FLOAT width, height;
	setSize->GetWidth(&width);
	setSize->GetHeight(&height);
	if (width != 0 || height != 0)
	{
		UINT originalWidth, originalHeight;
		pSource->GetSize(&originalWidth, &originalHeight);
		if (width == 0)
		{
			FLOAT scalar = static_cast<FLOAT>(height) / static_cast<FLOAT>(originalHeight);
			width = static_cast<UINT>(scalar * static_cast<FLOAT>(originalWidth));
		}
		else if (height == 0)
		{
			FLOAT scalar = static_cast<FLOAT>(width) / static_cast<FLOAT>(originalWidth);
			height = static_cast<UINT>(scalar * static_cast<FLOAT>(originalHeight));
		}
		DSIWICImagingFactory()->CreateBitmapScaler(&pScaler);
		pScaler->Initialize(pSource, width, height, WICBitmapInterpolationModeCubic);

		pConverter->Initialize(
			pScaler,
			GUID_WICPixelFormat32bppPBGRA,
			WICBitmapDitherTypeNone,
			NULL, 0.f,
			WICBitmapPaletteTypeMedianCut
		);
	}
	else
	{
		pConverter->Initialize(
			pSource,
			GUID_WICPixelFormat32bppPBGRA,
			WICBitmapDitherTypeNone,
			NULL, 0.f,
			WICBitmapPaletteTypeMedianCut
		);
	}
	DSIWICImagingFactory()->CreateBitmapFromSource(
		pConverter,
		WICBitmapCacheOnLoad,
		ret
	);
	SafeRelease(pSource);
	SafeRelease(pDecoder);
	SafeRelease(pScaler);
	SafeRelease(pConverter);
	return DSFINE;
}

DSReturn DeepSpace::DSID2D1BitmapFromFile(ID2D1Bitmap** ret, DSStr set, DSSize* setSize, ID2D1RenderTarget* pRT)
{
	IWICBitmapDecoder* pDecoder = NULL;
	IWICBitmapFrameDecode* pSource = NULL;

	IWICBitmapScaler* pScaler = NULL;
	IWICFormatConverter* pConverter = NULL;

	// 紗墮了夕-------------------------------------------------
	if (FAILED(DSIWICImagingFactory()->CreateDecoderFromFilename(
		set.c_str(), NULL, GENERIC_READ,
		WICDecodeMetadataCacheOnLoad, &pDecoder)))
	{
		return DSFAIL;
	};

	pDecoder->GetFrame(0, &pSource);
	DSIWICImagingFactory()->CreateFormatConverter(&pConverter);

	FLOAT width, height;
	setSize->GetWidth(&width);
	setSize->GetHeight(&height);
	if (width != 0 || height != 0)
	{
		UINT originalWidth, originalHeight;
		pSource->GetSize(&originalWidth, &originalHeight);
		if (width == 0)
		{
			FLOAT scalar = static_cast<FLOAT>(height) / static_cast<FLOAT>(originalHeight);
			width = static_cast<UINT>(scalar * static_cast<FLOAT>(originalWidth));
		}
		else if (height == 0)
		{
			FLOAT scalar = static_cast<FLOAT>(width) / static_cast<FLOAT>(originalWidth);
			height = static_cast<UINT>(scalar * static_cast<FLOAT>(originalHeight));
		}
		DSIWICImagingFactory()->CreateBitmapScaler(&pScaler);
		pScaler->Initialize(pSource, width, height, WICBitmapInterpolationModeCubic);

		pConverter->Initialize(
			pScaler,
			GUID_WICPixelFormat32bppPBGRA,
			WICBitmapDitherTypeNone,
			NULL, 0.f,
			WICBitmapPaletteTypeMedianCut
		);
	}
	else // Don't scale the image.
	{
		pConverter->Initialize(
			pSource,
			GUID_WICPixelFormat32bppPBGRA,
			WICBitmapDitherTypeNone,
			NULL, 0.f,
			WICBitmapPaletteTypeMedianCut
		);
	}

	pRT->CreateBitmapFromWicBitmap(
		pConverter,
		NULL,
		ret
	);

	SafeRelease(pSource);
	SafeRelease(pDecoder);
	SafeRelease(pScaler);
	SafeRelease(pConverter);
	return DSFINE;
}

DSReturn DeepSpace::DSID2D1BitmapFromIWICBitmap(ID2D1Bitmap** ret, IWICBitmap* set, DSSize* setSize, ID2D1RenderTarget* pRT)
{
	IWICBitmapScaler* pScaler = NULL;
	IWICFormatConverter* pConverter = NULL;

	DSIWICImagingFactory()->CreateFormatConverter(&pConverter);

	FLOAT width, height;
	setSize->GetWidth(&width);
	setSize->GetHeight(&height);
	if (width != 0 || height != 0)
	{
		UINT originalWidth, originalHeight;
		set->GetSize(&originalWidth, &originalHeight);
		if (width == 0)
		{
			FLOAT scalar = static_cast<FLOAT>(height) / static_cast<FLOAT>(originalHeight);
			width = static_cast<UINT>(scalar * static_cast<FLOAT>(originalWidth));
		}
		else if (height == 0)
		{
			FLOAT scalar = static_cast<FLOAT>(width) / static_cast<FLOAT>(originalWidth);
			height = static_cast<UINT>(scalar * static_cast<FLOAT>(originalHeight));
		}
		DSIWICImagingFactory()->CreateBitmapScaler(&pScaler);
		pScaler->Initialize(set, width, height, WICBitmapInterpolationModeCubic);

		pConverter->Initialize(
			pScaler,
			GUID_WICPixelFormat32bppPBGRA,
			WICBitmapDitherTypeNone,
			NULL, 0.f,
			WICBitmapPaletteTypeMedianCut
		);
	}
	else // Don't scale the image.
	{
		pConverter->Initialize(
			set,
			GUID_WICPixelFormat32bppPBGRA,
			WICBitmapDitherTypeNone,
			NULL, 0.f,
			WICBitmapPaletteTypeMedianCut
		);
	}

	pRT->CreateBitmapFromWicBitmap(
		pConverter,
		NULL,
		ret
	);

	SafeRelease(pScaler);
	SafeRelease(pConverter);
	return DSFINE;
}
