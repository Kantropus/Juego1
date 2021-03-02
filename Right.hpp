#pragma once
#include "IArrow.hpp"

struct Right : implement IArrow {
	Right();
	void move(COORD&) override;
	~Right() override;
};