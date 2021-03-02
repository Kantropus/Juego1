#ifndef CENTITY_HPP
#define CENTITY_HPP
#include "IArrow.hpp"
#define implement public 
#define extends public

interface CEntity {
	virtual void draw() = 0;
	virtual void move(IArrow*) = 0;
	virtual ~CEntity() {}
};

#endif