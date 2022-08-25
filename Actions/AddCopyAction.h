#pragma once
#ifndef ADD_COPY_ACTION_H
#define ADD_COPY_ACTION_H

#include "Action.h"

class AddCopyAction : public Action
{
public:
	AddCopyAction(ApplicationManager* pApp);

	//Do The copy command
	virtual void ReadActionParameters();
	virtual void Execute();

};

#endif