#pragma once
#ifndef CUT_H
#define CUT_H

#include "Actions/Action.h"
#include "ApplicationManager.h"

class Cut : public Action
{
	Point p;
public:
	Cut(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	bool Execute();



};
#endif