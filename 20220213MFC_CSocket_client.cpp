
// 20220213MFC_CSocket_client.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "20220213MFC_CSocket_client.h"
#include "20220213MFC_CSocket_clientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




BEGIN_MESSAGE_MAP(CMy20220213MFCCSocketclientApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()




CMy20220213MFCCSocketclientApp::CMy20220213MFCCSocketclientApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}




CMy20220213MFCCSocketclientApp theApp;  // 유일한 CMy20220213MFCCSocketclientApp 개체



BOOL CMy20220213MFCCSocketclientApp::InitInstance()   // 초기화
{
	CWinApp::InitInstance();

	if (!AfxSocketInit())      // wsa initializing(wsastartup) 
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}


	CMy20220213MFCCSocketclientDlg dlg;
	m_pMainWnd = &dlg;          
	dlg.DoModal();
	
	return FALSE;
}

