#pragma once


// CCarMsgChange �Ի���

class CCarMsgChange : public CDialogEx
{
	DECLARE_DYNAMIC(CCarMsgChange)

public:
	CCarMsgChange(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCarMsgChange();

// �Ի�������
	enum { IDD = IDD_DLG_MSG_CHANGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	CString m_strCarNum;
	CString m_strContact;
	CString m_strContactWay;
	CString m_strServeList;
	CString m_strOther;
	CString m_strCost;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeEditCost();
};
