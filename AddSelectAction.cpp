#include "AddSelectAction.h"
#include "cSelect.h"

#include "ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

AddSelectAction::AddSelectAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Selecting: Click at the desired shape.");

	//Read the point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


}

//Execute the action
void AddSelectAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	CFigure* R;

	//Select Figure
	pManager->SelectFigure();
}
