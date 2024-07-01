#pragma once
#include "afxdialogex.h"
#include "atlimage.h"

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
	// Alpha, Beta 이미지
	CImage m_cephAlphaImage;
	CImage m_cephBetaImage;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	
	void sampleImageHandler(CString pathName);

	void OnDrawImage();

	DECLARE_MESSAGE_MAP()

	public:
		afx_msg void OnBnClickedCephSampleLoadButton();


		afx_msg void OnSize(UINT nType, int cx, int cy);
		afx_msg void OnPaint();
};
