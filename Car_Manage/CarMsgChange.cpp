// CarMsgChange.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Car_Manage.h"
#include "CarMsgChange.h"
#include "afxdialogex.h"


// CCarMsgChange �Ի���

IMPLEMENT_DYNAMIC(CCarMsgChange, CDialogEx)

CCarMsgChange::CCarMsgChange(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCarMsgChange::IDD, pParent)
	, m_strCarNum(_T(""))
	, m_strContact(_T(""))
	, m_strContactWay(_T(""))
	, m_strServeList(_T(""))
	, m_strOther(_T(""))
	, m_strCost(_T(""))
{

}

CCarMsgChange::~CCarMsgChange()
{
}

void CCarMsgChange::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CAR_NUM, m_strCarNum);
	DDX_Text(pDX, IDC_EDIT_CONTACT, m_strContact);
	DDX_Text(pDX, IDC_EDIT_CONTACT_WAY, m_strContactWay);
	DDX_Text(pDX, IDC_EDIT_SERVE_LIST, m_strServeList);
	DDX_CBString(pDX, IDC_COMBO_OTHER, m_strOther);
	//  DDX_Text(pDX, IDC_EDIT_COST, m_strCost);
	//  DDX_Text(pDX, IDC_EDIT_COST, m_dCost);
	DDX_Text(pDX, IDC_EDIT_COST, m_strCost);
}


BEGIN_MESSAGE_MAP(CCarMsgChange, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_COST, &CCarMsgChange::OnEnChangeEditCost)
END_MESSAGE_MAP()


// CCarMsgChange ��Ϣ�������


BOOL CCarMsgChange::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	((CComboBox*)GetDlgItem(IDC_COMBO_OTHER))->AddString(_T("δ����"));    
	((CComboBox*)GetDlgItem(IDC_COMBO_OTHER))->AddString(_T("�Ѵ���")); 
	((CComboBox*)GetDlgItem(IDC_COMBO_OTHER))->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CCarMsgChange::OnEnChangeEditCost()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	for (int i=0; i<m_strCost.GetLength(); i++)
	{
		int nTemp = m_strCost.GetAt(i);

		if (i == 0)
		{
			if (nTemp<49 || nTemp>57)
			{
				AfxMessageBox(_T("�������ַ��쳣!"));
				m_strCost = _T("");
				UpdateData(FALSE);
				return;
			}
		}
		if ((nTemp<48 || nTemp>57) && nTemp!=46)
		{
			AfxMessageBox(_T("��������������!"));
			m_strCost = _T("");
			UpdateData(FALSE);
			return;
		}
	}

	if (m_strCost.ReverseFind(_T('.')) != -1 && m_strCost.GetLength() - m_strCost.ReverseFind(_T('.')) > 3)
	{
		m_strCost = m_strCost.Left(m_strCost.ReverseFind(_T('.'))+3);	
		UpdateData(FALSE);
		((CEdit*)GetDlgItem(IDC_EDIT_COST))->SetSel(-1);
		return;
	}
}
