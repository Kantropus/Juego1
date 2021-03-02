#ifndef CPIRATE_HPP
#define CPIRATE_HPP
#include <Windows.h>
#include "CCharacter.hpp"

struct CPirate : implement CCharacter
{
	CPirate(COORD);
	void draw()	override;
	void move(IArrow*) override;
	COORD GetCurrentPosition() const;
	~CPirate() override;
private:
	COORD m_coord;
	void gotoxy(COORD);
};

#endif