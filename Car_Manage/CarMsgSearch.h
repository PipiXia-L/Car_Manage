#pragma once


// CCarMsgSearch �Ի���

class CCarMsgSearch : public CDialogEx
{
	DECLARE_DYNAMIC(CCarMsgSearch)

public:
	CCarMsgSearch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCarMsgSearch();

// �Ի�������
	enum { IDD = IDD_DLG_MSG_SEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString m_strSearchProperty;
	CString m_strSearchValue;
	afx_msg void OnBnClickedOk();
};
