#pragma once
#include "DSGraph.h"

namespace DeepSpace
{
    class DSRect :
        public DSBase
    {
        DSOBJECT(DSRect);
    public:
        DSRect();
        ~DSRect();
        DSReturn Clone(DSBase** ret);
        DSBase& operator=(DSBase& rhs);
        BOOL operator==(DSBase& rhs);

    public:
        DSReturn Init(FLOAT setX, FLOAT setY, FLOAT setWidth, FLOAT setHeight);
    public:
        DSReturn GetD2D1RectU(D2D1_RECT_U* ret);
        DSReturn GetD2D1SizeU(D2D1_SIZE_U* ret);
        DSReturn GetD2D1PointU(D2D1_POINT_2U* ret);

        DSReturn GetD2D1RectF(D2D1_RECT_F* ret);
        DSReturn GetD2D1SizeF(D2D1_SIZE_F* ret);
        DSReturn GetD2D1PointF(D2D1_POINT_2F* ret);

        DSReturn SetSize(DSSize* set);
        DSReturn SetPoint(DSPoint* set);

        DSReturn SetX(FLOAT set);
        DSReturn SetY(FLOAT set);
        DSReturn SetWidth(FLOAT set);
        DSReturn SetHeight(FLOAT set);

        DSReturn SetTop(FLOAT set);
        DSReturn SetLeft(FLOAT set);
        DSReturn SetRight(FLOAT set);
        DSReturn SetBottom(FLOAT set);

        DSReturn GetSize(DSSize* ret);
        DSReturn GetPoint(DSPoint* ret);

        DSReturn GetX(FLOAT* ret);
        DSReturn GetY(FLOAT* ret);
        DSReturn GetWidth(FLOAT* ret);
        DSReturn GetHeight(FLOAT* ret);

        DSReturn GetTop(FLOAT* ret);
        DSReturn GetLeft(FLOAT* ret);
        DSReturn GetRight(FLOAT* ret);
        DSReturn GetBottom(FLOAT* ret);

        DSReturn Empty(BOOL* ret);
        DSReturn Offset(FLOAT setX, FLOAT setY);
        DSReturn Inflate(FLOAT setX, FLOAT setY);

        DSReturn Collision(DSBase* set, BOOL* ret);
    protected:
        FLOAT myX;
        FLOAT myY;
        FLOAT myWidth;
        FLOAT myHeight;
    };
}

namespace DeepSpace
{
    class DSSize
        : public DSBase
    {
        DSOBJECT(DSSize);
    public:
        DSSize();
        ~DSSize();
        DSReturn Clone(DSBase** ret);
        DSBase& operator=(DSBase& rhs);
        BOOL operator==(DSBase& rhs);

    public:
        DSReturn Init(FLOAT setWidth, FLOAT setHeight);
    public:
        DSReturn GetD2D1SizeF(D2D1_SIZE_F* ret);
        DSReturn GetD2D1SizeU(D2D1_SIZE_U* ret);

        DSReturn Empty(BOOL* ret);
        DSReturn Inflate(FLOAT setX, FLOAT setY);

        DSReturn SetWidth(FLOAT set);
        DSReturn SetHeight(FLOAT set);

        DSReturn GetWidth(FLOAT* ret);
        DSReturn GetHeight(FLOAT* ret);
    protected:
        FLOAT myWidth;
        FLOAT myHeight;
    };
}


namespace DeepSpace
{
    class DSPoint
        : public DSBase
    {
        DSOBJECT(DSPoint);
    public:
        DSPoint();
        ~DSPoint();
        DSReturn Clone(DSBase** ret);
        DSBase& operator=(DSBase& rhs);
        BOOL operator==(DSBase& rhs);

    public:
        DSReturn Init(FLOAT setX, FLOAT setY);
    public:
        DSReturn GetD2D1PointU(D2D1_POINT_2U* ret);
        DSReturn GetD2D1PointF(D2D1_POINT_2F* ret);

        DSReturn Offset(FLOAT setX, FLOAT setY);

        DSReturn SetX(FLOAT set);
        DSReturn SetY(FLOAT set);

        DSReturn GetX(FLOAT* ret);
        DSReturn GetY(FLOAT* ret);
    protected:
        FLOAT myX;
        FLOAT myY;
    };
}

namespace DeepSpace
{
    class DSColor
        : public DSBase
    {
        DSOBJECT(DSColor);
    public:
        DSColor();
        ~DSColor();
        DSReturn Clone(DSBase** ret);
        DSBase& operator=(DSBase& rhs);
        BOOL operator==(DSBase& rhs);

    public:
        DSReturn Init(FLOAT setA, FLOAT setR, FLOAT setG, FLOAT setB);
    public:
        DSReturn SetColor(FLOAT setA, UINT32 set)
            ;
        DSReturn GetD2D1ColorF(D2D1_COLOR_F* ret);

        DSReturn GetA(FLOAT* ret);
        DSReturn GetR(FLOAT* ret);
        DSReturn GetG(FLOAT* ret);
        DSReturn GetB(FLOAT* ret);
        DSReturn GetRGB(UINT32* ret);
    protected:
        FLOAT myA;
        FLOAT myR;
        FLOAT myG;
        FLOAT myB;
    };
}