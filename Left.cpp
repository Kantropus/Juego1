#include "Left.hpp"

Left::Left() {
	m_c = 0x25;
}

Left::~Left() {
}

void Left::move(COORD& current_pos) {
	if (current_pos.X - 1 > 0) current_pos.X--;
}
