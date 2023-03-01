#include <iostream>
#include <windows.h>

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    DWORD processId;
    GetWindowThreadProcessId(hwnd, &processId);

    if (GetCurrentProcessId() != processId) {
        SendMessage(hwnd, WM_CLOSE, 0, 0); // Send a close message
    }

    return TRUE;
}

int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    while (true)
    {
        if(GetKeyState(VK_CONTROL) & 0x8000 & GetKeyState(VK_SHIFT) & 0x8000 & GetKeyState(VK_DELETE) & 0x8000)/*Check if high-order bit is set (1 << 15)*/
        {
            EnumWindows(EnumWindowsProc, NULL);
        }
    }
    
    return 0;
    
}