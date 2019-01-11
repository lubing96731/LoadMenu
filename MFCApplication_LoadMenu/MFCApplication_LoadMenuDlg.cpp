
// MFCApplication_LoadMenuDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication_LoadMenu.h"
#include "MFCApplication_LoadMenuDlg.h"
#include "afxdialogex.h"

//#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication_LoadMenuDlg �Ի���



CMFCApplication_LoadMenuDlg::CMFCApplication_LoadMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION_LOADMENU_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication_LoadMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication_LoadMenuDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, &CMFCApplication_LoadMenuDlg::OnBnClickedButtonChange)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication_LoadMenuDlg::OnBnClickedButton1)

	ON_COMMAND(ID_PROPERTIES, &CMFCApplication_LoadMenuDlg::fun_Properties)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication_LoadMenuDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication_LoadMenuDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFCApplication_LoadMenuDlg ��Ϣ�������

BOOL CMFCApplication_LoadMenuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������	
	m_Menu.LoadMenu(IDR_MENU_NEW);
	SetMenu(&m_Menu);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCApplication_LoadMenuDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication_LoadMenuDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication_LoadMenuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication_LoadMenuDlg::OnBnClickedButtonChange()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMenu* MainMenu = AfxGetMainWnd()->GetMenu();
	MainMenu->ModifyMenu(0, MF_BYPOSITION, ID_FILE, _T("�ı�"));
}


void CMFCApplication_LoadMenuDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMenu* MainMenu = AfxGetMainWnd()->GetMenu();
	MainMenu->AppendMenu(MF_POPUP, ID_PROPERTIES, _T("����"));
	DrawMenuBar();
}

void CMFCApplication_LoadMenuDlg::fun_Properties()
{
	AfxMessageBox(_T("������Բ˵��ɹ���"));
}

void CMFCApplication_LoadMenuDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMenu* MainMenu = AfxGetMainWnd()->GetMenu();
	MainMenu->InsertMenu(1,MF_BYPOSITION|MF_STRING, ID_INSERT, _T("����"));
	DrawMenuBar();
}


void CMFCApplication_LoadMenuDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMenu* p_MainMenu = AfxGetMainWnd()->GetMenu();
	p_MainMenu = p_MainMenu->GetSubMenu(4);
	p_MainMenu->AppendMenu(MF_STRING, ID_SUBMENU1, _T("�Ӳ˵�1"));
	p_MainMenu->AppendMenu(MF_STRING, ID_SUBMENU2, _T("�Ӳ˵�2"));
	p_MainMenu->RemoveMenu(0, MF_BYPOSITION);
}
