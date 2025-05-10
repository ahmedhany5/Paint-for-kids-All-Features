#pragma once
#include "Action.h"
class LoadAction : public Action 
{
	std::string FileName;

public:
	LoadAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual bool Execute();
};
