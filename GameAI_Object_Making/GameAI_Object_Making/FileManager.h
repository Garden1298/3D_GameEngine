#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "include/GL/glew.h"

#include "Object.h"
#include "RenderableObject.h"

using namespace std;

class FileManager
{
public:

	FileManager() {}

	//╫л╠шео фпео
	static FileManager* instance()
	{
		static FileManager instance;
		return &instance;
	}

	void loadObj(
		RenderableObject* target_obj,
		std::string obj_path,
		std::string texture_path,
		std::string vs_shader_path,
		std::string fs_shader_path);

	bool loadOBJ(
		const char* path,
		std::vector<glm::vec3>& out_vertices,
		std::vector<glm::vec2>& out_uvs,
		std::vector<glm::vec3>& out_normals);

	GLuint loadDDS(const char* imagepath);

	vector<string> csv_read_row(istream& _file, char delimiter);
	void loadCSVFile(const string _fileName, GLfloat* array);

	GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);
};

