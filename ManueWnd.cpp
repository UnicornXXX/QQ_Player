#include "resource.h"
//#include "FrameWnd.h"
#include "ManueWnd.h"


CManueWnd::CManueWnd( LPCTSTR pszXMLPath )
: CXMLWnd(pszXMLPath)
{

}

void CManueWnd::InitWindow()
{
	//    SetIcon(IDR_MAINFRAME); // 设置任务栏图标
	CenterWindow();

	// 初始化CProgressUI控件
	//     CProgressUI* pProgress = static_cast<CProgressUI*>(m_PaintManager.FindControl(_T("ProgressDemo1")));    
	//     pProgress->SetValue(100);

}

void CManueWnd::ShowWindowOwn(POINT* pPoint, HWND hWnd)
{
	ShowWindow();
	::ClientToScreen(hWnd, pPoint);
	::SetWindowPos(m_hWnd, HWND_TOP, pPoint->x, pPoint->y, 120, 80, SWP_SHOWWINDOW);

}
void CManueWnd::Notify( TNotifyUI& msg )
{
	if( msg.sType == _T("click") ) 
	{
		if( msg.pSender->GetName() == _T("play_btn") ) 
		{

		}
	}
	else if(msg.sType == _T("selectchanged"))
	{

	}

	__super::Notify(msg);
}

LRESULT CManueWnd::HandleMessage( UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	LRESULT lRes = 0;
	BOOL bHandled = TRUE;

	switch( uMsg )
	{
	case WM_KILLFOCUS:    
		lRes = OnKillFocus(uMsg, wParam, lParam, bHandled); 
		break; 

	default:
		bHandled = FALSE;
	}

	if(bHandled || m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes)) 
	{
		return lRes;
	}

	return __super::HandleMessage(uMsg, wParam, lParam);
}

LRESULT CManueWnd::OnKillFocus( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
	Close();
	bHandled = FALSE;
	return __super::OnKillFocus(uMsg, wParam, lParam, bHandled); 
}