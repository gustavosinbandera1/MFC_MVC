
// Seasons.h : main header file for the Seasons application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSeasonsApp:
// See Seasons.cpp for the implementation of this class
//

class CSeasonsApp : public CWinApp
{
public:
	CSeasonsApp() noexcept;

private:
	CMultiDocTemplate* pDocTemplate;
// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSeasonsApp theApp;
