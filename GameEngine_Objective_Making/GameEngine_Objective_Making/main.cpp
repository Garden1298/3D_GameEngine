//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//
//#include "include/GL/glew.h"		
//#include "include/GLFW/glfw3.h" 
//#include "glm/glm.hpp"
//#include "include/Object.h"
//#include "include/RenderableObject.h"
//#include "include/NonRenderableObject.h"
//#include "include/Renderer.h"
//#include "include/FileManager.h"
//#include "include/NonRenderSample.h"
//#include "include/ControlableObject.h"
//#include "include/Time.h"
//#include "include/CompositeObject.h"
//
//using namespace glm;
//
//#pragma comment(lib, "OpenGL32.lib")
//#pragma comment(lib, "lib-vc2017/glew32.lib")
//#pragma comment(lib, "lib-vc2017/glfw3.lib")
// 
//int main()
//{
//	FileManager* file_mgr = FileManager::instance();
//
//	Renderer* renderer = Renderer::instance();
//	renderer->init();
//
//	Time* time = Time::instance();
//
//	CompositeObject* player = new CompositeObject();
//
//	ControlableObject* character = new ControlableObject();
//	renderer->addObject(character);
//	character->setPosition(glm::vec3(1.0f, 5.0f, 1.0f));
//	file_mgr->loadObj(
//		character,
//		"cube.obj",
//		"uvtemplate.DDS",
//		"vs.shader",
//		"fs.shader",
//		renderer);
//
//	RenderableObject* bullet = new RenderableObject();
//	renderer->addObject(bullet);
//	bullet->setPosition(glm::vec3(1.0f, 5.0f, 3.0f));
//	file_mgr->loadObj(
//		bullet,
//		"cube.obj",
//		"uvtemplate.DDS",
//		"vs.shader",
//		"fs.shader",
//		renderer);
//
//	player->add(character);
//	player->add(bullet);
//
//	while (true)
//	{
//		//����
//		if (time->isUpdateTiming())
//		{
//			renderer->update();
//			character->computeMatricesFromInputs(renderer->window,character);		
//		}
//
//		//����
//		renderer->render();
//	}
//
//	renderer->shutDown();
//
//	delete bullet;
//	delete character;
//
//	return 0; 
//}