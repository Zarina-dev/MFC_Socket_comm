
// 20220213MFC_CSocket_server.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "20220213MFC_CSocket_server.h"
#include "20220213MFC_CSocket_serverDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20220213MFCCSocketserverApp

BEGIN_MESSAGE_MAP(CMy20220213MFCCSocketserverApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMy20220213MFCCSocketserverApp 생성

CMy20220213MFCCSocketserverApp::CMy20220213MFCCSocketserverApp()
{
}




CMy20220213MFCCSocketserverApp theApp;

BOOL CMy20220213MFCCSocketserverApp::InitInstance()  // CMy20220213MFCCSocketserverApp 초기화
{
	CWinApp::InitInstance();

	if (!AfxSocketInit())              //  wsaStartup()
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}


	CMy20220213MFCCSocketserverDlg dlg;
	m_pMainWnd = &dlg;                   // 다른 파일에서 dlg창과 연결할 수 있도록 
	dlg.DoModal();
	
	return FALSE;
}

