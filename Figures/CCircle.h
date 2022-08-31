#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point EndRad;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IS_pin_shape(int x, int y);
	virtual string print();
	Point Getcenter() const;
	int GetR() const;
	string GetAllData(int ID);

};

#endif