
// textDoc.h : CtextDoc 类的接口
//


#pragma once


class CtextDoc : public CDocument
{
protected: // 仅从序列化创建
	CtextDoc();
	DECLARE_DYNCREATE(CtextDoc)

// 属性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);

// 实现
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

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};


