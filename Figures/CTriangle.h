#pragma once
#ifndef CTRIG_H
#define CTRIG_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	float area(int x1, int y1, int x2, int y2, int x3, int y3);
	virtual bool IS_pin_shape(int x, int y);
	virtual string print();
	Point getcornar1() const;
	Point getcornar2() const;
	Point getcornar3() const;
	string GetAllData(int ID);

};

#endif