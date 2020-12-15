#pragma once
#include <iostream>

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/gtc/matrix_transform.hpp"

#include "Object.h"
#include "ICleanUp.h"
#include "IRenderer.h"
//#include "RenderableObject.h"
#include "NonRenderableObject.h"
#include "ControlableObject.h"
#include "Template.h"

class RenderableObject;

class Renderer : public Template
{
public:
	GLFWwindow* window;
	ControlableObject* control;

	std::vector<RenderableObject*> _renderingObject;
	std::vector<NonRenderableObject*> _nonRenderingObject;

	GLuint programID;

	static Renderer* instance()
	{
		static Renderer instance;
		return &instance;
	}

	virtual void init();
	virtual void render();
	virtual void update();//렌더되지 않은 걸 업데이트 해주는 멤버함수
	virtual void shutDown() override;
	
	void addObject(RenderableObject* src_obj);
	void addObject(NonRenderableObject* src_obj);

	GLuint GetProgramID() { return programID; }
};
