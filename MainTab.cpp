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
	m_tabDialog[0]->Create(IDD_PANO_DIALOG, this);

	m_tabDialog[0]->MoveWindow(0, 20, 800, 600);
	m_tabDialog[0]->ShowWindow(SW_SHOW);

}
