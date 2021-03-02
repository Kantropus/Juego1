#pragma once
#include "CPirate.hpp"
#include "Arrows.hpp"
#include <vector.hpp>
#include <utility.hpp>


struct CScene {
	explicit CScene();
	explicit CScene(HANDLE, int, eestl::vector<CEntity*>, CCharacter*);
	explicit CScene(HANDLE, int, eestl::vector<CEntity*>, unsigned char);
	~CScene();
	void GameLoop();
private:
	eestl::vector<CEntity*> m_entities;
	CCharacter* m_main;

	eestl::vector<eestl::pair<int, IArrow*>> m_arrows;
};