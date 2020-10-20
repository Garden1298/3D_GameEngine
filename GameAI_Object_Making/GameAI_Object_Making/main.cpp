#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "include/GL/glew.h"		
#include "include/GLFW/glfw3.h" 

#include "glm/glm.hpp"

#include "Object.h"
#include "RenderableObject.h"
#include "NonRenderableObject.h"
#include "Renderer.h"
#include "FileManager.h"
#include "Sphere.h"
#include "NonRenderSample.h"

using namespace glm;

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")
 
int main()
{
	FileManager* file_mgr = FileManager::instance();

	Renderer* renderer = Renderer::instance();
	renderer->init();
	//renderer->setCameraPosition(glm::vec3(0.0f, 10.0f, 0.0f));

	RenderableObject* cube = new RenderableObject();
	renderer->addObject(cube);
	//cube->setPosition(glm::vec3(0.0f, 2.0f, 0.0f));

	file_mgr->loadObj(
		cube,
		"cube.obj",
		"uvtemplate.DDS",
		"vs.shader",
		"fs.shader");


	//Sphere* sphere = new Sphere();
	//renderer->addObject(sphere);

	NonRenderSample* non_render = new NonRenderSample();


	while (true)
	{
		renderer->update(non_render);
		renderer->render();
	}

	cube->shutDown();
	//sphere->shutDown();
	non_render->shutDown();

	renderer->shutDown();

	delete cube;
	//delete sphere;
	delete non_render;

	return 0; 
}