
// SeasonsView.h : interface of the CSeasonsView class
//

#pragma once


class CSeasonsView : public CFormView
{
protected: // create from serialization only
	CSeasonsView() noexcept;
	DECLARE_DYNCREATE(CSeasonsView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_SEASONS_FORM };
#endif

// Attributes
public:
	CSeasonsDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CSeasonsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString m_season;
	afx_msg void OnBnClickedChange();
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/) override;
	//virtual void OnDraw(CDC* /*pDC*/);
	afx_msg void OnSeasonFall();
	afx_msg void OnSeasonSprint();
	afx_msg void OnSeasonSummer();
	afx_msg void OnSeasonWinter();
	afx_msg void OnUpdateSeasonFall(CCmdUI *pCmdUI);
	afx_msg void OnUpdateSeasonSprint(CCmdUI *pCmdUI);
	afx_msg void OnUpdateSeasonSummer(CCmdUI *pCmdUI);
	afx_msg void OnUpdateSeasonWinter(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // debug version in SeasonsView.cpp
inline CSeasonsDoc* CSeasonsView::GetDocument() const
   { return reinterpret_cast<CSeasonsDoc*>(m_pDocument); }
#endif

