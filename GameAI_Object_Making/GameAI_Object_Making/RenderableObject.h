#pragma once

#include "Object.h"
#include "IRenderer.h"

class RenderableObject :public Object, public IRenderer
{
public:
	//�����鿡 ���� ������
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint normalbuffer;
	GLuint colorbuffer;//

	GLuint VertexArrayID;
	GLuint programID;
	GLuint Texture;
	GLuint TextureID;
	GLuint LightID;

	GLuint MatrixID;//�����������
	GLuint ModelMatrixID;//�����������
	GLuint ViewMatrixID;//�����������

	virtual void shutDown() override;
	virtual void render() override {};
};
