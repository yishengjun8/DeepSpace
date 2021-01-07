#pragma once
#include "DSGraphTypes.h"

#ifdef DS_BUILDING
#define DS_PORT __declspec(dllexport)
#else
#define DS_PORT __declspec(dllimport)
#pragma comment(lib, "DSGraph.lib")
/**/
#endif

//公开 类 - 模板
namespace DeepSpace
{
    class DS_PORT DSGraph;

    class DS_PORT DSCanvas;

    class DS_PORT DSImage;
    class DS_PORT DSWorld;

    class DS_PORT DSRectangle;
}

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
        DSRect myRect;
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
    public:
        DSReturn ResetRenderTarget();
    public:
        DSReturn DrawEnd();
        DSReturn DrawBegin();
        DSReturn GetRenderTarget(ID2D1RenderTarget** ret);
    public:
        DSReturn SetRect(DSRect* set);
        DSReturn SetSize(DSSize* set);
        
    protected:
        HWND myWnd;
        BOOL myDrawLock;
        DSColor myColor;
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
        DSReturn ResetCollisionGeometry();
    public:
        DSReturn FromFile(DSStr set);

        DSReturn SetCollisionBlock(DSSize* set);
    public:
        DSReturn SetRect(DSRect* set);
        DSReturn SetSize(DSSize* set);
    protected:
        DSCanvas* myCanvas;
        DSSize myCollisionBlock;
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
    };
}


#define __SafeRelease(com) \
if(com)\
{\
    com->Release();\
    com = NULL;\
}
