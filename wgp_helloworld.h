// wgp_helloworld.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cwgp_helloworldApp:
// See wgp_helloworld.cpp for the implementation of this class
//

class Cwgp_helloworldApp : public CWinApp
{
public:
	Cwgp_helloworldApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cwgp_helloworldApp theApp;