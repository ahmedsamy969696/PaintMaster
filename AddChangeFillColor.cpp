#include "AddChangeFillColor.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddChangeFillAction::AddChangeFillAction(ApplicationManager* pApp) :Action(pApp)
{}


void AddChangeFillAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pManager->setCopied(pManager->getSelected());
	pOut->PrintMessage("Selected Object Is copied");
}

//Execute the action
void AddChangeFillAction::Execute()
{
	ReadActionParameters();
}
