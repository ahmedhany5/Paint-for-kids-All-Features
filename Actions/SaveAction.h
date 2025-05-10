#pragma once
#include "Action.h"-
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;

class SaveAction : public Action
{
	string FileName;

public:
	SaveAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual bool Execute();
};

