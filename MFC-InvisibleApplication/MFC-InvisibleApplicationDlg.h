
// MFC-InvisibleApplicationDlg.h : header file
//

#pragma once

#define DO_ANYTHING_TIMER_ID	WM_USER + 1000

// CMFCInvisibleApplicationDlg dialog
class CMFCInvisibleApplicationDlg : public CDialogEx
{
// Construction
public:
	CMFCInvisibleApplicationDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCInvisibleApplication_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

public:
	bool		m_visible;

	UINT_PTR	doAnythingTimer;
	UINT		doAnythingTime;

public:
	void OnWindowPosChanging(WINDOWPOS FAR* lpwndpos);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
