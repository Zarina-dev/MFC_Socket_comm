
// 20220213MFC_CSocket_clientDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "20220213MFC_CSocket_client.h"
#include "20220213MFC_CSocket_clientDlg.h"
#include "afxdialogex.h"

#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20220213MFCCSocketclientDlg 대화 상자



CMy20220213MFCCSocketclientDlg::CMy20220213MFCCSocketclientDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY20220213MFC_CSOCKET_CLIENT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy20220213MFCCSocketclientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy20220213MFCCSocketclientDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BTN_SEND, &CMy20220213MFCCSocketclientDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMy20220213MFCCSocketclientDlg 메시지 처리기

BOOL CMy20220213MFCCSocketclientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.



	return TRUE; 
}


void CMy20220213MFCCSocketclientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}


HCURSOR CMy20220213MFCCSocketclientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy20220213MFCCSocketclientDlg::OnBnClickedButton1()
{
	//wchar_t inpValStr;
	//GetDlgItemText(IDC_EDIT_INP_VAL, inpValStr);


	int inpVal = GetDlgItemInt(IDC_EDIT_INP_VAL);
	SetDlgItemText(IDC_EDIT_INP_VAL, L"");
	
	//SetDlgItemText(IDC_EDIT_SET, L"Receiving data....");
	//SetDlgItemInt(IDC_EDIT_SET, inpVal);




	UINT PORT = 66666;
	CSocket clnSock;

	clnSock.Create();
	clnSock.Connect(L"172.30.1.4", PORT);    //  172.30.1.4 : 66666;

	clnSock.Send(&inpVal, sizeof(inpVal));


}
