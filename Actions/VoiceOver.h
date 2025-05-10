#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class VoiceOver : public Action
{
public:
	VoiceOver(ApplicationManager*);

	virtual void ReadActionParameters();
	virtual bool Execute();
};


