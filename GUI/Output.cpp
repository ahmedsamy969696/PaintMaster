#include "Output.h"
#include "..\ApplicationManager.h"

Output::Output()
{
	// Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	UI.width = 1600;
	UI.height = 700;
	UI.wx = 5;
	UI.wy = 5;

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;

	UI.DrawColor = BLUE;				   // Drawing color
	UI.FillColor = NULL;				   // Filling color
	UI.MsgColor = RED;					   // Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW; // Background color
	UI.HighlightColor = MAGENTA;		   // This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3; // width of the figures frames

	// Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	// Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	CreateDrawToolBar();
	CreateStatusBar();
}

Input *Output::CreateInput() const
{
	Input *pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window *Output::CreateWind(int w, int h, int x, int y) const
{
	window *pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	pW->DrawCircle(0, UI.ToolBarHeight, w);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	// Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	// You can draw the tool bar icons in any way you want.
	// Below is one possible way

	// First prepare List of images for each menu item
	// To control the order of these images in the menu,
	// reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_TRIG] = "images\\MenuItems\\Menu_Tri.jpg";
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Menu_Line.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\download.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Menu_Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Menu_Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Menu_Paste.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Remove.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\Menu_Play.jpg";
	MenuItemImages[ITM_CHANGE_CURRENT] = "images\\MenuItems\\Menu_Change_Current.jpg";
	MenuItemImages[ITM_CHANGE_FILL] = "images\\MenuItems\\Menu_Fill.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_Undo.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[ITM_CHNG_BORDER] = "images\\MenuItems\\Menu_Border.jpg";
	MenuItemImages[ITM_CHANGE_COLOR] = "images\\MenuItems\\Menu_Color.jpg";

	// TODO: Prepare images for each menu item and add it to the list

	// Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	// Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	UI.InterfaceMode = MODE_PLAY;
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_DRAW] = "images\\MenuItems\\Menu_Play.jpg";
	MenuItemImages[ITM_TYPE_PICK_HIDE] = "images\\MenuItems\\Menu_Pick_Shape.jpg";
	MenuItemImages[ITM_FILL_PICK_HIDE] = "images\\MenuItems\\FILL_PICK_HIDE.jpg";
	MenuItemImages[ITM_BOTH_PICK_HIDE] = "images\\MenuItems\\BOTH_PICK_HIDE.jpg";
	MenuItemImages[ITM_RESTART] = "images\\MenuItems\\Menu_Restart.jpg";
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	// Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateChangeColorBar() const
{

	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	UI.InterfaceMode = MODE_CHN_COLOR;
	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Menu_Red.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Menu_Yellow.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_Blue.jpg";
	MenuItemImages[ITM_DRAW_MODE] = "images\\MenuItems\\Mode_Draw.jpg";
	for (int i = 0; i < COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	// Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const // Prints a message on status bar
{
	ClearStatusBar(); // First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const // get current drwawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const // get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const // get current pen width
{
	return UI.PenWidth;
}

void Output::setCrntDrawColor(color drwclr)
{
	UI.DrawColor = drwclr;
}

void Output::setCrntFillColor(color fillclr)
{
	UI.FillColor = fillclr;
}

void Output::setCrntBrdrWidth(int brdrwidth)
{
	UI.PenWidth = brdrwidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected, bool Hidden) const
{
	color DrawingClr;
	if (selected)
	{
		DrawingClr = UI.HighlightColor;					   // Figure should be drawn highlighted
		pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth); // Set Drawing color & width

		drawstyle style;
		if (RectGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(RectGfxInfo.FillClr);
		}
		else
			style = FRAME;

		pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	}
	else if (Hidden)
	{
		DrawingClr = UI.BkGrndColor;
		pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth); // Set Drawing color & width

		drawstyle style;
		if (RectGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(UI.BkGrndColor);
		}
		else
			style = FRAME;

		pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	}
	else
	{
		DrawingClr = RectGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth); // Set Drawing color & width

		drawstyle style;
		if (RectGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(RectGfxInfo.FillClr);
		}
		else
			style = FRAME;

		pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	}
}

void Output::DrawCircle(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected, bool Hidden) const
{
	color DrawingClr;
	if (selected)
	{
		DrawingClr = UI.HighlightColor; // Figure should be drawn highlighted
		pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);
		drawstyle style;
		if (RectGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(RectGfxInfo.FillClr);
		}
		else
			style = FRAME;

		pWind->DrawCircle(P1.x, P1.y, sqrt((P2.x - P1.x) * (P2.x - P1.x) + (P2.y - P1.y) * (P2.y - P1.y)), style);
	}
	else if (Hidden)
	{
		DrawingClr = UI.BkGrndColor;
		pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);
		drawstyle style;
		if (RectGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(UI.BkGrndColor);
		}
		else
			style = FRAME;

		pWind->DrawCircle(P1.x, P1.y, sqrt((P2.x - P1.x) * (P2.x - P1.x) + (P2.y - P1.y) * (P2.y - P1.y)), style);
	}
	else
	{
		DrawingClr = RectGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth); // Set Drawing color & width

		drawstyle style;
		if (RectGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(RectGfxInfo.FillClr);
		}
		else
			style = FRAME;

		pWind->DrawCircle(P1.x, P1.y, sqrt((P2.x - P1.x) * (P2.x - P1.x) + (P2.y - P1.y) * (P2.y - P1.y)), style);
	}
}
void Output::DrawTrig(Point P1, Point P2, Point P3, GfxInfo TrigGfxInfo, bool selected, bool Hidden) const
{
	color DrawingClr;
	if (selected)
	{
		DrawingClr = UI.HighlightColor;					   // Figure should be drawn highlighted
		pWind->SetPen(DrawingClr, TrigGfxInfo.BorderWdth); // Set Drawing color & width

		drawstyle style;
		if (TrigGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(TrigGfxInfo.FillClr);
		}
		else
			style = FRAME;

		pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
	}
	else if (Hidden)
	{
		DrawingClr = UI.BkGrndColor;
		pWind->SetPen(DrawingClr, TrigGfxInfo.BorderWdth); // Set Drawing color & width

		drawstyle style;
		if (TrigGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(UI.BkGrndColor);
		}
		else
			style = FRAME;

		pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
	}
	else
	{
		DrawingClr = TrigGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, TrigGfxInfo.BorderWdth); // Set Drawing color & width

		drawstyle style;
		if (TrigGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(TrigGfxInfo.FillClr);
		}
		else
			style = FRAME;

		pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
	}
}

void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected, bool Hidden) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; // Figure should be drawn highlighted
	else if (Hidden)
		DrawingClr = UI.BkGrndColor;
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth); // Set Drawing color & width

	drawstyle style;
	if (LineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LineGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
