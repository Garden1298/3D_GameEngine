#include "RenderableObject.h"
#include <iostream>
#include "Renderer.h"

void RenderableObject::shutDown()
{
	//Object::shutDown();

	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteBuffers(1, &elementbuffer);
	glDeleteTextures(1, &Texture);
	glDeleteVertexArrays(1, &VertexArrayID);
}

void RenderableObject::addObject(RenderableObject* obj)
{
	Renderer::instance()->addObject(obj);
}

//void loadOBJ(RenderableObject* target_obj,
//	std::string obj_path,
//	std::string texture_path,
//	std::string vs_shader_path,
//	std::string fs_shader_path,
//	Renderer* render_obj)
//{
//	FileManager::instance()->loadObj(target_obj,
//		obj_path, texture_path, vs_shader_path,
//		fs_shader_path, render_obj);
//}

void RenderableObject::setPosition(glm::vec3 position)
{
	modelMatrix = glm::mat4(1.0f);
	glm::mat4 translate = glm::mat4(1.0f);

	translate = glm::translate(translate, position);

	modelMatrix = translate * modelMatrix;

	std::cout << position.x<<position.y<<position.z<< std::endl;
}