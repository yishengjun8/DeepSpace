#pragma once
#include "DSGraph.h"

namespace DeepSpace
{
    class DSRectF :
        public DSBase
    {
        DSOBJECT(DSRectF);
    public:
        DSRectF();
        ~DSRectF();
        DSReturn Clone(DSBase** ret);
        DSBase& operator=(DSBase& rhs);
        DSBase& operator==(DSBase& rhs);
        DSReturn Init(FLOAT setX, FLOAT setY, FLOAT setWidth, FLOAT setHeight);
    
    public:
        DSReturn SetD2D1RectF(D2D1_RECT_F* set);
        DSReturn SetD2D1SizeF(D2D1_SIZE_F* set);
        DSReturn SetD2D1PointF(D2D1_POINT_2F* set);

        DSReturn GetD2D1RectF(D2D1_RECT_F* ret);
        DSReturn GetD2D1SizeF(D2D1_SIZE_F* ret);
        DSReturn GetD2D1PointF(D2D1_POINT_2F* ret);

        DSReturn SetX(FLOAT set);
        DSReturn SetY(FLOAT set);
        DSReturn SetWidth(FLOAT set);
        DSReturn SetHeight(FLOAT set);

        DSReturn SetTop(FLOAT set);
        DSReturn SetLeft(FLOAT set);
        DSReturn SetRight(FLOAT set);
        DSReturn SetBottom(FLOAT set);

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
        FLOAT X;
        FLOAT Y;
        FLOAT Width;
        FLOAT Height;
    };
}


namespace DeepSpace
{
    class DSSizeF
        : public DSBase
    {
        DSOBJECT(DSSizeF);
    public:
        DSSizeF();
        ~DSSizeF();
        DSReturn Clone(DSBase** ret);
        DSBase& operator=(DSBase& rhs);
        bool operator==(DSBase& rhs);
        DSReturn Init(FLOAT setWidth, FLOAT setHeight);
    public:
        DSReturn SetD2D1SizeF(D2D1_SIZE_F* set);
        DSReturn GetD2D1SizeF(D2D1_SIZE_F* ret);

        DSReturn Empty(BOOL* ret);
        DSReturn Inflate(FLOAT setX, FLOAT setY);

        DSReturn SetWidth(FLOAT set);
        DSReturn SetHeight(FLOAT set);

        DSReturn GetWidth(FLOAT* ret);
        DSReturn GetHeight(FLOAT* ret);
    protected:
        FLOAT Width;
        FLOAT Height;
    };
}


namespace DeepSpace
{
    class DSPointF
        : public DSBase
    {
        DSOBJECT(DSPointF);
    public:
        DSPointF();
        ~DSPointF();
        DSReturn Clone(DSBase** ret);
        DSBase& operator=(DSBase& rhs);
        bool operator==(DSBase& rhs);
        DSReturn Init(FLOAT setX, FLOAT setY);
    public:
        DSReturn SetD2D1PointF(D2D1_POINT_2F* set);
        DSReturn GetD2D1PointF(D2D1_POINT_2F* ret);

        DSReturn Offset(FLOAT setX, FLOAT setY);

        DSReturn SetX(FLOAT set);
        DSReturn SetY(FLOAT set);

        DSReturn GetX(FLOAT* ret);
        DSReturn GetY(FLOAT* ret);
    protected:
        FLOAT X;
        FLOAT Y;
    };
}

namespace DeepSpace
{
    class DSColorF
        : public DSBase
    {
        DSOBJECT(DSColorF);
    public:
        DSColorF();
        ~DSColorF();
        DSReturn Clone(DSBase** ret);
        DSBase& operator=(DSBase& rhs);
        bool operator==(DSBase& rhs);
        DSReturn Init(FLOAT setA, FLOAT setR, FLOAT setG, FLOAT setB);
    public:
        DSReturn SetD2D1ColorF(D2D1_COLOR_F* set);
        DSReturn GetD2D1ColorF(D2D1_COLOR_F* ret);

        DSReturn SetA(FLOAT set);
        DSReturn SetR(FLOAT set);
        DSReturn SetG(FLOAT set);
        DSReturn SetB(FLOAT set);

        DSReturn GetA(FLOAT* ret);
        DSReturn GetR(FLOAT* ret);
        DSReturn GetG(FLOAT* ret);
        DSReturn GetB(FLOAT* ret);
    protected:
        FLOAT X;
        FLOAT Y;
    };
}