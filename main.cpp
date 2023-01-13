#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include "nogo_func.h"
using namespace std;

int main(void)
{
    initgraph(1280, 720, EW_SHOWCONSOLE);
    HWND hnd = GetHWnd();
    SetWindowText(hnd, L"²»Î§Æå No-Go Ver3.0");
    bgmnum = randSelectQuestion(1, 8);
    opening();
    system("pause");
    closegraph();
    return 0;

}