
// Car_Manage.h : Car_Manage 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CCar_ManageApp:
// 有关此类的实现，请参阅 Car_Manage.cpp
//

class CCar_ManageApp : public CWinApp
{
public:
	CCar_ManageApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

public:
	CString m_strActualUser;
	CString m_strLoginTime;
};

extern CCar_ManageApp theApp;
