
// MFC-InvisibleApplicationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC-InvisibleApplication.h"
#include "MFC-InvisibleApplicationDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCInvisibleApplicationDlg dialog

CMFCInvisibleApplicationDlg::CMFCInvisibleApplicationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCInvisibleApplication_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCInvisibleApplicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCInvisibleApplicationDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_WINDOWPOSCHANGING()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCInvisibleApplicationDlg message handlers

BOOL CMFCInvisibleApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

//=============================================================================//
// Set dialog Invisible to run in background by timer
//=============================================================================//
	m_visible = false;
//=============================================================================//
//=============================================================================//

	// Create timer to run in background
	doAnythingTime = 3 * 1000;
	doAnythingTimer = SetTimer(DO_ANYTHING_TIMER_ID, doAnythingTime, 0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCInvisibleApplicationDlg::OnPaint()
{
	CDialogEx::OnPaint();
}

void CMFCInvisibleApplicationDlg::OnWindowPosChanging(WINDOWPOS FAR* lpwndpos)
{
	if (!m_visible)
		lpwndpos->flags &= ~SWP_SHOWWINDOW;

	CDialog::OnWindowPosChanging(lpwndpos);
}

void CMFCInvisibleApplicationDlg::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
		case DO_ANYTHING_TIMER_ID:
			KillTimer(doAnythingTimer);
		

			// Do anything in background
			

			doAnythingTimer = SetTimer(DO_ANYTHING_TIMER_ID, doAnythingTime, 0);

			break;

		default:
			break;
	}

	CDialogEx::OnTimer(nIDEvent);
}
