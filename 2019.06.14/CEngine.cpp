#include "CEngine.h"

CEngine::CEngine()	

{
	Init(); //√ ±‚»≠
}

CEngine::~CEngine()
{
	Term(); // ªË¡¶
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
	//cout << "Tick µ—æÓ∞£¥Ÿ" << endl;

	switch (CurrentKeyInput)
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
	
	vector<CCharacter*>::iterator iter = m_Characters.begin();
	vector<CCharacter*>::iterator iter_end = m_Characters.end();

	for (iter; iter != iter_end; ++iter)
	{
		(*iter)->Tick();
	}

	m_Characters[0]->Position.x = m_map->clamp(m_Characters[0]->Position.x, 1, 8);
	m_Characters[0]->Position.y = m_map->clamp(m_Characters[0]->Position.y, 1, 8);

	
}


void CEngine::Render()
{
	//∏  ∑ª¥ı
	system("cls");

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{

			if (i == m_Characters[0]->Position.x && j == m_Characters[0]->Position.y)
				m_Characters[0]->Render();
			else
				cout << m_map->Data[i][j];

		}
		cout << endl;
	}
}

bool CEngine::GameLoop()
{
	while (bIsRunning)
	{
		input();
		Tick();
		Render();
		if (m_Characters[0]->Position.x == 8 && m_Characters[0]->Position.y == 8)
		{
			cout << "≈ª√‚" << endl;
			break;
		}
	}
	return false;
}

