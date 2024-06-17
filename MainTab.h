#pragma once
#include <afxcmn.h>
#include "afxdialogex.h"


class MainTab : public CTabCtrl
{
	DECLARE_DYNAMIC(MainTab)

public:
	MainTab();
	virtual ~MainTab();

	CDialog *m_tabDialog[3];

	//°¢ Tab Index
	int m_tabCurrentIndex;

	//Tab Dialog ÃÑ °³¼ö
	int m_tabDialogNum;

	int window_X, Window_Y;
	double max_X, max_Y;


public:
	void Init();
	void SetTabDialogRect();

protected:
		DECLARE_MESSAGE_MAP()
private:

	
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

