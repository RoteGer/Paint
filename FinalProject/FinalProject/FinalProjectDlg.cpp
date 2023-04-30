
// FinalProjectDlg.cpp : implementation file

#include "pch.h"
#include "framework.h"
#include "FinalProject.h"
#include "FinalProjectDlg.h"
#include "afxdialogex.h"
#include <windows.h>
#include <mmsystem.h>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFinalProjectDlg dialog

CFinalProjectDlg::CFinalProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FINALPROJECT_DIALOG, pParent)
	, User_Name(_T("Enter your name"))
	, NewName(_T("User"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFinalProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_sliderCtrl);
	DDX_Text(pDX, IDC_MFCCOLORBUTTON1, frame);
	DDX_Text(pDX, IDC_MFCCOLORBUTTON2, filling);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, Frame);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, Filling);
	DDX_Text(pDX, IDC_EDIT1, User_Name);
	DDX_Text(pDX, MY_TITLE_LBL, NewName);
	DDX_Control(pDX, IDC_BUTTON8, My_btn);
	DDX_Control(pDX, IDC_COMBO1, m_comboBoxCtrl);

	DDX_Control(pDX, IDC_BUTTON7, REDOBTN);
	DDX_Control(pDX, IDC_BUTTON6, UNDOBTN);
	DDX_Control(pDX, IDC_BUTTON4, SAVEBTN);
	DDX_Control(pDX, IDC_BUTTON5, UPLOADBTN);
	DDX_Control(pDX, IDOK, EXITBTN);
}

BEGIN_MESSAGE_MAP(CFinalProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON1, &CFinalProjectDlg::OnBnClickedChill)
	ON_BN_CLICKED(IDC_BUTTON2, &CFinalProjectDlg::OnBnClickedDubSteps)
	ON_BN_CLICKED(IDC_BUTTON3, &CFinalProjectDlg::OnBnClickedHipHop)
	ON_BN_CLICKED(IDC_BUTTON4, &CFinalProjectDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_BUTTON5, &CFinalProjectDlg::OnBnClickedLoad)
	ON_BN_CLICKED(IDC_BUTTON6, &CFinalProjectDlg::OnBnClickedUndo)
	ON_BN_CLICKED(IDC_BUTTON7, &CFinalProjectDlg::OnBnClickedRedo)
	ON_BN_CLICKED(IDC_BUTTON8, &CFinalProjectDlg::OnBnClickedHello)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CFinalProjectDlg::OnBnClickedMfccolorbutton1)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON2, &CFinalProjectDlg::OnBnClickedMfccolorbutton2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CFinalProjectDlg::OnCbnSelchangeCombo1)
	ON_COMMAND(ID_SHAPES_ELLIPSE, &CFinalProjectDlg::OnShapesEllipse)
	ON_COMMAND(ID_RECTANGLE_RECTANGLE, &CFinalProjectDlg::OnRectangleRectangle)
	ON_COMMAND(ID_RECTANGLE_RECTANGLE32777, &CFinalProjectDlg::OnRectangleRectangleEllipse)
	ON_COMMAND(ID_SHAPES_LINE, &CFinalProjectDlg::OnShapesLine)
	ON_COMMAND(ID_RECTANGLE_RECTANGLE32778, &CFinalProjectDlg::OnRectangleRectangleTriangle)
	ON_COMMAND(ID_SHAPES_TRIANGLE, &CFinalProjectDlg::OnShapesTriangle)
	
	ON_BN_CLICKED(IDOK, &CFinalProjectDlg::OnBnClickedOk)
END_MESSAGE_MAP()

CFinalProjectDlg::~CFinalProjectDlg()
{
	for (int i = 0; i < figs.GetSize(); i++)
		delete figs[i];
}
// CFinalProjectDlg message handlers
BOOL CFinalProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
		
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	Frame.SetColor(frame);
	Filling.SetColor(filling);
	CString str;
	for (int i = 1; i < 10; i++)
	{
		str.Format(_T("thickness: %d"), i);
		m_comboBoxCtrl.AddString(str);
	}
	m_comboBoxCtrl.SetCurSel(m_PenWidth = 4);
	m_sliderCtrl.SetRange(0, 0xFFFF, TRUE);
	m_sliderCtrl.SetPos(0x7FFF);
	PlaySound(TEXT("Sounds/chill.wav"), NULL, SND_ASYNC);

	// icons

	REDOBTN.SetButtonStyle(BS_ICON | WS_VISIBLE | WS_CHILD, 1); // Redo icon
	REDOBTN.SetIcon(RedoIcon);

	UNDOBTN.SetButtonStyle(BS_ICON | WS_VISIBLE | WS_CHILD, 1); // Undo icon
	UNDOBTN.SetIcon(UndoIcon);
	
	SAVEBTN.SetButtonStyle(BS_ICON | WS_VISIBLE | WS_CHILD, 1); // Save icon
	SAVEBTN.SetIcon(SaveIcon);

	UPLOADBTN.SetButtonStyle(BS_ICON | WS_VISIBLE | WS_CHILD, 1); // Upload icon
	UPLOADBTN.SetIcon(UploadIcon);
	
	EXITBTN.SetButtonStyle(BS_ICON | WS_VISIBLE | WS_CHILD, 1); // Exit icon
	EXITBTN.SetIcon(ExitIcon);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFinalProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}
// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
void CFinalProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CRect rect;
		GetClientRect(&rect);
		CPaintDC dc(this);
		for (int i = 0; i < figs.GetSize(); i++)
			figs[i]->Draw(&dc);
		CDialogEx::OnPaint();
		CString opening("The official painter by Rotem G. and Ravino I.");
		rect.OffsetRect(-440, 250);
		dc.SetTextColor(RGB(0, 0, 0));
		dc.DrawText(opening, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	}
}
// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFinalProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
/*=======================================================================*/
void CFinalProjectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	start = point;
	isPressed = true;
	switch (futureFigureKind)
	{
	case 1:
		figs.Add(new RectangleF(start, start, m_PenWidth, frame, filling));
		break;
	case 2:
		figs.Add(new EllipseF(start, start, m_PenWidth, frame, filling));
		break;
	case 3:
		figs.Add(new Line(start, start,m_PenWidth,frame));
		break;
	case 4:
		figs.Add(new RectangleCirc(start, start, m_PenWidth, frame, filling));
		break;
	case 5:
		figs.Add(new RectangleTriangle(start, start, m_PenWidth, frame, filling));
		break;
	case 6:
		figs.Add(new Triangle(start, start, m_PenWidth, frame, filling));
		break;
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}
void CFinalProjectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (isPressed)
	{
		end = point;
		isPressed = false;
	}
	CDialog::OnLButtonUp(nFlags, point);
}
void CFinalProjectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (isPressed)
	{
		end = point;
		figs[figs.GetSize() - 1]->Redefine(start, end);
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}
	CDialog::OnMouseMove(nFlags, point);
}
/*=======================================================================*/
void CFinalProjectDlg::OnBnClickedChill()
{
	// TODO: Add your control notification handler code here
	PlaySound(TEXT("Sounds/chill.wav"), NULL, SND_ASYNC);
}
void CFinalProjectDlg::OnBnClickedDubSteps()
{
	// TODO: Add your control notification handler code here
	PlaySound(TEXT("Sounds/dubstep.wav"), NULL, SND_ASYNC);
}
void CFinalProjectDlg::OnBnClickedHipHop()
{
	// TODO: Add your control notification handler code here
	PlaySound(TEXT("Sounds/hiphop.wav"), NULL, SND_ASYNC);
}
void CFinalProjectDlg::OnBnClickedSave()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	// FALSE to SAVE
	//CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	LPCTSTR pszFilter = _T("Figure (*.figs)|*.figs||");
	CFileDialog dlg(FALSE, _T("figs"),_T("Hello.figs"), OFN_OVERWRITEPROMPT, pszFilter, AfxGetMainWnd());
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}
}
void CFinalProjectDlg::OnBnClickedLoad()
{
	//TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}

}
void CFinalProjectDlg::OnBnClickedUndo() // Undo
{
	if (figs.GetSize() >= 1)
	{
		Figure* figure = figs[figs.GetSize() - 1];
		figs.RemoveAt(figs.GetSize() - 1, 1);
		memory.push(figure);
		Invalidate();
	}
}
void CFinalProjectDlg::OnBnClickedRedo() // Redo
{
	if (!memory.empty())
	{
		Figure* figure = memory.top();
		figs.Add(figure);
		memory.pop();
		Invalidate();
	}
}
void CFinalProjectDlg::OnBnClickedHello()
{
	// TODO: Add your control notification handler code here
	CString s;
	CString var;
	My_btn.GetWindowText(s);
	if (s == _T("Hello"))
	{
		My_btn.SetWindowText(_T("שלום"));
	}
	else if (s == _T("שלום"))
	{
		My_btn.SetWindowText(_T("مرحبا"));
	}
	else
	{
		My_btn.SetWindowText(_T("Hello"));
	}
	UpdateData(TRUE); // Insert the value the user typed into User_Name
	NewName.SetString(User_Name); // NewName = User_Name
	if (User_Name != "Welcome")
	{
		User_Name.SetString(_T("Welcome")); //User_Name = Welcome
		UpdateData(FALSE); // Display the value 
	}
}
/*=======================================================================*/

void CFinalProjectDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	if (pScrollBar == (CScrollBar*)&m_sliderCtrl) {
		int value = m_sliderCtrl.GetPos();
		waveOutSetVolume(NULL, value);
		UpdateData(FALSE);
	}
	else {
		CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}
void CFinalProjectDlg::OnBnClickedMfccolorbutton1()
{
	frame = Frame.GetColor();
}
void CFinalProjectDlg::OnBnClickedMfccolorbutton2()
{
	filling = Filling.GetColor();
}
void CFinalProjectDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	m_PenWidth = m_comboBoxCtrl.GetCurSel()+1;
	UpdateData(FALSE);
}
void CFinalProjectDlg::OnShapesEllipse()
{
	// TODO: Add your command handler code here
	futureFigureKind = 2;
}
void CFinalProjectDlg::OnRectangleRectangle()
{
	// TODO: Add your command handler code here
	futureFigureKind = 1;
}
void CFinalProjectDlg::OnRectangleRectangleEllipse()
{
	// TODO: Add your command handler code here
	futureFigureKind = 4;
}
void CFinalProjectDlg::OnShapesLine()
{
	// TODO: Add your command handler code here
	futureFigureKind = 3;
}
void CFinalProjectDlg::OnRectangleRectangleTriangle()
{
	// TODO: Add your command handler code here
	futureFigureKind = 5;
}
void CFinalProjectDlg::OnShapesTriangle()
{
	// TODO: Add your command handler code here
	futureFigureKind = 6;
}


void CFinalProjectDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
