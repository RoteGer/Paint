#pragma once
#include "Figure.h"
class EllipseF :public Figure {
	DECLARE_SERIAL(EllipseF) 
public:
	EllipseF() {}
	EllipseF(CPoint p1, CPoint p2, int thickness, COLORREF frame, COLORREF filling);
	void Draw(CDC* dc) const;
};