
// Car_ManageView.h : CCar_ManageView ��Ľӿ�
//

#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "UseMySQLData.h"
#include "CarMsgAdd.h"

class CCar_ManageView : public CFormView
{
protected: // �������л�����
	CCar_ManageView();
	DECLARE_DYNCREATE(CCar_ManageView)

public:
	enum{ IDD = IDD_CAR_MANAGE_FORM };

// ����
public:
	CCar_ManageDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CCar_ManageView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
public:
	CUseMySQLData *m_UseMySQL;
	vector<server_form> m_vServer_Form;

	unsigned int m_nCarIdMax;

	BOOL UpdateMsgCtrlList();
	BOOL DisplaySearchMsg(vector<server_form> vSearch_Server_Form);

protected:
	DECLARE_MESSAGE_MAP()

public:
	CListCtrl m_CtlCarMsg;
	afx_msg void OnMenuMsgAdd();
	afx_msg void OnMenuMsgSearch();
	afx_msg void OnMenuMsgChange();
	afx_msg void OnMenuMsgDelete();
	afx_msg void OnMenuDisplayAll();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // Car_ManageView.cpp �еĵ��԰汾
inline CCar_ManageDoc* CCar_ManageView::GetDocument() const
   { return reinterpret_cast<CCar_ManageDoc*>(m_pDocument); }
#endif

