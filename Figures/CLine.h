#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IS_pin_shape(int x, int y);
	virtual string print();
	Point getP1();
	Point getP2();
	Point getcornar1() const;
	Point getcornar2() const;
	string GetAllData(int ID);
};

#endif