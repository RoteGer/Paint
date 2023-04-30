// FinalProjectDlg.h : header file

#include <stack>
#include "Figure.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Line.h"
#include "RectangleCirc.h"
#include "RectangleTriangle.h"
#include "Triangle.h"
using namespace std;
#pragma once


// CFinalProjectDlg dialog
class CFinalProjectDlg : public CDialogEx
{

// Construction
public:
	CFinalProjectDlg(CWnd* pParent = nullptr);	// standard constructor
	~CFinalProjectDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FINALPROJECT_DIALOG };
#endif
	CPoint start, end;
	bool isPressed = false;
	CTypedPtrArray< CObArray, Figure*> figs;
	int futureFigureKind = 2; //Rectangle (2 - Ellipse)
	stack<Figure*>memory; // for redo and undo

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedChill();
	afx_msg void OnBnClickedDubSteps();
	afx_msg void OnBnClickedHipHop();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedLoad();
	afx_msg void OnBnClickedUndo();
	afx_msg void OnBnClickedRedo();
	afx_msg void OnBnClickedHello();
	afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void OnBnClickedMfccolorbutton2();
	CSliderCtrl m_sliderCtrl;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	COLORREF frame = RGB(255,255,0);
	COLORREF filling = RGB(100,100,100);
	CMFCColorButton Frame;
	CMFCColorButton Filling;
	int m_PenWidth;	
	CString User_Name;
	CString NewName;
	CButton My_btn;
	CComboBox m_comboBoxCtrl;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnShapesEllipse();
	afx_msg void OnRectangleRectangle();
	afx_msg void OnRectangleRectangleEllipse();
	afx_msg void OnShapesLine();
	afx_msg void OnRectangleRectangleTriangle();
	afx_msg void OnShapesTriangle();
	afx_msg void OnBnClickedOk();

	HICON RedoIcon = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 25, 25, 0);
	HICON UndoIcon = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON2), IMAGE_ICON, 25, 25, 0);
	HICON SaveIcon = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON3), IMAGE_ICON, 35, 35, 0);
	HICON UploadIcon = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON4), IMAGE_ICON, 35, 35, 0);
	HICON ExitIcon = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON5), IMAGE_ICON, 35, 35, 0);

	CButton REDOBTN;
	CButton UNDOBTN;
	CButton SAVEBTN;
	CButton UPLOADBTN;
	CButton EXITBTN;
};
