#include "CMyEngine.h"
#include "CPlayer.h"
#include "CMonster.h"

CMyEngine::CMyEngine()
{
	Init();
}

CMyEngine::~CMyEngine()
{
	Term();
}

bool CMyEngine::Init()
{
	m_map = new CMap;
	m_Characters.push_back(new CPlayer());
	m_Characters.push_back(new CMonster());

	return true;
}

bool CMyEngine::Run()
{
	CEngine::GameLoop();

	return false;
}

bool CMyEngine::Term()
{
	if (!m_Characters.empty())
	{
		for (int i = 0; i < m_Characters.size(); ++i)
		{
			delete m_Characters[i];
			m_Characters[i] = NULL;
		}
	}
	if (m_map != NULL)
	{
		delete m_map;
		m_map = NULL;
	}
	return false;
}

void CMyEngine::input()
{
	CEngine::input();
}

void CMyEngine::Tick()
{
	//*************
	//로직 추가부분

	//*************
	CEngine::Tick();
}
