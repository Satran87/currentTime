
// currentTime.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CcurrentTimeApp:
// � ���������� ������� ������ ��. currentTime.cpp
//

class CcurrentTimeApp : public CWinApp
{
public:
	CcurrentTimeApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CcurrentTimeApp theApp;