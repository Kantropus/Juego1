#pragma once
#include "IArrow.hpp"

struct Down : implement IArrow {
	Down();
	~Down() override;
	void move(COORD&) override;
};