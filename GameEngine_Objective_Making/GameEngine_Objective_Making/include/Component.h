#pragma once
#include "Object.h"

class Component: public Object
{
public:
	virtual ~Component() {};
	virtual void shutDown()override {};
};