#include "AddActionChangeBorder.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddActionChangeBorder::AddActionChangeBorder(ApplicationManager* pApp) :Action(pApp)
{
	this->pApp = pApp;
}


void AddActionChangeBorder::ReadActionParameters() {

}

//Execute the action
void AddActionChangeBorder::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure** FiguresSelected = pManager->getSelected();
	pOut->PrintMessage("Please Enter the new border size");
	string width = pIn->GetSrting(pOut);
	int widtht = stoi(width);
	int selectCount = pManager->getSelectedCount();
	for (int i = 0; i < selectCount; i++) {
		FiguresSelected[i]->ChngBorderWidth(widtht);
		FiguresSelected[i]->SetSelected(false);
	}
	pApp->setSelected();
}
