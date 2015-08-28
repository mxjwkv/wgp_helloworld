// wgp_helloworldDlg.cpp : implementation file
//

#include "stdafx.h"

#define VER 1

#include "wgp_helloworld.h"
#include "wgp_helloworldDlg.h"

#include "../wlp_libfunc/libfunc.h"
#include "../wlp_libclass/libclass.h"

#ifdef _DEBUG
  #include "__build_num_debug.h"
  char gszBuildType[] = "Debug";
#else
  #include "__build_num_release.h"
  char gszBuildType[] = "Release";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cwgp_helloworldDlg dialog


Cwgp_helloworldDlg::Cwgp_helloworldDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cwgp_helloworldDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cwgp_helloworldDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cwgp_helloworldDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
    ON_BN_CLICKED(IDC_BUTTON1, &Cwgp_helloworldDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Cwgp_helloworldDlg message handlers

BOOL Cwgp_helloworldDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cwgp_helloworldDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cwgp_helloworldDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cwgp_helloworldDlg::OnBnClickedButton1()
{
    char szBuf128[128];
    x x1(100, 200); // create object x1

    sprintf_s(szBuf128, 128, "wgp_helloworld - Ver %d (%s) Build %d", VER, gszBuildType, BUILD_NUM);
    MessageBoxA(NULL, szBuf128, "Info", MB_OK);

    ///printf("libfunc - lib_test_incr_num(101) = %d\n", lib_test_incr_num(101));
    sprintf_s(szBuf128, 128, "libfunc - lib_test_incr_num(101) = %d", lib_test_incr_num(101));
    MessageBoxA(NULL, szBuf128, "Info", MB_OK);

    x1.setb(222);
    ///printf("libclass - x.display():\n");
    ///x1.display();
    sprintf_s(szBuf128, 128, "libclass - x1.geta()=%d  x1.getb()=%d", x1.geta(), x1.getb());
    MessageBoxA(NULL, szBuf128, "Info", MB_OK);
}
