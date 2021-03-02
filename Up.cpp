#include "Up.hpp"

Up::Up() {
	m_c = 0x26;
}

Up::~Up() {
}

void Up::move(COORD& current_pos) {
	if (current_pos.Y - 1 > 0)current_pos.Y--;
}
