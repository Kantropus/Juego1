#pragma once
#include <Windows.h>
#include <iostream>
#include <wchar.h>

constexpr bool operator != (const COORD& cl, const COORD cr) {
	return (cl.X != cr.X) && (cl.Y != cl.Y);
}

void gotoxy(COORD c) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void gotoxy(SHORT x, SHORT y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
}

void hide_cursor() {
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 100;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void SetFontSize(SHORT y, const wchar_t* font) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.dwFontSize.X = y/2;                   
	cfi.dwFontSize.Y = y;   
	wcscpy_s(cfi.FaceName, font); 
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &cfi);
}

void SetWindowSize(SHORT x, SHORT y) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, x, y, TRUE);
}

void RemoveScrollBar() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}

void EnableWalls() {
	for (int x = 0; x < 85; ++x) {
		gotoxy(x, 0); printf("%c", 205);
		gotoxy(x, 24); printf("%c", 205);
	}
	for (int y = 0; y < 24; ++y) {
		gotoxy(0, y); printf("%c", 186);
		gotoxy(84, y); printf("%c", 186);
	}
	gotoxy(0, 0); printf("%c", 201);
	gotoxy(0, 24); printf("%c", 200);
	gotoxy(84, 0); printf("%c", 187);
	gotoxy(84, 24); printf("%c", 188);
}

std::ostream& operator << (std::ostream& os, COORD c) {
	os << "( " << c.X << ", " << c.Y << " )";
	return os;
}
