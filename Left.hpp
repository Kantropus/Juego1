#pragma once
#include "IArrow.hpp"

struct Left : implement IArrow {
	Left();
	~Left() override;
	void move(COORD&) override;
};