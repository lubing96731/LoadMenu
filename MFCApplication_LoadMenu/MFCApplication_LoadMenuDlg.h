
// MFCApplication_LoadMenuDlg.h : 头文件
//

#pragma once


// CMFCApplication_LoadMenuDlg 对话框
class CMFCApplication_LoadMenuDlg : public CDialogEx
{
// 构造
public:
	CMFCApplication_LoadMenuDlg(CWnd* pParent = NULL);	// 标准构造函数
	CMenu m_Menu;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION_LOADMENU_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonChange();
	afx_msg void OnBnClickedButton1();

	afx_msg void fun_Properties();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
