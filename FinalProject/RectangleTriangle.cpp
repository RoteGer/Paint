#include "pch.h"
#include "RectangleTriangle.h"

IMPLEMENT_SERIAL(RectangleTriangle, CObject, 1)


void RectangleTriangle::Draw(CDC* dc) const
{
	RectangleF::Draw(dc); // Inherits from rectangle
	CPoint p1 = getP1(); 
	CPoint p3 = getP2();
	CPoint p2(p1.x, p3.y);
	p1.x = (p1.x + p3.x) / 2;
	CPen myPen1(PS_SOLID, currThickness, RGB(255, 0, 0)); // const color for inside frame
	CPen* old_pen;
	dc->SelectObject(&myPen1);
	old_pen = dc->SelectObject(&myPen1);
	CPoint TriArr[3] = { p1,p2,p3 };
	dc->Polygon(TriArr, 3);
	dc->SelectObject(old_pen);
}

RectangleTriangle::RectangleTriangle(CPoint start, CPoint end, int thickness, COLORREF frame, COLORREF filling)
	:RectangleF(P1, P2, thickness, frame, filling)
{
}

