
// MFCApplication_LoadMenu.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCApplication_LoadMenuApp: 
// �йش����ʵ�֣������ MFCApplication_LoadMenu.cpp
//

class CMFCApplication_LoadMenuApp : public CWinApp
{
public:
	CMFCApplication_LoadMenuApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication_LoadMenuApp theApp;