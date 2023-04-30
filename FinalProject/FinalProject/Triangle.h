#pragma once
#include "Rectangle.h"
class Triangle :public Figure {
	DECLARE_SERIAL(Triangle)
public:
	Triangle() {}
	Triangle(CPoint Start, CPoint end, int thickness, COLORREF frame, COLORREF filling);
	void Draw(CDC* dc) const;
};




