#include "pch.h"
#include "DSGraphTypes.h"

DSOBJECT_INIT_0(DSRect)
DSOBJECT_AUTOFUNC_REG(DSRect, Init, 0);
DSOBJECT_AUTOFUNC_REG(DSRect, GetD2D1RectU, 1);
DSOBJECT_AUTOFUNC_REG(DSRect, GetD2D1SizeU, 2);
DSOBJECT_AUTOFUNC_REG(DSRect, GetD2D1PointU, 3);
DSOBJECT_AUTOFUNC_REG(DSRect, GetD2D1RectF, 4);
DSOBJECT_AUTOFUNC_REG(DSRect, GetD2D1SizeF, 5);
DSOBJECT_AUTOFUNC_REG(DSRect, GetD2D1PointF, 6);
DSOBJECT_AUTOFUNC_REG(DSRect, SetSize, 7);
DSOBJECT_AUTOFUNC_REG(DSRect, SetPoint, 8);
DSOBJECT_AUTOFUNC_REG(DSRect, SetX, 9);
DSOBJECT_AUTOFUNC_REG(DSRect, SetY, 10);
DSOBJECT_AUTOFUNC_REG(DSRect, SetWidth, 11);
DSOBJECT_AUTOFUNC_REG(DSRect, SetHeight, 12);
DSOBJECT_AUTOFUNC_REG(DSRect, SetTop, 13);
DSOBJECT_AUTOFUNC_REG(DSRect, SetLeft, 14);
DSOBJECT_AUTOFUNC_REG(DSRect, SetRight, 15);
DSOBJECT_AUTOFUNC_REG(DSRect, SetBottom, 16);
DSOBJECT_AUTOFUNC_REG(DSRect, GetSize, 17);
DSOBJECT_AUTOFUNC_REG(DSRect, GetPoint, 18);
DSOBJECT_AUTOFUNC_REG(DSRect, GetX, 19);
DSOBJECT_AUTOFUNC_REG(DSRect, GetY, 20);
DSOBJECT_AUTOFUNC_REG(DSRect, GetWidth, 21);
DSOBJECT_AUTOFUNC_REG(DSRect, GetHeight, 22);
DSOBJECT_AUTOFUNC_REG(DSRect, GetTop, 23);
DSOBJECT_AUTOFUNC_REG(DSRect, GetLeft, 24);
DSOBJECT_AUTOFUNC_REG(DSRect, GetRight, 25);
DSOBJECT_AUTOFUNC_REG(DSRect, GetBottom, 26);
DSOBJECT_AUTOFUNC_REG(DSRect, Empty, 27);
DSOBJECT_AUTOFUNC_REG(DSRect, Offset, 28);
DSOBJECT_AUTOFUNC_REG(DSRect, Inflate, 29);
DSOBJECT_AUTOFUNC_REG(DSRect, Collision, 30);
DSOBJECT_INIT_1(DSRect)
DSOBJECT_AUTOFUNC_CASE_4(DSRect, DSBase, Init, 0)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, GetD2D1RectU, 1)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, GetD2D1SizeU, 2)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, GetD2D1PointU, 3)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, GetD2D1RectF, 4)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, GetD2D1SizeF, 5)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, GetD2D1PointF, 6)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, SetSize, 7)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, SetPoint, 8)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, SetX, 9)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, SetY, 10)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, SetWidth, 11)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, SetHeight, 12)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, SetTop, 13)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, SetLeft, 14)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, SetRight, 15)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, SetBottom, 16)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, GetSize, 17)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, GetPoint, 18)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, GetX, 19)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, GetY, 20)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, GetWidth, 21)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, GetHeight, 22)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, GetTop, 23)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, GetLeft, 24)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, GetRight, 25)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, GetBottom, 26)
DSOBJECT_AUTOFUNC_CASE_1(DSRect, DSBase, Empty, 27)
DSOBJECT_AUTOFUNC_CASE_2(DSRect, DSBase, Offset, 28)
DSOBJECT_AUTOFUNC_CASE_2(DSRect, DSBase, Inflate, 29)
DSOBJECT_AUTOFUNC_CASE_2(DSRect, DSBase, Collision, 30)
DSOBJECT_INIT_2(DSRect, DSBase);

DeepSpace::DSRect::DSRect()
{
	DSCODELOCK(this);
	myX = myY = myWidth = myHeight = 0;
}

DeepSpace::DSRect::~DSRect()
{
	DSCODELOCK(this);
}

DSReturn DeepSpace::DSRect::Clone(DSBase** ret)
{
	DSCODELOCK(this);
	*ret = new DSRect;
	((DSRect*)(*ret))->Init(myX, myY, myWidth, myHeight);
	return DSFINE;
}

DSBase& DeepSpace::DSRect::operator=(DSBase& rhs)
{
	DSCODELOCK(this);
	rhs.AutoFunc(L"GetX", &myX);
	rhs.AutoFunc(L"GetY", &myY);
	rhs.AutoFunc(L"GetWidth", &myWidth);
	rhs.AutoFunc(L"GetHeight", &myHeight);
	return *this;
}

BOOL DeepSpace::DSRect::operator==(DSBase& rhs)
{
	DSCODELOCK(this);
	FLOAT tX = 0, tY = 0, tW = 0, tH = 0;
	rhs.AutoFunc(L"GetX", &tX);
	rhs.AutoFunc(L"GetY", &tY);
	rhs.AutoFunc(L"GetWidth", &tW);
	rhs.AutoFunc(L"GetHeight", &tH);
	return tX == myX && tY == myY && tW == myWidth && tH == myHeight;
}

DSReturn DeepSpace::DSRect::Init(FLOAT setX, FLOAT setY, FLOAT setWidth, FLOAT setHeight)
{
	DSCODELOCK(this);
	myX = setX;
	myY = setY;
	myWidth = setWidth;
	myHeight = setHeight;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::GetD2D1RectU(D2D1_RECT_U* ret)
{
	DSCODELOCK(this);

	FLOAT tT = 0, tL = 0, tR = 0, tB = 0;
	GetTop(&tT);
	GetLeft(&tL);
	GetRight(&tR);
	GetBottom(&tB);


	ret->top = tT;
	ret->left = tL;
	ret->right = tR;
	ret->bottom = tB;

	return DSFINE;
}

DSReturn DeepSpace::DSRect::GetD2D1SizeU(D2D1_SIZE_U* ret)
{
	DSCODELOCK(this);
	FLOAT tW = 0, tH = 0;
	GetWidth(&tW);
	GetHeight(&tH);
	ret->width = tW;
	ret->height = tH;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::GetD2D1PointU(D2D1_POINT_2U* ret)
{
	DSCODELOCK(this);
	FLOAT tX = 0, tY = 0;
	GetX(&tX);
	GetY(&tY);
	ret->x = tX;
	ret->y = tY;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::GetD2D1RectF(D2D1_RECT_F* ret)
{
	DSCODELOCK(this);
	GetTop(&(ret->top));
	GetLeft(&(ret->left));
	GetRight(&(ret->right));
	GetBottom(&(ret->bottom));
	return DSFINE;
}

DSReturn DeepSpace::DSRect::GetD2D1SizeF(D2D1_SIZE_F* ret)
{
	DSCODELOCK(this);
	GetWidth(&(ret->width));
	GetHeight(&(ret->height));
	return DSFINE;
}

DSReturn DeepSpace::DSRect::GetD2D1PointF(D2D1_POINT_2F* ret)
{
	DSCODELOCK(this);
	GetX(&(ret->x));
	GetY(&(ret->y));
	return DSFINE;
}

DSReturn DeepSpace::DSRect::SetSize(DSSize* set)
{
	DSCODELOCK(this);
	set->GetWidth(&myWidth);
	set->GetHeight(&myHeight);
	return DSReturn();
}

DSReturn DeepSpace::DSRect::SetPoint(DSPoint* set)
{
	DSCODELOCK(this);
	set->GetX(&myX);
	set->GetY(&myY);
	return DSReturn();
}

DSReturn DeepSpace::DSRect::SetX(FLOAT set)
{
	DSCODELOCK(this);
	myX = set;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::SetY(FLOAT set)
{
	DSCODELOCK(this);
	myY = set;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::SetWidth(FLOAT set)
{
	DSCODELOCK(this);
	myWidth = set;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::SetHeight(FLOAT set)
{
	DSCODELOCK(this);
	myHeight = set;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::SetTop(FLOAT set)
{
	DSCODELOCK(this);
	myY = set;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::SetLeft(FLOAT set)
{
	DSCODELOCK(this);
	myX = set;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::SetRight(FLOAT set)
{
	DSCODELOCK(this);
	myWidth = set - myX;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::SetBottom(FLOAT set)
{
	DSCODELOCK(this);
	myHeight = set - myY;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::GetSize(DSSize* ret)
{
	ret->Init(myWidth, myHeight);
	return DSFINE;
}

DSReturn DeepSpace::DSRect::GetPoint(DSPoint* ret)
{
	ret->Init(myX, myY);
	return DSFINE;
}

DSReturn DeepSpace::DSRect::GetX(FLOAT* ret)
{
	DSCODELOCK(this);
	*ret = myX;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::GetY(FLOAT* ret)
{
	DSCODELOCK(this);
	*ret = myY;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::GetWidth(FLOAT* ret)
{
	DSCODELOCK(this);
	*ret = myWidth;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::GetHeight(FLOAT* ret)
{
	DSCODELOCK(this);
	*ret = myHeight;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::GetTop(FLOAT* ret)
{
	DSCODELOCK(this);
	*ret = myY;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::GetLeft(FLOAT* ret)
{
	DSCODELOCK(this);
	*ret = myX;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::GetRight(FLOAT* ret)
{
	DSCODELOCK(this);
	*ret = myX + myWidth;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::GetBottom(FLOAT* ret)
{
	DSCODELOCK(this);
	*ret = myY + myHeight;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::Empty(BOOL* ret)
{
	DSCODELOCK(this);
	*ret = myWidth < 0 || myHeight < 0;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::Offset(FLOAT setX, FLOAT setY)
{
	DSCODELOCK(this);
	myX += setX;
	myY += setY;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::Inflate(FLOAT setX, FLOAT setY)
{
	DSCODELOCK(this);
	myX -= setX;
	myX -= setY;
	myWidth += 2 * setX;
	myHeight += 2 * setY;
	return DSFINE;
}

DSReturn DeepSpace::DSRect::Collision(DSBase* set, BOOL* ret)
{
	DSCODELOCK(this);
	FLOAT myTop = 0, myLeft = 0, myRight = 0, myBottom = 0;
	FLOAT setTop = 0, setLeft = 0, setRight = 0, setBottom = 0;

	GetTop(&myTop); set->AutoFunc(L"GetBottom", &setTop);
	GetLeft(&myLeft); set->AutoFunc(L"GetLeft", &myLeft);
	GetRight(&myRight); set->AutoFunc(L"GetRight", &myRight);
	GetBottom(&myBottom); set->AutoFunc(L"GetBottom", &myBottom);

	*ret = (myLeft < setRight) && (myTop < setBottom) &&
		(myRight > setLeft) && (myBottom > setTop);
	return DSFINE;
}

DSOBJECT_INIT_0(DSSize)
DSOBJECT_AUTOFUNC_REG(DSSize, Init, 0);
DSOBJECT_AUTOFUNC_REG(DSSize, GetD2D1SizeF, 1);
DSOBJECT_AUTOFUNC_REG(DSSize, GetD2D1SizeU, 2);
DSOBJECT_AUTOFUNC_REG(DSSize, Empty, 3);
DSOBJECT_AUTOFUNC_REG(DSSize, Inflate, 4);
DSOBJECT_AUTOFUNC_REG(DSSize, SetWidth, 5);
DSOBJECT_AUTOFUNC_REG(DSSize, SetHeight, 6);
DSOBJECT_AUTOFUNC_REG(DSSize, GetWidth, 7);
DSOBJECT_AUTOFUNC_REG(DSSize, GetHeight, 8);
DSOBJECT_INIT_1(DSSize)
DSOBJECT_AUTOFUNC_CASE_2(DSSize, DSBase, Init, 0)
DSOBJECT_AUTOFUNC_CASE_1(DSSize, DSBase, GetD2D1SizeF, 1)
DSOBJECT_AUTOFUNC_CASE_1(DSSize, DSBase, GetD2D1SizeU, 2)
DSOBJECT_AUTOFUNC_CASE_1(DSSize, DSBase, Empty, 3)
DSOBJECT_AUTOFUNC_CASE_2(DSSize, DSBase, Inflate, 4)
DSOBJECT_AUTOFUNC_CASE_1(DSSize, DSBase, SetWidth, 5)
DSOBJECT_AUTOFUNC_CASE_1(DSSize, DSBase, SetHeight, 6)
DSOBJECT_AUTOFUNC_CASE_1(DSSize, DSBase, GetWidth, 7)
DSOBJECT_AUTOFUNC_CASE_1(DSSize, DSBase, GetHeight, 8)
DSOBJECT_INIT_2(DSSize, DSBase);

DeepSpace::DSSize::DSSize()
{
	DSCODELOCK(this);
	myWidth = myHeight = 0;
}

DeepSpace::DSSize::~DSSize()
{
	DSCODELOCK(this);
}

DSReturn DeepSpace::DSSize::Clone(DSBase** ret)
{
	DSCODELOCK(this);
	*ret = new DSSize;
	((DSSize*)(*ret))->Init(myWidth, myHeight);
	return DSFINE;
}

DSBase& DeepSpace::DSSize::operator=(DSBase& rhs)
{
	DSCODELOCK(this);
	rhs.AutoFunc(L"GetWidth", &myWidth);
	rhs.AutoFunc(L"GetHeight", &myHeight);
	return *this;
}

BOOL DeepSpace::DSSize::operator==(DSBase& rhs)
{
	DSCODELOCK(this);
	FLOAT tW = 0, tH = 0;
	rhs.AutoFunc(L"GetWidth", &tW);
	rhs.AutoFunc(L"GetHeight", &tH);
	return tW == myWidth && tH == myHeight;
	return DSFINE;
}

DSReturn DeepSpace::DSSize::Init(FLOAT setWidth, FLOAT setHeight)
{
	DSCODELOCK(this);
	myWidth = setWidth;
	myHeight = setHeight;
	return DSFINE;
}

DSReturn DeepSpace::DSSize::GetD2D1SizeF(D2D1_SIZE_F* ret)
{
	DSCODELOCK(this);
	GetWidth(&(ret->width));
	GetHeight(&(ret->height));
	return DSFINE;
}

DSReturn DeepSpace::DSSize::GetD2D1SizeU(D2D1_SIZE_U* ret)
{
	DSCODELOCK(this);
	FLOAT tW = 0, tH = 0;
	GetWidth(&tW);
	GetHeight(&tH);
	ret->width = tW;
	ret->height = tH;
	return DSFINE;
}

DSReturn DeepSpace::DSSize::Empty(BOOL* ret)
{
	DSCODELOCK(this);
	*ret = myWidth < 0 || myHeight < 0;
	return DSFINE;
}

DSReturn DeepSpace::DSSize::Inflate(FLOAT setX, FLOAT setY)
{
	DSCODELOCK(this);
	myWidth += 2 * setX;
	myHeight += 2 * setY;
	return DSFINE;
}

DSReturn DeepSpace::DSSize::SetWidth(FLOAT set)
{
	DSCODELOCK(this);
	myWidth = set;
	return DSFINE;
}

DSReturn DeepSpace::DSSize::SetHeight(FLOAT set)
{
	DSCODELOCK(this);
	myHeight = set;
	return DSFINE;
}

DSReturn DeepSpace::DSSize::GetWidth(FLOAT* ret)
{
	DSCODELOCK(this);
	*ret = myWidth;
	return DSFINE;
}

DSReturn DeepSpace::DSSize::GetHeight(FLOAT* ret)
{
	DSCODELOCK(this);
	*ret = myHeight;
	return DSFINE;
}

DSOBJECT_INIT_0(DSPoint)
DSOBJECT_AUTOFUNC_REG(DSPoint, Init, 0);
DSOBJECT_AUTOFUNC_REG(DSPoint, GetD2D1PointU, 1);
DSOBJECT_AUTOFUNC_REG(DSPoint, GetD2D1PointF, 2);
DSOBJECT_AUTOFUNC_REG(DSPoint, Offset, 3);
DSOBJECT_AUTOFUNC_REG(DSPoint, SetX, 4);
DSOBJECT_AUTOFUNC_REG(DSPoint, SetY, 5);
DSOBJECT_AUTOFUNC_REG(DSPoint, GetX, 6);
DSOBJECT_AUTOFUNC_REG(DSPoint, GetY, 7);
DSOBJECT_INIT_1(DSPoint)
DSOBJECT_AUTOFUNC_CASE_2(DSPoint, DSBase, Init, 0)
DSOBJECT_AUTOFUNC_CASE_1(DSPoint, DSBase, GetD2D1PointU, 1)
DSOBJECT_AUTOFUNC_CASE_1(DSPoint, DSBase, GetD2D1PointF, 2)
DSOBJECT_AUTOFUNC_CASE_2(DSPoint, DSBase, Offset, 3)
DSOBJECT_AUTOFUNC_CASE_1(DSPoint, DSBase, SetX, 4)
DSOBJECT_AUTOFUNC_CASE_1(DSPoint, DSBase, SetY, 5)
DSOBJECT_AUTOFUNC_CASE_1(DSPoint, DSBase, GetX, 6)
DSOBJECT_AUTOFUNC_CASE_1(DSPoint, DSBase, GetY, 7)
DSOBJECT_INIT_2(DSPoint, DSBase);

DeepSpace::DSPoint::DSPoint()
{
	DSCODELOCK(this);
	myX = myY = 0;
}

DeepSpace::DSPoint::~DSPoint()
{
	DSCODELOCK(this);
}

DSReturn DeepSpace::DSPoint::Clone(DSBase** ret)
{
	DSCODELOCK(this);
	*ret = new DSPoint;
	((DSPoint*)(*ret))->Init(myX, myY);
	return DSFINE;
}

DSBase& DeepSpace::DSPoint::operator=(DSBase& rhs)
{
	DSCODELOCK(this);
	rhs.AutoFunc(L"GetX", &myX);
	rhs.AutoFunc(L"GetY", &myY);
	return *this;
}

BOOL DeepSpace::DSPoint::operator==(DSBase& rhs)
{
	// TODO: 在此处插入 return 语句
	DSCODELOCK(this);
	FLOAT tX = 0, tY = 0;
	rhs.AutoFunc(L"GetX", &tX);
	rhs.AutoFunc(L"GetY", &tY);
	return tX == myX && tY == myY;
	return DSFINE;
}

DSReturn DeepSpace::DSPoint::Init(FLOAT setX, FLOAT setY)
{
	DSCODELOCK(this);
	myX = setX;
	myY = setY;
	return DSFINE;
}

DSReturn DeepSpace::DSPoint::GetD2D1PointU(D2D1_POINT_2U* ret)
{
	DSCODELOCK(this);
	FLOAT tX = 0, tY = 0;
	GetX(&tX);
	GetY(&tY);
	ret->x = tX;
	ret->y = tY;
	return DSFINE;
}

DSReturn DeepSpace::DSPoint::GetD2D1PointF(D2D1_POINT_2F* ret)
{
	DSCODELOCK(this);
	GetX(&(ret->x));
	GetY(&(ret->y));
	return DSFINE;
}

DSReturn DeepSpace::DSPoint::Offset(FLOAT setX, FLOAT setY)
{
	DSCODELOCK(this);
	myX += setX;
	myY += setY;
	return DSFINE;
}

DSReturn DeepSpace::DSPoint::SetX(FLOAT set)
{
	DSCODELOCK(this);
	myX = set;
	return DSFINE;
}

DSReturn DeepSpace::DSPoint::SetY(FLOAT set)
{
	DSCODELOCK(this);
	myY = set;
	return DSFINE;
}

DSReturn DeepSpace::DSPoint::GetX(FLOAT* ret)
{
	DSCODELOCK(this);
	*ret = myX;
	return DSFINE;
}

DSReturn DeepSpace::DSPoint::GetY(FLOAT* ret)
{
	DSCODELOCK(this);
	*ret = myY;
	return DSFINE;
}

DSOBJECT_INIT_0(DSColor)
DSOBJECT_INIT_1(DSColor)
DSOBJECT_INIT_2(DSColor, DSBase);

static const UINT32 sc_redShift = 16;
static const UINT32 sc_greenShift = 8;
static const UINT32 sc_blueShift = 0;

static const UINT32 sc_redMask = 0xff << sc_redShift;
static const UINT32 sc_greenMask = 0xff << sc_greenShift;
static const UINT32 sc_blueMask = 0xff << sc_blueShift;

DeepSpace::DSColor::DSColor()
{
	DSCODELOCK(this);
	myA = myR = myG = myB = 0;
}

DeepSpace::DSColor::~DSColor()
{
	DSCODELOCK(this);
}

DSReturn DeepSpace::DSColor::Clone(DSBase** ret)
{
	DSCODELOCK(this);
	*ret = new DSColor;
	((DSColor*)(*ret))->Init(myA, myR, myG, myB);
	return DSFINE;
}

DSBase& DeepSpace::DSColor::operator=(DSBase& rhs)
{
	DSCODELOCK(this);
	rhs.AutoFunc(L"GetA", &myA);
	rhs.AutoFunc(L"GetR", &myR);
	rhs.AutoFunc(L"GetG", &myG);
	rhs.AutoFunc(L"GetB", &myB);
	return *this;
}

BOOL DeepSpace::DSColor::operator==(DSBase& rhs)
{
	DSCODELOCK(this);
	FLOAT tA = 0, tR = 0, tG = 0, tB = 0;
	rhs.AutoFunc(L"GetA", &tA);
	rhs.AutoFunc(L"GetR", &tR);
	rhs.AutoFunc(L"GetG", &tG);
	rhs.AutoFunc(L"GetB", &tB);
	return tA == myA && tR == myR && tG == myG && tB == myB;
}

DSReturn DeepSpace::DSColor::Init(FLOAT setA, FLOAT setR, FLOAT setG, FLOAT setB)
{
	DSCODELOCK(this);
	myA = setA;
	myR = setR;
	myG = setG;
	myB = setB;
	return DSFINE;
}

DSReturn DeepSpace::DSColor::SetColor(FLOAT setA, UINT32 set)
{
	DSCODELOCK(this);
	myR = static_cast<FLOAT>((set & sc_redMask) >> sc_redShift) / 255.f;
	myG = static_cast<FLOAT>((set & sc_greenMask) >> sc_greenShift) / 255.f;
	myB = static_cast<FLOAT>((set & sc_blueMask) >> sc_blueShift) / 255.f;
	myA = setA;
	return DSFINE;
}

DSReturn DeepSpace::DSColor::GetD2D1ColorF(D2D1_COLOR_F* ret)
{
	DSCODELOCK(this);
	GetA(&(ret->a));
	GetR(&(ret->r));
	GetG(&(ret->g));
	GetB(&(ret->b));
	return DSFINE;
}

DSReturn DeepSpace::DSColor::GetA(FLOAT* ret)
{
	DSCODELOCK(this);
	*ret = myA;
	return DSFINE;
}

DSReturn DeepSpace::DSColor::GetR(FLOAT* ret)
{
	DSCODELOCK(this);
	*ret = myR;
	return DSFINE;
}

DSReturn DeepSpace::DSColor::GetG(FLOAT* ret)
{
	DSCODELOCK(this);
	*ret = myG;
	return DSFINE;
}

DSReturn DeepSpace::DSColor::GetB(FLOAT* ret)
{
	DSCODELOCK(this);
	*ret = myB;
	return DSFINE;
}

DSReturn DeepSpace::DSColor::GetRGB(UINT32* ret)
{
	DSCODELOCK(this);
	*ret = RGB(myR, myG, myB);
	return DSFINE;
}
