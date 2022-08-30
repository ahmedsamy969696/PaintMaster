#ifndef ADD_SWITCHPLAY_ACTION_H
#define ADD_SWITCHPLAY_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class AddSwitchPlayAction : public Action
{
public:
	AddSwitchPlayAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif
#pragma once
