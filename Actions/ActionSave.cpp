#include "ActionSave.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

ActionSave::ActionSave(ApplicationManager* pApp, int FigCount) :Action(pApp)
{
	FileName = "DRAW";
	FigCnt = FigCount;
}

void ActionSave::ReadActionParameters()
{
	string FillCol;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please write the file name then press ENTER");
	FileName = pIn->GetSrting(pOut);  //read the file name

	ofstream OutFile;
	OutFile.open(FileName + ".txt");  // create a file with FileName and .txt exetention

	while (OutFile.fail())
	{
		pOut->PrintMessage("Please write a valid name then press ENTER");
		FileName = pIn->GetSrting(pOut);
		OutFile.open(FileName + ".txt");
		if (OutFile.good())
			break;
	}

	if (UI.FillColor == NULL)
	{
		FillCol = "NO_FILL";
	}
	else {
		FillCol = pManager->ConvertToString(UI.FillColor);
	}
	OutFile << pManager->ConvertToString(UI.DrawColor)
		<< "\t" << FillCol
		<< "\t" << pManager->ConvertToString(UI.BkGrndColor)
		<< "\n";  //Write the Current Draw Color 
	OutFile << FigCnt << "\n";  //and Current Fill Color and in the second line write the number of figures 
	OutFile << pManager->GetFigListData(); //Now Start Saving each figure proccess 
	pOut->PrintMessage("Drawing SAVED");  //Done
	OutFile.close(); //close the file 
	pManager->savethis = true;
}

//Execute the action
void ActionSave::Execute()
{
	
	ReadActionParameters();

}
