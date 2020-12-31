#pragma once
#include "MfxBasicModules.h"

namespace MicroFlakeX
{
	class MFX_MOUDULEDLL_IMPORT MfxBasicGraph;	// ͼƬ����
	class MFX_MOUDULEDLL_IMPORT MfxGraphList;

	class MFX_MOUDULEDLL_IMPORT MfxImage;	//ͼƬ
	class MFX_MOUDULEDLL_IMPORT MfxWords;	//����
	class MFX_MOUDULEDLL_IMPORT MfxShape;	//��״

	class MFX_MOUDULEDLL_IMPORT MfxTexture;	//��״
	
}

//MfxBasicGraph����
namespace MicroFlakeX
{
	typedef Gdiplus::Graphics GdipGraphics;
	typedef Gdiplus::GraphicsPath GdipGraphicsPath;

	typedef Gdiplus::Rect GdipRect; //����
	typedef Gdiplus::Size GdipSize; //��С
	typedef Gdiplus::Point GdipPoint; //��
	typedef Gdiplus::Color GdipColor; //��ɫ
	typedef int MfxPenWidth; //�ʵĴ�ϸ
	typedef Gdiplus::Region GdipRegion; //����
	typedef Gdiplus::ImageAttributes GdipImageAttributes;
	typedef Gdiplus::ColorMap GdipColorMap;

	typedef Gdiplus::Pen GdipPen; //��
	typedef Gdiplus::Font GdipFont; //����
	typedef Gdiplus::FontFamily GdipFontFamily; //�������
	typedef Gdiplus::Brush GdipBrush; //��ˢ
	typedef Gdiplus::SolidBrush GdipBrushSolid; //��ɫ��ˢ
	typedef Gdiplus::StringFormat GdipStringFormat; //������Ϣ
	typedef Gdiplus::Region GdipRegion;
	typedef Gdiplus::Bitmap GdipBitmap;
	typedef Gdiplus::CachedBitmap GdipCachedBitmap;
	typedef Gdiplus::Matrix GdipMatrix;


	typedef int MfxFontStyle;
	typedef int MfxWords_TextXY;
	typedef int MfxWords_ShowStyle;


	struct MfxGraphList_Value
	{
		MfxGraphList_Value(MfxBasicGraph* graph, int floor)
		{
			myGraph = graph;
			myFloor = floor;
		}
		MfxBasicGraph* myGraph;
		int myFloor;

		MfxGraphList_Value* Clone()
		{
			return new MfxGraphList_Value(myGraph, myFloor);
		}
	};
}

//MfxBasicGraph����
namespace MicroFlakeX
{
	typedef std::vector<MfxGraphList_Value*> MfxBasicGraph_Vector;

	typedef MfxDataFlag<GdipBitmap*> MfxDataFlag_pGdipBitmap;
	typedef MfxDataFlag<GdipSize> MfxDataFlag_Size;
	typedef MfxDataFlag<GdipRect> MfxDataFlag_Rect;
	typedef MfxDataFlag<GdipRegion*> MfxDataFlag_Region;
}

//MfxBasicGraphö��
namespace MicroFlakeX
{
	//���������
	enum MfxSmoothingMode_EN
	{
		MfxSmoothingMode_Low = Gdiplus::SmoothingModeHighSpeed, //�����������
		MfxSmoothingMode_Hig = Gdiplus::SmoothingModeHighQuality, //�����������
		MfxSmoothingMode_Def = MfxSmoothingMode_Low, //Ĭ�ϵ���������� - ��ͬ��MfxGraph_SmoothingMode_low
	};

	//ͼƬ��ֵ����
	enum MfxInterpolationMode_EN
	{
		MfxInterpolationMode_Low = Gdiplus::InterpolationModeNearestNeighbor, //������ - ���ڽ���ֵ��
		MfxInterpolationMode_Med = Gdiplus::InterpolationModeHighQualityBilinear, //������ - ˫���Բ�ֵ��
		MfxInterpolationMode_Hig = Gdiplus::InterpolationModeHighQualityBicubic, //������ - ˫����ֵ
		MfxInterpolationMode_Def = Gdiplus::InterpolationModeDefault, //Ĭ�ϵĲ�ֵ����
	};

	//������ʽ
	enum MfxFontStyle_EN
	{
		MfxFontStyle_Regu = Gdiplus::FontStyleRegular, //ָ������������������ϸ��
		MfxFontStyle_Bold = Gdiplus::FontStyleBold, //ָ�������֡������ǽ��ص��������ȡ�
		MfxFontStyle_Ital = Gdiplus::FontStyleItalic, //ָ��б�����壬������ʹ�ַ��Ĵ�ֱ�ʸ�������б��
		MfxFontStyle_UnderLine = Gdiplus::FontStyleUnderline, //ָ���»��ߣ����»������ַ��Ļ����·���ʾһ�С�
		MfxFontStyle_StrikeOut = Gdiplus::FontStyleStrikeout, //ָ��ɾ���ߣ�ɾ������ʾ���ַ��м���Ƶ�ˮƽ�ߡ�
	};

	//������ʾ��ʽ(����ϣ����ö����|��������)
	enum MfxWords_ShowStyle_EN
	{

		MfxWords_ShowStyle_null = 0x0000,	//����ʾ����
		MfxWords_ShowStyle_fill = 0x0001,	//��䱳��
		MfxWords_ShowStyle_fram = 0x0002,	//���߿�
		MfxWords_ShowStyle_def = MfxWords_ShowStyle_null,	//Ĭ�ϵ���ʾ��ʽ - ��ͬ��MfxWords_ShowType_null
	};

	//�����Ű��ʽ
	enum  MfxWords_TextXY_EN
	{
		MfxWords_TextX_near = 0x0001,		//X�῿���Ű�
		MfxWords_TextX_center = 0x0002,		//X������Ű�
		MfxWords_TextX_far = 0x0004,		//X�῿���Ű�
		MfxWords_TextX_def = MfxWords_TextX_center, //Ĭ�ϵĸ�ʽ - ��ͬ��MfxWords_FormatX_near
		MfxWords_TextY_near = 0x0010,		//Y�῿���Ű�
		MfxWords_TextY_center = 0x0020,		//Y������Ű�
		MfxWords_TextY_far = 0x0040,		//Y�῿���Ű�
		MfxWords_TextY_def = MfxWords_TextY_center, //Ĭ�ϵĸ�ʽ - ��ͬ��MfxWords_FormatY_near
	};
}

//MfxBasicGraph�ṹ��
namespace MicroFlakeX
{
	struct MfxWorlds_Type
	{
		MfxStrW myFontName; //��������

		MfxWords_TextXY myTextXY; //MfxWords�Ű��ʽ - ���С����ҡ�����
		MfxWords_ShowStyle myShowStyle; //MfxWords��ʾģʽ - ���֡��������߿�
		MfxFontStyle myFontStyle; //Font��ʽ - �Ӵ֡�б�塢ɾ�����»���
		MfxSmoothingMode_EN mySmoothingMode; //���ֻ�������

		GdipColor myTextColor; //������ɫ
		MfxPenWidth myTextSize_em; //���ִ�ϸ - em��С

		GdipColor myFrameColor; //�߿���ɫ
		MfxPenWidth myFramePenWidth; //�߿��ϸ

		GdipColor myBackColor; //������ɫ
	};
}

//
namespace MicroFlakeX
{
	MFX_MOUDULEDLL_IMPORT ID2D1Factory* MfxGetID2D1Factory();
	MFX_MOUDULEDLL_IMPORT IDWriteFactory* MfxGetIDWriteFactory();
	MFX_MOUDULEDLL_IMPORT IWICImagingFactory* MfxGetIWICImagingFactory();

	MFX_MOUDULEDLL_IMPORT ID2D1DCRenderTarget* MfxGetID2D1DCRenderTarget(HDC hDC, GdipRect rect);
	MFX_MOUDULEDLL_IMPORT ID2D1HwndRenderTarget* MfxGetID2D1HwndRenderTarget(HWND hWnd, GdipSize size);

	MFX_MOUDULEDLL_IMPORT IWICBitmap* MfxIWICBitmapFromFile(MfxStrW path, UINT width, UINT height);
	MFX_MOUDULEDLL_IMPORT ID2D1Bitmap* MfxID2D1BitmapFromIWICBitmap(IWICBitmap* bitmap, UINT width, UINT height, ID2D1RenderTarget* pRenderTarget);
	MFX_MOUDULEDLL_IMPORT ID2D1Bitmap* MfxID2D1BitmapFromFile(MfxStrW path, UINT width, UINT height, ID2D1RenderTarget * pRenderTarget);
}

//�ڲ�����
namespace __MicroFlakeX
{
	using namespace MicroFlakeX;
	MFX_MOUDULEDLL_IMPORT bool MfxGraphListFloorCompare(MfxGraphList_Value* lhs, MfxGraphList_Value* rhs);
}

//MfxBasicGraph����
namespace MicroFlakeX
{
	//MfxGraph�� - ���Ի���ͼ��
	class MfxBasicGraph
		: public MfxBasicObject
	{
	public:
		MfxBasicGraph();
		virtual ~MfxBasicGraph();
	};
}

namespace MicroFlakeX
{
	class MfxGraphList 
		: public MfxBasicGraph
	{
		DEFINE_AUTOBASIC;
	protected:
		void MfxGraphListInitData();
	public:
		MfxGraphList();
		virtual ~MfxGraphList();
		MfxReturn Clone(MfxGraphList** ret);
		MfxReturn Similar(MfxGraphList* set);

	protected:
		HDC myDC;
		GdipRect myRect;
		GdipSize myCollisionBlock;
		ID2D1RenderTarget* myRenderTarget;
		MfxBasicGraph_Vector myGraphVector;
		MfxBasicGraph_Vector::iterator myItem;
	public:
		MfxReturn AddItem(MfxBasicGraph* set, int floor);
		MfxReturn RemoveItem(MfxBasicGraph* set);

		MfxReturn NextItem();
		MfxReturn GetItemObject(MfxBasicGraph** ret);

	public:
		MfxReturn Draw();

		MfxReturn SetDC(HDC set);
		MfxReturn GetDC(HDC* ret);

		MfxReturn SetRenderTarget(ID2D1RenderTarget* set);
		MfxReturn GetRenderTarget(ID2D1RenderTarget** ret);

		MfxReturn SetRect(GdipRect set);
		MfxReturn SetSize(GdipSize set);
		MfxReturn SetPoint(GdipPoint set);
		
		MfxReturn GetRect(GdipRect* ret);
		MfxReturn GetSize(GdipSize* ret);
		MfxReturn GetPoint(GdipPoint* ret);

		MfxReturn SetCollisionBlock(GdipSize set);
		MfxReturn CollisionWith(MfxBasicGraph* set, bool* ret);
	};
}

/* ���������������������������������������������������������������������������������������� */
/* ���������������������������������������������������������������������������������������� */
/* ���������������������������������������������������������������������������������������� */

//MfxImage
namespace MicroFlakeX
{
	//֧�����ֻ���ģʽ
	class MfxImage
		: public MfxBasicGraph
	{
		DEFINE_AUTOBASIC;
	protected:
		void MfxImageInitData();
	public:
		MfxImage();
		virtual ~MfxImage();
		void operator=(MfxImage& rhs);

		MfxReturn Clone(MfxImage** ret);
		MfxReturn Similar(MfxImage* set);
	protected:
		MfxDataFlag_Rect myRect; //ͼƬ����
		MfxDataFlag_pGdipBitmap myBasicBitmap; //ͼƬ��׼ - ���ŵ�ʱ��������ͼƬΪ��׼
		MfxInterpolationMode_EN myImageQuality; //ͼƬ����

		HDC myDC;
		GdipGraphics* myGraphics;
		GdipBitmap* myShowBitmap;
		GdipCachedBitmap* myCachedShowBitmap;

		GdipRegion* myBasicRegion,* myShowRegion;
		MfxDataFlag_Size myCollisionBlock;

		BOOL myResetRegionLock;
		BOOL myResetShowBitmapLock;
		BOOL myResetShowCachedBitmapLock;
	protected:
		void Mode_ClearDC();
		void Mode_ResetDC(HDC set);

	public:
		MfxReturn LockResetRegion();
		MfxReturn UnLockResetRegion();

		MfxReturn LockResetShowBitmap();
		MfxReturn UnLockResetShowBitmap();

		MfxReturn LockResetCachedShowBitmap();
		MfxReturn UnLockResetCachedShowBitmap();

		MfxReturn ResetRegion();
		MfxReturn ResetShowBitmap();
		MfxReturn ResetCachedShowBitmap();
	public:
		MfxReturn SetDC(HDC set);
		MfxReturn GetDC(HDC* get);
	public:
		MfxReturn FromFile(MfxStrW path);
		MfxReturn FromColor(GdipColor set);
		MfxReturn FromBitmap(GdipBitmap* set);

		MfxReturn GetShowBitmap(GdipBitmap** ret); //��ȡ��ǰ��ʾͼƬ
		MfxReturn GetBasicBitmap(GdipBitmap** ret); //��ȡ����ͼƬ
		MfxReturn SetBasicBitmap(GdipBitmap* set);

		MfxReturn Draw();
		MfxReturn DrawBitmap(GdipGraphics* set); //����ͼƬ������Ϊ: GdipGraphics*

	public:
		MfxReturn SetQuality(MfxInterpolationMode_EN set); //����ͼƬ��ֵ����

		MfxReturn SetRect(GdipRect set);
		MfxReturn SetSize(GdipSize set);
		MfxReturn SetPoint(GdipPoint set);

		MfxReturn CollisionWith(MfxBasicGraph* set, bool* ret);
		MfxReturn SetCollisionBlock(GdipSize set);

		MfxReturn CropSize(GdipColor set); //������ɫ�ü�ͼƬ��ѡ�е���ɫ���ᱻ�ü�
		MfxReturn ChangeColor(GdipColor oldColor, GdipColor newColor); //������ɫ����һ��������oldcolor���ڶ���������newcolor

	public:
		MfxReturn GetQuality(MfxInterpolationMode_EN* ret);

		MfxReturn GetRegion(GdipRegion** ret);
		MfxReturn GetRegionBlock(GdipSize* ret);

		MfxReturn GetRect(GdipRect* ret);
		MfxReturn GetSize(GdipSize* ret);
		MfxReturn GetPoint(GdipPoint* ret);
	};
}

//MfxWorld
namespace MicroFlakeX
{
	//֧�����ֻ���ģʽ
	class MfxWords
		: public MfxBasicGraph
	{
		DEFINE_AUTOBASIC;
	protected:
		void MfxWordsInitData(MfxWorlds_Type set);
	public:
		MfxWords();
		MfxWords(MfxWorlds_Type set);
		virtual ~MfxWords();
		void operator=(MfxWords& rhs);

		MfxReturn Clone(MfxWords** ret);
		MfxReturn Similar(MfxWords* set);
	protected:
		static MfxWorlds_Type g_DefType;
	public:
		static void SetDefType(MfxWorlds_Type& setType);
		static void GetDefType(MfxWorlds_Type& getType);

		/**/
	protected:
		int myCachedMode; //����ģʽ
		HDC myDC;
		GdipGraphics* myGraphics;
		GdipGraphicsPath* myGraphicsPath;

		MfxDataFlag_Rect myRect; //�ı���λ��
		MfxStrW myText;
		MfxWorlds_Type myType; //�������� - ʹ��ȫ�ֲ���
		GdipFontFamily* myFontFamily; //���ּ���
		GdipStringFormat* myStringFormat; //������Ϣ

		GdipPen* myFramePen;
		GdipBrush* myBackBrush;
		GdipBrush* myTextBrush;

		GdipRect myTextRect; //�������ֵ�λ��
		GdipPen* myTextRectPen; //�����������ֵı߿��

		MfxDataFlag_pGdipBitmap myShowBitmap;
		GdipGraphics* myShowGraphics;
		GdipCachedBitmap* myCachedShowBitmap;

		GdipRegion* myBasicRegion, * myShowRegion;
		MfxDataFlag_Size myCollisionBlock;

		BOOL myResetRegionLock;
		BOOL myResetTextPathLock;
		BOOL myResetShowBitmapLock;
		BOOL myResetShowCachedBitmapLock;
	protected:
		void Mode_ClearDC();
		void Mode_ResetDC(HDC set);
		/* ���������������������������������������������������������������������������������������� */
	public:
		MfxReturn LockResetRegion();
		MfxReturn UnLockResetRegion();

		MfxReturn LockResetTextPath();
		MfxReturn UnLockResetTextPath();

		MfxReturn LockResetShowBitmap();
		MfxReturn UnLockResetShowBitmap();

		MfxReturn LockResetCachedShowBitmap();
		MfxReturn UnLockResetCachedShowBitmap();

		MfxReturn ResetRegion();
		MfxReturn ResetTextPath(); //��������·��
		MfxReturn ResetShowBitmap(); //������ʾͼƬ
		MfxReturn ResetCachedShowBitmap();
	public:
		MfxReturn SetDC(HDC set);
		MfxReturn GetDC(HDC* ret);

		MfxReturn GetShowBitmap(GdipBitmap** ret); //��ȡ��ǰ��ʾͼƬ

		MfxReturn Draw();
		MfxReturn DrawBitmap(GdipGraphics* set);

	public:
		MfxReturn SetText(MfxStrW set);
		MfxReturn GetText(MfxStrW* ret);

		MfxReturn SetStringFormat(GdipStringFormat* set); //�������ָ�ʽ
		MfxReturn GetStringFormat(GdipStringFormat** ret);
		/* ���������������������������������������������������������������������������������������� */
	public:
		MfxReturn SetType(MfxWorlds_Type set);

		MfxReturn SetFontName(MfxStrW set); //��������

		MfxReturn SetTextXY(MfxWords_TextXY set); //�������ֶ���
		MfxReturn SetShowStyle(MfxWords_ShowStyle set);
		MfxReturn SetFontStyle(MfxFontStyle set);
		MfxReturn SetSmoothingMode(MfxSmoothingMode_EN set);

		MfxReturn SetTextColor(GdipColor set);
		MfxReturn SetTextSize_em(MfxPenWidth set); //���������С

		MfxReturn SetFrameColor(GdipColor set);
		MfxReturn SetFramePenWidth(MfxPenWidth set); //���ñ߿���

		MfxReturn SetBackColor(GdipColor set);

	public:
		MfxReturn GetType(MfxWorlds_Type* ret);

		MfxReturn GetFontName(MfxStrW* ret); //��������

		MfxReturn GetTextXY(MfxWords_TextXY* ret); //�������ֶ���
		MfxReturn GetShowStyle(MfxWords_ShowStyle* ret);
		MfxReturn GetFontStyle(MfxFontStyle* ret);
		MfxReturn GetSmoothingMode(MfxSmoothingMode_EN* ret);

		MfxReturn GetTextColor(GdipColor* ret);
		MfxReturn GetTextSize_em(MfxPenWidth* ret); //���������С

		MfxReturn GetFrameColor(GdipColor* ret);
		MfxReturn GetFramePenWidth(MfxPenWidth* ret); //���ñ߿���

		MfxReturn GetBackColor(GdipColor* ret);
		/* ���������������������������������������������������������������������������������������� */
	public:
		MfxReturn SetRect(GdipRect set);
		MfxReturn SetSize(GdipSize set);
		MfxReturn SetPoint(GdipPoint set);

		MfxReturn SetCollisionBlock(GdipSize set);
		MfxReturn CollisionWith(MfxBasicGraph* set, bool* ret);

		MfxReturn SetFramePen(GdipPen* set);
		MfxReturn SetBackBrush(GdipBrush* set);
		MfxReturn SetTextBrush(GdipBrush* set);

	public:
		MfxReturn GetRect(GdipRect* ret);
		MfxReturn GetSize(GdipSize* ret);
		MfxReturn GetPoint(GdipPoint* ret);

		MfxReturn GetRegion(GdipRegion** ret);
		MfxReturn GetRegionBlock(GdipSize* ret);

		MfxReturn GetFramePen(GdipPen** ret);
		MfxReturn GetBackBrush(GdipBrush** ret);
		MfxReturn GetTextBrush(GdipBrush** ret);
		/* ���������������������������������������������������������������������������������������� */
	};
}

namespace MicroFlakeX
{
	class MfxTexture
		: public MfxBasicGraph
	{
		DEFINE_AUTOBASIC;
	protected:
		void MfxTextureInitData();
	public:
		MfxTexture();
		virtual ~MfxTexture();
		void operator=(MfxTexture& rhs);

		MfxReturn Clone(MfxTexture** ret);
		MfxReturn Similar(MfxTexture* set);
	protected:
		MfxDataFlag_Rect myRect;
		ID2D1RenderTarget* myRenderTarget;
		
		IWICBitmap* myBasicIWICBitmap;
		ID2D1Bitmap* myShowID2D1Bitmap;
	public:
		MfxReturn ResetShowBitmap();
	public:
		MfxReturn FromFile(MfxStrW path);
		MfxReturn FromColor(MfxStrW path);

		MfxReturn SetRenderTarget(ID2D1RenderTarget* set);
		MfxReturn GetRenderTarget(ID2D1RenderTarget** ret);

		MfxReturn Draw();

		MfxReturn SetRect(GdipRect set);
		MfxReturn SetSize(GdipSize set);
		MfxReturn SetPoint(GdipPoint set);

		MfxReturn GetRect(GdipRect* ret);
		MfxReturn GetSize(GdipSize* ret);
		MfxReturn GetPoint(GdipPoint* ret);

		MfxReturn CollisionWith(MfxBasicGraph* set, bool* ret);
		MfxReturn SetCollisionBlock(GdipSize set);
	};
}