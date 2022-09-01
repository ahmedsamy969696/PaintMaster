#include "ActionChangeDefault.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddChangeDefaultAction::AddChangeDefaultAction(ApplicationManager* pApp) :Action(pApp)
{
	this->pApp = pApp;
}


void AddChangeDefaultAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter Default Boarder Color(red,blue,yellow,green)");
	string brdrclrstr = pIn->GetSrting(pOut);
	pOut->PrintMessage("Enter Default Fill Color(red,blue,yellow,green)");
	string fillclrstr = pIn->GetSrting(pOut);
	pOut->PrintMessage("Enter Default Border Width");
	brdrwdth = stoi(pIn->GetSrting(pOut));
	brdrclr = pApp->ConvertToColor(brdrclrstr);
	fillclr = pApp->ConvertToColor(fillclrstr);
}

//Execute the action
void AddChangeDefaultAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->setCrntBrdrWidth(brdrwdth);
	pOut->setCrntDrawColor(brdrclr);
	pOut->setCrntFillColor(fillclr);
}
