// CarManageLogin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Car_Manage.h"
#include "CarManageLogin.h"
#include "afxdialogex.h"
#include "UseMySQLData.h"


// CCarManageLogin �Ի���

IMPLEMENT_DYNAMIC(CCarManageLogin, CDialogEx)

CCarManageLogin::CCarManageLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCarManageLogin::IDD, pParent)
	, m_strUserName(_T(""))
	, m_strPassword(_T(""))
{

}

CCarManageLogin::~CCarManageLogin()
{
}

void CCarManageLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_strUserName);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_strPassword);
	DDX_Control(pDX, IDC_PIT_LOGIN, m_PitLogin);
}


BEGIN_MESSAGE_MAP(CCarManageLogin, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCarManageLogin::OnBnClickedOk)
//	ON_WM_PAINT()
END_MESSAGE_MAP()


// CCarManageLogin ��Ϣ�������


BOOL CCarManageLogin::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ����ר�ô����/����û���
	cs.style &= ~WS_MAXIMIZEBOX; //��ֹ���
	cs.style &= ~WS_THICKFRAME; //��ֹ������С
	cs.style &= ~(LONG) FWS_ADDTOTITLE;

	return CDialogEx::PreCreateWindow(cs);
}


void CCarManageLogin::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CUseMySQLData useMySQL;
	useMySQL.ConnectMySQL();
	int nRet = useMySQL.CheckPassword(m_strUserName.GetString(), m_strPassword.GetString());
	if (nRet == 1)
	{
		AfxMessageBox(_T("�û�������!"));
		return;
	}
	else if (nRet == 2)
	{
		AfxMessageBox(_T("�������!"));
		return;
	}
	else
	{
		theApp.m_strActualUser = m_strUserName;
	}
	
	CDialogEx::OnOK();
}

void CCarManageLogin::InitBitMap()
{
	CBitmap bitmap;      //����ָ��λͼ��Դ BmpͼƬID      
	bitmap.LoadBitmap(IDB_BITMAP1);        //��ȡ�Ի����ϵľ�� ͼƬ�ؼ�ID        
//	p->ModifyStyle(0xf,SS_BITMAP|SS_CENTERIMAGE);       //��ͼƬ���õ�Picture�ؼ���      
	((CStatic *)GetDlgItem(IDC_PIT_LOGIN))->SetBitmap(bitmap);    	
	BITMAP bmpInfo;     
	bitmap.GetBitmap(&bmpInfo);     
	CDC dcMemory;     
	CDC* pDC=GetDlgItem(IDC_PIT_LOGIN)->GetDC();     
	dcMemory.CreateCompatibleDC(pDC);     
	CBitmap* pOldBitmap = dcMemory.SelectObject(&bitmap);     
	CRect rect;     
	GetClientRect(&rect);       
	pDC->SetStretchBltMode(COLORONCOLOR);     
	pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMemory,0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, SRCCOPY);     
	dcMemory.SelectObject(pOldBitmap);     
	ReleaseDC(pDC);
}

// void CCarManageLogin::OnPaint()
// {
// 	CPaintDC dc(this); // device context for painting
// 	// TODO: �ڴ˴������Ϣ����������
// 	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
// 	UpdateWindow();
// 	InitBitMap();
// }

BOOL CCarManageLogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��   
	::SetWindowPos(this->m_hWnd, HWND_BOTTOM, 0, 0, 660, 420, SWP_NOZORDER);

	CRect rect;     
	GetClientRect(&rect);
	m_PitLogin.SetWindowPos(this, 0, 0, rect.Width(), rect.Height(), SWP_NOZORDER);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
