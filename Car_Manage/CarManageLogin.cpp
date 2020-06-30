// CarManageLogin.cpp : 实现文件
//

#include "stdafx.h"
#include "Car_Manage.h"
#include "CarManageLogin.h"
#include "afxdialogex.h"
#include "UseMySQLData.h"


// CCarManageLogin 对话框

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


// CCarManageLogin 消息处理程序


BOOL CCarManageLogin::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此添加专用代码和/或调用基类
	cs.style &= ~WS_MAXIMIZEBOX; //禁止最大化
	cs.style &= ~WS_THICKFRAME; //禁止调整大小
	cs.style &= ~(LONG) FWS_ADDTOTITLE;

	return CDialogEx::PreCreateWindow(cs);
}


void CCarManageLogin::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CUseMySQLData useMySQL;
	useMySQL.ConnectMySQL();
	int nRet = useMySQL.CheckPassword(m_strUserName.GetString(), m_strPassword.GetString());
	if (nRet == 1)
	{
		AfxMessageBox(_T("用户不存在!"));
		return;
	}
	else if (nRet == 2)
	{
		AfxMessageBox(_T("密码错误!"));
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
	CBitmap bitmap;      //加载指定位图资源 Bmp图片ID      
	bitmap.LoadBitmap(IDB_BITMAP1);        //获取对话框上的句柄 图片控件ID        
//	p->ModifyStyle(0xf,SS_BITMAP|SS_CENTERIMAGE);       //将图片设置到Picture控件上      
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
// 	// TODO: 在此处添加消息处理程序代码
// 	// 不为绘图消息调用 CDialogEx::OnPaint()
// 	UpdateWindow();
// 	InitBitMap();
// }

BOOL CCarManageLogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化   
	::SetWindowPos(this->m_hWnd, HWND_BOTTOM, 0, 0, 660, 420, SWP_NOZORDER);

	CRect rect;     
	GetClientRect(&rect);
	m_PitLogin.SetWindowPos(this, 0, 0, rect.Width(), rect.Height(), SWP_NOZORDER);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
