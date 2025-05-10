

#include "Action.h"
#include "../ApplicationManager.h"

class Paste :public Action {
	Point p;
public:
	Paste(ApplicationManager* pAppManager);


	virtual void ReadActionParameters();

	bool  Execute();
};

