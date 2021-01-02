#pragma once
#include "DSBase.h"

#ifdef DS_BUILDING
#ifdef DS_PORT
#undef DS_PORT
#endif
#define DS_PORT __declspec(dllexport)
#else
#define DS_PORT __declspec(dllimport)
#pragma comment(lib, "DSGraph.lib")

#include "DSGraphTypes.h"

/* 数学库 */
#include <cmath>
/**/

/* STL模板库 */
/**/

/* Direct2D1 */
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#include <dwmapi.h>

#pragma comment(lib, "D2D1.lib")
#pragma comment(lib, "DWrite.lib")
/**/
#endif

//公开 类型
namespace DeepSpace
{
    class DS_PORT DSGraph;

    class DS_PORT DSCanvas;

    class DS_PORT DSImage;
    class DS_PORT DSWorld;

    class DS_PORT DSRectF;
    class DS_PORT DSSizeF;
    class DS_PORT DSPointF;

    class DS_PORT DSColorF;
}

//公开 DSGraph基类
namespace DeepSpace
{
    class DSGraph 
        : public DSBase
    {
        DSOBJECT(DSGraph);
    public:
        DSGraph();
        ~DSGraph();
        DSReturn Clone(DSBase** ret);
        DSBase& operator=(DSBase& rhs);
        bool operator==(DSBase& rhs);

    public:
        DSReturn SetRect(DSRectF* set);
        DSReturn SetSize(DSSizeF* set);
        DSReturn SetPoint(DSPointF* set);

        DSReturn GetRect(DSRectF* ret);
        DSReturn GetSize(DSSizeF* ret);
        DSReturn GetPoint(DSPointF* ret);

        DSReturn Collision(DSBase* set, BOOL* ret);
    protected:
        DSRectF* myRectF;
    };
    
}

//公开 DS画板
namespace DeepSpace
{
    class DSCanvas
        : public DSGraph
    {
        DSOBJECT(DSGraph);
    public:
        DSCanvas();
        ~DSCanvas();
        DSReturn Clone(DSBase** ret);
        DSBase& operator=(DSBase& rhs);
        bool operator==(DSBase& rhs);

    public:
        DSReturn SetWnd(HWND set);

        DSReturn AddGraph(DSGraph* set);
        DSReturn RemoveGraph(DSGraph* set);
    public:
        DSReturn SetRect(DSRectF* set);
        DSReturn SetSize(DSSizeF* set);
        DSReturn SetPoint(DSPointF* set);

        DSReturn GetRect(DSRectF* ret);
        DSReturn GetSize(DSSizeF* ret);
        DSReturn GetPoint(DSPointF* ret);
    };
}

//公开 DS图片
namespace DeepSpace
{
    class DSImage
        : public DSGraph
    {
        DSOBJECT(DSImage);
    public:
        DSImage();
        ~DSImage();
        DSReturn Clone(DSBase** ret);
        DSBase& operator=(DSBase& rhs);
        bool operator==(DSBase& rhs);

    public:
        DSReturn Paint();

        DSReturn SetCanvas(DSCanvas* set);
        DSReturn GetCanvas(DSCanvas** ret);

    public:
        DSReturn FromFile(DSStr set);
        DSReturn FromColor(DSStr path);


        DSReturn SetRect(DSRectF* set);
        DSReturn SetSize(DSSizeF* set);
        DSReturn SetPoint(DSPointF* set);

        DSReturn GetRect(DSRectF* ret);
        DSReturn GetSize(DSSizeF* ret);
        DSReturn GetPoint(DSPointF* ret);

        DSReturn SetCollisionBlock(DSSizeF set);
        DSReturn Collision(DSBase* set, BOOL* ret);
    };
}

//公开 DS文字
namespace DeepSpace
{
    class DSWorld
        : public DSGraph
    {
        DSOBJECT(DSWorld);
    public:
        DSWorld();
        ~DSWorld();
        DSReturn Clone(DSBase** ret);
        DSBase& operator=(DSBase& rhs);
        bool operator==(DSBase& rhs);

    public:
        DSReturn Paint();

        DSReturn SetCanvas(DSCanvas* set);
        DSReturn GetCanvas(DSCanvas** ret);

    public:
        DSReturn SetText(DSStr set);
        DSReturn GetText(DSStr* ret);

        DSReturn SetTextSize(FLOAT set);
        DSReturn GetTextSize(FLOAT ret);

        DSReturn SetRect(DSRectF* set);
        DSReturn SetSize(DSSizeF* set);
        DSReturn SetPoint(DSPointF* set);

        DSReturn GetRect(DSRectF* ret);
        DSReturn GetSize(DSSizeF* ret);
        DSReturn GetPoint(DSPointF* ret);

        DSReturn SetCollisionBlock(DSSizeF set);
        DSReturn Collision(DSBase* set, BOOL* ret);
    };
}

