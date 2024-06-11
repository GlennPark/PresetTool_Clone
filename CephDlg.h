#pragma once
#include "afxdialogex.h"


// CephDlg 대화 상자

class CephDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CephDlg)

public:
	CephDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CephDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CEPH_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
