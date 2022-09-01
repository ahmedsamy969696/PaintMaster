#ifndef ADD_CHANGE_DEFAULT_ACTION_H
#define ADD_CHANGE_DEFAULT_ACTION_H

#include "Action.h"

class AddChangeDefaultAction : public Action
{
private:
	ApplicationManager* pApp;
	int brdrwdth;
	color brdrclr;
	color fillclr;
public:
	AddChangeDefaultAction(ApplicationManager* pApp);

	//Do The copy command
	virtual void ReadActionParameters();
	virtual void Execute();

};

#endif