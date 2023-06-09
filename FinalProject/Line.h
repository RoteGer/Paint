#pragma once
#include "Figure.h"
class Line : public Figure {
	DECLARE_SERIAL(Line)   
public:
	Line() {}
	Line(CPoint p1, CPoint p2, int thickness, COLORREF frame);
	void Draw(CDC* dc) const;
};
