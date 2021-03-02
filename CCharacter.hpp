#ifndef CCHARACTER_HPP
#define CCHARACTER_HPP
#include "CEntity.hpp"

interface CCharacter : extends CEntity {
	const char* m_sprite;
	virtual COORD GetCurrentPosition() const = 0;
	virtual ~CCharacter() {}
};
#endif