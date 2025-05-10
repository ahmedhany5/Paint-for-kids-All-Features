#pragma once
#ifndef SEND_TO_BACK_ACTION_H
#define SEND_TO_BACK_ACTION_H
#include "Action.h"
#include "../ApplicationManager.h"
#include <iostream>

class SendToBackAction : public Action					//SendToBackAction class inherites from action class
{
public:
	SendToBackAction(ApplicationManager* pApp);			
	virtual void ReadActionParameters();				//Reads the parameters to execute
	virtual bool Execute();								//Add send to back to the ApplicationManager to execute the action 
};
#endif
