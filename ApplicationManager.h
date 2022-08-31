#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* selected[MaxFigCount];
	CFigure* copiedFigures[MaxFigCount];
	int selectedcounter;
	int copiedcounter;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	
public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	int getFigCount();
	int mode;
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void SelectFigure(CFigure* pFig, int& c);
	int getshape(CFigure*& r, int x, int y);
	void Change_Current();
	void setSelected();
	void setCopied();
	void setCut();
	void setDelete();
	CFigure** getSelected();
	CFigure** getCopied();
	int getSelectedCount();
	int getCopiedCounter();
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
};

#endif