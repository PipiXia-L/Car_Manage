// CarMsgSearch.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Car_Manage.h"
#include "CarMsgSearch.h"
#include "afxdialogex.h"


// CCarMsgSearch �Ի���

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


// CCarMsgSearch ��Ϣ�������


BOOL CCarMsgSearch::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	((CComboBox*)GetDlgItem(IDC_COMBO_SEARCH_PROPERTY))->AddString(_T("����"));    
	((CComboBox*)GetDlgItem(IDC_COMBO_SEARCH_PROPERTY))->AddString(_T("��ϵ��")); 
	((CComboBox*)GetDlgItem(IDC_COMBO_SEARCH_PROPERTY))->SetCurSel(0);  

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CCarMsgSearch::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_strSearchValue == _T(""))
	{
		AfxMessageBox(_T("������Ϣ����Ϊ��!"));
		return;
	}
	CDialogEx::OnOK();
}
