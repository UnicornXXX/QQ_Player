#pragma once
#include "duilib.h"

class CManueWnd: public CXMLWnd
{
public:
	explicit CManueWnd(LPCTSTR pszXMLPath);

	virtual void InitWindow();
	virtual void Notify(TNotifyUI& msg);
	LRESULT HandleMessage( UINT uMsg, WPARAM wParam, LPARAM lParam );
	LRESULT OnKillFocus( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled );

	void ShowWindowOwn(POINT* pPoint, HWND hWnd);
};