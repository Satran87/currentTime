
// currentTime.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CcurrentTimeApp:
// О реализации данного класса см. currentTime.cpp
//

class CcurrentTimeApp : public CWinApp
{
public:
	CcurrentTimeApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CcurrentTimeApp theApp;