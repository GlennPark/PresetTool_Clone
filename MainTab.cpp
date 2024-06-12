#include "pch.h"
#include "MainTab.h"
#include "PanoDlg.h"
#include "CephDlg.h"
#include "CTDlg.h"
#include "framework.h"
#include "afxdialogex.h"

#include "resource.h"

#include <string>
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

	RECT tabDialogRect, tabItemRect;

	//초기화 포함
	GetWindowRect(&tabDialogRect);
	GetItemRect(0, &tabItemRect);	


	const int tabItemHeight = 10;
	int tabItemLeft = tabItemRect.left;
	int tabItemBottom = tabItemRect.bottom;
	int tabDialogWidth = tabDialogRect.right - tabDialogRect.left;
	int tabDialogHeight = tabDialogRect.bottom - tabItemBottom;


	m_tabDialog[0]->SetWindowPos(&wndTop, tabItemLeft, (tabItemBottom + tabItemHeight) * dMaxTabDialog_Y, tabDialogWidth, tabDialogHeight, SWP_SHOWWINDOW);
	
	for (int nCount = 1; nCount < m_tabDialogNum; nCount++)
	{
		//nCount 출력
		AfxMessageBox(_T("nCount : "));

		m_tabDialog[nCount]->SetWindowPos(&wndTop, tabItemLeft, (tabItemBottom + tabItemHeight) * dMaxTabDialog_Y, tabDialogWidth, tabDialogHeight, SWP_HIDEWINDOW);
	}

}
