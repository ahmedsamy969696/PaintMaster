#pragma once
#ifndef ACTION_SAVE_H
#define ACTION_SAVE_H
#include"..\Actions\Action.h"

class ActionSave :public Action
{
private:
	string FileName;
	int FigCnt;
public:
	ActionSave(ApplicationManager* pApp, int FigCount);

	virtual void ReadActionParameters();

	virtual void Execute();

};
#endif#pragma once
