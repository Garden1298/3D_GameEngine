#pragma once
#include <vector>

#include "../glm/glm.hpp"
#include "../include/GL/glew.h"
#include "../glm/gtc/matrix_transform.hpp"

#include "ICleanUp.h"
#include "Template.h"

class Object : public Template
{
public:
	virtual ~Object() {}

	virtual void init() {}
	virtual void renderer() {}
	virtual void update() {}
	virtual void shutDown() {}
};