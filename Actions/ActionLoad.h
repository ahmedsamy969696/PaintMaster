#pragma once
#ifndef ACTION_LOAD_H
#define ACTION_LOAD_H
#include"Action.h"
class ActionLoad :public Action
{
private:
	string FileName;

public:
	ActionLoad(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};
#endif