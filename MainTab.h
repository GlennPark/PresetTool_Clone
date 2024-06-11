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

	int m_tabIndex;
	int m_tabDialogNum;

	int window_X, Window_Y;
	double max_X, max_Y;


public:
	void Init();


protected:
		DECLARE_MESSAGE_MAP()
private:

	
};

