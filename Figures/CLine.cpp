#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
Point CLine::getcornar1() const
{
	return  Corner1;
}

Point CLine::getcornar2() const
{
	return Corner2;
}

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a Line on the screen	
	pOut->DrawLine(Corner1, Corner2, FigGfxInfo, Selected);
}


bool CLine::IS_pin_shape(int x, int y)
{
	double m = (Corner2.y - Corner1.y) / (Corner2.x - Corner1.x); //slope
	double c = Corner1.y - (m * Corner1.x); //y intercept

	if (y == ((m * x) + c))
	{
		return true;
	}//(y == ((m * x) + c))
	else
	{
		return false;
	}
}

Point CLine::getP1() {
	return Corner1;
}

Point CLine::getP2() {
	return Corner2;
}

string CLine::print()
{
	string values;
	double len = pow(pow(Corner2.x - Corner1.x, 2) + pow(Corner2.y - Corner1.y, 2), -1);
	values = "This is a LINE.The ID: " + to_string(ID) + ". Start Point: (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + "). End Point: (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + "). The length of the line is: " + to_string(len) + ".";
	return values;
}

string CLine::GetAllData(int ID)
{
	string data = "LINE " + to_string(ID) + "  " +
		to_string(Corner1.x) + "  " +
		to_string(Corner1.y) + "  " +
		to_string(Corner2.x) + "  " +
		to_string(Corner2.y) + "  ";
	data += ConvertToString2(FigGfxInfo.DrawClr) + " ";
	if (FigGfxInfo.isFilled)
	{
		data += ConvertToString2(FigGfxInfo.FillClr);
	}
	else
	{
		data += "NO_FILL";
	}
	data += "\n";
	return data;
}
