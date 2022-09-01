#include "AddTrigAction.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddtrigAction::AddtrigAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddtrigAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P3.x, P3.y);

	if (UI.FillColor == NULL) {
		TrigGfxInfo.isFilled = false;
	}
	else {
		TrigGfxInfo.isFilled = true;
	}
	//get drawing, filling colors and pen width from the interface
	TrigGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TrigGfxInfo.FillClr = pOut->getCrntFillColor();
	TrigGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddtrigAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Triangle with the parameters read from the user
	CTriangle* T = new CTriangle(P1, P2, P3, TrigGfxInfo);

	//Add the Triangle to the list of figures
	pManager->AddFigure(T);
}
