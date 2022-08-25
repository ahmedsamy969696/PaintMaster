#include "AddCopyAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCopyAction::AddCopyAction(ApplicationManager* pApp) :Action(pApp)
{}


void AddCopyAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pManager->setCopied(pManager->getSelected());
	pOut->PrintMessage("Selected Object Is copied");
}

//Execute the action
void AddCopyAction::Execute()
{
	ReadActionParameters();
}
