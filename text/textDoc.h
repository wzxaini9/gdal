
// textDoc.h : CtextDoc ��Ľӿ�
//


#pragma once


class CtextDoc : public CDocument
{
protected: // �������л�����
	CtextDoc();
	DECLARE_DYNCREATE(CtextDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);

// ʵ��
public:
	int nYsize;
	int nXsize;
	int BdCGray;
	int BandsType;
	int m_Bands;

	BYTE *opBandBlock_Gray;
	BYTE *opBandBlock_R;
	BYTE *opBandBlock_G;
	BYTE *opBandBlock_B;

	virtual ~CtextDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


