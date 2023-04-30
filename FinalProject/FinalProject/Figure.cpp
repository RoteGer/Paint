#include "pch.h"
#include "Figure.h"

IMPLEMENT_SERIAL(Figure, CObject, 1)

Figure::Figure(CPoint p1, CPoint p2, int thickness, COLORREF frame, COLORREF filling):P1(p1), P2(p2)
{
	currFrame = frame;
	currFilling = filling;
	currThickness = thickness;
}
void Figure::Draw(CDC* dc) const
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
	dc->Rectangle(P1.x, P1.y, P2.x, P2.y);
	dc->SelectObject(oldBrush);
	dc->SelectObject(old_pen);
}
void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring()) // Save
	{
		ar << P1;
		ar << P2;
		ar << currThickness;
		ar << currFrame;
		ar << currFilling;
	}
	else				// Loading
	{
		ar >> P1;
		ar >> P2;
		ar >> currThickness;
		ar >> currFrame;
		ar >> currFilling;
	}
}