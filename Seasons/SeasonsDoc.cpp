
// SeasonsDoc.cpp : implementation of the CSeasonsDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Seasons.h"
#endif

#include "SeasonsDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSeasonsDoc

IMPLEMENT_DYNCREATE(CSeasonsDoc, CDocument)

BEGIN_MESSAGE_MAP(CSeasonsDoc, CDocument)
END_MESSAGE_MAP()

// CSeasonsDoc construction/destruction

CSeasonsDoc::CSeasonsDoc() noexcept {
  // TODO: add one-time construction code here
  //m_season = "Fall";
}

CSeasonsDoc::~CSeasonsDoc() {}

BOOL CSeasonsDoc::OnNewDocument() {
  if (!CDocument::OnNewDocument())
    return FALSE;

  // TODO: add reinitialization code here
  // (SDI documents will reuse this document)

  return TRUE;
}

// CSeasonsDoc serialization

void CSeasonsDoc::Serialize(CArchive &ar) {
  if (ar.IsStoring()) {
    // TODO: add storing code here
	  ar << m_season;
  } else {
    // TODO: add loading code here
	  ar >> m_season;
  }
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CSeasonsDoc::OnDrawThumbnail(CDC &dc, LPRECT lprcBounds) {
  // Modify this code to draw the document's data
  dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

  CString strText = _T("TODO: implement thumbnail drawing here");
  LOGFONT lf;

  CFont *pDefaultGUIFont =
      CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
  pDefaultGUIFont->GetLogFont(&lf);
  lf.lfHeight = 36;

  CFont fontDraw;
  fontDraw.CreateFontIndirect(&lf);

  CFont *pOldFont = dc.SelectObject(&fontDraw);
  dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
  dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CSeasonsDoc::InitializeSearchContent() {
  CString strSearchContent;
  // Set search contents from document's data.
  // The content parts should be separated by ";"

  // For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
  SetSearchContent(strSearchContent);
}

void CSeasonsDoc::SetSearchContent(const CString &value) {
  if (value.IsEmpty()) {
    RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
  } else {
    CMFCFilterChunkValueImpl *pChunk = nullptr;
    ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
    if (pChunk != nullptr) {
      pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
      SetChunkValue(pChunk);
    }
  }
}

#endif // SHARED_HANDLERS

// CSeasonsDoc diagnostics

#ifdef _DEBUG

void CSeasonsDoc::AssertValid() const { CDocument::AssertValid(); }

void CSeasonsDoc::Dump(CDumpContext &dc) const { CDocument::Dump(dc); }
#endif //_DEBUG

// CSeasonsDoc commands

void CSeasonsDoc::ChangeSession(CString season) {
  // TODO: Add your implementation code here.
  if (season == "next") {
    if (m_season == "Fall") {
      m_season = "Winter";
    } else if (m_season == "Winter") {
      m_season = "Spring";
    } else if (m_season == "Spring") {
      m_season = "Summer";
    } else {
      m_season = "Fall";
    }
  } else {
    m_season = season;
  }
  SetModifiedFlag(TRUE);
  UpdateAllViews(NULL);
}
