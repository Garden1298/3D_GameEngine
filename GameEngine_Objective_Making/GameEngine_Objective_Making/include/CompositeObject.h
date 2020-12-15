#pragma once
#include "Component.h"
#include "vector"

class CompositeObject:public Component
{
public:
	CompositeObject()
	{
		table_ = new std::vector<Component*>();
	}

	~CompositeObject()
	{
		for (
			std::vector<Component*>::const_iterator it = table_->begin();
			it != table_->end();
			++it
			)
		{
			delete (*it);
		}

		table_->clear();

		delete table_;
	}

	void add(Component* obj)
	{
		table_->push_back(obj);
	}

private:
	std::vector<Component*>* table_;
};