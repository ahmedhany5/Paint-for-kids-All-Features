#pragma once
#ifndef Bring_To_Forward_Action_H
#define BRING_TO_FORWARD_ACTION_H
#include "Action.h"
#include "../ApplicationManager.h"
#include <iostream>

class BringToForwardAction : public Action			//BringToForwardAction class inherites from action class
{
public:
	BringToForwardAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();				//Reads the parameters to execute
	virtual bool Execute();								//Add bring to forward to the ApplicationManager to execute the action 
};
#endif