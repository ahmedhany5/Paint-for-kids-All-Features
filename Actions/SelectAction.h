#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

class SelectAction : public Action
{
    Point P;
    CFigure* Figure;

public:
    SelectAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();
    virtual bool Execute();

};

