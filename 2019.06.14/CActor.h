#pragma once
class CActor
{
public:
	CActor();
	virtual ~CActor();
public:
	virtual void Tick() = 0; //���������Լ�
	virtual void Render() = 0; //���������Լ�

};

