#include<windows.h> 
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR szBuffer[50];
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	MSG msg;
	static TCHAR szAppName[] = TEXT("HappyNewYear");
	HWND hwnd;
	WNDCLASS wndclass;
	wndclass.cbClsExtra = NULL;
	wndclass.cbWndExtra = NULL;
	wndclass.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("the program requires windows NT"), szAppName, MB_OK | MB_ICONERROR);
		return 0;
	}
	hwnd = CreateWindow(szAppName, TEXT("黑皮妞伊儿!"), WS_SYSMENU | WS_OVERLAPPED | WS_CAPTION, 0, 0, 200, 50, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);
	memset(szBuffer, 50, 0);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}


TCHAR* szFont(int i)
{
	switch (i)
	{
	case 0:return TEXT("黑体");
	case 1:return TEXT("仿宋_GB2312");
	case 2:return TEXT("楷体_GB2312");
	default:return TEXT("楷体_GB2312");
	}
}

void SetBuffer(int i)
{
	switch (i)
	{
	case 0:
		wsprintf(szBuffer, "Happy new yeah!"); break;
	case 1:
		wsprintf(szBuffer, "明 け ま し て お め で と う ご ざ い ま す !"); break;
	case 2:
		wsprintf(szBuffer, "Bonne année !"); break;
	case 3:
		wsprintf(szBuffer, "新年快乐"); break;
	default:
		wsprintf(szBuffer, "Nuovo Anno Felice "); break;
	}
}


void TianLiangLe()
{
	HDC hdc;
	int iRed, iGreen, iBlue;
	HFONT hFont;
	int x, y;
	static int cxWindow = GetSystemMetrics(SM_CXSCREEN), cyWindow = GetSystemMetrics(SM_CYSCREEN);
	iRed = rand() % 255;
	iBlue = rand() % 255;
	iGreen = rand() % 255;
	y = rand() % 250 + 20;
	x = y / 2;
	hdc = CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);
	SetTextColor(hdc, RGB(iRed, iGreen, iBlue));
	SetBkMode(hdc, TRANSPARENT);
	hFont = CreateFontA(y, x, 0, 0, 700, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, szFont(rand() % 3));
	SelectObject(hdc, hFont);
	SetBuffer(rand() % 4);
	TextOut(hdc, rand() % (cxWindow - 200), rand() % (cyWindow - 200), szBuffer, lstrlen(szBuffer));
	DeleteObject(hFont);
	DeleteDC(hdc);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	TCHAR tempBuffer[] = TEXT("按下空格键结束程序");
	switch (message)
	{
	case WM_CREATE:
		SetTimer(hwnd, 2, 800, NULL);
		SetTimer(hwnd, 1, 20000, NULL);
		SetFocus(hwnd);
		return 0;
	case WM_KILLFOCUS:
		SetFocus(hwnd);
		return 0;
	case WM_CHAR:
		if (wParam == VK_SPACE)
			SendMessage(hwnd, WM_DESTROY, 0, 0);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 20, 0, tempBuffer, lstrlen(tempBuffer));
		EndPaint(hwnd, &ps);
		return 0;
	case WM_TIMER:
		if (wParam == 2)
			TianLiangLe();
		else
			InvalidateRect(NULL, NULL, true);
		return 0;
	case WM_DESTROY:
		KillTimer(hwnd, 1);
		KillTimer(hwnd, 2);
		InvalidateRect(0, NULL, true);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
