#pragma once
class Template
{
public:
	//������Ʈ �ʱ�ȭ�� ���� ���ø�
	virtual void init() = 0;
	//������Ʈ �������� ����
	virtual void render() {};
	//������Ʈ�� ������Ʈ�� ����
	virtual void update() {};
	//������Ʈ�� �Ҹ�ó���� ����
	virtual void shutDown() = 0;
};

