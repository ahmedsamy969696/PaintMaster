#include "AddActionPaste.h"
#include "..\Figures\CRectangle.h"
#include "AddActionPaste.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>

AddActionPaste::AddActionPaste(ApplicationManager* pApp) :Action(pApp)
{
	this->pApp = pApp;
}

void AddActionPaste::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click At The Location you want to paste the items at");

	//Read 1 Center and store in point and Radius.
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
}

//Execute the action
void AddActionPaste::Execute()
{
	ReadActionParameters();
	int copiedCounter = pApp->getCopiedCounter();
	CFigure** FiguresCopied = pApp->getCopied();
	Point refPoint;
	for (int i = 0; i < copiedCounter; i++) {
		//std::cout << FiguresCopied[i]->print();;
		CCircle* posscir = dynamic_cast<CCircle*>(FiguresCopied[i]);
		CRectangle* possrect = dynamic_cast<CRectangle*>(FiguresCopied[i]);
		CTriangle* posstrig = dynamic_cast<CTriangle*>(FiguresCopied[i]);
		CLine* possline = dynamic_cast<CLine*>(FiguresCopied[i]);
		if (posscir != NULL) {
			if (i == 0) {
				refPoint = posscir->getCenter();
			}
			Point orgcen = posscir->getCenter();
			int orgrad = posscir->getRadius();
			GfxInfo inf = posscir->getGfxInfo();
			Point newcen;
			Point diff = { refPoint.x - orgcen.x,refPoint.y - orgcen.y };
			newcen.x = P.x - diff.x;
			newcen.y = P.y - diff.y;
			Point newrad = { newcen.x + orgrad,newcen.y};
			CCircle* newCir = new CCircle(newcen, newrad, inf);
			pManager->AddFigure(newCir);
		}
		if (possrect != NULL) {
			if (i == 0) {
				refPoint = possrect->getCorner2();
			}
			Point A = possrect->getCorner1();
			Point B = possrect->getCorner2();
			Point diff = { refPoint.x - B.x,refPoint.y - B.y };
			Point newCorner2 = { P.x - diff.x,P.y - diff.y };
			Point diffdiff = { P.x - B.x, P.y - B.y };
			Point d = { A.x + diffdiff.x - diff.x,A.y + diffdiff.y - diff.y };
			GfxInfo inf = possrect->getGfxInfo();
			CRectangle* R = new CRectangle(d, newCorner2, inf); //Create a rectangle with the parameters read from the user
			pManager->AddFigure(R);  //Add the rectangle to the list of figures
		}
		if (posstrig != NULL) {
			if (i == 0) {
				refPoint = posstrig->getCorner3();
			}
			Point A = posstrig->getCorner1();
			Point B = posstrig->getCorner2();
			Point C = posstrig->getCorner3();
			Point diff = { refPoint.x - C.x,refPoint.y - C.y };
			Point newCorner2 = { P.x - diff.x,P.y - diff.y };
			Point diffdiff = { P.x - C.x, P.y - C.y };
			Point d = { A.x + diffdiff.x-diff.x,A.y + diffdiff.y -diff.y};
			Point e = { B.x + diffdiff.x - diff.x,B.y + diffdiff.y - diff.y };
			GfxInfo inf = posstrig->getGfxInfo();
			CTriangle* T = new CTriangle(d, e, newCorner2, inf); //Create a rectangle with the parameters read from the user
			pManager->AddFigure(T);  //Add the rectangle to the list of figures
		}
		if (possline != NULL) {
			if (i == 0) {
				refPoint = possline->getP1();
			}
			Point A = possline->getP1();
			Point B = possline->getP2();
			Point diff = { refPoint.x - A.x,refPoint.y - A.y };
			Point newCorner2 = { P.x - diff.x,P.y - diff.y };
			Point diffdiff = { P.x - A.x, P.y - A.y };
			Point d = { B.x + diffdiff.x - diff.x,B.y + diffdiff.y - diff.y };
			GfxInfo inf = possline->getGfxInfo();
			CLine* L = new CLine(newCorner2, d,inf);
			pManager->AddFigure(L);
		}
	}
	pApp->setSelected();
}
