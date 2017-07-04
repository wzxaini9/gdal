
// textDoc.cpp : CtextDoc 类的实现
//

#include "stdafx.h"
#include "text.h"
#include "DlgBands.h"
#include "textDoc.h"
#include <gdal_priv.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtextDoc

IMPLEMENT_DYNCREATE(CtextDoc, CDocument)

BEGIN_MESSAGE_MAP(CtextDoc, CDocument)
END_MESSAGE_MAP()


// CtextDoc 构造/析构

CtextDoc::CtextDoc()
{
	// TODO: 在此添加一次性构造代码
	BdCGray = 0;
	m_Bands = 0;
}

CtextDoc::~CtextDoc()
{
}

BOOL CtextDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CtextDoc 序列化

void CtextDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CtextDoc 诊断

#ifdef _DEBUG
void CtextDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CtextDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CtextDoc 命令
BOOL CtextDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	GDALDataset * DataSet; 
	GDALAllRegister();
	DataSet = (GDALDataset *)GDALOpen(lpszPathName,GA_Update);
	GDALRasterBand **pBand;
	m_Bands = DataSet->GetRasterCount();
	pBand = new GDALRasterBand *[m_Bands];
	for (int i = 0; i < m_Bands; i++)
	{
		pBand[i] = DataSet->GetRasterBand(i+1);
	}
	CDlgBands dlg;
	if (dlg.m_BandsType ==0)
	{
		BandsType = dlg.m_BandsType;
		BdCGray = dlg.BdChoiceGray;
		if (pBand[BdCGray] == NULL)
		{
			return 0;
		}
		nXsize = pBand[BdCGray]->GetXSize();
		nYsize = pBand[BdCGray]->GetYSize();
		opBandBlock_Gray = (BYTE *)CPLMalloc(sizeof(BYTE)*(nXsize*nYsize));
		pBand[BdCGray]->RasterIO(GF_Read,0,0,nXsize,nYsize,opBandBlock_Gray,
			nXsize,nYsize,pBand[BdCGray]->GetRasterDataType(),0,0);
	}
	UpdateAllViews(NULL);
	delete DataSet;
	return TRUE;
}