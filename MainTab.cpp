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
	ON_WM_LBUTTONDOWN()
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

	//Dlg ó�� ȣ�� �� �� ���� ����
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

	//�ʱ�ȭ ����
	GetWindowRect(&tabDialogRect);
	GetItemRect(0, &tabItemRect);	


	const int tabItemHeight = 10;
	int tabItemLeft = tabItemRect.left;
	int tabItemBottom = tabItemRect.bottom;
	int tabDialogWidth = tabDialogRect.right - tabDialogRect.left;
	int tabDialogHeight = tabDialogRect.bottom - tabItemBottom;

	//���� ���⿡�� Dialog ũ�Ⱑ �پ�� �� �� ũ�⵵ �پ�鵵�� ���� �ʿ�
	m_tabDialog[0]->SetWindowPos(&wndTop, tabItemLeft, (tabItemBottom + tabItemHeight) * dMaxTabDialog_Y, tabDialogWidth, tabDialogHeight, SWP_SHOWWINDOW);
	

	for (int nCount = 1; nCount < m_tabDialogNum; nCount++)
	{
		//nCount ���
		AfxMessageBox(_T("nCount : "));

		m_tabDialog[nCount]->SetWindowPos(&wndTop, tabItemLeft, (tabItemBottom + tabItemHeight) * dMaxTabDialog_Y, tabDialogWidth, tabDialogHeight, SWP_HIDEWINDOW);
	}

}


void MainTab::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CTabCtrl::OnLButtonDown(nFlags, point);

	if (m_tabCurrentIndex != GetCurFocus())
	{
		m_tabDialog[m_tabCurrentIndex]->ShowWindow(SW_HIDE);
		m_tabCurrentIndex = GetCurFocus();
		m_tabDialog[m_tabCurrentIndex]->ShowWindow(SW_SHOW);
		m_tabDialog[m_tabCurrentIndex]->SetFocus();
	}
}
