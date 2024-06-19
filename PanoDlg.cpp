// PanoDlg.cpp: 구현 파일
//

#include "pch.h"

#include "PanoDlg.h"

//2024.06.19 pch 적용을 위한 기타 헤더 비활성화
// #include "PresetTool.h"
 #include "afxdialogex.h" 

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
