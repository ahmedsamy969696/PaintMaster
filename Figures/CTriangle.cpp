#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTrig(Corner1, Corner2,Corner3, FigGfxInfo, Selected);
}

float CTriangle::area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool CTriangle::IS_pin_shape(int x, int y)
{
	float temp = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	float temp1 = area(x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	float temp2 = area(Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y);
	float temp3 = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y);
	if (temp == temp1 + temp2 + temp3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string CTriangle::print()
{
	string values;;
	values = "This is a TRIANGLE.The ID: " + to_string(ID) + ". First Point: (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + "). Second Point: (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + "). Third Point: (" + to_string(Corner3.x) + ", " + to_string(Corner3.y) + ")" + "The Area of the Triangle is: " + to_string(area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y)) + ".";
	return values;
}
