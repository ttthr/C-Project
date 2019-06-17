#include "CEngine.h"

CEngine::CEngine()	
{
	Init(); //�ʱ�ȭ
}

CEngine::~CEngine()
{
	Term(); // ����
}

bool CEngine::Init()
{
	bIsRunning = true; 
	return true;
}

bool CEngine::Run()
{
	return GameLoop(); 
}

bool CEngine::Term()
{
	return false;
}

void CEngine::input()
{
	CurrentKeyInput = getch();
}

void CEngine::Tick()
{
	KeyInput(CurrentKeyInput); //�÷��̾� Űó�� �Լ�
	m_map->SetCharacters(m_Characters); //ĳ���͸� ������ �ѱ�� �Լ�
	Collision(); // �÷��̾�,���� �浹,���ó�� �Լ�

}

void CEngine::Render()
{

	system("cls");
	m_map->Render(); //�� ����

}

bool CEngine::GameLoop()
{
	while (bIsRunning)
	{
		input();
		Tick();
		Render();
	
	}
	return false;
}

void CEngine::KeyInput(int _CurrentKeyInput)
{
	switch (_CurrentKeyInput)
	{
	case right:
	{
		m_Characters[0]->Position.x++;
		break;
	}
	case left:
	{
		m_Characters[0]->Position.x--;
		break;
	}
	case up:
	{
		m_Characters[0]->Position.y--;
		break;
	}
	case down:
	{
		m_Characters[0]->Position.y++;
		break;
	}
	case 'Q':
	{
		bIsRunning = false;
		break;
	}
	case 'q':
	{
		bIsRunning = false;
		break;
	}
	}

	CurrentKeyInput = 0;
}

void CEngine::Collision()
{
	dynamic_cast<CPlayer*>(m_Characters[0])->Tick();
	dynamic_cast<CPlayer*>(m_Characters[0])->Position.x = m_map->clamp(dynamic_cast<CPlayer*>(m_Characters[0])->Position.x, 1, 8);
	dynamic_cast<CPlayer*>(m_Characters[0])->Position.y = m_map->clamp(dynamic_cast<CPlayer*>(m_Characters[0])->Position.y, 1, 8);
	if (dynamic_cast<CPlayer*>(m_Characters[0])->Position.x == 8 && dynamic_cast<CPlayer*>(m_Characters[0])->Position.y == 8)
	{
		bIsRunning = false;
		cout << "Ż��" << endl;
	}
	if (dynamic_cast<CPlayer*>(m_Characters[0])->Position.x == dynamic_cast<CMonster*>(m_Characters[1])->Position.x &&
		dynamic_cast<CPlayer*>(m_Characters[0])->Position.y == dynamic_cast<CMonster*>(m_Characters[1])->Position.y)
	{
		bIsRunning = false;
		cout << "�÷��̾� ���" << endl;
	}

	dynamic_cast<CMonster*>(m_Characters[1])->Tick();
	dynamic_cast<CMonster*>(m_Characters[1])->Position.x = m_map->clamp(dynamic_cast<CMonster*>(m_Characters[1])->Position.x, 1, 8);
	dynamic_cast<CMonster*>(m_Characters[1])->Position.y = m_map->clamp(dynamic_cast<CMonster*>(m_Characters[1])->Position.y, 1, 8);

}

