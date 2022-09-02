#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label+= Key;
		pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_TRIG: return DRAW_TRIG;
			case ITM_LINE: return DRAW_LINE;
			case ITM_SELECT: return SELECT_FIGURE;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_CHANGE_CURRENT: return CHNG_DEFAULT;
			case ITM_PASTE: return PASTE;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_EXIT: return EXIT;	
			case ITM_PLAY: return TO_PLAY;
			case ITM_DELETE: return DELETEE;
			case ITM_CHANGE_COLOR: return CHNG_DRAW_CLR;
			case ITM_CHANGE_FILL: return CHNG_FILL_CLR;
			case ITM_CHNG_BORDER: return CHNG_BORDER;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_PLAY)	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action

		int x, y;
		pWind->WaitMouseClick(x, y);

		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_DRAW: return DRAW_MODE;
			case ITM_RESTART: return RESTART;
			case ITM_TYPE_PICK_HIDE: return TYPE_PICK_HIDE;
			case ITM_FILL_PICK_HIDE: return FILL_PICK_HIDE;
			case ITM_BOTH_PICK_HIDE: return BOTH_PICK_HIDE;
				//case ITM_EXIT_EXIT: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}

		}
	}
	else if (UI.InterfaceMode == MODE_CHN_COLOR)	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action

		int x, y;
		pWind->WaitMouseClick(x, y);

		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{

				case ITM_RED: return CLR_RED;
				case ITM_BLUE: return CLR_BLUE;
				case ITM_YELLOW: return CLR_YELLOW;
				case ITM_DRAW_MODE: return DRAW_MODE;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}

		}
	}

}
/////////////////////////////////
	
string Input::getUIMode() {
	if (UI.InterfaceMode == MODE_PLAY) {
		return "play";
	}
	else {
		return "draw";
	}
}

Input::~Input()
{
}
