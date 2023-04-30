#include "pch.h"
#include "Rectangle.h"

IMPLEMENT_SERIAL(RectangleF, CObject, 1)

RectangleF::RectangleF(CPoint p1, CPoint p2, int thickness, COLORREF frame, COLORREF filling)
	:Figure(p1, p2, thickness, frame, filling)
{
}