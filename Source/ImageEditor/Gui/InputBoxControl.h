// This file was generated by WTL subclass control wizard 
// LogListBox.h : Declaration of the CLogListBox

#ifndef LOGLISTBOX_H
#define LOGLISTBOX_H

#pragma once

#include <atlbase.h>
#include <atlctrls.h>
#include <atlmisc.h>
#include <atlcrack.h>
#include "../InputBox.h"
#include <sstream>

// CLogListBox

namespace ImageEditor {

class InputBoxControl :
	public CWindowImpl<InputBoxControl, CRichEditCtrl,CControlWinTraits>, public InputBox
{
	public:
		typedef CWindowImpl<InputBoxControl, CRichEditCtrl,CControlWinTraits> Base;
		InputBoxControl();
		~InputBoxControl();
		DECLARE_WND_SUPERCLASS(_T("CInputBoxControl"), CRichEditCtrl::GetWndClassName())

		enum {  IDMM_UNDO = 100, IDMM_REDO, IDMM_CUT, IDMM_COPY, IDMM_PASTE};
		
		 BEGIN_MSG_MAP(InputBoxControl)
			//MSG_WM_KILLFOCUS(OnKillFocus)
			MESSAGE_HANDLER(WM_CREATE, OnCreate)
			MESSAGE_HANDLER(WM_DESTROY, OnDestroy) 
			MESSAGE_HANDLER(WM_KEYDOWN, OnKeyDown )
			//MESSAGE_HANDLER(WM_KEYDOWN, OnKeyDown )
			MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBkgnd)
			MESSAGE_HANDLER(WM_CONTEXTMENU, OnContextMenu)
			MESSAGE_HANDLER(WM_SETCURSOR, OnSetCursor)
			REFLECTED_NOTIFY_CODE_HANDLER(EN_REQUESTRESIZE, OnRequestResize)
			REFLECTED_NOTIFY_CODE_HANDLER(EN_SELCHANGE, OnSelChange)
			//NOTIFY_CODE_HANDLER(EN_REQUESTRESIZE, OnRequestResize)
			REFLECTED_COMMAND_CODE_HANDLER_EX(EN_CHANGE, OnChange)
			COMMAND_ID_HANDLER(IDMM_UNDO, OnUndo)
			COMMAND_ID_HANDLER(IDMM_REDO, OnRedo)
			COMMAND_ID_HANDLER(IDMM_CUT, OnCut)
			COMMAND_ID_HANDLER(IDMM_COPY, OnCopy)
			COMMAND_ID_HANDLER(IDMM_PASTE, OnPaste)
			//CHAIN_MSG_MAP(Base) 
		 END_MSG_MAP()

		 // Handler prototypes:
		 //  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		 //  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
		 //  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
		LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam,BOOL& bHandled);
		LRESULT OnEraseBkgnd(UINT uMsg, WPARAM wParam, LPARAM lParam,BOOL& bHandled);
		LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam,BOOL& bHandled);
		LRESULT OnKillFocus(HWND hwndNewFocus);
		//LRESULT OnKeyUp(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		LRESULT OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		LRESULT OnChange(UINT wNotifyCode,int, HWND);
		LRESULT OnRequestResize(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
		LRESULT OnSelChange(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
		LRESULT OnContextMenu(UINT uMsg, WPARAM wParam, LPARAM lParam,BOOL& bHandled);
		LRESULT OnUndo(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
		LRESULT OnRedo(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
		LRESULT OnCut(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
		LRESULT OnCopy(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
		LRESULT OnPaste(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
		LRESULT OnSetCursor(UINT uMsg, WPARAM wParam, LPARAM lParam,BOOL& bHandled);

	public:
		int NotifyParent(int nItem);
		BOOL SubclassWindow(HWND hWnd);
		virtual void show(bool s);
		virtual void resize(int x, int y, int w,int h, std::vector<MovableElement::Grip> grips);
		virtual void render(Gdiplus::Graphics* graphics, Gdiplus::Bitmap* background, Gdiplus::Rect layoutArea);
		virtual bool isVisible();
		virtual void invalidate();
		virtual void setTextColor(Gdiplus::Color color);
		virtual void setFont(LOGFONT font,  DWORD changeMask);
		virtual void setRawText(const std::string& text);
		virtual std::string getRawText();
protected:
	static DWORD CALLBACK EditStreamOutCallback(DWORD_PTR dwCookie, LPBYTE pbBuff, LONG cb, LONG *pcb);
	static DWORD CALLBACK EditStreamInCallback(DWORD_PTR dwCookie, LPBYTE pbBuff, LONG cb, LONG *pcb);
	bool contextMenuOpened_;


};

}

#endif // LOGLISTBOX_H


