#include "CScene.hpp"
#include "Graphics.hpp"


CScene::CScene() {
}

CScene::CScene(
				HANDLE h, 
				int GameMode, 
				eestl::vector<CEntity*> e, 
				CCharacter* Main	) 
	:			m_entities{e}, m_main{Main}
{
	RemoveScrollBar();
	EnableWalls();
	COORD c;
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), GameMode, &c);
	SetFontSize(30, L"Comic San");
	hide_cursor();

	m_arrows.push_back({ 0, new Left() });
	m_arrows.push_back({ 1, new Right() });
	m_arrows.push_back({ 2, new Up() });
	m_arrows.push_back({ 3, new Down() });
}

CScene::CScene(
				HANDLE h, 
				int GameMode, 
				eestl::vector<CEntity*> e, 
				unsigned char t_main ) 
{
}

CScene::~CScene() {
	delete m_main;
	for (auto& a : m_entities) delete a;
}

void CScene::GameLoop() {
	while (1) {
		gotoxy(70, 3); std::cout << m_main->GetCurrentPosition();
		for (int i = 0; i < m_arrows.size(); ++i) {
			if ((GetAsyncKeyState(m_arrows[i].second->m_c)) & 0x7FFF) {
				m_main->move(m_arrows[i].second);
			}
			if (GetAsyncKeyState(0x0D) & 0x7FFF) {
				this->~CScene();
				return;
			}
		}
	}
}
