#pragma once
#include "Rectangle.h"
class RectangleTriangle : public RectangleF {
	DECLARE_SERIAL(RectangleTriangle)
public:
	RectangleTriangle() {}
	RectangleTriangle(CPoint Start, CPoint end, int thickness, COLORREF frame, COLORREF filling);
	void Draw(CDC* dc) const;
};




