#include "pch.h"
#include "RectangleCirc.h"

IMPLEMENT_SERIAL(RectangleCirc, CObject, 1)

 void RectangleCirc::Draw(CDC* dc) const
{
	RectangleF::Draw(dc); // Inherits from rectangle
	CPoint p1 = getP1(); // Getting points for the Ellipse
	CPoint p2 = getP2();
	CPen myPen1(PS_SOLID, currThickness, RGB(255, 0, 0)); // const color for inside frame
	CPen* old_pen;
	dc->SelectObject(&myPen1);
	old_pen = dc->SelectObject(&myPen1);
	dc->Ellipse(p1.x, p1.y, p2.x, p2.y);
	dc->SelectObject(old_pen);
}

 RectangleCirc::RectangleCirc(CPoint start, CPoint end, int thickness, COLORREF frame, COLORREF filling)
	 :RectangleF(P1, P2, thickness, frame, filling)
 {
 }
