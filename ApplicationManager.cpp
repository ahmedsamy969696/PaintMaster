#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddTrigAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddCopyAction.h"
#include "Actions\AddCutAction.h"
#include "Actions\AddDeleteAction.h"
#include "Actions\AddActionSwitchPlay.h"
#include "Actions\AddChangeColorBar.h"
#include "Actions\AddChangeColor.h"
#include "Actions\AddDrawModeAction.h"
#include "Actions\AddActionChangeBorder.h"
#include "Actions\AddActionPaste.h"
#include "Actions/AddSelectAction.h"
#include "Figures\CRectangle.h"
#include "Figures\CCircle.h"
#include "Figures\CLine.h"
#include "Figures\CTriangle.h"
#include "AddChangeCurrentAction.h"
#include <iostream>

using namespace std;
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			break;
		case DRAW_TRIG:
			pAct = new AddtrigAction(this);
			break;
		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;
		case SELECT_FIGURE:
			pAct = new AddSelectAction(this);
			break;
		case COPY:
			pAct = new AddCopyAction(this);
			break;
		case CUT:
			pAct = new AddCutAction(this);
			break;
		case DELETEE:
			pAct = new AddDeleteAction(this);
			break;
		case TO_PLAY:
			pAct = new AddSwitchPlayAction(this);
			break;
		case CHNG_DRAW_CLR:
			mode = 0;
			pAct = new AddColorChangeBarAction(this);
			break;
		case CHNG_FILL_CLR:
			mode = 1;
			pAct = new AddColorChangeBarAction(this);
			break;
		case CLR_RED:
			pAct = new AddColorChangeAction(this,mode, 1);
			break;
		case CLR_YELLOW:
			pAct = new AddColorChangeAction(this,mode, 2);
			break;
		case CLR_BLUE:
			pAct = new AddColorChangeAction(this,mode ,3);
			break;
		case CHNG_BORDER:
			pAct = new AddActionChangeBorder(this);
			break;
		case DRAW_MODE:
			pAct = new AddSwitchDrawAction(this);
			break;
		case PASTE:
			pAct = new AddActionPaste(this);
			break;
		//case
			///create AddLineAction here

			//break;

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
int ApplicationManager::getFigCount()
{
	return FigCount;
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	///Add your code here to search for a figure given a point x,y	

	return NULL;
}

void ApplicationManager::SelectFigure(CFigure* pFig, int& c)
{
	CFigure* pselected; // to know the selected shape, if we unselect another shape.
	if (!pFig->IsSelected())
	{
		pFig->SetSelected(true);
		c++;
		if (c == 1)
		{
			pOut->PrintMessage(pFig->print());
		}
		else if (c > 1)
		{
			string val;
			val = to_string(c);
			pOut->PrintMessage("The number of selected shapes is: " + val);
		}
		else
		{
			pOut->ClearStatusBar();
		}
		//pFig->ChngFillClr('E');
	}
	else
	{
		pFig->SetSelected(false);
		c--;
		if (c == 1)
		{
			for (int i = 0; i < FigCount; i++)
			{
				if (FigList[i]->IsSelected())
				{
					pselected = FigList[i];
				}
			}
			pOut->PrintMessage(pselected->print());
		}
		else if (c > 1)
		{
			string val;
			val = to_string(c);
			pOut->PrintMessage("The number of selected shapes is " + val);
		}
		else
		{
			pOut->ClearStatusBar();
		}
	}
	setSelected();
}
int ApplicationManager::getshape(CFigure*& r, int x, int y)
{
	int temp = 0;
	for (int i = FigCount-1; i >=0; i--)
	{
		if (FigList[i]->IS_pin_shape(x, y))
		{
			r = FigList[i];
			temp = 1;
			return temp;
		}
	}
	pOut->PrintMessage("Click on a Valid Shape.");
	return temp;
}

void ApplicationManager::setSelected() {
	CFigure* selected[MaxFigCount];
	selectedcounter = 0;
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->IsSelected())
		{
			ApplicationManager::selected[selectedcounter] = FigList[i];
			selectedcounter += 1;
		}
	}
}

int ApplicationManager::getSelectedCount() {
	return selectedcounter;
}

CFigure** ApplicationManager::getSelected() {
	return selected;
}


void ApplicationManager::setCopied() {
	copiedFigures[MaxFigCount];
	copiedcounter = selectedcounter;
	for (int i = 0; i < selectedcounter; i++) {
		CCircle* posscir = dynamic_cast<CCircle*>(selected[i]);
		CRectangle* possrect = dynamic_cast<CRectangle*>(selected[i]);
		CTriangle* posstrig = dynamic_cast<CTriangle*>(selected[i]);
		CLine* possline = dynamic_cast<CLine*>(selected[i]);
		if (posscir != NULL) {
			Point orgcen = posscir->getCenter();
			Point orgrad = posscir->getradius();
			GfxInfo inf = posscir->getGfxInfo();
			CCircle* newCir = new CCircle(orgcen, orgrad, inf);
			copiedFigures[i] = newCir;
		}
		if (possrect != NULL) {
			Point A = possrect->getCorner1();
			Point B = possrect->getCorner2();
			GfxInfo inf = possrect->getGfxInfo();
			CRectangle* R = new CRectangle(A, B, inf);
			copiedFigures[i] = R;
		}
		if (posstrig != NULL) {
			Point A = posstrig->getCorner1();
			Point B = posstrig->getCorner2();
			Point C = posstrig->getCorner3();
			GfxInfo inf = posstrig->getGfxInfo();
			CTriangle* T = new CTriangle(A, B, C, inf);
			copiedFigures[i] = T;
		}
		if (possline != NULL) {
			Point A = possline->getP1();
			Point B = possline->getP2();
			GfxInfo inf = possline->getGfxInfo();
			CLine* L = new CLine(A, B, inf);
			copiedFigures[i] = L;
		}
	}
	for (int i = 0; i < selectedcounter; i++) {
		cout << copiedFigures[i]->print() << endl;
	}
}

int ApplicationManager::getCopiedCounter() {
	return copiedcounter;
}

CFigure** ApplicationManager::getCopied() {
	return copiedFigures;
}

void ApplicationManager::setDelete() {
	for (int j = 0; j < selectedcounter; j++) {
		for (int i = 0; i < FigCount; i++) {
			if (selected[j] == FigList[i])
			{
				delete FigList[i];
				FigList[i] = NULL;
				FigCount--;
				for (int k = i; k < FigCount; k++) {
					FigList[k] = FigList[k + 1];
				}
			}
		}
	}

	pOut->ClearDrawArea();
	UpdateInterface();
}

void ApplicationManager::setCut() {
	setCopied();
	for (int j = 0; j < selectedcounter; j++) {
		for (int i = 0; i < FigCount; i++) {
			if (selected[j] == FigList[i])
			{
				delete FigList[i];
				FigList[i] = NULL;
				FigCount--;
				for (int k = i; k < FigCount; k++) {
					FigList[k] = FigList[k + 1];
				}
			}
		}
	}
	pOut->ClearDrawArea();
	UpdateInterface();
}

void ApplicationManager::Change_Current()
{
	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }

////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
