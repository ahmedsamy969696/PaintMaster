#include "AddChangeColor.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddColorChangeAction::AddColorChangeAction(ApplicationManager* pApp,int mode,int colorNum) :Action(pApp)
{
	this->colorNum = colorNum;
	this->mode = mode;
	this->pApp = pApp;
}


void AddColorChangeAction::ReadActionParameters() {
	
}

//Execute the action
void AddColorChangeAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	CFigure** FiguresSelected = pManager->getSelected();
	int selectCount = pManager->getSelectedCount();
	if (mode == 0) {
		if (colorNum == 1) {
			for (int i = 0; i < selectCount; i++) {
				FiguresSelected[i]->ChngDrawClr(RED);
				FiguresSelected[i]->SetSelected(false);
				
			}
		}
		if (colorNum == 2) {
			for (int i = 0; i < selectCount; i++) {
				FiguresSelected[i]->ChngDrawClr(YELLOW);
				FiguresSelected[i]->SetSelected(false);
				
			}
		}
		if (colorNum == 3) {
			for (int i = 0; i < selectCount; i++) {
				FiguresSelected[i]->ChngDrawClr(BLUE);
				FiguresSelected[i]->SetSelected(false);
				
			}
		}
	}
	else if (mode == 1) {

		if (colorNum == 1) {
			for (int i = 0; i < selectCount; i++) {
				FiguresSelected[i]->ChngFillClr(RED);
				FiguresSelected[i]->SetSelected(false);
				
			}
		}
		if (colorNum == 2) {
			for (int i = 0; i < selectCount; i++) {
				FiguresSelected[i]->ChngFillClr(YELLOW);
				FiguresSelected[i]->SetSelected(false);
				

			}
		}
		if (colorNum == 3) {
			for (int i = 0; i < selectCount; i++) {
				FiguresSelected[i]->ChngFillClr(BLUE);
				FiguresSelected[i]->SetSelected(false);
				
			}
		}
	}
	pApp->setSelected();

}
