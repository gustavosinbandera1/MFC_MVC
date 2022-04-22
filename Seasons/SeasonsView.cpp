
// SeasonsView.cpp : implementation of the CSeasonsView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Seasons.h"
#endif

#include "SeasonsDoc.h"
#include "SeasonsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSeasonsView

IMPLEMENT_DYNCREATE(CSeasonsView, CFormView)

BEGIN_MESSAGE_MAP(CSeasonsView, CFormView)
	ON_BN_CLICKED(IDC_CHANGE, &CSeasonsView::OnBnClickedChange)
	ON_COMMAND(ID_SEASON_FALL, &CSeasonsView::OnSeasonFall)
	ON_COMMAND(ID_SEASON_SPRINT, &CSeasonsView::OnSeasonSprint)
	ON_COMMAND(ID_SEASON_SUMMER, &CSeasonsView::OnSeasonSummer)
	ON_COMMAND(ID_SEASON_WINTER, &CSeasonsView::OnSeasonWinter)
	ON_UPDATE_COMMAND_UI(ID_SEASON_FALL, &CSeasonsView::OnUpdateSeasonFall)
	ON_UPDATE_COMMAND_UI(ID_SEASON_SPRINT, &CSeasonsView::OnUpdateSeasonSprint)
	ON_UPDATE_COMMAND_UI(ID_SEASON_SUMMER, &CSeasonsView::OnUpdateSeasonSummer)
	ON_UPDATE_COMMAND_UI(ID_SEASON_WINTER, &CSeasonsView::OnUpdateSeasonWinter)
END_MESSAGE_MAP()

// CSeasonsView construction/destruction

CSeasonsView::CSeasonsView() noexcept : CFormView(IDD_SEASONS_FORM) {}

CSeasonsView::~CSeasonsView() {}

void CSeasonsView::DoDataExchange(CDataExchange *pDX) {
  CFormView::DoDataExchange(pDX);
  DDX_Text(pDX, IDC_SEASON, m_season);
}

BOOL CSeasonsView::PreCreateWindow(CREATESTRUCT &cs) {
  // TODO: Modify the Window class or styles here by modifying
  //  the CREATESTRUCT cs

  return CFormView::PreCreateWindow(cs);
}

void CSeasonsView::OnInitialUpdate() {
  CFormView::OnInitialUpdate();
  ResizeParentToFit();
}

// CSeasonsView diagnostics

#ifdef _DEBUG
void CSeasonsView::AssertValid() const { CFormView::AssertValid(); }

void CSeasonsView::Dump(CDumpContext &dc) const { CFormView::Dump(dc); }

CSeasonsDoc *CSeasonsView::GetDocument() const // non-debug version is inline
{
  ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSeasonsDoc)));
  return (CSeasonsDoc *)m_pDocument;
}
#endif //_DEBUG

// CSeasonsView message handlers

void CSeasonsView::OnBnClickedChange() {
  CSeasonsDoc *pDoc = GetDocument();
  pDoc->ChangeSession();
  // TODO: Add your control notification handler code here
}

void CSeasonsView::OnUpdate(CView * /*pSender*/, LPARAM /*lHint*/,
                            CObject * /*pHint*/) {
  // MessageBox(_T("Receiving update"));
  CSeasonsDoc *pDoc = GetDocument();
  m_season = pDoc->m_season;
  UpdateData(FALSE); // IDC_SEASON = m_season
                     // pDoc->UpdateAllViews(this);
}

//
// void CSeasonsView::OnDraw(CDC* /*pDC*/)
//{
//	//MessageBox(_T("OnDraw"));
//	CSeasonsDoc* pDoc = GetDocument();
//	m_season = pDoc->m_season;
//	//MessageBox(_T("Receiving update"));
//	// TODO: Add your specialized code here and/or call the base class
//}

void CSeasonsView::OnSeasonFall() {
  // TODO: Add your command handler code here
	CSeasonsDoc* pDoc = GetDocument();
	pDoc->ChangeSession(_T("Fall"));
}

void CSeasonsView::OnSeasonSprint() {
  // TODO: Add your command handler code here
	CSeasonsDoc* pDoc = GetDocument();
	pDoc->ChangeSession(_T("Sprint"));
}

void CSeasonsView::OnSeasonSummer() {
  // TODO: Add your command handler code here
	CSeasonsDoc* pDoc = GetDocument();
	pDoc->ChangeSession(_T("Winter"));
}

void CSeasonsView::OnSeasonWinter() {
  // TODO: Add your command handler code here
	CSeasonsDoc* pDoc = GetDocument();
	pDoc->ChangeSession(_T("Winter"));
}

void CSeasonsView::OnUpdateSeasonFall(CCmdUI *pCmdUI) {
	// TODO: Add your command update UI handler code here
	if (m_season == "Fall")
		pCmdUI->Enable(FALSE); // disable [Season]/[Fall]
}

void CSeasonsView::OnUpdateSeasonSprint(CCmdUI *pCmdUI) {
  // TODO: Add your command update UI handler code here
	if (m_season == "Sprint")
		pCmdUI->Enable(FALSE); // disable [Season]/[Fall]
}

void CSeasonsView::OnUpdateSeasonSummer(CCmdUI *pCmdUI) {
  // TODO: Add your command update UI handler code here
	if (m_season == "Summer")
		pCmdUI->Enable(FALSE); // disable [Season]/[Fall]
}

void CSeasonsView::OnUpdateSeasonWinter(CCmdUI *pCmdUI) {
  // TODO: Add your command update UI handler code here
	if (m_season == "Winter")
		pCmdUI->Enable(FALSE); // disable [Season]/[Fall]
}
