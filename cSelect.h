#pragma once
#ifndef CSELECT_H
#define CSELECT_H

#include "Figures/CFigure.h"

class cSelect : public CFigure
{
private:
	Point P;
public:
	cSelect(Point);
	virtual void Select(Output* pOut) const;
};

#endif