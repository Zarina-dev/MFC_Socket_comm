
// 20220213MFC_CSocket_serverDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "20220213MFC_CSocket_server.h"
#include "20220213MFC_CSocket_serverDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20220213MFCCSocketserverDlg 대화 상자



CMy20220213MFCCSocketserverDlg::CMy20220213MFCCSocketserverDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY20220213MFC_CSOCKET_SERVER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}



void CMy20220213MFCCSocketserverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy20220213MFCCSocketserverDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()



BOOL CMy20220213MFCCSocketserverDlg::OnInitDialog()   // 메시지 처리기
{
	CDialogEx::OnInitDialog();

	
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.





	UINT PORT = 66666;
	m_lsningSock.Create(PORT);
	m_lsningSock.Listen();

	

	SetDlgItemText(IDC_STATIC_INF, L"server is listening..");
	






	return TRUE; 
}

void CMy20220213MFCCSocketserverDlg::OnPaint()
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


HCURSOR CMy20220213MFCCSocketserverDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

