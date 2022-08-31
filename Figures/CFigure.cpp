#include "CFigure.h"

CFigure::CFigure()
{
}

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

bool CFigure::IS_pin_shape(int x, int y)
{
	return true;
}


string CFigure::ConvertToString2(color cc) const
{
	if (cc == BLACK) return "BLACK";
	else if (cc == WHITE) return "WHITE";
	else if (cc == BLUE) return "BLUE";
	else if (cc == RED) return "RED";
	else if (cc == YELLOW) return "YELLOW";
	else if (cc == GREEN) return "GREEN";
	else if (cc == GREY) return "GREY";
	else if (cc == LIGHTGOLDENRODYELLOW) return "LIGHTGOLDENRODYELLOW";
	return "COLOR";
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

string CFigure::print()
{
	return "This is a Figure.";
}

