#include "pch.h"
#include "Ellipse.h"

IMPLEMENT_SERIAL(EllipseF, CObject, 1)

EllipseF::EllipseF(CPoint p1, CPoint p2, int thickness, COLORREF frame, COLORREF filling): 
	Figure(p1, p2,  thickness, frame,filling)
{
}
void EllipseF::Draw(CDC* dc) const
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CPen myPen1(PS_SOLID, currThickness, currFrame);
	CPen* old_pen;
	CBrush myBrush(currFilling), * oldBrush;
	dc->SelectObject(&myPen1);
	dc->SelectObject(&myBrush);
	oldBrush = dc->SelectObject(&myBrush);
	old_pen = dc->SelectObject(&myPen1);
	dc->Ellipse(p1.x, p1.y, p2.x, p2.y);
	dc->SelectObject(oldBrush);
	dc->SelectObject(old_pen);
}
