#include "Down.hpp"

Down::Down() {
	m_c = 0x28;
}

Down::~Down() {

}

void Down::move(COORD& current_pos) {
	if(current_pos.Y+1<24) current_pos.Y++;
}
