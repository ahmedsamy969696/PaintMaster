#ifndef ADD_SWITCHDRAW_ACTION_H
#define ADD_SWITCHDRAW_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class AddSwitchDrawAction : public Action
{
public:
	AddSwitchDrawAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif
