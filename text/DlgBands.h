#pragma once
#include "afxwin.h"

class CDlgBands :
	public CDialog
{
public:
	int BdChoiceGray;
	int BdChoiceR;
	int BdChoiceG;
	int BdChoiceB;
	
	int m_BandsType;

	CButton m_RdGray;

	CStatic m_StaticGray;
	CStatic m_StaticR;
	CStatic	m_StaticG;
	CStatic m_StaticB;

	CComboBox m_mCmboGray;
	CComboBox m_mCmboRed;
	CComboBox m_mCmboGreen;
	CComboBox m_mCmboBlue;

	int m_mBands;

	CDlgBands();
	
protected:
	afx_msg void OnRadioGray();
	afx_msg void OnRadioRgb();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelChageCombo_R();
	afx_msg void OnSelChageCombo_G();
	afx_msg void OnSelChageCombo_B();
	afx_msg void OnSelChageCombo_Gray();

};
