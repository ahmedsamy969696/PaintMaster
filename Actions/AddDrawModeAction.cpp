#include "AddDrawModeAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSwitchDrawAction::AddSwitchDrawAction(ApplicationManager* pApp) :Action(pApp)
{}


void AddSwitchDrawAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Draw Mode");
	pOut->CreateDrawToolBar();

}

//Execute the action
void AddSwitchDrawAction::Execute()
{
	ReadActionParameters();
}
