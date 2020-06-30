
// Car_ManageView.cpp : CCar_ManageView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Car_Manage.h"
#endif

#include "Car_ManageDoc.h"
#include "Car_ManageView.h"
#include "CarMsgSearch.h"
#include "CarMsgChange.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCar_ManageView

IMPLEMENT_DYNCREATE(CCar_ManageView, CFormView)

BEGIN_MESSAGE_MAP(CCar_ManageView, CFormView)
	ON_COMMAND(ID_MENU_MSG_ADD, &CCar_ManageView::OnMenuMsgAdd)
	ON_COMMAND(ID_MENU_MSG_SEARCH, &CCar_ManageView::OnMenuMsgSearch)
	ON_COMMAND(ID_MENU_MSG_CHANGE, &CCar_ManageView::OnMenuMsgChange)
	ON_COMMAND(ID_MENU_MSG_DELETE, &CCar_ManageView::OnMenuMsgDelete)
	ON_COMMAND(ID_MENU_DISPLAY_ALL, &CCar_ManageView::OnMenuDisplayAll)
	ON_COMMAND(ID_RIGHT_MENU_MSG_ADD, &CCar_ManageView::OnMenuMsgAdd)
	ON_COMMAND(ID_RIGHT_MENU_MSG_SEARCH, &CCar_ManageView::OnMenuMsgSearch)
	ON_COMMAND(ID_RIGHT_MENU_MSG_CHANGE, &CCar_ManageView::OnMenuMsgChange)
	ON_COMMAND(ID_RIGHT_MENU_MSG_DELETE, &CCar_ManageView::OnMenuMsgDelete)
	ON_COMMAND(ID_RIGHT_MENU_DISPLAY_ALL, &CCar_ManageView::OnMenuDisplayAll)
	ON_WM_CONTEXTMENU()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CCar_ManageView ����/����

CCar_ManageView::CCar_ManageView()
	: CFormView(CCar_ManageView::IDD)
{
	// TODO: �ڴ˴���ӹ������
	m_UseMySQL = new CUseMySQLData;
	m_nCarIdMax = 0;
}

CCar_ManageView::~CCar_ManageView()
{
	delete m_UseMySQL;
	m_UseMySQL = NULL;
}

void CCar_ManageView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CAR_MSG, m_CtlCarMsg);
}

BOOL CCar_ManageView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CCar_ManageView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	CRect Rect;
	GetClientRect(&Rect);
	m_CtlCarMsg.InsertColumn(0, _T("���"), LVCFMT_CENTER, Rect.Width()*0, 0);  //����
	m_CtlCarMsg.InsertColumn(1, _T("����"), LVCFMT_CENTER, Rect.Width()*12/100, 1);   
	m_CtlCarMsg.InsertColumn(2, _T("��ϵ��"), LVCFMT_CENTER, Rect.Width()*10/100, 2); 
	m_CtlCarMsg.InsertColumn(3, _T("�ֻ�/�绰"), LVCFMT_CENTER, Rect.Width()*16/100, 3); 
	m_CtlCarMsg.InsertColumn(4, _T("������Ŀ"), LVCFMT_CENTER, Rect.Width()*22/100, 4);  
	m_CtlCarMsg.InsertColumn(5, _T("��ע"), LVCFMT_CENTER, Rect.Width()*12/100, 5); 
	m_CtlCarMsg.InsertColumn(6, _T("����"), LVCFMT_CENTER, Rect.Width()*10/100, 6); 
	m_CtlCarMsg.InsertColumn(7, _T("����ʱ��"), LVCFMT_CENTER, Rect.Width()*18/100, 7); 
	m_CtlCarMsg.ShowScrollBar(SB_BOTH,FALSE);

	m_CtlCarMsg.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP);
	UpdateMsgCtrlList();

	theApp.m_strActualUser;
}

// CCar_ManageView ���

#ifdef _DEBUG
void CCar_ManageView::AssertValid() const
{
	CFormView::AssertValid();
}

void CCar_ManageView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CCar_ManageDoc* CCar_ManageView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCar_ManageDoc)));
	return (CCar_ManageDoc*)m_pDocument;
}
#endif //_DEBUG

BOOL CCar_ManageView::UpdateMsgCtrlList()
{
	
	if (!m_UseMySQL->bConnectFlag && !m_UseMySQL->ConnectMySQL())
	{
		AfxMessageBox(_T("�������ݿ�ʧ�ܣ�"));
		return FALSE;
	}
	else
	{
		m_UseMySQL->GetServeFormData(m_vServer_Form);
	}
	
	m_CtlCarMsg.DeleteAllItems();

	for (unsigned int i=0; i<m_vServer_Form.size(); i++)
	{
		if (m_vServer_Form[i].nCarId  >= m_nCarIdMax)
		{
			m_nCarIdMax = m_vServer_Form[i].nCarId+1;
		}
		CString strIDTemp;
		strIDTemp.Format(_T("%d"), m_vServer_Form[i].nCarId);
		m_CtlCarMsg.InsertItem(i, (LPCTSTR)strIDTemp);
		m_CtlCarMsg.SetItemText(i, 1, (LPCTSTR)m_vServer_Form[i].strCar_Num.c_str());
		m_CtlCarMsg.SetItemText(i, 2, (LPCTSTR)m_vServer_Form[i].strContact.c_str());
		m_CtlCarMsg.SetItemText(i, 3, (LPCTSTR)m_vServer_Form[i].strContact_Way.c_str());
		m_CtlCarMsg.SetItemText(i, 4, (LPCTSTR)m_vServer_Form[i].strServe_List.c_str());
		m_CtlCarMsg.SetItemText(i, 5, (LPCTSTR)m_vServer_Form[i].strOther.c_str());

		CString strCostTemp;
		strCostTemp.Format(_T("%.2f"), m_vServer_Form[i].dCost);
		m_CtlCarMsg.SetItemText(i, 6, (LPCTSTR)strCostTemp);
		m_CtlCarMsg.SetItemText(i, 7, (LPCTSTR)m_vServer_Form[i].strTime.c_str());
	}
	UpdateData(FALSE);
	m_vServer_Form.clear();

	return TRUE;
}

BOOL CCar_ManageView::DisplaySearchMsg(vector<server_form> vSearch_Server_Form)
{
	m_CtlCarMsg.DeleteAllItems();
	for (unsigned int i=0; i<vSearch_Server_Form.size(); i++)
	{
		if (vSearch_Server_Form[i].nCarId  >= m_nCarIdMax)
		{
			m_nCarIdMax = vSearch_Server_Form[i].nCarId+1;
		}
		CString strIDTemp;
		strIDTemp.Format(_T("%d"), vSearch_Server_Form[i].nCarId);
		m_CtlCarMsg.InsertItem(i, (LPCTSTR)strIDTemp);
		m_CtlCarMsg.SetItemText(i, 1, (LPCTSTR)vSearch_Server_Form[i].strCar_Num.c_str());
		m_CtlCarMsg.SetItemText(i, 2, (LPCTSTR)vSearch_Server_Form[i].strContact.c_str());
		m_CtlCarMsg.SetItemText(i, 3, (LPCTSTR)vSearch_Server_Form[i].strContact_Way.c_str());
		m_CtlCarMsg.SetItemText(i, 4, (LPCTSTR)vSearch_Server_Form[i].strServe_List.c_str());
		m_CtlCarMsg.SetItemText(i, 5, (LPCTSTR)vSearch_Server_Form[i].strOther.c_str());

		CString strCostTemp;
		strCostTemp.Format(_T("%.2f"), vSearch_Server_Form[i].dCost);
		m_CtlCarMsg.SetItemText(i, 6, (LPCTSTR)strCostTemp);
		m_CtlCarMsg.SetItemText(i, 7, (LPCTSTR)vSearch_Server_Form[i].strTime.c_str());
	}
	UpdateData(FALSE);
	return TRUE;
}
// CCar_ManageView ��Ϣ�������

void CCar_ManageView::OnMenuMsgAdd()
{
	// TODO: �ڴ���������������
	CCarMsgAdd msgAdd;
	
	if (msgAdd.DoModal() == IDOK)
	{
		vector<server_form> vServer_form_Add_Msg;
		server_form server_form_Add_Msg;
		server_form_Add_Msg.nCarId = m_nCarIdMax;
		server_form_Add_Msg.strCar_Num = msgAdd.m_strCarNum;
		server_form_Add_Msg.strContact = msgAdd.m_strContact;
		server_form_Add_Msg.strContact_Way = msgAdd.m_strContactWay;
		server_form_Add_Msg.strServe_List = msgAdd.m_strServeList;
		server_form_Add_Msg.strOther = msgAdd.m_strOther;
		server_form_Add_Msg.dCost = atof(msgAdd.m_strCost);

		SYSTEMTIME st;
		CString strTime;
		GetLocalTime(&st);
		strTime.Format(_T("%d-%d-%d %d:%d:%d"), st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
		server_form_Add_Msg.strTime = strTime;
		vServer_form_Add_Msg.push_back(server_form_Add_Msg);

		m_UseMySQL->InsertServeDataToMySQL(vServer_form_Add_Msg);
		UpdateMsgCtrlList();
	}
}

void CCar_ManageView::OnMenuMsgSearch()
{
	// TODO: �ڴ���������������
	CCarMsgSearch msgSearch;
	if (msgSearch.DoModal() == IDOK)
	{
		vector<server_form> vSearch_Server_Form;
		if (msgSearch.m_strSearchProperty == _T("����"))
		{
			m_UseMySQL->SearchServeDataFromMySQL(_T("car_num"), msgSearch.m_strSearchValue.GetString(), vSearch_Server_Form);
		}
		else if(msgSearch.m_strSearchProperty == _T("��ϵ��"))
		{
			m_UseMySQL->SearchServeDataFromMySQL(_T("contact"), msgSearch.m_strSearchValue.GetString(), vSearch_Server_Form);
		}
		else
		{

		}
		DisplaySearchMsg(vSearch_Server_Form);
	}
}

void CCar_ManageView::OnMenuMsgChange()
{
	// TODO: �ڴ���������������
	int nItem = m_CtlCarMsg.GetSelectionMark();

	if (nItem == -1)
	{
		AfxMessageBox(_T("δѡ���κ�����!"));
		return;
	}

	CCarMsgChange msgChange;
	msgChange.m_strCarNum = m_CtlCarMsg.GetItemText(nItem, 1);
	msgChange.m_strContact = m_CtlCarMsg.GetItemText(nItem, 2);
	msgChange.m_strContactWay = m_CtlCarMsg.GetItemText(nItem, 3);
	msgChange.m_strServeList = m_CtlCarMsg.GetItemText(nItem, 4);
	msgChange.m_strOther = m_CtlCarMsg.GetItemText(nItem, 5);
	msgChange.m_strCost = m_CtlCarMsg.GetItemText(nItem, 6);

	if (msgChange.DoModal() == IDOK)
	{
		vector<server_form> vServer_form_Add_Msg;
		server_form server_form_Add_Msg;
		server_form_Add_Msg.nCarId = atoi(m_CtlCarMsg.GetItemText(nItem, 0));
		server_form_Add_Msg.strCar_Num = msgChange.m_strCarNum;
		server_form_Add_Msg.strContact = msgChange.m_strContact;
		server_form_Add_Msg.strContact_Way = msgChange.m_strContactWay;
		server_form_Add_Msg.strServe_List = msgChange.m_strServeList;
		server_form_Add_Msg.strOther = msgChange.m_strOther;
		server_form_Add_Msg.dCost = atof(msgChange.m_strCost);

		SYSTEMTIME st;
		CString strTime;
		GetLocalTime(&st);
		strTime.Format(_T("%d-%d-%d %d:%d:%d"), st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
		server_form_Add_Msg.strTime = strTime;
		vServer_form_Add_Msg.push_back(server_form_Add_Msg);
		
		m_UseMySQL->ChangeServeDataToMySQL(vServer_form_Add_Msg);
		UpdateMsgCtrlList();
	}
}


void CCar_ManageView::OnMenuMsgDelete()
{
	// TODO: �ڴ���������������
	int nItem = m_CtlCarMsg.GetSelectionMark();

	if (nItem == -1)
	{
		AfxMessageBox(_T("δѡ���κ�����!"));
		return;
	}

	CString strCarID = m_CtlCarMsg.GetItemText(nItem, 0);

	if (AfxMessageBox(_T("ȷ��ɾ��?"), MB_OKCANCEL) == IDOK)
	{
		m_UseMySQL->DeleteServeDataFromMySQL(strCarID.GetString());
		UpdateMsgCtrlList();
	}	
}


void CCar_ManageView::OnMenuDisplayAll()
{
	// TODO: �ڴ���������������
	UpdateMsgCtrlList();
}


void CCar_ManageView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: �ڴ˴������Ϣ����������
	CMenu menu;	menu.LoadMenu(IDR_RIGHT_MENU);
	CMenu * pMenu;	pMenu = menu.GetSubMenu(0);	
	pMenu->EnableMenuItem(ID_MENU_MSG_ADD, MF_BYCOMMAND|MF_ENABLED);
	pMenu->EnableMenuItem(ID_MENU_MSG_SEARCH, MF_BYCOMMAND|MF_ENABLED);
	pMenu->EnableMenuItem(ID_MENU_MSG_CHANGE, MF_BYCOMMAND|MF_ENABLED);
	pMenu->EnableMenuItem(ID_MENU_DISPLAY_ALL, MF_BYCOMMAND|MF_ENABLED);
	pMenu->EnableMenuItem(ID_MENU_MSG_DELETE, MF_BYCOMMAND|MF_ENABLED);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, point.x, point.y, this);
	pMenu->Detach();
	menu.DestroyMenu();
}

void CCar_ManageView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);
	
	// TODO: �ڴ˴������Ϣ����������
	if (m_CtlCarMsg.GetSafeHwnd())
	{
		if (nType != SIZE_MINIMIZED)
		{			
			CRect Rect;			
			GetClientRect(&Rect);  //�õ�������CFormView�Ĵ�С��λ��		
			m_CtlCarMsg.SetWindowPos(this, Rect.top, Rect.left, Rect.Width(), Rect.Height(),SWP_SHOWWINDOW|SWP_NOZORDER);
			m_CtlCarMsg.SetColumnWidth(0, Rect.Width()*0);
			m_CtlCarMsg.SetColumnWidth(1, Rect.Width()*12/100);   
			m_CtlCarMsg.SetColumnWidth(2, Rect.Width()*10/100); 
			m_CtlCarMsg.SetColumnWidth(3, Rect.Width()*16/100); 
			m_CtlCarMsg.SetColumnWidth(4, Rect.Width()*22/100);  
			m_CtlCarMsg.SetColumnWidth(5, Rect.Width()*12/100); 
			m_CtlCarMsg.SetColumnWidth(6, Rect.Width()*10/100); 
			m_CtlCarMsg.SetColumnWidth(7, Rect.Width()*18/100);
			ShowScrollBar(SB_BOTH,FALSE);
			m_CtlCarMsg.ShowScrollBar(SB_BOTH,FALSE);
		}
	}	
}

