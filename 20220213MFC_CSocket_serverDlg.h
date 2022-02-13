
// 20220213MFC_CSocket_serverDlg.h: 헤더 파일
//

#pragma once
#include "ListeningSocket.h"

// CMy20220213MFCCSocketserverDlg 대화 상자
class CMy20220213MFCCSocketserverDlg : public CDialogEx
{
// 생성입니다.
public:
	CMy20220213MFCCSocketserverDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20220213MFC_CSOCKET_SERVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	ListeningSocket m_lsningSock;
};
