#include "AddSelectAction.h"
#include "Action.h"

#include "../ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

AddSelectAction::AddSelectAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	//pOut->PrintMessage("Selecting: Click at the desired shape.");
	

	//Read the point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->ClearStatusBar();

}

//Execute the action
int AddSelectAction::c = 0;
void AddSelectAction::Execute()
{
	CFigure* R;
	int temp;
	int co = 0;
	if (pManager->getFigCount() >= 1)
	{
		pManager->GetOutput()->PrintMessage("Selecting: Click at the desired shape.");
		//This action needs to read some parameters first
		do
		{
			ReadActionParameters();
			co++;
			temp = pManager->getshape(R, P1.x, P1.y);
		} while (temp == 0);
		//Select Figure
		pManager->SelectFigure(R, c);
	}
	else
	{
		pManager->GetOutput()->PrintMessage("Please, Create A Figure FIRST.");
	}
}
