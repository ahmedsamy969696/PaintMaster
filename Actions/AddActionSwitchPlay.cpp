#include "AddActionSwitchPlay.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSwitchPlayAction::AddSwitchPlayAction(ApplicationManager* pApp) :Action(pApp)
{}


void AddSwitchPlayAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Play Mode");
	pOut->CreatePlayToolBar();

}

//Execute the action
void AddSwitchPlayAction::Execute()
{
	ReadActionParameters();
}
