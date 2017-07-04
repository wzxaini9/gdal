#include "StdAfx.h"
#include "DlgBands.h"
#include "text.h"

CDlgBands::CDlgBands()
{
	m_mBands = 0;
	m_BandsType = 0;
	BdChoiceGray = 0;
	BdChoiceR = 0;
	BdChoiceG = 1;
	BdChoiceB = 2;
}

void CDlgBands::OnRadioGray()
{
	m_BandsType = 0;

	m_mCmboGray.ShowWindow(SW_NORMAL);
	m_mCmboRed.ShowWindow(SW_HIDE);
	m_mCmboGreen.ShowWindow(SW_HIDE);
	m_mCmboBlue.ShowWindow(SW_HIDE);

	m_StaticGray.ShowWindow(SW_NORMAL);
	m_StaticR.ShowWindow(SW_HIDE);
	m_StaticG.ShowWindow(SW_HIDE);
	m_StaticB.ShowWindow(SW_HIDE);
}

void CDlgBands::OnRadioRgb()
{
	m_BandsType = 1;

	m_mCmboGray.ShowWindow(SW_HIDE);
	m_mCmboRed.ShowWindow(SW_NORMAL);
	m_mCmboGreen.ShowWindow(SW_NORMAL);
	m_mCmboBlue.ShowWindow(SW_NORMAL);

	m_StaticGray.ShowWindow(SW_HIDE);
	m_StaticR.ShowWindow(SW_NORMAL);
	m_StaticG.ShowWindow(SW_NORMAL);
	m_StaticB.ShowWindow(SW_NORMAL);
}

BOOL CDlgBands::OnInitDialog()
{
	CDialog::OnInitDialog();
	switch(m_BandsType)
	{
	case 0:
		m_RdGray.SetCheck(TRUE);
		m_mCmboGray.ShowWindow(SW_NORMAL);
		m_mCmboRed.ShowWindow(SW_HIDE);
		m_mCmboGreen.ShowWindow(SW_HIDE);
		m_mCmboBlue.ShowWindow(SW_HIDE);

		m_StaticGray.ShowWindow(SW_NORMAL);
		m_StaticR.ShowWindow(SW_HIDE);
		m_StaticG.ShowWindow(SW_HIDE);
		m_StaticB.ShowWindow(SW_HIDE);
		UpdateData(FALSE);
		break;
	case 1:
		m_mCmboGray.ShowWindow(SW_HIDE);
		m_mCmboRed.ShowWindow(SW_NORMAL);
		m_mCmboGreen.ShowWindow(SW_NORMAL);
		m_mCmboBlue.ShowWindow(SW_NORMAL);

		m_StaticGray.ShowWindow(SW_HIDE);
		m_StaticR.ShowWindow(SW_NORMAL);
		m_StaticG.ShowWindow(SW_NORMAL);
		m_StaticB.ShowWindow(SW_NORMAL);
		UpdateData(FALSE);
		break;
	}
	m_mCmboGray.Clear();
	m_mCmboRed.Clear();
	m_mCmboGreen.Clear();
	m_mCmboBlue.Clear();
	for (int i = 0;i < m_mBands;i++)
	{
		CString s;
		s.Format('%d',i+1);
		m_mCmboGray.AddString(s);
		m_mCmboRed.AddString(s);
		m_mCmboGreen.AddString(s);
		m_mCmboBlue.AddString(s);
	}
	m_mCmboGray.SetCurSel(0);
	m_mCmboRed.SetCurSel(0);
	m_mCmboGreen.SetCurSel(1);
	m_mCmboBlue.SetCurSel(2);
	BdChoiceGray = 0;
	BdChoiceR = 0;
	BdChoiceG = 0;
	BdChoiceB = 0;
	UpdateData(FALSE);
	return TRUE;
}

void CDlgBands::OnSelChageCombo_R()
{
	int indexR = m_mCmboRed.GetCurSel();
	const char * strChoiceR;
	m_mCmboRed.GetLBText(indexR,(LPTSTR)strChoiceR);
	BdChoiceR = atoi(strChoiceR) -1;
	UpdateData(TRUE);
}

void CDlgBands::OnSelChageCombo_G()
{
	int indexG = m_mCmboGreen.GetCurSel();
	const char * strChoiceG;
	m_mCmboGreen.GetLBText(indexG,(LPTSTR)strChoiceG);
	BdChoiceG = atoi(strChoiceG) -1;
	UpdateData(TRUE);
}

void CDlgBands::OnSelChageCombo_B()
{
	int indexB = m_mCmboBlue.GetCurSel();
	const char * strChoiceB;
	m_mCmboBlue.GetLBText(indexB,(LPTSTR)strChoiceB);
	BdChoiceB = atoi(strChoiceB) -1;
	UpdateData(TRUE);
}

void CDlgBands::OnSelChageCombo_Gray()
{
	int indexGray = m_mCmboGray.GetCurSel();
	const char * strChoiceGray;
	m_mCmboGray.GetLBText(indexGray,(LPTSTR)strChoiceGray);
	BdChoiceGray = atoi(strChoiceGray) -1;
	UpdateData(TRUE);
}