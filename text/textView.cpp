
// textView.cpp : CtextView 类的实现
//

#include "stdafx.h"
#include "text.h"

#include "textDoc.h"
#include "textView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtextView

IMPLEMENT_DYNCREATE(CtextView, CView)

BEGIN_MESSAGE_MAP(CtextView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CtextView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CtextView 构造/析构

CtextView::CtextView()
{
	// TODO: 在此处添加构造代码

}

CtextView::~CtextView()
{
}

BOOL CtextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CtextView 绘制

void CtextView::OnDraw(CDC* pDC)
{
	// TODO: 在此处为本机数据添加绘制代码
	CtextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->BandsType == 0)
	{
		int i,j;
		int  nWidth = pDoc->nXsize;
		int nHeight = pDoc->nYsize;
		BITMAPINFO * pBmpInfo = (BITMAPINFO*) new char[sizeof(BITMAPINFO) + sizeof(RGBQUAD)*(256)];
		pBmpInfo->bmiHeader.biBitCount = 8;
		pBmpInfo->bmiHeader.biClrImportant = 0;
		pBmpInfo->bmiHeader.biClrUsed = 0;
		pBmpInfo->bmiHeader.biCompression = BI_RGB;
		pBmpInfo->bmiHeader.biWidth = nWidth;
		pBmpInfo->bmiHeader.biHeight = nHeight;
		pBmpInfo->bmiHeader.biPlanes = 1;
		pBmpInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		pBmpInfo->bmiHeader.biSizeImage = (nWidth*8+31)/32*4*nHeight;
		pBmpInfo->bmiHeader.biXPelsPerMeter = 0;
		pBmpInfo->bmiHeader.biYPelsPerMeter = 0;
		for (i=0;i<256;i++)
		{
			pBmpInfo->bmiColors[i].rgbRed = i;
			pBmpInfo->bmiColors[i].rgbGreen = i;
			pBmpInfo->bmiColors[i].rgbBlue = i;
			pBmpInfo->bmiColors[i].rgbReserved = 0;
		}
		LONG LineBytes = (nWidth*8+31)/32*4;
		LPBYTE pData = (LPBYTE)new char[LineBytes*nHeight];
		for (i=0;i<nHeight;i++)
		{
			for (j=0;j<nWidth;j++)
			{
				pData[(nHeight-i-1)*LineBytes+j] = pDoc->opBandBlock_Gray[i*nWidth+j];
			}
		}
		SetStretchBltMode(pDC->m_hDC,BLACKONWHITE|WHITEONBLACK);
		StretchDIBits(pDC->m_hDC,0,0,nWidth,nHeight,0,0,nWidth,nHeight,
			pData,pBmpInfo,DIB_RGB_COLORS,SRCCOPY);
		UpdateWindow();
		delete pBmpInfo;
		delete pData;
	}
	if (pDoc->BandsType ==1)
	{
		int i,j,k;
		int nWidth = pDoc->nXsize;
		int nHeight = pDoc->nYsize;
		BITMAPINFO *pBmpInfo = (BITMAPINFO *)new char[sizeof(BITMAPINFO)+sizeof(RGBQUAD)*256];
		pBmpInfo->bmiHeader.biBitCount = 24;
		pBmpInfo->bmiHeader.biClrImportant = 0;
		pBmpInfo->bmiHeader.biClrUsed = 0;
		pBmpInfo->bmiHeader.biCompression = BI_RGB;
		pBmpInfo->bmiHeader.biWidth = nWidth;
		pBmpInfo->bmiHeader.biHeight = nHeight;
		pBmpInfo->bmiHeader.biPlanes =1;
		pBmpInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		pBmpInfo->bmiHeader.biSizeImage =(nWidth*24+31)/32*4*nHeight;
		pBmpInfo->bmiHeader.biXPelsPerMeter = 0;
		pBmpInfo->bmiHeader.biYPelsPerMeter = 0;
		for (i=0;i<256;i++)
		{
			pBmpInfo->bmiColors[i].rgbRed = i;
			pBmpInfo->bmiColors[i].rgbGreen = i;
			pBmpInfo->bmiColors[i].rgbBlue = i;
			pBmpInfo->bmiColors[i].rgbReserved = 0;
		}
		LONG LineBytes = (nWidth*24+31)/32*4;
		LPBYTE pData = (LPBYTE)new char[LineBytes*nHeight*3];
		for (i=0;i<nHeight;i++)
		{
			for (j=k=0;j<nWidth,k<3*nWidth;j++,k+=3)
			{
				pData[(nHeight-i-1)*LineBytes+k] = pDoc->opBandBlock_B[i*nWidth+j];
				pData[(nHeight-i-1)*LineBytes+k+1] = pDoc->opBandBlock_G[i*nWidth+j];
				pData[(nHeight-i-1)*LineBytes+k+2] = pDoc->opBandBlock_R[i*nWidth+j];
			}
		}
		SetStretchBltMode(pDC->m_hDC,BLACKONWHITE|WHITEONBLACK);
		StretchDIBits(pDC->m_hDC,0,0,nWidth,nHeight,0,0,nWidth,nHeight,
			pData,pBmpInfo,DIB_RGB_COLORS,SRCCOPY);
		UpdateWindow();
		delete pBmpInfo;
		delete pData;
	}
}

BOOL CtextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CtextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CtextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}
// CtextView 诊断

#ifdef _DEBUG
void CtextView::AssertValid() const
{
	CView::AssertValid();
}

void CtextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtextDoc* CtextView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtextDoc)));
	return (CtextDoc*)m_pDocument;
}
#endif //_DEBUG


// CtextView 消息处理程序
