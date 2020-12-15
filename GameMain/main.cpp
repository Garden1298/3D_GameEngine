#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "GL/glew.h"		
#include "GLFW/glfw3.h" 
#include "../glm/glm.hpp"
#include "Object.h"
#include "RenderableObject.h"
#include "NonRenderableObject.h"
#include "Renderer.h"
#include "FileManager.h"
#include "NonRenderSample.h"
#include "ControlableObject.h"
#include "Time.h"
#include "CompositeObject.h"

using namespace glm;

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

//#include "OpenGL32.lib"
//#include "../lib-vc2017/glew32.lib"
//#include "../lib-vc2017/glfw3.lib"
 
int main()
{
	FileManager* file_mgr = FileManager::instance();

	Renderer* renderer = Renderer::instance();
	renderer->init();

	Time* time = Time::instance();

	CompositeObject* player = new CompositeObject();

	ControlableObject* character = new ControlableObject();
	renderer->addObject(character);
	character->setPosition(glm::vec3(1.0f, 5.0f, 1.0f));
	file_mgr->loadObj(
		character,
		"cube.obj",
		"uvtemplate.DDS",
		"vs.shader",
		"fs.shader",
		renderer);

	RenderableObject* bullet = new RenderableObject();
	renderer->addObject(bullet);
	bullet->setPosition(glm::vec3(1.0f, 5.0f, 3.0f));
	file_mgr->loadObj(
		bullet,
		"cube.obj",
		"uvtemplate.DDS",
		"vs.shader",
		"fs.shader",
		renderer);

	player->add(character);
	player->add(bullet);

	while (true)
	{
		//고정
		if (time->isUpdateTiming())
		{
			renderer->update();
			character->computeMatricesFromInputs(renderer->window,character);		
		}

		//가변
		renderer->render();
	}

	renderer->shutDown();

	delete bullet;
	delete character;

	return 0; 
}