#pragma once
#ifndef ADD_PASTE_ACTION_H
#define ADD_PASTE_ACTION_H

#include "Action.h"
#include "../Figures/CFigure.h"

//Add Rectangle Action class
class AddActionChangeBorder : public Action
{
private:
	ApplicationManager* pApp;
	Point P;
public:
	AddActionChangeBorder(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif
