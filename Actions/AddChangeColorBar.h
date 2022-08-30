#pragma once
#ifndef ADD_CHANGE_FILL_COLOR_ACTION_H
#define ADD_CHANGE_FILL_COLOR_ACTION_H

#include "Action.h"
#include "../Figures/CFigure.h"

//Add Rectangle Action class
class AddColorChangeBarAction : public Action
{
public:
	AddColorChangeBarAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif
