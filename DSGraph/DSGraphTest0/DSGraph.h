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

//公开 类 - 模板
namespace DeepSpace
{
    class DS_PORT DSGraph;

    class DS_PORT DSCanvas;

    class DS_PORT DSImage;
    class DS_PORT DSWorld;

    class DS_PORT DSRect;
    class DS_PORT DSSize;
    class DS_PORT DSPoint;

    class DS_PORT DSColor;
}

#include "DSGraphTypes.h"

//公开 容器
namespace DeepSpace
{
    typedef std::vector<DSGraph*> DSGraphVector;;
    

}
//公开 函数
namespace DeepSpace
{
    DS_PORT ID2D1Factory* DSID2D1Factory();
    DS_PORT IDWriteFactory* DSIDWriteFactory();
    DS_PORT IWICImagingFactory* DSIWICImagingFactory();

    DS_PORT DSReturn DSID2D1DCRenderTarget(ID2D1DCRenderTarget** ret, HDC set, DSRect* setRect);
    DS_PORT DSReturn DSID2D1HwndRenderTarget(ID2D1HwndRenderTarget** ret, HWND set, DSSize* setSize);

    DS_PORT DSReturn DSIWICBitmapFromFile(IWICBitmap** ret, DSStr set, DSSize* setSize);

    DS_PORT DSReturn DSID2D1BitmapFromFile(ID2D1Bitmap** ret, DSStr set, DSSize* setSize, ID2D1RenderTarget* pRT);
    DS_PORT DSReturn DSID2D1BitmapFromIWICBitmap(ID2D1Bitmap** ret, IWICBitmap* set, DSSize* setSize, ID2D1RenderTarget* pRT);
}

namespace DeepSpace
{
#define SafeRelease(com) __SafeRelease(com)
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
        BOOL operator==(DSBase& rhs);

    public:
        virtual DSReturn SetRect(DSRect* set);
        virtual DSReturn SetSize(DSSize* set);
        virtual DSReturn SetPoint(DSPoint* set);

        virtual DSReturn GetRect(DSRect* ret);
        virtual DSReturn GetSize(DSSize* ret);
        virtual DSReturn GetPoint(DSPoint* ret);

        virtual DSReturn Collision(DSBase* set, BOOL* ret);
    protected:
        DSRect* myRect;
    };
    
}

//公开 DS画板
namespace DeepSpace
{
    class DSCanvas
        : public DSGraph
    {
        DSOBJECT(DSCanvas);
    public:
        DSCanvas();
        ~DSCanvas();
        DSReturn Clone(DSBase** ret);
        DSBase& operator=(DSBase& rhs);
        BOOL operator==(DSBase& rhs);

    public:
        DSReturn SetWnd(HWND set);
        DSReturn GetWnd(HWND* ret);
        DSReturn AddGraph(DSGraph* set);
        DSReturn RemoveGraph(DSGraph* set);
    public:
        DSReturn DrawEnd();
        DSReturn DrawBegin();
        DSReturn IsDraw(BOOL* ret);
        DSReturn GetRenderTarget(ID2D1RenderTarget** ret);
    public:
        DSReturn SetRect(DSRect* set);
        DSReturn SetSize(DSSize* set);
        
    protected:
        HWND myWnd;
        BOOL myDrawLock;
        DSGraphVector myGraphVector;
        ID2D1HwndRenderTarget* myHwndRenderTarget;
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
        BOOL operator==(DSBase& rhs);

    public:
        DSReturn Draw();

        DSReturn SetCanvas(DSCanvas* set);
        DSReturn GetCanvas(DSCanvas** ret);
    protected:
        DSReturn ResetID2D1Bitmap();
    public:
        DSReturn FromFile(DSStr set);
        DSReturn FromColor(DSStr path);

        DSReturn SetCollisionBlock(DSSize set);
        DSReturn Collision(DSBase* set, BOOL* ret);
    public:
        DSReturn SetRect(DSRect* set);
        DSReturn SetSize(DSSize* set);
    protected:
        DSCanvas* myCanvas;
        IWICBitmap* myIWICBitmap;
        ID2D1Bitmap* myID2D1Bitmap;
        ID2D1RenderTarget* myRenderTarget;
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
        BOOL operator==(DSBase& rhs);

    public:
        DSReturn Draw();

        DSReturn SetCanvas(DSCanvas* set);
        DSReturn GetCanvas(DSCanvas** ret);

    public:
        DSReturn SetText(DSStr set);
        DSReturn GetText(DSStr* ret);

        DSReturn SetTextSize(FLOAT set);
        DSReturn GetTextSize(FLOAT* ret);

        DSReturn SetTextColor(DSColor* set);
        DSReturn GetTextColor(DSColor* ret);

        DSReturn SetTextAlignment(UCHAR set);
        DSReturn GetTextAlignment(UCHAR* ret);

        DSReturn SetRect(DSRect* set);
        DSReturn SetSize(DSSize* set);
        DSReturn SetPoint(DSPoint* set);

        DSReturn SetCollisionBlock(DSSize set);
        DSReturn Collision(DSBase* set, BOOL* ret);
    };
}


#define __SafeRelease(com) \
if(com)\
{\
    com->Release();\
    com = NULL;\
}
