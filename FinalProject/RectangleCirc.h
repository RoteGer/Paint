#pragma once
#include "Rectangle.h"
class RectangleCirc : public RectangleF{
	DECLARE_SERIAL(RectangleCirc)
public:
	RectangleCirc() {}
	RectangleCirc(CPoint Start, CPoint end, int thickness, COLORREF frame, COLORREF filling);
	void Draw(CDC* dc) const;
};




