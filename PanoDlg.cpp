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
	ON_BN_CLICKED(IDC_PANO_RECENT_LOAD_BUTTON, &PanoDlg::OnBnClickedPanoRecentLoadButton)
	ON_BN_CLICKED(IDC_PANO_SAMPLE_LOAD_BUTTON, &PanoDlg::OnBnClickedPanoSampleLoadButton)
	ON_WM_PAINT()

END_MESSAGE_MAP()


// PanoDlg 메시지 처리기

void PanoDlg::OnPaint()
{

	if (m_image.IsNull() == false)
		OnDrawImage();
	
	CDialogEx::OnPaint();

}

void PanoDlg::OnDrawImage()
{
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	m_image.Draw(dc, rect);
}


void PanoDlg::OnBnClickedPanoRecentLoadButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void PanoDlg::OnBnClickedPanoSampleLoadButton()
{
	CFileDialog fileDlg(TRUE, _T("jpg"), nullptr, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T("JPEG Files (*.jpg)|*.jpg|All Files (*.*)|*.*||"));
	if (fileDlg.DoModal() == IDOK)
	{
		CString filePath = fileDlg.GetPathName();
		HRESULT hResult = m_image.Load(filePath);

		if (SUCCEEDED(hResult))
		{
			AfxMessageBox(_T("Image loaded successfully."));
			// Here you can use m_image for further processing or display
		}
		else
		{
			AfxMessageBox(_T("Failed to load image."));
		}
	}

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Invalidate();
}
