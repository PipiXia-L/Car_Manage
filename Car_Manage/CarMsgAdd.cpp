// CarMsgAdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Car_Manage.h"
#include "CarMsgAdd.h"
#include "afxdialogex.h"


// CCarMsgAdd �Ի���

IMPLEMENT_DYNAMIC(CCarMsgAdd, CDialogEx)

CCarMsgAdd::CCarMsgAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCarMsgAdd::IDD, pParent)
	, m_strCarNum(_T(""))
	, m_strContact(_T(""))
	, m_strContactWay(_T(""))
	, m_strServeList(_T(""))
	, m_strOther(_T(""))
	, m_strCost(_T(""))
{  
}

CCarMsgAdd::~CCarMsgAdd()
{
}

void CCarMsgAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CAR_NUM, m_strCarNum);
	DDX_Text(pDX, IDC_EDIT_CONTACT, m_strContact);
	DDX_Text(pDX, IDC_EDIT_CONTACT_WAY, m_strContactWay);
	DDX_Text(pDX, IDC_EDIT_SERVE_LIST, m_strServeList);
	DDX_CBString(pDX, IDC_COMBO_OTHER, m_strOther);
	//  DDX_Text(pDX, IDC_EDIT_COST, m_dCost);
	DDX_Text(pDX, IDC_EDIT_COST, m_strCost);
}


BEGIN_MESSAGE_MAP(CCarMsgAdd, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCarMsgAdd::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT_COST, &CCarMsgAdd::OnEnChangeEditCost)
END_MESSAGE_MAP()


// CCarMsgAdd ��Ϣ�������


void CCarMsgAdd::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������	
	UpdateData(TRUE);
	if (m_strCarNum == _T(""))
	{
		AfxMessageBox(_T("������Ϣ����Ϊ��!"));
		return;
	}

	CDialogEx::OnOK();
}


BOOL CCarMsgAdd::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	((CComboBox*)GetDlgItem(IDC_COMBO_OTHER))->AddString(_T("δ����"));    
	((CComboBox*)GetDlgItem(IDC_COMBO_OTHER))->AddString(_T("�Ѵ���")); 
	((CComboBox*)GetDlgItem(IDC_COMBO_OTHER))->SetCurSel(0);  

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}



void CCarMsgAdd::OnEnChangeEditCost()
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
