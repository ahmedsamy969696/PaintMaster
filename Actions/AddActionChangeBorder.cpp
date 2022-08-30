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
	CFigure** FiguresSelected = pManager->getSelected();
	int selectCount = pManager->getSelectedCount();
	for (int i = 0; i < selectCount; i++) {
		FiguresSelected[i]->ChngDrawClr(RED);
		FiguresSelected[i]->SetSelected(false);
	}
	pApp->setSelected();
}
