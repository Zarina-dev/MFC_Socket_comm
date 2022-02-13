#pragma once

#include "UserCommSock1.h"
#include "UserCommSock2.h"
// ListeningSocket 명령 대상

class ListeningSocket : public CSocket
{
public:
	ListeningSocket();
	virtual ~ListeningSocket();
	virtual void OnAccept(int nErrorCode);
public:
	UserCommSock1 m_userSock1;
	UserCommSock2 m_userCommSock2;
};


