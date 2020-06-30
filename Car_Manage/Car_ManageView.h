
// Car_ManageView.h : CCar_ManageView 类的接口
//

#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "UseMySQLData.h"
#include "CarMsgAdd.h"

class CCar_ManageView : public CFormView
{
protected: // 仅从序列化创建
	CCar_ManageView();
	DECLARE_DYNCREATE(CCar_ManageView)

public:
	enum{ IDD = IDD_CAR_MANAGE_FORM };

// 特性
public:
	CCar_ManageDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CCar_ManageView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // Car_ManageView.cpp 中的调试版本
inline CCar_ManageDoc* CCar_ManageView::GetDocument() const
   { return reinterpret_cast<CCar_ManageDoc*>(m_pDocument); }
#endif

