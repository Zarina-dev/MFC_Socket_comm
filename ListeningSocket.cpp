// ListeningSocket.cpp: 구현 파일
//

#include "pch.h"
#include "20220213MFC_CSocket_server.h"
#include "ListeningSocket.h"


// ListeningSocket

ListeningSocket::ListeningSocket()
{
}

ListeningSocket::~ListeningSocket()
{
}


// ListeningSocket 멤버 함수


void ListeningSocket::OnAccept(int nErrorCode)
{
	// 어느 소켓이 그 클라이언트랑 통신할 지 결정함
	//Accept(m_userSock1);      // m_userSock1이 클라이언트랑 통신을 담당하게 됨
	
	Accept(m_userCommSock2);
	AfxGetMainWnd()->SetDlgItemText(IDC_STATIC_INF, L"client is accepted !");


	CSocket::OnAccept(nErrorCode);
}
