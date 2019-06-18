#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player();
	Player(class Map* const newMap);
	virtual ~Player();

	virtual void Tick() override;
	virtual void Render() override;
protected:
	virtual void Move() override;
	class Map* mapData;
};

