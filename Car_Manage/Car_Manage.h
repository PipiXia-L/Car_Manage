
// Car_Manage.h : Car_Manage Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CCar_ManageApp:
// �йش����ʵ�֣������ Car_Manage.cpp
//

class CCar_ManageApp : public CWinApp
{
public:
	CCar_ManageApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

public:
	CString m_strActualUser;
	CString m_strLoginTime;
};

extern CCar_ManageApp theApp;
