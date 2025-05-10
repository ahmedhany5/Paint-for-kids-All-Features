#pragma once

#include "Action.h"
#include "../ApplicationManager.h"

class Copy : public Action
{
	Point p;
public:
	Copy(ApplicationManager* pAppManager);

	
	virtual void ReadActionParameters();

	
	virtual bool Execute();



};

