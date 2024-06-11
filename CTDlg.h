#pragma once
#include "afxdialogex.h"


// CTDlg 대화 상자

class CTDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTDlg)

public:
	CTDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CTDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
