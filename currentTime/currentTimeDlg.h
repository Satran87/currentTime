
// currentTimeDlg.h : ���� ���������
//

#pragma once


// ���������� ���� CcurrentTimeDlg
class CcurrentTimeDlg : public CDialogEx
{
// ��������
public:
	CcurrentTimeDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CURRENTTIME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
//	afx_msg void OnEnable(BOOL bEnable);
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	void SetFont()
	{
		HFONT hFont = CreateFont(36, 10, 0, 0, FW_NORMAL, TRUE, FALSE, FALSE,
			DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS, PROOF_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE, L"Times New Roman");
		CFont *pFont = CFont::FromHandle(hFont);
		GetDlgItem(IDC_STATIC_My)->SetFont(pFont);
	}

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	afx_msg void OnClose();
	void StayTopMost();
	void StayLikeOther();
	afx_msg void OnBnClickedCheck1();
};
