#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point EndRad;
	int radius;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IS_pin_shape(int x, int y);
	virtual string print();
	Point getCenter();
	Point getradius();
	int getRadius();

};

#endif