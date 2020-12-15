#pragma once
class Template
{
public:
	//오브젝트 초기화를 위한 템플릿
	virtual void init() = 0;
	//오브젝트 렌더링을 위함
	virtual void render() {};
	//오브젝트의 업데이트를 위함
	virtual void update() {};
	//오브젝트의 소멸처리를 위함
	virtual void shutDown() = 0;
};

