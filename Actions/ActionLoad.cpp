#include "ActionLoad.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CCircle.h"
#include "../Figures/CLine.h"
#include "../Figures/CTriangle.h"
#include <fstream>
#include <iostream>

using namespace std;


ActionLoad::ActionLoad(ApplicationManager* pApp) :Action(pApp)
{


}

void ActionLoad::ReadActionParameters()
{

}

//Execute the action
void ActionLoad::Execute()
{
	ifstream InFile;         //object of ifstream class
	string name, DrawClr, FillClr, Background;
	int Cnt;
	CFigure* fig;

	Output* pOut = pManager->GetOutput();   //Get a pointer to the Output class
	Input* pIn = pManager->GetInput();     //Get a pointer to Input Class

	pOut->PrintMessage("Please write the file name :) ");
	FileName = pIn->GetSrting(pOut);     //get the file name

	InFile.open(FileName + ".txt"); //open the file on the disk with FileName name and .txt exetension
	pOut->ClearDrawArea();    //Clear current graph

	if (InFile.fail())       //Check if the FileName is a valid name
	{
		pOut->PrintMessage("Invalid Name");
		return;
	}
	InFile >> DrawClr >> FillClr >> Background;     //Read the Current FillColor and DrawColor
	UI.DrawColor = pManager->ConvertToColor(DrawClr);  //Convert them
	UI.FillColor = pManager->ConvertToColor(FillClr);  //To Color type
	UI.BkGrndColor = pManager->ConvertToColor(Background);
	pManager->LoadFig();        //Delete The figure list

	string str_cnt;

	InFile >> str_cnt;    //read the Number of Figures


	Cnt = stoi(str_cnt);


	int ID;
	Point X, Y, Z;
	string color1, color2;
	GfxInfo Info;
	Info.BorderWdth = 2;
	for (int i = 0; i < Cnt; i++) {
		InFile >> name;
		if (name == "RECT") {
			InFile >> ID;
			InFile >> X.x >> X.y >> Y.x >> Y.y >> color1 >> color2;
			color c1 = pManager->ConvertToColor(color1);
			color c2 = pManager->ConvertToColor(color2);
			Info.DrawClr = c1;
			if (color2 != "NO_FILL") {
				color c2 = pManager->ConvertToColor(color2);
				Info.FillClr = c2;
				Info.isFilled = true;
			}
			else {
				//color c2 = pManager->ConvertToColor("LIGHTGOLDENRODYELLOW");
				Info.isFilled = false;
				Info.FillClr = NULL;
			}

			fig = new CRectangle(X, Y, Info);
			pManager->AddFigure(fig);
		}

		else if (name == "LINE") {
			InFile >> ID;
			InFile >> X.x >> X.y >> Y.x >> Y.y >> color1 >> color2;
			color c1 = pManager->ConvertToColor(color1);
			//color c2 = pManager->ConvertToColor(color2);
			Info.DrawClr = c1;
			//Info.FillClr = c2;
			Info.isFilled = false;
			cout << "1st check!!  \n";
			fig = new CLine(X, Y, Info);
			pManager->AddFigure(fig);
			cout << "2nd check!!  \n";
		}
		else if (name == "TRIG") {
			InFile >> ID;
			InFile >> X.x >> X.y >> Y.x >> Y.y >> Z.x >> Z.y >> color1 >> color2;
			cout << "1st check!!  \n";
			color c1 = pManager->ConvertToColor(color1);
			Info.DrawClr = c1;
			if (color2 != "NO_FILL") {
				color c2 = pManager->ConvertToColor(color2);
				Info.FillClr = c2;
				Info.isFilled = true; 
			}
			else {
				//color c2 = pManager->ConvertToColor("LIGHTGOLDENRODYELLOW");
				Info.isFilled = false;
				Info.FillClr = NULL;
			}
			cout << "maybe!!  \n";
			fig = new CTriangle(X, Y, Z, Info);
			pManager->AddFigure(fig);
		}

		else if (name == "CIRC") {

			InFile >> ID;
			InFile >> X.x >> X.y >> Y.x >> Y.y >> color1 >> color2;
			color c1 = pManager->ConvertToColor(color1);
			cout << "\n look at this:  " << color2 << endl;
			if (color2 != "NO_FILL")
			{

				color c2 = pManager->ConvertToColor(color2);
				Info.isFilled = true;
				Info.FillClr = c2;
				cout << "do we reach here?  \n";
			}
			else {
				Info.isFilled = false;
				Info.FillClr = NULL;
				cout << "ok but do we reach here?  \n";
			}

			Info.DrawClr = c1;

			fig = new CCircle(X, Y, Info);
			pManager->AddFigure(fig);
		}

		//fig->Load(InFile);  //Now we created the object and we should load it
		//pManager->AddFigure(fig); //Add to the figure list
		//pManager->UpdateInterface();     //Draw the figure list
	}
	pManager->UpdateInterface();     //Draw the figure list
	cout << "3rd check!!  \n";
	pOut->PrintMessage("Drawing Loaded Successfully");
	pOut->ClearStatusBar();
	pOut->CreateStatusBar();

}
