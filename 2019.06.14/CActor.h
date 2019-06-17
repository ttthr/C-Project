#pragma once
class CActor
{
public:
	CActor();
	virtual ~CActor();
public:
	virtual void Tick() = 0; //순수가상함수
	virtual void Render() = 0; //순수가상함수

};

