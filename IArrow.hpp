#pragma once
#include <Windows.h>
#define interface struct 
#define implement public

interface IArrow {
	int m_c;
	virtual void move(COORD&) = 0;
	virtual ~IArrow() {}
};