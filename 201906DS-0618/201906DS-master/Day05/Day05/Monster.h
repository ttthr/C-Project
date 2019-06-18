#pragma once
#include "Character.h"
class Monster : public Character
{
public:
	Monster();
	Monster(class Map* const newMap);

	virtual ~Monster();

	virtual void Tick() override;
	virtual void Render() override;

protected:
	virtual void Move() override;
	class Map* mapData;
};

