// UserCommSock2.cpp: 구현 파일
//

#include "pch.h"
#include "20220213MFC_CSocket_server.h"
#include "UserCommSock2.h"


// UserCommSock2

UserCommSock2::UserCommSock2()
{
}

UserCommSock2::~UserCommSock2()
{
}


// UserCommSock2 멤버 함수


void UserCommSock2::OnReceive(int nErrorCode)
{
	AfxGetMainWnd()->SetDlgItemText(IDC_STATIC_INF, L"New data is received !");

	int recvdData;
	Receive(&recvdData, sizeof(recvdData));

	AfxGetMainWnd()->SetDlgItemInt(IDC_EDIT_DISPLAY, recvdData);
	CSocket::OnReceive(nErrorCode);
}


void UserCommSock2::OnClose(int nErrorCode)
{
	ShutDown(2);
	Close();
	CSocket::OnClose(nErrorCode);
}
