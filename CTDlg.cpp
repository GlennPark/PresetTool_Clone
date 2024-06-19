// CTDlg.cpp: 구현 파일
//

#include "pch.h"
#include "CTDlg.h"

//2024.06.19 pch 적용을 위한 기타 헤더 비활성화
// #include "PresetTool.h"
// #include "afxdialogex.h"
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
