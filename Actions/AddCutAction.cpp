#include "AddCutAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCutAction::AddCutAction(ApplicationManager* pApp) :Action(pApp)
{}


void AddCutAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pManager->setCut();
	pOut->PrintMessage("Selected Object Is cutted");
}

//Execute the action
void AddCutAction::Execute()
{
	ReadActionParameters();
}
