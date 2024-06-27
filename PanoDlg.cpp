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
	ON_WM_SIZE()

END_MESSAGE_MAP()


// PanoDlg 메시지 처리기

void PanoDlg::OnPaint()
{

	if (m_image.IsNull() == false)
		OnDrawImage();
	
	CDialogEx::OnPaint();

}

void PanoDlg::resize()
{
}

///2020.07.20 : Sample Image data 불러옴
void PanoDlg::sampleData_Load_ImgView(CString path_name)
{
	if (m_image.IsNull() == false)
	{
		m_image.Destroy();
	}
	int m_nImageSize_Width = 2320, m_nImageSize_Height=1152;
	m_image.Create(m_nImageSize_Width, m_nImageSize_Height, 32);	// CImage m_image.Create(너비,높이,비트수,알파값유뮤)

	unsigned short* p_src_image = new unsigned short[m_nImageSize_Width * m_nImageSize_Height]; // pano 영상 unsigned short 16bit
	memset(p_src_image, 0, sizeof(short) * m_nImageSize_Width * m_nImageSize_Height);

	unsigned char* p_dest_image = new unsigned char[m_nImageSize_Width * m_nImageSize_Height * 4]; // 출력할때 32비트 이미지로 출력하기 위해서 8비트 이미지를 32비트 이미지로 바꾸기 위해서 width *  height*4 크기의 메모리를 할당한다. 
	memset(p_dest_image, 0, sizeof(char) * m_nImageSize_Width * m_nImageSize_Height * 4);
	// p_dest_image, p_src_image는 동적 할당된 메모리의 시작 주소를 기억하고 있어야지 
	// 작업이 끝난 후에 동적 할당된 메모리의 주소를 해제할 수 있다. 
	unsigned char* p_dest_pos = p_dest_image;
	unsigned short* p_src_pos = p_src_image;

	CFile file;
	if (file.Open(path_name, CFile::modeRead | CFile::shareExclusive) != NULL)
	{
		UINT uLength = UINT(file.GetLength());
		file.Read(p_src_image, uLength);
		for (int i = 0; i < m_nImageSize_Width * m_nImageSize_Height; i++)
		{
			*p_dest_pos++ = (char)((*p_src_pos) / 257); // Blue 
			*p_dest_pos++ = (char)((*p_src_pos) / 257); // -Green 
			*p_dest_pos++ = (char)((*p_src_pos++) / 257); // Red 
			*p_dest_pos++ = 0xFF; // Alpha 
		}
		file.Close();
		::SetBitmapBits(m_image, m_nImageSize_Width * m_nImageSize_Height * 4, p_dest_image);
		//m_image.Save(_T("test_re.bmp"), Gdiplus::ImageFormatBMP);  //디버깅용
	}
	delete[] p_dest_image;  // 이미지 변환에 사용한 메모리를 해제(8비트 이미지를 읽기 위해 사용한 메모리를 해제한다.)
	delete[] p_src_image;
}

void PanoDlg::OnDrawImage()
{

	// Picture Control DC를 생성.
	CClientDC dc(GetDlgItem(IDC_PANO_EXIST_STATIC));

	// Picture Control 크기를 얻는다.
	CRect rect;
	GetDlgItem(IDC_PANO_EXIST_STATIC)->GetClientRect(&rect);

	CDC memDC;
	CBitmap* pOldBitmap, bitmap;

	// Picture Control DC에 호환되는 새로운 CDC를 생성. (임시 버퍼)
	memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(m_image);	//TEST

	// Picture Control의 크기와 동일한 비트맵을 생성.
	//bitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	CStatic* staticSize = (CStatic*)GetDlgItem(IDC_PANO_EXIST_STATIC);//TEST
	staticSize->GetWindowRect(rect);//TEST
	ScreenToClient(&rect);//TEST

	

	// 임시 버퍼에서 방금 생성한 비트맵을 선택하면서, 이전 비트맵을 보존.
	pOldBitmap = memDC.SelectObject(&bitmap);
	int m_nImageSize_Width = 2320, m_nImageSize_Height = 1152;

	dc.SetStretchBltMode(COLORONCOLOR);//TEST
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, m_nImageSize_Width, m_nImageSize_Height, SRCCOPY);


	// 이전 비트맵으로 재설정.
	//memDC.SelectObject(pOldBitmap);
	memDC.SelectObject(memDC.SelectObject(m_image));	//TEST

	// 생성한 리소스 해제.
	memDC.DeleteDC();
	bitmap.DeleteObject();

}


void PanoDlg::OnBnClickedPanoRecentLoadButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void PanoDlg::OnBnClickedPanoSampleLoadButton()
{
	CFileDialog fileDlg(TRUE, _T("raw"), nullptr, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T("raw Files (*.raw)|*.raw|All Files (*.*)|*.*||"));
	if (fileDlg.DoModal() == IDOK)
	{
		CString filePath = fileDlg.GetPathName();
		sampleData_Load_ImgView(filePath);

	}

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Invalidate();
}

void PanoDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);


	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
