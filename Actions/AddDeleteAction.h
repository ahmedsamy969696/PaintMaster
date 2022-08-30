#pragma once
#ifndef ADD_DELETE_ACTION_H
#define ADD_DELETE_ACTION_H

#include "Action.h"

class AddDeleteAction : public Action
{
public:
	AddDeleteAction(ApplicationManager* pApp);

	//Do The copy command
	virtual void ReadActionParameters();
	virtual void Execute();

};

#endif