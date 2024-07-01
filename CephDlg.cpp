// CephDlg.cpp: 구현 파일
//

#include "pch.h"
#include "CephDlg.h"

//2024.06.19 pch 적용을 위한 기타 헤더 비활성화
//#include "PresetTool.h"
#include "afxdialogex.h"


// CephDlg 대화 상자

IMPLEMENT_DYNAMIC(CephDlg, CDialogEx)

CephDlg::CephDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CEPH_DIALOG, pParent)
{

}

CephDlg::~CephDlg()
{
}

void CephDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CephDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CEPH_SAMPLE_LOAD_BUTTON, &CephDlg::OnBnClickedCephSampleLoadButton)

	ON_WM_PAINT()
	ON_WM_SIZE()
END_MESSAGE_MAP()

void CephDlg::OnPaint()
{

	//	CPaintDC dc(this); // device context for painting
		// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_cephAlphaImage.IsNull() || m_cephAlphaImage.IsNull() == false)
	{
		OnDrawImage();
	}
	CDialogEx::OnPaint();
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
}


void CephDlg::sampleImageHandler(CString pathName)
{
	if (m_cephAlphaImage.IsNull() || m_cephAlphaImage.IsNull() == false)
	{
		m_cephAlphaImage.Destroy();
		m_cephBetaImage.Destroy();
	}
	// 2024.07.01 Alpha, Beta 이미지 사이즈 임의설정

	int nAlphaImageSizeWidth = 3000, nAlphaImageSizeHeight = 2400;
	int nBetaImageSizeWidth = 3000, nBetaImageSizeHeight = 2400;

	m_cephAlphaImage.Create(nAlphaImageSizeWidth, nAlphaImageSizeHeight, 32);	// alpha 이미지 32비트로 생성
	m_cephBetaImage.Create(nBetaImageSizeWidth, nBetaImageSizeHeight, 32);	// beta 이미지 32비트로 생성

	unsigned short* pSrcAlphaImage = new unsigned short[nAlphaImageSizeWidth * nAlphaImageSizeHeight]; // pano 영상 unsigned short 16bit
	memset(pSrcAlphaImage, 0, sizeof(short) * nAlphaImageSizeWidth * nAlphaImageSizeHeight);
	unsigned char* pDestAlphaImage = new unsigned char[nAlphaImageSizeWidth * nAlphaImageSizeHeight * 4]; // 출력할때 32비트 이미지로 출력하기 위해서 8비트 이미지를 32비트 이미지로 바꾸기 위해서 width *  height*4 크기의 메모리를 할당한다. 
	memset(pDestAlphaImage, 0, sizeof(char) * nAlphaImageSizeWidth * nAlphaImageSizeHeight * 4);

	unsigned short* pSrcBetaImage = new unsigned short[nBetaImageSizeWidth * nBetaImageSizeHeight];
	memset(pSrcBetaImage, 0, sizeof(short) * nBetaImageSizeWidth * nBetaImageSizeHeight);
	unsigned char* pDestBetaImage = new unsigned char[nBetaImageSizeWidth * nBetaImageSizeHeight * 4];
	memset(pDestBetaImage, 0, sizeof(char) * nBetaImageSizeWidth * nBetaImageSizeHeight * 4);

	// pDestAlphaImage, pDestBetaImage, pSrcAlphaImage, pSrcBetaImage 는 동적 할당된 메모리의 시작 주소를 기억하고 있어야 작업이 끝난 후에 동적 할당된 메모리의 주소를 해제할 수 있다. 
	unsigned short* pSrcAlphaPos = pSrcAlphaImage;
	unsigned char* pDestAlphaPos = pDestAlphaImage;

	unsigned short* pSrcBetaPos = pSrcBetaImage;
	unsigned char* pDestBetaPos = pDestBetaImage;

	CFile fileAlpha, fileBeta;
	if (fileAlpha.Open(pathName, CFile::modeRead | CFile::shareExclusive) != NULL)
	{
		UINT uAlphaLength = UINT(fileAlpha.GetLength());
		fileAlpha.Read(pSrcAlphaImage, uAlphaLength);
		for (int i = 0; i < nAlphaImageSizeWidth * nAlphaImageSizeHeight; i++)
		{
			*pDestAlphaPos++ = (char)((*pSrcAlphaPos) / 256); // Blue 
			*pDestAlphaPos++ = (char)((*pSrcAlphaPos) / 256); // -Green 
			*pDestAlphaPos++ = (char)((*pSrcAlphaPos++) / 256); // Red 
			*pDestAlphaPos++ = 0xFF; // Alpha 
		}
		fileAlpha.Close();
		::SetBitmapBits(m_cephAlphaImage, nAlphaImageSizeWidth * nAlphaImageSizeHeight * 4, pDestAlphaImage);

		//m_panoAlphaImage.Load(_T("test_re.bmp"), Gdiplus::ImageFormatBMP);  //디버깅용
	}


	if (fileBeta.Open(pathName, CFile::modeRead | CFile::shareExclusive) != NULL)
	{
		UINT uBetaLength = UINT(fileBeta.GetLength());
		fileBeta.Read(pSrcBetaImage, uBetaLength);
		for (int i = 0; i < nBetaImageSizeWidth * nBetaImageSizeHeight; i++)
		{
			*pDestBetaPos++ = (char)((*pSrcBetaPos) / 256); // Blue 
			*pDestBetaPos++ = (char)((*pSrcBetaPos) / 256); // -Green 
			*pDestBetaPos++ = (char)((*pSrcBetaPos++) / 256); // Red 
			*pDestBetaPos++ = 0xFF; // Alpha
		}
		fileBeta.Close();
		::SetBitmapBits(m_cephBetaImage, nBetaImageSizeWidth * nBetaImageSizeHeight * 4, pDestAlphaImage);

		//m_panoBetaImage.Load(_T("test_re.bmp"), Gdiplus::ImageFormatBMP);  //디버깅용
	}

	delete[] pDestAlphaImage;  // 이미지 변환에 사용한 메모리를 해제(8비트 이미지를 읽기 위해 사용한 메모리를 해제한다.)
	delete[] pSrcAlphaImage;

	delete[] pDestBetaImage;
	delete[] pSrcBetaImage;

	Invalidate();
}

void CephDlg::OnDrawImage()
{
	// Picture Control DC를 생성.
	CClientDC dcAlpha(GetDlgItem(IDC_CEPH_ALPHA_STATIC));
	CClientDC dcBeta(GetDlgItem(IDC_CEPH_BETA_STATIC));

	// Picture Control 크기를 얻는다.
	CRect rectAlpha, rectBeta;

	GetDlgItem(IDC_CEPH_ALPHA_STATIC)->GetClientRect(&rectAlpha);
	GetDlgItem(IDC_CEPH_BETA_STATIC)->GetClientRect(&rectBeta);

	CDC memAlphaDC, memBetaDC;

	CBitmap* pOldAlphaBitmap, pNewAlphaBitmap, pOldBetaBitmap, pNewBetaBitmap;

	// Picture Control DC에 호환되는 새로운 CDC를 생성. (임시 버퍼)
	memAlphaDC.CreateCompatibleDC(&dcAlpha);
	memBetaDC.CreateCompatibleDC(&dcBeta);

	memAlphaDC.SelectObject(m_cephAlphaImage);
	memBetaDC.SelectObject(m_cephBetaImage);

	// Picture Control의 크기와 동일한 비트맵을 생성.
	CStatic* staticSizeAlpha = (CStatic*)GetDlgItem(IDC_CEPH_ALPHA_STATIC);
	CStatic* staticSizeBeta = (CStatic*)GetDlgItem(IDC_CEPH_BETA_STATIC);

	staticSizeAlpha->GetWindowRect(rectAlpha);
	staticSizeBeta->GetWindowRect(rectBeta);

	ScreenToClient(&rectAlpha);
	ScreenToClient(&rectBeta);

	// 임시 버퍼에서 방금 생성한 비트맵을 선택하면서, 이전 비트맵을 보존.
	pOldAlphaBitmap = memAlphaDC.SelectObject(&pNewAlphaBitmap);

	int nAlphaImageSizeWidth = 3000, nAlphaImageSizeHeight = 2400;
	int nBetaImageSizeWidth = 3000, nBetaImageSizeHeight = 2400;

	dcAlpha.SetStretchBltMode(COLORONCOLOR);
	dcAlpha.StretchBlt(0, 0, rectAlpha.Width(), rectAlpha.Height(), &memAlphaDC, 0, 0, nAlphaImageSizeWidth, nAlphaImageSizeHeight, SRCCOPY);

	dcBeta.SetStretchBltMode(COLORONCOLOR);
	dcBeta.StretchBlt(0, 0, rectBeta.Width(), rectBeta.Height(), &memBetaDC, 0, 0, nBetaImageSizeWidth, nBetaImageSizeHeight, SRCCOPY);


	// 이전 비트맵으로 재설정.
	memAlphaDC.SelectObject(memAlphaDC.SelectObject(m_cephAlphaImage));
	memBetaDC.SelectObject(memBetaDC.SelectObject(m_cephBetaImage));

	// 생성한 리소스 해제.
	memAlphaDC.DeleteDC();
	pNewAlphaBitmap.DeleteObject();

	memBetaDC.DeleteDC();
	pNewBetaBitmap.DeleteObject();
}




// CephDlg 메시지 처리기


void CephDlg::OnBnClickedCephSampleLoadButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog fileDlg(TRUE, _T("raw"), nullptr, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T("raw Files (*.raw)|*.raw|All Files (*.*)|*.*||"));
	if (fileDlg.DoModal() == IDOK)
	{
		CString filePath = fileDlg.GetPathName();
		sampleImageHandler(filePath);

	}

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Invalidate();
}


void CephDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


