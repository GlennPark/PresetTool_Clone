
// DlgProxy.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "PresetTool.h"
#include "DlgProxy.h"
#include "PresetToolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPresetToolDlgAutoProxy

IMPLEMENT_DYNCREATE(CPresetToolDlgAutoProxy, CCmdTarget)

CPresetToolDlgAutoProxy::CPresetToolDlgAutoProxy()
{
	EnableAutomation();

	// 자동화 개체가 활성화되어 있는 동안 계속 애플리케이션을 실행하기 위해
	//	생성자에서 AfxOleLockApp를 호출합니다.
	AfxOleLockApp();

	// 애플리케이션의 주 창 포인터를 통해 대화 상자에 대한
	//  액세스를 가져옵니다.  프록시의 내부 포인터를 설정하여
	//  대화 상자를 가리키고 대화 상자의 후방 포인터를 이 프록시로
	//  설정합니다.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CPresetToolDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CPresetToolDlg)))
		{
			m_pDialog = reinterpret_cast<CPresetToolDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CPresetToolDlgAutoProxy::~CPresetToolDlgAutoProxy()
{
	// 모든 개체가 OLE 자동화로 만들어졌을 때 애플리케이션을 종료하기 위해
	// 	소멸자가 AfxOleUnlockApp를 호출합니다.
	//  이러한 호출로 주 대화 상자가 삭제될 수 있습니다.
	if (m_pDialog != nullptr)
		m_pDialog->m_pAutoProxy = nullptr;
	AfxOleUnlockApp();
}

void CPresetToolDlgAutoProxy::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다.  기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하세요.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CPresetToolDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CPresetToolDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 참고: IID_IPresetTool에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다.
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {abf18b33-9e3b-4702-a52e-26a70f941057}
static const IID IID_IPresetTool =
{0xabf18b33,0x9e3b,0x4702,{0xa5,0x2e,0x26,0xa7,0x0f,0x94,0x10,0x57}};

BEGIN_INTERFACE_MAP(CPresetToolDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CPresetToolDlgAutoProxy, IID_IPresetTool, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 매크로가 이 프로젝트의 pch.h에 정의됩니다.
// {b3c46d07-8c48-4de7-a3d8-d7d67862f52f}
IMPLEMENT_OLECREATE2(CPresetToolDlgAutoProxy, "PresetTool.Application", 0xb3c46d07,0x8c48,0x4de7,0xa3,0xd8,0xd7,0xd6,0x78,0x62,0xf5,0x2f)


// CPresetToolDlgAutoProxy 메시지 처리기
