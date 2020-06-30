// CarMsgSearch.cpp : 实现文件
//

#include "stdafx.h"
#include "Car_Manage.h"
#include "CarMsgSearch.h"
#include "afxdialogex.h"


// CCarMsgSearch 对话框

IMPLEMENT_DYNAMIC(CCarMsgSearch, CDialogEx)

CCarMsgSearch::CCarMsgSearch(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCarMsgSearch::IDD, pParent)
	, m_strSearchProperty(_T(""))
	, m_strSearchValue(_T(""))
{

}

CCarMsgSearch::~CCarMsgSearch()
{
}

void CCarMsgSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO_SEARCH_PROPERTY, m_strSearchProperty);
	DDX_Text(pDX, IDC_EDIT_PROPERTY_VALUE, m_strSearchValue);
}


BEGIN_MESSAGE_MAP(CCarMsgSearch, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCarMsgSearch::OnBnClickedOk)
END_MESSAGE_MAP()


// CCarMsgSearch 消息处理程序


BOOL CCarMsgSearch::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	((CComboBox*)GetDlgItem(IDC_COMBO_SEARCH_PROPERTY))->AddString(_T("车牌"));    
	((CComboBox*)GetDlgItem(IDC_COMBO_SEARCH_PROPERTY))->AddString(_T("联系人")); 
	((CComboBox*)GetDlgItem(IDC_COMBO_SEARCH_PROPERTY))->SetCurSel(0);  

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CCarMsgSearch::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_strSearchValue == _T(""))
	{
		AfxMessageBox(_T("搜索信息不能为空!"));
		return;
	}
	CDialogEx::OnOK();
}
