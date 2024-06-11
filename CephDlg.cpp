// CephDlg.cpp: 구현 파일
//

#include "pch.h"
#include "PresetTool.h"
#include "afxdialogex.h"
#include "CephDlg.h"


// CephDlg 대화 상자

IMPLEMENT_DYNAMIC(CephDlg, CDialogEx)

CephDlg::CephDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CEPH_DIALOG, pParent)
{

}

CephDlg::~CephDlg()
{
}

void CephDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CephDlg, CDialogEx)
END_MESSAGE_MAP()


// CephDlg 메시지 처리기
