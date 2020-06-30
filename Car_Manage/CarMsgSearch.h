#pragma once


// CCarMsgSearch 对话框

class CCarMsgSearch : public CDialogEx
{
	DECLARE_DYNAMIC(CCarMsgSearch)

public:
	CCarMsgSearch(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCarMsgSearch();

// 对话框数据
	enum { IDD = IDD_DLG_MSG_SEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString m_strSearchProperty;
	CString m_strSearchValue;
	afx_msg void OnBnClickedOk();
};
