#pragma once

// UserCommSock2 명령 대상

class UserCommSock2 : public CSocket
{
public:
	UserCommSock2();
	virtual ~UserCommSock2();
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
};


