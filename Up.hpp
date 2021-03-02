#pragma once
#include "IArrow.hpp"

struct Up : implement IArrow {
	Up();
	~Up() override;
	void move(COORD&) override;
};