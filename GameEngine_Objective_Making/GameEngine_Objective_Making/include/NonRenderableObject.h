#pragma once
#include "Object.h"
#include "IUpdater.h"
#include "CompositeObject.h"

class NonRenderableObject :public Object, public IUpdater, public CompositeObject
{
public:
	virtual void init() {}
	virtual void renderer() {}
	virtual void shutDown() override {}
	virtual void update() override {}
};