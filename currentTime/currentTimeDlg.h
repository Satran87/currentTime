
// currentTimeDlg.h : файл заголовка
//

#pragma once


// диалоговое окно CcurrentTimeDlg
class CcurrentTimeDlg : public CDialogEx
{
// Создание
public:
	CcurrentTimeDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CURRENTTIME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	void SetFont()
	{
		HFONT hFont = CreateFont(56, 20, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
			DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS, PROOF_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE, L"Times New Roman");
		CFont *pFont = CFont::FromHandle(hFont);
		GetDlgItem(IDC_STATIC_My)->SetFont(pFont);
		GetDlgItem(IDC_STATIC_My2)->SetFont(pFont);
	}

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	afx_msg void OnClose();
	void StayTopMost();
	void StayLikeOther();
	afx_msg void OnBnClickedCheck1();

};
