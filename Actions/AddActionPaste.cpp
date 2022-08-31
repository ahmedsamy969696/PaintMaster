#include "AddActionPaste.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddActionChangeBorder::AddActionChangeBorder(ApplicationManager* pApp) :Action(pApp)
{
	this->pApp = pApp;
}


void AddActionChangeBorder::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click At The Location you want to paste the items at");

	//Read 1 Center and store in point and Radius.
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
}

//Execute the action
void AddActionChangeBorder::Execute()
{
	int copiedCounter = pApp->getCopiedCounter();
	CFigure** FiguresCopied = pApp->getCopied();
	for (int i = 0; i < copiedCounter; i++) {
		CCircle* posscir = dynamic_cast<CCircle*>(FiguresCopied[i]);
		if (posscir != NULL) {
			Point orgcen = posscir->getCenter();
			Point orgrad = posscir->getRadius();

		}
	}
	pApp->setSelected();
}
