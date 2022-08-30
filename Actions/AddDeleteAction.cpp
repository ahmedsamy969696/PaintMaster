#include "AddDeleteAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddDeleteAction::AddDeleteAction(ApplicationManager* pApp) :Action(pApp)
{}


void AddDeleteAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pManager->setDelete();
	pOut->PrintMessage("Selected Object Is Removed");
}

//Execute the action
void AddDeleteAction::Execute()
{
	ReadActionParameters();
}
