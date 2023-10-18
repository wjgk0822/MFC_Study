
// MFC_Study2Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC_Study2.h"
#include "MFC_Study2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMFCStudy2Dlg 대화 상자



CMFCStudy2Dlg::CMFCStudy2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_STUDY2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCStudy2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCStudy2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_Image, &CMFCStudy2Dlg::OnBnClickedBtnImage)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCStudy2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCStudy2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BTN_ACT, &CMFCStudy2Dlg::OnBnClickedBtnAct)
END_MESSAGE_MAP()


// CMFCStudy2Dlg 메시지 처리기

BOOL CMFCStudy2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCStudy2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCStudy2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCStudy2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCStudy2Dlg::OnBnClickedBtnImage()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nWidth = 640;
	int nHeight = 480;
	//int nWidth = 32;
	//int nHeight = 24;
	//int nHeight = 4;
	//int nWidth = 8;
	int nBpp = 8;

	//m_image.Create(640, 480, 8);

	//m_image.Create(nWidth, nHeight, nBpp);

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

	//for (int j = 0; j < nHeight; j++) {
	//	for (int i = 0; i < nWidth; i++) {
	//		fn[j * nPitch + i] = (i % 0xff);
	//	}
	//}

	//////for (int j = 0; j < nHeight; j++) {
	//////	for (int i = 0; i < nWidth; i++) {
	//////		//fn[j * nPitch + i] = 128;
	//////		//fn[j * nPitch + i] = 255;
	//////		//fn[j * nPitch + i] = j % 255;
	//////		//fn[j * nPitch + i] = (j*60) % 255;
	//////		fn[j * nPitch + i] = 0xff;

	//////	}
	//////}

	//fn[12 * nPitch + 16] = 0;
	/*fn[0 * nPitch + 0] = 128;
	fn[0 * nPitch + 1] = 128;
	fn[1 * nPitch + 1] = 128;*/

	/*for (int j = 0; j < nHeight; j++) {
		for (int i = 0; i < nWidth; i++) {
			fn[j * nPitch + i] = 200;
		}
	}*/



	//CClientDC dc(this);
	//m_image.Draw(dc, 0, 0);
	//m_image.Draw(dc, nWidth / 2, nHeight / 2);

	UpdateDisplay();

	m_image.Save(_T("C:\\Users\\wjgk0\\source\\repos\\first_MFC\\MFC_Study2\\Image\\save12.bmp"));



}

CString g_strFileImage = _T("C:\\Users\\wjgk0\\source\\repos\\first_MFC\\MFC_Study2\\Image\\save11.bmp");
void CMFCStudy2Dlg::OnBnClickedButton2()
{

	m_image.Save(g_strFileImage);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCStudy2Dlg::OnBnClickedButton3()
{
	if (m_image != NULL) {
		m_image.Destroy();
	}
	m_image.Load(g_strFileImage);

	UpdateDisplay();

	//CClientDC dc(this);
	//m_image.Draw(dc, 0, 0);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMFCStudy2Dlg::UpdateDisplay()
{
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
}


void CMFCStudy2Dlg::moveRect()
{
	static int nSttx = 0;
	static int nStty = 0;
	int nGray = 80;
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	//int nRadius = 10;
	int nRadius = 20;
	unsigned char* fn = (unsigned char*)m_image.GetBits();

	//memset(fn, 0xff, nWidth*nHeight);

	drawCircle(fn, nSttx, nStty, nRadius, 0xff);

	//nSttx++;

	drawCircle(fn, ++nSttx, ++nStty, nRadius, nGray);

	/*for (int j = nStty; j < nStty+48; j++) {
		for (int i = nSttx; i < nSttx+64; i++) {
			if(validImgPos(i,j))
				fn[j * nPitch + i] = nGray;
		}
	}*/

	//nSttx++;
	//nStty++;

	UpdateDisplay();

	CString strFile;
	strFile.Format(_T("C:\\Users\\wjgk0\\source\\repos\\first_MFC\\MFC_Study2\\Image\\image%d.jpg"), nSttx);

	m_image.Save(strFile);
}

void CMFCStudy2Dlg::OnBnClickedBtnAct()
{

	for (int i = 0; i < 400; i++) {
		//moveRect();
		//moveElipse();
		moveRect();

		Sleep(10);

	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

BOOL CMFCStudy2Dlg::validImgPos(int x, int y) {

	//BOOL bRet = false;

	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	CRect rect(0, 0, nWidth, nHeight);

	return rect.PtInRect(CPoint(x, y));



	/*if (x > 0 && x <= nWidth) {

		bRet=true;

	}

	if (y > 0 && y <= nHeight) {
		bRet = true;
	}

	return bRet;*/

}

BOOL CMFCStudy2Dlg::isInsideEllipse(int x, int y, int centerX, int centerY, int radiusX, int radiusY)
{
	double dx = (x - centerX) / static_cast<double>(radiusX);
	double dy = (y - centerY) / static_cast<double>(radiusY);
	return (dx * dx + dy * dy <= 1.0);
}


void CMFCStudy2Dlg::moveElipse()
{
	static int nSttx = 0;
	static int nStty = 0;
	int nGray = 50;
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	unsigned char* fn = (unsigned char*)m_image.GetBits();

	// Clear the image with a white background
	memset(fn, 0xff, nWidth * nHeight);

	// Draw a gray ellipse at the specified position
	for (int j = nStty; j < nStty + 48; j++) {
		for (int i = nSttx; i < nSttx + 64; i++) {
			if (validImgPos(i, j)) {
				// Check if the point is inside the ellipse
				if (isInsideEllipse(i, j, nSttx + 32, nStty + 24, 32, 24)) {
					fn[j * nPitch + i] = nGray;
				}
			}
		}
	}

	// Move the ellipse
	nSttx++;
	nStty++;

	UpdateDisplay();
}


void CMFCStudy2Dlg::drawCircle(unsigned char* fn, int x, int y, int nRadius, int nGray)
{

	int nCenterX = x + nRadius;

	int nCenterY = y + nRadius;

	int nPitch = m_image.GetPitch();

	for (int j = y; j < y + nRadius * 2; j++) {
		for (int i = x; i < x + nRadius * 2; i++) {

			if(initCircle(i,j,nCenterX,nCenterY,nRadius))
			fn[j * nPitch + i] = nGray;
		}
	}

}

bool CMFCStudy2Dlg::initCircle(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;


	double dx = i - nCenterX;
	double dy = j - nCenterY;

	double dDist = dx * dx + dy*dy;

	if (dDist < nRadius*nRadius) {
		bRet = true;


	}


	return bRet;
}