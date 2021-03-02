#include "Right.hpp"

Right::Right() {
	m_c = 0x27;
}

void Right::move(COORD& current_pos) {
	if (current_pos.X + 1 < 84)current_pos.X++;
}

Right::~Right()
{
}
