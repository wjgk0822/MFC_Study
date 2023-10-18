﻿// CDlgImage.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_4-3.h"
#include "afxdialogex.h"
#include "CDlgImage.h"


// CDlgImage 대화 상자

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CDlgImage, pParent)
{
	m_pParent = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	//ON_BN_CLICKED(IDC_BTN_1, &CDlgImage::OnBnClickedBtn1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgImage::OnBnClickedButton2)
//	ON_WM_NOTIFYFORMAT()
ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기


void CDlgImage::OnBnClickedBtn1()
{


	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

#include "MFC_4-3Dlg.h"
void CDlgImage::OnBnClickedButton2()
{

	static int n = 100;
	CMFC43Dlg* pDlg = (CMFC43Dlg*)m_pParent;

	pDlg->callFunc(n++);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	MoveWindow(0, 0, 640, 480);

	initImage();

	//int nWidth = 640;
	//int nHeight = 480;
	//int nBpp = 8;


	//m_image.Create(nWidth, -nHeight, nBpp);
	//if (nBpp == 8) {

	//	static RGBQUAD rgb[256];
	//	for (int i = 0; i < 256; i++) {
	//		rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;

	//		m_image.SetColorTable(0, 256, rgb);
	//	}
	//}

	//int nPitch = m_image.GetPitch();

	//unsigned char* fn = (unsigned char*)m_image.GetBits();

	//memset(fn, 0xff, nWidth * nHeight);

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	//AfxMessageBox(_T("ready?"));






	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


//UINT CDlgImage::OnNotifyFormat(CWnd* pWnd, UINT nCommand)
//{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

//	return CDialogEx::OnNotifyFormat(pWnd, nCommand);
//}


void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	if (m_image) {
		m_image.Draw(dc, 0, 0);
	}
}

void CDlgImage::initImage()
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;


	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {

		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++) {
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;

			m_image.SetColorTable(0, 256, rgb);
		}
	}

	int nPitch = m_image.GetPitch();

	unsigned char* fn = (unsigned char*)m_image.GetBits();

	memset(fn, 0xff, nWidth * nHeight);

}
