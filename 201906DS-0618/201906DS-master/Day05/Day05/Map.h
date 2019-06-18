#pragma once
#include "Actor.h"

class Map : public Actor
{
public:
	Map();
	~Map();
	enum class TYPE
	{
		EMPTY = 0,
		WALL = 1,
		START = 2,
		GOAL = 9
	};

	int Data[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 2, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 9, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};
	virtual void Tick() override;
	virtual void Render() override;

	class Vector FindPlayerPosition();
	class Vector FindMonsterPosition();
	

private:
	char GetMapTile(int Type);
};

