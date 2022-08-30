#pragma once
#ifndef ADD_CHANGE_COLOR_ACTION_H
#define ADD_CHANGE_COLOR_ACTION_H

#include "Action.h"
#include "../Figures/CFigure.h"

//Add Rectangle Action class
class AddColorChangeAction : public Action
{
private:
	int colorNum;
	int mode;
	ApplicationManager* pApp;
public:
	AddColorChangeAction(ApplicationManager* pApp,int mode,int colorNum);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif
