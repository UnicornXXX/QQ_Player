#include "FrameWnd.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    ::CoInitialize(NULL);
    CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("Skin"));

    CFrameWnd *pFrame = new CFrameWnd(_T("QQPlayer.xml"));
    pFrame->Create(NULL, _T("QQÓ°Òô"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
    pFrame->ShowModal();

    delete pFrame;
    ::CoUninitialize();
    return 0;
}
