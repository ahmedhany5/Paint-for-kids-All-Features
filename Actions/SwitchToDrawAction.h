#pragma once
#include "Action.h"

class SwitchToDrawAction : public Action
{
public:
	SwitchToDrawAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual bool Execute();
};

