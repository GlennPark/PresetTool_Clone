// CTDlg.cpp: 구현 파일
//

#include "pch.h"
#include "PresetTool.h"
#include "afxdialogex.h"
#include "CTDlg.h"


// CTDlg 대화 상자

IMPLEMENT_DYNAMIC(CTDlg, CDialogEx)

CTDlg::CTDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CT_DIALOG, pParent)
{

}

CTDlg::~CTDlg()
{
}

void CTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTDlg, CDialogEx)
END_MESSAGE_MAP()


// CTDlg 메시지 처리기
