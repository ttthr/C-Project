#include <stdio.h>
#include "Engine.h"
#include "MyEngine.h"

int main()
{
	Engine* engine = new MyEngine();

	engine->Run();

	delete engine;
	engine = nullptr;

	return 0;
}
//
//C++
//Hello World
//���� ȯ�� ����
//������ ���α׷� �� ���α׷� ����
//
//���
//�ڷ���
//������
//����
//�迭
//�ݺ���
//���ǹ�
//������
//�Լ�
//Ŭ����
//Ŭ���� ���� ���
//�����͸𵨸�
//���� �����
//���
//������(�������̵�, virtual, override)
//Ŭ���� ����(is a, has a)
//const, overload
//���� ���� ����
//While(1)
//{
//	Input()
//		Tick()
//		Redner()
//}
//
//
//
//
