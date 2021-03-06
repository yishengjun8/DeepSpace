#include "pch.h"
#include "DSGraph.h"

DSOBJECT_INIT_0(DSImage)
DSOBJECT_AUTOFUNC_REG(DSImage, Draw, 0);
DSOBJECT_AUTOFUNC_REG(DSImage, SetCanvas, 1);
DSOBJECT_AUTOFUNC_REG(DSImage, GetCanvas, 2);
DSOBJECT_AUTOFUNC_REG(DSImage, FromFile, 3);
DSOBJECT_AUTOFUNC_REG(DSImage, SetCollisionBlock, 6);
DSOBJECT_INIT_1(DSImage)
DSOBJECT_AUTOFUNC_CASE_0(DSImage, DSGraph, Draw, 0)
DSOBJECT_AUTOFUNC_CASE_1(DSImage, DSGraph, SetCanvas, 1)
DSOBJECT_AUTOFUNC_CASE_1(DSImage, DSGraph, GetCanvas, 2)
DSOBJECT_AUTOFUNC_CASE_1(DSImage, DSGraph, FromFile, 3)
DSOBJECT_AUTOFUNC_CASE_1(DSImage, DSGraph, SetCollisionBlock, 6)
DSOBJECT_INIT_2(DSImage, DSGraph);

DeepSpace::DSImage::DSImage()
{
	DSCODELOCK(this);

	myCanvas = nullptr;
	myIWICBitmap = nullptr;
	myID2D1Bitmap = nullptr;
	myRenderTarget = nullptr;

	myCollisionBlock.Init(24, 24);
}

DeepSpace::DSImage::~DSImage()
{
	DSCODELOCK(this);

	SafeRelease(myIWICBitmap);
	SafeRelease(myID2D1Bitmap);
}

DSReturn DeepSpace::DSImage::Clone(DSBase** ret)
{
	DSCODELOCK(this);
	return DSFAIL;
}

DSBase& DeepSpace::DSImage::operator=(DSBase& rhs)
{
	DSCODELOCK(this);
	// TODO: �ڴ˴����� return ���
	return *this;
}

BOOL DeepSpace::DSImage::operator==(DSBase& rhs)
{
	DSCODELOCK(this);
	return 0;
}

DSReturn DeepSpace::DSImage::Draw()
{
	DSCODELOCK(this);
	if (myCanvas)
	{
		D2D1_RECT_F temp;
		myRect.GetD2D1RectF(&temp);
		myRenderTarget->DrawBitmap(myID2D1Bitmap, temp);
	}
	return DSFINE;
}

DSReturn DeepSpace::DSImage::SetCanvas(DSCanvas* set)
{
	DSCODELOCK(this);
	myCanvas = set;
	if (myIWICBitmap)
	{
		SafeRelease(myID2D1Bitmap);
		ResetID2D1Bitmap();
	}
	return DSFINE;
}

DSReturn DeepSpace::DSImage::GetCanvas(DSCanvas** ret)
{
	DSCODELOCK(this);
	*ret = myCanvas;
	return DSFINE;
}

DSReturn DeepSpace::DSImage::ResetID2D1Bitmap()
{
	DSCODELOCK(this);
	if (myCanvas && myIWICBitmap)
	{
		DSSize tSize;
		myRect.GetSize(&tSize);
		myCanvas->GetRenderTarget(&myRenderTarget);
		DSID2D1BitmapFromIWICBitmap(&myID2D1Bitmap, myIWICBitmap, &tSize, myRenderTarget);
	}
	return DSFINE;
}

DSReturn DeepSpace::DSImage::ResetCollisionGeometry()
{
	return DSReturn();
}

DSReturn DeepSpace::DSImage::FromFile(DSStr set)
{
	DSCODELOCK(this);
	DSSize tSize;
	if (DS_SECCESS(DSIWICBitmapFromFile(&myIWICBitmap, set, &tSize)))
	{
		ResetID2D1Bitmap();
		return DSFINE;
	}
	return DSFAIL;
}

DSReturn DeepSpace::DSImage::SetCollisionBlock(DSSize* set)
{
	DSCODELOCK(this);
	myCollisionBlock = *set;
	ResetCollisionGeometry();
	return DSFINE;
}

DSReturn DeepSpace::DSImage::SetRect(DSRect* set)
{
	DSCODELOCK(this);
	myRect = *set;
	ResetID2D1Bitmap();
	return DSFINE;
}

DSReturn DeepSpace::DSImage::SetSize(DSSize* set)
{
	DSCODELOCK(this);
	myRect.SetSize(set);
	ResetID2D1Bitmap();
	return DSFINE;
}
