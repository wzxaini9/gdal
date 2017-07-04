
// textDoc.cpp : CtextDoc ���ʵ��
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


// CtextDoc ����/����

CtextDoc::CtextDoc()
{
	// TODO: �ڴ����һ���Թ������
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

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CtextDoc ���л�

void CtextDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CtextDoc ���

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


// CtextDoc ����
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