
// currentTimeDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "currentTime.h"
#include "currentTimeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <string>


// ���������� ���� CcurrentTimeDlg

CDC m_pDC;
CcurrentTimeDlg::CcurrentTimeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CURRENTTIME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcurrentTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CcurrentTimeDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
ON_WM_TIMER()
ON_WM_CREATE()
ON_WM_CLOSE()
ON_BN_CLICKED(IDC_CHECK_TOP, &CcurrentTimeDlg::OnBnClickedCheck1)
ON_WM_ERASEBKGND()
ON_WM_DRAWITEM()
ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// ����������� ��������� CcurrentTimeDlg

BOOL CcurrentTimeDlg::OnInitDialog()
{
	CreateCompatibleDC(m_pDC);
	CDialogEx::OnInitDialog();

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	ShowWindow(SW_SHOWNORMAL);

	// TODO: �������� �������������� �������������
	SetFont();
	CheckDlgButton(IDC_CHECK_TOP, BST_CHECKED);
	StayTopMost();
	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.
void CcurrentTimeDlg::OnPaint()
{
	/////
	//CDC pDC;
	//CRect rect1;
	//GetClientRect(&rect1);
	//
	//CreateCompatibleDC(pDC);
	//auto bitmap=CreateCompatibleBitmap(pDC, rect1.Width(), rect1.Height());
	//auto pOldBmp = pDC.SelectObject(bitmap);
	//pDC.FillSolidRect(rect1, pDC.GetBkColor());
	//m_pDC.BitBlt(rect1.left, rect1.top, rect1.Width(), rect1.Height(), &pDC, rect1.left, rect1.top, SRCCOPY);
	//pDC.SelectObject(pOldBmp);
	/////
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������
		//

		//
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CcurrentTimeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





bool useSecond = false;
void CcurrentTimeDlg::OnTimer(UINT_PTR nIDEvent)
{
	SYSTEMTIME  curTime;
	::GetLocalTime(&curTime);
	CString StrMilli;
	StrMilli.Format(L"%03d", curTime.wMilliseconds);
	CString StrSec;
	StrSec.Format(L"%02d", curTime.wSecond);
	CString StrMin;
	StrMin.Format(L"%02d", curTime.wMinute);
	CString StrHours;
	StrHours.Format(L"%02d", curTime.wHour);
	CString separator (":");
	CString resultString(StrHours + separator + StrMin + separator + StrSec + separator + StrMilli);
	/////////////////////// ������� 2 ����������, ���������� � ���� ����� �������� � ������ ������
	if(useSecond)
	{
		useSecond = true;
	}
	SetDlgItemText(IDC_STATIC_My, resultString);
}


int CcurrentTimeDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;
	

	if (!SetTimer(1, 5, NULL))

	return 0;
}


void CcurrentTimeDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(1);
	CDialogEx::OnClose();
}
void CcurrentTimeDlg::StayTopMost()
{
	::SetWindowPos(this->m_hWnd,       // handle to window
		HWND_TOPMOST,  // placement-order handle
		0,     // horizontal position
		0,      // vertical position
		0,  // width
		0, // height
		SWP_NOMOVE | SWP_NOSIZE); // window-positioning options);
}
void CcurrentTimeDlg::StayLikeOther()
{
	::SetWindowPos(this->m_hWnd,       // handle to window
		HWND_NOTOPMOST,  // placement-order handle
		0,     // horizontal position
		0,      // vertical position
		0,  // width
		0, // height
		SWP_NOMOVE | SWP_NOSIZE); // window-positioning options);
}


void CcurrentTimeDlg::OnBnClickedCheck1()
{
	if(IsDlgButtonChecked(IDC_CHECK_TOP))
	{
		StayTopMost();
	}
	else
	{
		StayLikeOther();
	}
}



BOOL CcurrentTimeDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	return true;
	return CDialogEx::OnEraseBkgnd(pDC);
}
