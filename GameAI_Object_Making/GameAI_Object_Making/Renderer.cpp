#include "Renderer.h"

void Renderer::init()
{
	_renderingObject = new std::vector<IRenderer*>(10);

	if (!glfwInit()) {
		std::cout << "GLFW 초기화 실패" << '\n';
		getchar();
		exit(-1);
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(
		1024, // width
		768, // height
		"GameArc_CT_Objective",
		NULL,
		NULL);

	if (!window)
	{
		std::cerr << "윈도우 생성 실패" << '\n';
		getchar();
		glfwTerminate();
		exit(-1);
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		std::cerr << "GLEW 초기화 실패 " << glewGetErrorString(err) << '\n';
		getchar();
		glfwTerminate();
		exit(-1);
	}

	//ESC키 누르는 걸 확인하기 위함
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	//마우스 포인터 숨기고, 움직임 비활성화
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//마우스가 화면의 중심에 오게
	glfwPollEvents();
	glfwSetCursorPos(window, 1024 / 2, 768 / 2);

	//화면 하얗게 채우기
	glClearColor(1, 1, 1, 1);

	// depth test
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	//culling
	glEnable(GL_CULL_FACE);

}

void Renderer::render()
{
	for (std::vector<RenderableObject*>::iterator iter = _OBJ.begin(); iter != _OBJ.end(); iter++)
	{
		//화면 지우기
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//쉐이더 사용
		glUseProgram((*iter)->programID);

		glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
		glm::mat4 View = glm::lookAt(
			glm::vec3(-3, 3, 5),
			glm::vec3(0, 0, 0),
			glm::vec3(0, 1, 0)
		);

		glm::mat4 Model = glm::mat4(1.0f);
		glm::mat4 MVP = Projection * View * Model;	//카메라 설정

		glUniformMatrix4fv((*iter)->MatrixID, 1, GL_FALSE, &MVP[0][0]);
		glUniformMatrix4fv((*iter)->ModelMatrixID, 1, GL_FALSE, &Model[0][0]);
		glUniformMatrix4fv((*iter)->ViewMatrixID, 1, GL_FALSE, &View[0][0]);

		glm::vec3 lightPos = glm::vec3(0, 0, 10);
		glUniform3f((*iter)->LightID, lightPos.x, lightPos.y, lightPos.z);

		// Bind our texture in Texture Unit 0
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, (*iter)->Texture);
		// Set our "myTextureSampler" sampler to use Texture Unit 0
		glUniform1i((*iter)->TextureID, 0);

		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, (*iter)->vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		// 2nd attribute buffer : UVs
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, (*iter)->uvbuffer);
		glVertexAttribPointer(
			1,                                // attribute
			2,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

		// 3rd attribute buffer : normals
		glEnableVertexAttribArray(2);
		glBindBuffer(GL_ARRAY_BUFFER, (*iter)->normalbuffer);
		glVertexAttribPointer(
			2,                                // attribute
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

		// Draw the triangles !
		glDrawArrays(GL_TRIANGLES, 0, (*iter)->vertices.size());

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

//void Renderer::renderer(RenderableObject* render_obj) 
//{
//	//화면 지우기
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	//쉐이더 사용
//	glUseProgram(render_obj->programID);
//
//	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
//	glm::mat4 View = glm::lookAt(
//		glm::vec3(-3, 3, 5),
//		glm::vec3(0, 0, 0),
//		glm::vec3(0, 1, 0)
//	);
//	glm::mat4 Model = glm::mat4(1.0f);
//	glm::mat4 MVP = Projection * View * Model;	//카메라 설정
//
//	glUniformMatrix4fv(render_obj->MatrixID, 1, GL_FALSE, &MVP[0][0]);
//	glUniformMatrix4fv(render_obj->ModelMatrixID, 1, GL_FALSE, &Model[0][0]);
//	glUniformMatrix4fv(render_obj->ViewMatrixID, 1, GL_FALSE, &View[0][0]);
//
//	glm::vec3 lightPos = glm::vec3(0, 0, 10);
//	glUniform3f(render_obj -> LightID, lightPos.x, lightPos.y, lightPos.z);
//
//
//
//
//
//
//	// Bind our texture in Texture Unit 0
//	glActiveTexture(GL_TEXTURE0);
//	glBindTexture(GL_TEXTURE_2D, render_obj->Texture);
//	// Set our "myTextureSampler" sampler to use Texture Unit 0
//	glUniform1i(render_obj->TextureID, 0);
//
//	// 1rst attribute buffer : vertices
//	glEnableVertexAttribArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, render_obj->vertexbuffer);
//	glVertexAttribPointer(
//		0,                  // attribute
//		3,                  // size
//		GL_FLOAT,           // type
//		GL_FALSE,           // normalized?
//		0,                  // stride
//		(void*)0            // array buffer offset
//	);
//
//	// 2nd attribute buffer : UVs
//	glEnableVertexAttribArray(1);
//	glBindBuffer(GL_ARRAY_BUFFER, render_obj->uvbuffer);
//	glVertexAttribPointer(
//		1,                                // attribute
//		2,                                // size
//		GL_FLOAT,                         // type
//		GL_FALSE,                         // normalized?
//		0,                                // stride
//		(void*)0                          // array buffer offset
//	);
//
//	// 3rd attribute buffer : normals
//	glEnableVertexAttribArray(2);
//	glBindBuffer(GL_ARRAY_BUFFER, render_obj->normalbuffer);
//	glVertexAttribPointer(
//		2,                                // attribute
//		3,                                // size
//		GL_FLOAT,                         // type
//		GL_FALSE,                         // normalized?
//		0,                                // stride
//		(void*)0                          // array buffer offset
//	);
//
//	// Draw the triangles !
//	glDrawArrays(GL_TRIANGLES, 0, render_obj->vertices.size());
//
//	glDisableVertexAttribArray(0);
//	glDisableVertexAttribArray(1);
//	glDisableVertexAttribArray(2);
//
//	// Swap buffers
//	glfwSwapBuffers(window);
//	glfwPollEvents();
//
//}

//void Renderer::addObject(IRenderer* src_obj)
//{
//	_renderingObject->push_back(src_obj);
//}

void Renderer::addObject(RenderableObject* src_obj)
{
	_OBJ.push_back(src_obj);
}

void Renderer::update(IUpdater* src_obj)
{
	src_obj->update();
}

void Renderer::shutDown()
{

	for (std::vector<RenderableObject*>::iterator iter = _OBJ.begin(); iter != _OBJ.end(); iter++)
	{
		(*iter)->shutDown();
	}

	delete _renderingObject;

	glfwTerminate();
}