#pragma once

#include "Action.h"
#include "../ApplicationManager.h"

class Delete : public Action
{
	Point p;

public:
	Delete(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual bool Execute();

};
