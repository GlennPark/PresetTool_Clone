#pragma once
#include "afxdialogex.h"
#include "atlimage.h"


// PanoDlg 대화 상자

class PanoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PanoDlg)

public:
	PanoDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~PanoDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PANO_DIALOG };
#endif
	CImage m_image;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	void OnDrawImage();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedPanoRecentLoadButton();
	afx_msg void OnBnClickedPanoSampleLoadButton();
	afx_msg void OnPaint();



};
