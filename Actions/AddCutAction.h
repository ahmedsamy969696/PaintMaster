#pragma once
#ifndef ADD_CUT_ACTION_H
#define ADD_CUT_ACTION_H

#include "Action.h"

class AddCutAction : public Action
{
public:
	AddCutAction(ApplicationManager* pApp);

	//Do The copy command
	virtual void ReadActionParameters();
	virtual void Execute();

};

#endif