#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddTrigAction.h"
#include "Actions\AddLineAction.h"
#include "Actions/AddSelectAction.h"
#include "AddChangeCurrentAction.h"

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
		case CHNG_CURRENT:
			pAct = new AddChangeCurrentAction(this);
			break;
			///create AddLineAction here

			break;

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
