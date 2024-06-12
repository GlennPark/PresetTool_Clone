#include "pch.h"
#include "MainTab.h"
#include "PanoDlg.h"
#include "CephDlg.h"
#include "CTDlg.h"
#include "framework.h"
#include "afxdialogex.h"

#include "resource.h"
IMPLEMENT_DYNAMIC(MainTab, CTabCtrl)

BEGIN_MESSAGE_MAP(MainTab, CTabCtrl)
	ON_WM_LBUTTONDOWN()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



MainTab::MainTab()
{
	
}

MainTab::~MainTab()
{

}

void MainTab::Init()
{
	this->InsertItem(0, _T("       Pano       "));
	this->InsertItem(1, _T("       Ceph       "));
	this->InsertItem(2, _T("        CT        "));

	m_tabDialog[0] = new PanoDlg;
	m_tabDialog[1] = new CephDlg;
	m_tabDialog[2] = new CTDlg;

	m_tabDialogNum = 3;

	//Dlg 처음 호출 시 탭 상태 설정
	m_tabDialog[0]->Create(IDD_PANO_DIALOG, this);
	m_tabDialog[1]->Create(IDD_CEPH_DIALOG, this);
	m_tabDialog[2]->Create(IDD_CT_DIALOG, this);
	
	m_tabDialog[0]->ShowWindow(SW_SHOW);
	m_tabDialog[1]->ShowWindow(SW_HIDE);
	m_tabDialog[2]->ShowWindow(SW_HIDE);

	SetTabDialogRect();

}

void MainTab::SetTabDialogRect()
{
	int tabDialog_X = (int)GetSystemMetrics(SM_CXSCREEN);
	int tabDialog_Y = (int)GetSystemMetrics(SM_CYSCREEN);

	double dMaxTabDialog_X = double(tabDialog_X) / double(2560);
	double dMaxTabDialog_Y = double(tabDialog_Y) / double(1440);

	RECT tabDialogRect;
	::GetWindowRect(m_hWnd, &tabDialogRect);
//	::MoveWindow(m_tabDialog[0], 0, 0, tabDialog_X, tabDialog_Y - 30 * dMaxTabDialog_Y, TRUE);

	m_tabDialog[0]->MoveWindow(0, 20, 2560, 1440);

	m_tabDialog[1]->MoveWindow(0, 20, 2560, 1440);

	m_tabDialog[2]->MoveWindow(0, 20, 2560, 1440);

	



	
}
