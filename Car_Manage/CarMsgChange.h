#pragma once


// CCarMsgChange 对话框

class CCarMsgChange : public CDialogEx
{
	DECLARE_DYNAMIC(CCarMsgChange)

public:
	CCarMsgChange(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCarMsgChange();

// 对话框数据
	enum { IDD = IDD_DLG_MSG_CHANGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
