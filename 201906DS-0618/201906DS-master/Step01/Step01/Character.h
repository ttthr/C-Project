#pragma once
class Character
{
public:
	Character();
	virtual ~Character();

	int Attack;
	int HP;
	int Speed;

	virtual void Move();
};

