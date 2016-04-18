#include "resource.h"
#include "FrameWnd.h"
#include "ManueWnd.h"

CFrameWnd::CFrameWnd( LPCTSTR pszXMLPath )
: CXMLWnd(pszXMLPath)
{

}

void CFrameWnd::InitWindow()
{
    SetIcon(IDI_ICON1); // 设置任务栏图标
	CenterWindow();

	//一开始先隐藏列表
	CControlUI* pList = m_PaintManager.FindControl(_T("PlayList"));
	pList->SetVisible(FALSE);

	CListUI* pFileList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("FileList")));
	// 添加List列表内容，必须先Add(pListElement)，再SetText
	CListTextElementUI* pListElement1 = new CListTextElementUI;
	pListElement1->SetTag(0);
	pListElement1->SetFixedHeight(27);
	pFileList->Add(pListElement1);
	pListElement1->SetText(1, _T("sample1.mov"));
	pListElement1->SetText(2, _T("7秒"));

	CListTextElementUI* pListElement2 = new CListTextElementUI;
	pListElement2->SetTag(1);
	pListElement2->SetFixedHeight(27);
	pFileList->Add(pListElement2);
	pListElement2->SetText(1, _T("sample2.mov"));
	pListElement2->SetText(2, _T("10秒"));





}

void CFrameWnd::Notify( TNotifyUI& msg )
{
    if( msg.sType == _T("click") ) 
    {
        if( msg.pSender->GetName() == _T("play_btn") ) 
		{
			CButtonUI* pPlayBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("play_btn")));
			CButtonUI* pPauseBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("pause_btn")));
			pPlayBtn->SetVisible(FALSE);
			pPauseBtn->SetVisible(TRUE);
		}
		else if (msg.pSender->GetName() == _T("pause_btn"))
		{
			CButtonUI* pPlayBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("play_btn")));
			CButtonUI* pPauseBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("pause_btn")));
			pPlayBtn->SetVisible(TRUE);
			pPauseBtn->SetVisible(FALSE);
		}
		else if (msg.pSender->GetName() == _T("text_list"))
		{
			CButtonUI* pTextList = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("text_list")));
			CButtonUI* pPictureList = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("picture_list")));
			pTextList->SetVisible(FALSE);
			pPictureList->SetVisible(TRUE);
		}
		else if (msg.pSender->GetName() == _T("picture_list"))
		{
			CButtonUI* pTextList = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("text_list")));
			CButtonUI* pPictureList = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("picture_list")));
			pTextList->SetVisible(TRUE);
			pPictureList->SetVisible(FALSE);
		}
		else if (msg.pSender->GetName() == _T("min_list"))
		{
			CControlUI* pList = m_PaintManager.FindControl(_T("PlayList"));
			CControlUI* pListMin = m_PaintManager.FindControl(_T("FileListMin"));
			pList->SetVisible(FALSE);
			pListMin->SetVisible(TRUE);
		}
		else if (msg.pSender->GetName() == _T("max_list"))
		{
			CControlUI* pList = m_PaintManager.FindControl(_T("PlayList"));
			CControlUI* pListMin = m_PaintManager.FindControl(_T("FileListMin"));
			pList->SetVisible(TRUE);
			pListMin->SetVisible(FALSE);
		}
		else if (msg.pSender->GetName() == _T("volume_btn3"))
		{
			CButtonUI* pVolumeBtn3 = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("volume_btn3")));
			CButtonUI* pSilenceBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("silence_btn")));
			CSliderUI* pVolumeSld = static_cast<CSliderUI*>(m_PaintManager.FindControl(_T("volume_sld")));
			pVolumeSld->SetValue(0);
			pVolumeBtn3->SetVisible(FALSE);
			pSilenceBtn->SetVisible(TRUE);
		}
		else if (msg.pSender->GetName() == _T("silence_btn"))
		{
			CButtonUI* pVolumeBtn3 = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("volume_btn3")));
			CButtonUI* pSilenceBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("silence_btn")));
			CSliderUI* pVolumeSld = static_cast<CSliderUI*>(m_PaintManager.FindControl(_T("volume_sld")));
			pVolumeSld->SetValue(50);
			pVolumeBtn3->SetVisible(TRUE);
			pSilenceBtn->SetVisible(FALSE);
		}
		else if (msg.pSender->GetName() == _T("list_show"))
		{
			CControlUI* pList = m_PaintManager.FindControl(_T("PlayList"));
			CButtonUI* pListShow = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("list_show")));
			CButtonUI* pListHide = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("list_hide")));
			pList->SetVisible(TRUE);
			pListShow->SetVisible(FALSE);
			pListHide->SetVisible(TRUE);
		}
		else if (msg.pSender->GetName() == _T("list_hide"))
		{
			CControlUI* pList = m_PaintManager.FindControl(_T("PlayList"));
			CControlUI* pListMin = m_PaintManager.FindControl(_T("FileListMin"));
			CButtonUI* pListShow = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("list_show")));
			CButtonUI* pListHide = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("list_hide")));
			pList->SetVisible(FALSE);
			pListMin->SetVisible(FALSE);
			pListShow->SetVisible(TRUE);
			pListHide->SetVisible(FALSE);
		}
		else if (msg.pSender->GetName() == _T("main_manue_btn"))
		{
			CManueWnd *pManue = new CManueWnd(_T("MainManue.xml"));
			pManue->Create(*this, _T("MainManue"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
			RECT rect = msg.pSender->GetPos();
			POINT Point;
			Point.x = rect.left;
			Point.y = rect.bottom;
			pManue->ShowWindowOwn(&Point, *this);
		}
    }
    else if(msg.sType == _T("selectchanged"))
    {

    }

    __super::Notify(msg);
}

CControlUI* CFrameWnd::CreateControl( LPCTSTR pstrClassName )
{
	if (_tcsicmp(pstrClassName, _T("WndCaption")) == 0)
	{
		CDialogBuilder builder;
		CControlUI* pUI = builder.Create(_T("Caption.xml")); 
		return pUI;
	}
	if (_tcsicmp(pstrClassName, _T("WndProgress")) == 0)
	{
		CDialogBuilder builder;
		CControlUI* pUI = builder.Create(_T("Progress.xml")); 
		return pUI;
	}
	if (_tcsicmp(pstrClassName, _T("WndControl")) == 0)
	{
		CDialogBuilder builder;
		CControlUI* pUI = builder.Create(_T("Control.xml")); 
		return pUI;
	}
	if (_tcsicmp(pstrClassName, _T("WndPlayList")) == 0)
	{
		CDialogBuilder builder;
		CControlUI* pUI = builder.Create(_T("PlayList.xml")); 
		return pUI;
	}

    return NULL;
}

