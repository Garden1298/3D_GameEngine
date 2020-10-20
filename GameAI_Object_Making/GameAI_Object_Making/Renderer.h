#pragma once
#include <iostream>

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 

#include "Object.h"
#include "ICleanUp.h"
#include "RenderableObject.h"
#include "NonRenderableObject.h"

class Renderer : public ICleanUp
{
private:

public:
	GLFWwindow* window;

	std::vector<IRenderer*>* _renderingObject;

	static Renderer* instance()
	{
		static Renderer instance;
		return &instance;
	}

	void init();
	void render();
	void renderer(RenderableObject* render_obj);
	void update(IUpdater* src_obj);//�������� ���� �� ������Ʈ ���ִ� ����Լ�
	void addObject(IRenderer* src_obj);
	virtual void shutDown() override;
};
