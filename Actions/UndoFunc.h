#ifndef UNDO_F
#define UNDO_F

#include "Action.h"
#include <string>
#include <iostream>
#include "..\ApplicationManager.h"
using namespace std;


//Add Rectangle Action class
class UndoFunc : public Action
{
private:
	string type;
public:
	UndoFunc(ApplicationManager* pApp) :Action(pApp) {
		
	}
	virtual void ReadActionParameters(){}

	virtual void Execute()
	{
		Output* pOut = pManager->GetOutput();
		int shapes = pManager->getFigCount() - 1;
		pManager->deletelastshape(shapes);
		cout << "1st Undo check\n";
		pOut->ClearDrawArea();
		cout << "2nd Undo check\n";
		pManager->UpdateInterface();


	}
};

#endif