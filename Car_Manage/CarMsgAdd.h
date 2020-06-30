#pragma once


// CCarMsgAdd 对话框

class CCarMsgAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CCarMsgAdd)

public:
	CCarMsgAdd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCarMsgAdd();

// 对话框数据
	enum { IDD = IDD_DLG_MSG_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();

	CString m_strCarNum;
	CString m_strContact;
	CString m_strContactWay;
	CString m_strServeList;
	CString m_strOther;
	CString m_strCost;
	afx_msg void OnEnChangeEditCost();	
};
