// PanoDlg.cpp: 구현 파일
//

#include "pch.h"
#include "PresetTool.h"
#include "afxdialogex.h"
#include "PanoDlg.h"


// PanoDlg 대화 상자

IMPLEMENT_DYNAMIC(PanoDlg, CDialogEx)

PanoDlg::PanoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PANO_DIALOG, pParent)
{

}

PanoDlg::~PanoDlg()
{
}

void PanoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PanoDlg, CDialogEx)
END_MESSAGE_MAP()


// PanoDlg 메시지 처리기
