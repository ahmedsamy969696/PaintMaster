#include "AddChangeColorBar.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddColorChangeBarAction::AddColorChangeBarAction(ApplicationManager* pApp) :Action(pApp)
{}


void AddColorChangeBarAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Change Color");
	pOut->CreateChangeColorBar();
	
}

//Execute the action
void AddColorChangeBarAction::Execute()
{
	ReadActionParameters();
	pManager->UpdateInterface();
}
