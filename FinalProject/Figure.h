#pragma once
class Figure : public CObject
{
	DECLARE_SERIAL(Figure) 
public:
	Figure() {}
	Figure(CPoint p1, CPoint p2, int thickness, COLORREF frame, COLORREF filling);
	void Serialize(CArchive& ar);
	virtual void Draw(CDC* dc) const;
	CPoint getP1() const { return P1; }
	CPoint getP2() const { return P2; }
	virtual void Redefine(CPoint p1, CPoint p2) { P1 = p1; P2 = p2; }
protected:
	CPoint P1, P2;
	COLORREF currFilling;
	COLORREF currFrame;
	int currThickness;
};