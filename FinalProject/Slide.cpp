// Slide.cpp : implementation file
//

#include "pch.h"
#include "FinalProject.h"
#include "Slide.h"
#include "afxdialogex.h"


// Slide dialog

IMPLEMENT_DYNAMIC(Slide, CDialogEx)

Slide::Slide(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FINALPROJECT_DIALOG, pParent)
{

}

Slide::~Slide()
{
}

void Slide::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Slide, CDialogEx)
END_MESSAGE_MAP()


// Slide message handlers
