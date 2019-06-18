#pragma once
class Actor
{
public:
	Actor();
	virtual ~Actor();

	virtual void Tick() = 0;
	virtual void Render() = 0;

};

