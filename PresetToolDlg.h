
// PresetToolDlg.h: 헤더 파일
//

#pragma once

#include "CephDlg.h"
#include "PanoDlg.h"
#include "CTDlg.h"

#include "MainTab.h"
class CPresetToolDlgAutoProxy;


// CPresetToolDlg 대화 상자
class CPresetToolDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPresetToolDlg);
	friend class CPresetToolDlgAutoProxy;

// 생성입니다.
public:
	CPresetToolDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	virtual ~CPresetToolDlg();

	// 창 크기 설정
//	int mainWindow_X, mainWindow_Y = 0;
	// 창 최대 크기 설정
//	double dMax_X, dMax_Y = 0;

	// Tab Class 호출
	MainTab m_mainTab;
	
public:
	void setMainWindowRect();


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRESETTOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	CPresetToolDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
};
