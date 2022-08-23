#include "AddChangeCurrentAction.h"
#include "Actions/Action.h"

#include "ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

AddChangeCurrentAction::AddChangeCurrentAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddChangeCurrentAction::ReadActionParameters()
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
void AddChangeCurrentAction::Execute()
{

}
