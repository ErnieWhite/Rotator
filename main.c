#include <windows.h>
#include <stdio.h>

BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData) {
    MONITORINFOEX mi;
    mi.cbSize = sizeof(MONITORINFOEX);
    if (GetMonitorInfo(hMonitor, &mi)) {
        printf("Monitor: %s\n", mi.szDevice);
        printf("  Position: (%d, %d)\n", lprcMonitor->left, lprcMonitor->top);
        printf("  Resolution: %dx%d\n", lprcMonitor->right - lprcMonitor->left, lprcMonitor->bottom - lprcMonitor->top);
        printf("  Primary: %s\n", (mi.dwFlags & MONITORINFOF_PRIMARY) ? "Yes" : "No");
    }
    return TRUE; // Continue enumeration
}

int main() {
    if (!EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, 0)) {
        printf("Failed to enumerate monitors\n");
        return 1;
    }
    return 0;
}

