#include <Windows.h>
#include <d2d1_1.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
		
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR pCmdLine, int nCmdShow)
{
	//Setup main window class
	WNDCLASSEX mainWindowClass;
	mainWindowClass.cbSize = sizeof(WNDCLASSEX);
	mainWindowClass.style = CS_HREDRAW | CS_VREDRAW;
	mainWindowClass.lpfnWndProc = WndProc;
	mainWindowClass.cbClsExtra = 0;
	mainWindowClass.cbWndExtra = 0;
	mainWindowClass.hInstance = hInstance;
	mainWindowClass.hIcon = NULL;
	mainWindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	mainWindowClass.hbrBackground = NULL;
	mainWindowClass.lpszMenuName = NULL;
	mainWindowClass.lpszClassName = L"MainWindow";
	mainWindowClass.hIconSm = NULL;

	//Ensure class registration doesn't fail
	if (RegisterClassEx(&mainWindowClass) == 0)
	{
		return 1;
	}

	//Create main window
	HWND mainWindow = CreateWindowEx(
		0,
		L"MainWindow",
		L"Direct2D Test",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		640,
		480,
		NULL,
		NULL,
		hInstance,
		NULL);

	//Ensure window creation does not fail
	if (mainWindow == NULL)
	{
		return 1;
	}
	
	//Show main window
	ShowWindow(mainWindow, nCmdShow);

	//Pump the messages
	MSG message;
	while (GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	
	return (int)message.wParam;
}