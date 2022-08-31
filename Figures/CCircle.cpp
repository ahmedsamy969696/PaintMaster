#include "CCircle.h"
#include "CFigure.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
	EndRad = P2;
	radius = sqrt(pow((EndRad.x - Center.x), 2) + pow((EndRad.y - Center.y), 2));
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawCircle(Center, EndRad, FigGfxInfo, Selected);
}

Point CCircle::getradius() {
	return EndRad;
}

bool CCircle::IS_pin_shape(int x, int y)
{
	double radious = sqrt(pow((EndRad.x - Center.x), 2) + pow((EndRad.y - Center.y),2));//√ (x2 – x1) + (y2 – y1) 2.
	if (pow(x - Center.x, 2) + pow (y - Center.y, 2) <= pow(radious, 2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Point CCircle::getCenter() {
	return Center;
}

int CCircle::getRadius() {
	return radius;
}

string CCircle::print()
{
	string values;
	double rad = pow(pow(EndRad.x - Center.x, 2) + pow(EndRad.y - Center.y, 2), -1);
	values = "This is a Circle.The ID: " + to_string(ID) + ". The Point of the center: (" + to_string(Center.x) + ", " + to_string(Center.y) + "). The Point on the border: (" + to_string(EndRad.x) + ", " + to_string(EndRad.y) + "). The Radious is: " + to_string(rad) + ".";
	return values;
}
