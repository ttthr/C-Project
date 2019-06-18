#include "Map.h"
#include "Util.h"
#include "Vector.h"
#include <stdlib.h>
#include <time.h>



Map::Map()
{
}


Map::~Map()
{
}

void Map::Tick()
{
}

void Map::Render()
{
	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 10; ++x)
		{
			Util::SetXY(x, y);
			Util::SetObject(GetMapTile(Data[y][x]));
		}
	}
}

Vector Map::FindPlayerPosition()
{
	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 10; ++x)
		{
			if (Data[y][x] == 2)
			{
				Vector result;
				result.X = x;
				result.Y = y;
				return result;
			}
		}
	}
	return Vector();
}

Vector Map::FindMonsterPosition()
{
	srand((unsigned int)time(0));

	while (true)
	{
		int X = rand() % 10;
		int Y = rand() % 10;
		if (Data[Y][X] == 0)
		{
			Vector result;
			result.X = X;
			result.Y = Y;
			return result;
		}
	}

	return Vector();
}

char Map::GetMapTile(int Type)
{
	switch (Type)
	{
		case 0:
			return ' ';
			break;
		case 1:
			Util::TextColor(WHITE, BLACK);
			return '#';
			break;
		case 2:
			return ' ';
			break;
		case 9:
			Util::TextColor(YELLOW, BLACK);
			return '*';
			break;
	}

	return ' ';
}

