#pragma once
#pragma once
#ifndef ADD_CHANGE_CURRENT_ACTION_H
#define ADD_CHANGE_CURRENT_ACTION_H

#include "Actions/Action.h"

//Add Changing Action class
class AddChangeCurrentAction : public Action
{
private:
	Point P1; //the selected point inside the shape
	GfxInfo SelectedGfxInfo;
public:
	static int c;
	AddChangeCurrentAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();


	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif