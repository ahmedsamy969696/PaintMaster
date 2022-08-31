#include "CFigure.h"

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

void CFigure::ChngBorderWidth(int width) {
	FigGfxInfo.BorderWdth = width;
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

GfxInfo CFigure::getGfxInfo() {
	return FigGfxInfo;
}

string CFigure::print()
{
	return "This is a Figure.";
}

