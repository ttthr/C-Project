#include "CMyEngine.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CMap.h"

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
	m_Characters.push_back(new CPlayer(m_map));
	m_Characters.push_back(new CMonster(m_map));

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
	m_Characters.clear();

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
	//���� �߰��κ�
	m_map->Tick();
	for(int i = 0; i < m_Characters.size() ; ++i)
		m_Characters[i]->Tick();

	if (dynamic_cast<CPlayer*>(m_Characters[0])->Position.x == dynamic_cast<CMonster*>(m_Characters[1])->Position.x &&
		dynamic_cast<CPlayer*>(m_Characters[0])->Position.y == dynamic_cast<CMonster*>(m_Characters[1])->Position.y)
	{
		bIsRunning = false;
		cout << "�÷��̾� ���" << endl;
		//���ȭ�� �߰�
	}
	else if (dynamic_cast<CPlayer*>(m_Characters[0])->Position.x == 8 && dynamic_cast<CPlayer*>(m_Characters[0])->Position.y == 8)
	{
		bIsRunning = false;
		cout << "Ż��" << endl;
		//���ȭ�� �߰�
	}

	//*************
	CEngine::Tick();
}

void CMyEngine::Render()
{
	CEngine::Render();
	system("cls");
	m_map->Render();
	for (int i = 0; i < m_Characters.size(); ++i)
		m_Characters[i]->Render();
}
