
// MFCApplication_LoadMenuDlg.h : ͷ�ļ�
//

#pragma once


// CMFCApplication_LoadMenuDlg �Ի���
class CMFCApplication_LoadMenuDlg : public CDialogEx
{
// ����
public:
	CMFCApplication_LoadMenuDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CMenu m_Menu;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION_LOADMENU_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
