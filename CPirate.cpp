#include "CPirate.hpp"
#include <iostream>

constexpr bool operator == (const COORD& cl, const COORD cr) {
	return (cl.X == cr.X) && (cl.Y == cl.Y);
}

CPirate::CPirate(COORD c) : m_coord{c}
{
	m_sprite = "#";
}

void CPirate::draw() {
	gotoxy(m_coord);
	printf("%s", m_sprite);
}

void CPirate::move(IArrow* dir) {
	gotoxy(m_coord); printf(" ");
	dir->move(m_coord);
	draw();
}

COORD CPirate::GetCurrentPosition() const
{
	return m_coord;
}

CPirate::~CPirate() {
	m_sprite = NULL;
}

void CPirate::gotoxy(COORD c) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
