#include "ApplicationManager.h"
#include <iostream>
#include "Actions\Action.h"
using namespace std;

int Action::op_num = 0;

int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the interface
		AppManager.UpdateInterface();	

	}while(ActType != EXIT);

	
	return 0;
}

