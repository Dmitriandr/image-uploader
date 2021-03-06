// This file was generated by WTL subclass control wizard 
// LogListBox.h : Declaration of the CLogListBox

#pragma once
#include "atlheaders.h"
#include "resource.h"
#include "Core/HistoryManager.h"
#include <map>

struct HistoryTreeViewItem
{
    CString strTitle;
    int TitleHeight;

    CString strText;
    int TextHeight;

    CString Info;
    int InfoHeight;

    RECT InfoDim;

    CString Time;
    int nLinesCount;
};

class CHistoryTreeView :
    public CWindowImpl<CHistoryTreeView, CTreeViewCtrl,CControlWinTraits>, 
    public CCustomDraw<CHistoryTreeView> , public CThemeImpl <CHistoryTreeView>   
{
    public:
        CHistoryTreeView();
        ~CHistoryTreeView();
        DECLARE_WND_SUPERCLASS(_T("CHistoryTreeView"), CListViewCtrl::GetWndClassName())
        
         BEGIN_MSG_MAP(CHistoryTreeView)
            MSG_WM_KILLFOCUS(OnKillFocus)
            //MESSAGE_HANDLER(OCM_DRAWITEM, OnDrawitem)
            MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
            MESSAGE_HANDLER(WM_LBUTTONDBLCLK, OnLButtonDoubleClick)
            MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
            MESSAGE_HANDLER(WM_RBUTTONDOWN, OnLButtonDown)    
             CHAIN_MSG_MAP(CCustomDraw<CHistoryTreeView>)
             //REFLECT_NOTIFICATIONS()
         END_MSG_MAP()

         // Handler prototypes:
         //  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
         //  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
         //  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
        LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam,BOOL& bHandled);
        
        LRESULT OnDrawitem(UINT uMsg, WPARAM wParam, LPARAM lParam,BOOL& bHandled);
        LRESULT OnMeasureItem(UINT uMsg, WPARAM wParam, LPARAM lParam,BOOL& bHandled);
        int AddString( LPCTSTR szTitle,LPCTSTR szText, LPCTSTR szInfo=NULL);
        LRESULT OnKillFocus(HWND hwndNewFocus);
        DWORD OnPrePaint(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/);
        DWORD OnItemPrePaint(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/);
        DWORD OnSubItemPrePaint(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/);

    public:
        int NotifyParent(int nItem);
        HICON ErrorIcon, WarningIcon;
        HFONT UnderlineFont, NormalFont, BoldFont;
        int m_thumbWidth;
        BOOL SubclassWindow(HWND hWnd);
        void addSubEntry(HTREEITEM res, HistoryItem it);
        HTREEITEM addEntry(CHistorySession* session, const CString& text);
        void Init();
        void Clear();
        bool IsItemAtPos(int x, int y, bool &isRoot);
        LRESULT ReflectContextMenu(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
private:
    HistoryItem* getItemData(HTREEITEM res);
    std::map<CString, HICON> m_fileIconCache;
    std::map<CString, HICON> m_serverIconCache;
    HICON getIconForExtension(const CString& serverName);
    HICON getIconForServer(const CString& serverName);
    int CalcItemHeight(HTREEITEM item); 
    LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    void DrawItem(HTREEITEM res, HDC dc, DWORD itemState,RECT invRC, int* outHeight);
    void DrawSubItem(HTREEITEM res, HDC dc, DWORD itemState, RECT invRC,  int* outHeight);
    LRESULT OnLButtonDoubleClick(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
         
};


