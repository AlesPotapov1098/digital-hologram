#include "framework.h"
#include "OCL.h"

#define CONTROL_ID (LOWORD((wParam)))

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{

    DialogBox(hInstance, MAKEINTRESOURCE(IDD_INIT_OCL), NULL, InitOCLProc);

    return 0;
}

INT_PTR CALLBACK InitOCLProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    auto ControlID = CONTROL_ID;

    switch (msg)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;
    case WM_COMMAND:
        switch (ControlID)
        {
        case IDOK:
            EndDialog(hwnd, ControlID);
            return (INT_PTR)TRUE;

        case IDCANCEL:
            EndDialog(hwnd, ControlID);
            return (INT_PTR)TRUE;

        default:
            break;
        }
    }

    return (INT_PTR)FALSE;
}

