#pragma once
#include "afxwin.h"


// CCarManageLogin �Ի���

class CCarManageLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CCarManageLogin)

public:
	CCarManageLogin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCarManageLogin();

// �Ի�������
	enum { IDD = IDD_DLG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
	CString m_strUserName;
	CString m_strPassword;
	afx_msg void OnBnClickedOk();

	CStatic m_PitLogin;
	void InitBitMap();
//	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
};
