#include "pch.h"
#include "Triangle.h"

IMPLEMENT_SERIAL(Triangle, CObject, 1)

void Triangle::Draw(CDC* dc) const
{
	CPoint p1 = getP1();
	CPoint p3 = getP2();
	CPen myPen1(PS_SOLID, currThickness, currFrame);
	CPen* old_pen;
	CBrush myBrush(currFilling), * oldBrush;
	CPoint p2(p1.x, p3.y);
	p1.x = (p1.x + p3.x) / 2;
	dc->SelectObject(&myPen1);
	dc->SelectObject(&myBrush);
	oldBrush = dc->SelectObject(&myBrush);
	old_pen = dc->SelectObject(&myPen1);
	CPoint TriArr[3] = { p1,p2,p3 };
	dc->Polygon(TriArr, 3);
	dc->SelectObject(oldBrush);
	dc->SelectObject(old_pen);
}

Triangle::Triangle(CPoint start, CPoint end, int thickness, COLORREF frame, COLORREF filling)
	:Figure(P1, P2, thickness, frame, filling)
{
}
