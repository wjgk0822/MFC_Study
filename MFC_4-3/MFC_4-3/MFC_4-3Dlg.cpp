
// MFC_4-3Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC_4-3.h"
#include "MFC_4-3Dlg.h"
#include "afxdialogex.h"
#include <iostream>

//int count = 0;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")

//int count = 0;



// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
using namespace std;

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
public:
//	virtual BOOL OnInitDialog();
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


// CMFC43Dlg 대화 상자



CMFC43Dlg::CMFC43Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_43_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC43Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC43Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC43Dlg::OnBnClickedButton1)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC43Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC43Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BTN_MAKE_PATTERN, &CMFC43Dlg::OnBnClickedBtnMakePattern)
	ON_BN_CLICKED(IDC_BTN_GET_DATA, &CMFC43Dlg::OnBnClickedBtnGetData)
END_MESSAGE_MAP()


// CMFC43Dlg 메시지 처리기

BOOL CMFC43Dlg::OnInitDialog()
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

	MoveWindow(0,0,1280,800);

	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_CDlgImage,this);
	m_pDlgImage->ShowWindow(SW_SHOW);
	m_pDlgImage->MoveWindow(0, 0, 640, 480);

	m_pDlgImageResult = new CDlgImage;
	m_pDlgImageResult->Create(IDD_CDlgImage, this);
	m_pDlgImageResult->ShowWindow(SW_SHOW);
	m_pDlgImageResult->MoveWindow(640, 0, 640, 480);



	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFC43Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC43Dlg::OnPaint()
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
HCURSOR CMFC43Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//#include "CDlgImage.h"

void CMFC43Dlg::OnBnClickedButton1()
{
	/*CDlgImage dlg;
	dlg.DoModal();*/

	//m_pDlgImage->ShowWindow(SW_SHOW);
	unsigned char* fn = (unsigned char*)m_pDlgImage->m_image.GetBits();

	memset(fn, 0, 640 * 480);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFC43Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if(m_pDlgImage) delete m_pDlgImage;
	if(m_pDlgImageResult) delete m_pDlgImageResult;

	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

//#include <iostream>
void CMFC43Dlg::callFunc(int n)
{

	//int nData = n;
	cout << n << endl;


}


//BOOL CAboutDlg::OnInitDialog()
//{
//	CDialogEx::OnInitDialog();
//
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

//	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
//}


void CMFC43Dlg::OnBnClickedButton2()
{

	unsigned char* fn = (unsigned char*)m_pDlgImage->m_image.GetBits();

	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();

	//memset(fn, 0xff, nWidth * nHeight);
	memset(fn, 0, nWidth * nHeight);

	//memset(fn, 0, 640 * 480);
	//memset(fn, 0, 320 * 240);
	for (int k = 0; k < MAX_POINT; k++) {

		int x = rand() % nWidth;
		int y = rand() % nHeight;


		fn[y * nPitch + x] =rand()%0xff;

	}

	int nIndex = 0;
	int nTh = 100;

	for (int j = 0; j < nHeight; j++) {
		for (int i = 0; i < nWidth; i++) {
			if (/*fn[j * nPitch + i] != 0*/
				fn[j * nPitch + i] > nTh) {
				if (m_pDlgImageResult->m_nDataCount < MAX_POINT) {

					//cout << nIndex << endl;

					//cout << nIndex << ":" << i << "," << j << endl;

					//nSum++;

					m_pDlgImageResult->m_ptData[nIndex].x = i;
					m_pDlgImageResult->m_ptData[nIndex].y = j;
					m_pDlgImageResult->m_nDataCount = ++nIndex;
				}
			}
		}
	}

	//std::cout << nSum << std::endl;

	m_pDlgImage->Invalidate();
	m_pDlgImageResult->Invalidate();

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


#include "CProcess.h"
#include <chrono>
void CMFC43Dlg::OnBnClickedButton3()
{

	CProcess process;

	auto start = std::chrono::system_clock::now();



	int nRet=process.getStartInfo(&m_pDlgImage->m_image,100);

	auto end= std::chrono::system_clock::now();

	auto millisec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);



	cout << nRet <<"\t" <<millisec.count()<<"ms" << endl;



	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFC43Dlg::OnBnClickedBtnMakePattern()
{

	//CDC* pDc = GetDC();

	unsigned char* fn = (unsigned char*)m_pDlgImage->m_image.GetBits();

	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();

	/*static int nSttx = 100;
	static int nStty = 100;
	int nGray = 80;

	int nRadius = 20;*/

	//memset(fn, 0xff, nWidth * nHeight);
	memset(fn, 0, nWidth * nHeight);

	//CDC* pDc = GetDC();

	//CRect rect(100, 200, 150, 400);
	//CRect rect(100, 100, 200, 200);
	CRect circle(100, 100, 200, 200);

	//pDc->Ellipse(circle);

	//for (int j = (circle.left + circle.right) / 2;)

	int centerX = (circle.left + circle.right) / 2; // 원의 중심 X 좌표

	int centerY = (circle.top + circle.bottom) / 2; // 원의 중심 Y 좌표

	int radius = 20;

	int yellow = 0xE0;


	for (int j = centerY - radius; j <= centerY + radius; j++) {
		for (int i = centerX - radius; i <= centerX + radius; i++) {
			// 원의 중심에서 반지름 이내의 픽셀만 색칠
			if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) <= radius * radius) {
				fn[j * nPitch + i] = 0xff; // 특정 색상 (여기서는 중간 회색)


			}
		}
	}

	int nSumX = 0;
	int nSumY = 0;
	int nCount = 0;

	int nTh = 0x80;

	// 원 내부의 픽셀만 무게 중심을 계산
	for (int j = centerY - radius; j <= centerY + radius; j++) {
		for (int i = centerX - radius; i <= centerX + radius; i++) {
			// 원 내부의 픽셀만 고려
			if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) <= radius * radius) {
				if (fn[j * nPitch + i] > nTh) {
					nSumX += i;
					nSumY += j;
					nCount++;
				}
			}
		}
	}

	double dCenterX = (double)nSumX / nCount;
	double dCenterY = (double)nSumY / nCount;

	cout << "무게 중심 X 좌표: " << dCenterX << "\t무게 중심 Y 좌표: " << dCenterY << endl;

	int numEC = int(dCenterX);

	int nIndex = 0;

	//nTh = 100;

	//radius = 10;

	for (int j = centerY - radius; j <= centerY + radius; j++) {
		for (int i = centerX - radius; i <= centerX + radius; i++) {
			// 원 내부의 픽셀만 고려
			if (!((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) <= radius * radius)) {

				//fn[j * nPitch + i] = 200;

				for (int k = 0; k < numEC; k++)
				{

					int x = rand() % nWidth;
					int y = rand() % nHeight;

					fn[y * nPitch + x] = yellow;
				}


				//if (fn[j * nPitch + i] > nTh) {
				//	nSumX += i;
				//	nSumY += j;
				//	nCount++;
				}
			}
		}
	//}




	for (int j = 0; j < nHeight; j++) {
		for (int i = 0; i < nWidth; i++) {
			if (/*fn[j * nPitch + i] != 0*/
				fn[j * nPitch + i] > nTh) {
				if (m_pDlgImageResult->m_nDataCount < MAX_POINT) {

					//cout << nIndex << endl;

					//cout << nIndex << ":" << i << "," << j << endl;

					//nSum++;

					m_pDlgImageResult->m_ptData[nIndex].x = i;
					m_pDlgImageResult->m_ptData[nIndex].y = j;
					m_pDlgImageResult->m_nDataCount = ++nIndex;
				}
			}
		}
	}

	m_pDlgImage->Invalidate();
	m_pDlgImageResult->Invalidate();
			}
		//}
	//}

	//for (int j = 0; j < nHeight; j++) {
	//	for (int i = 0; i <nWidth; i++) {
	//		if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) > radius * radius) {
	//			for (int k = 0; k < numEC; k++)
	//			{

	//				/*int x = rand()%300;
	//				int y = rand()%300;*/

	//				fn[j * nPitch + i] = yellow; // 원 외부 픽셀에 노란색 동그라미 그리기
	//			}
	//		}
	//	}
	//}

	//radius = 20;

	//for (int j = 0; j < nHeight; j++) {
	//	for (int i = 0; i < nWidth; i++) {
	//		if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) > radius * radius) {

	//			//int x = rand() % nWidth;
	//			//int y = rand() % nHeight;

	//			for (int k = 0; k < numEC; k++) {
	//				/*int x = rand() % nWidth;
	//				int y = rand() % nHeight;
	//				fn[y * nPitch + x] = yellow;*/
	//			}
	//			//fn[j * nPitch + i] = yellow; // 원 외부 픽셀에 노란색 동그라미 그리기
	//		}
	//	}
	//}

	//for (int k = 0; k < numEC; k++) {
	//	int randX = centerX + (rand() % (2 * radius) - radius);
	//	int randY = centerY + (rand() % (2 * radius) - radius);

	//	if (randX >= 0 && randX < nWidth && randY >= 0 && randY < nHeight) {
	//		fn[randY * nPitch + randX] = yellow; // 노란색 동그라미
	//	}
	//}


	//for (int j = centerY - radius; j <= centerY + radius; j++) {
	//	for (int i = centerX - radius; i <= centerX + radius; i++) {
	//		// 원의 중심에서 반지름 이내의 픽셀만 색칠
	//		if (!((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) <= radius * radius)) {
	//			//fn[j * nPitch + i] = 0x81; // 특정 색상 (여기서는 중간 회색)
	//			for (int k = 0; k < numEC; k++)
	//			{
	//				int randX = centerX + (rand() % (2 * radius) - radius);
	//				int randY = centerY + (rand() % (2 * radius) - radius);

	//				if (randX >= 0 && randX < nWidth && randY >= 0 && randY < nHeight) {

	//					fn[randY * nPitch + randX] = yellow;
	//				}
	//					//fn[randY * nPitch + randX] = yellow;

	//			}
	//				//fn[j * nPitch + i] = yellow;
	//				/*int randX = centerX + (rand() % (2 * radius) - radius);
	//				int randY = centerY + (rand() % (2 * radius) - radius);
	//				fn[randY * nPitch + randX] = yellow;*/




	//		}
	//	}
	//}








	//drawCircle(fn, nSttx, nStty, nRadius, nGray);

	//cout<<


	//memset(fn, 0, 640 * 480);
	//memset(fn, 0, 320 * 240);
	//for (int j = circle.top; j <circle.bottom; j++) {

	//	for (int i = circle.left; i < circle.right; i++) {

	//		fn[j * nPitch + i] = 0x81;//rand() % 0xff;//100;
	//	}

	//	/*int x = rand() % nWidth;
	//	int y = rand() % nHeight;


	//	fn[y * nPitch + x] = rand() % 0xff;*/

	//}



	//m_pDlgImage->Invalidate();
	//}

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//}


void CMFC43Dlg::OnBnClickedBtnGetData()
{
	unsigned char* fn = (unsigned char*)m_pDlgImage->m_image.GetBits();

	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();

	int nTh = 0x80;

	CRect rect(0, 0, nWidth, nHeight);



	int centerX = (rect.left + rect.right) / 2; // 중심 X 좌표
	int centerY = (rect.top + rect.bottom) / 2; // 중심 Y 좌표
	int radius = 20;   // 원의 반지름

	int nSumX = 0;
	int nSumY = 0;
	int nCount = 0;

	// 원 내부의 픽셀만 무게 중심을 계산
	for (int j = centerY - radius; j <= centerY + radius; j++) {
		for (int i = centerX - radius; i <= centerX + radius; i++) {
			// 원 내부의 픽셀만 고려
			if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) <= radius * radius) {
				if (fn[j * nPitch + i] > nTh) {
					nSumX += i;
					nSumY += j;
					nCount++;
				}
			}
		}
	}

	double dCenterX = (double)nSumX / nCount;
	double dCenterY = (double)nSumY / nCount;

	cout << "무게 중심 X 좌표: " << dCenterX << "\t무게 중심 Y 좌표: " << dCenterY << endl;






	//CRect rect(0, 0, nWidth, nHeight);

	//int nSumX = 0;
	//int nSumY = 0;
	//int nCount = 0;

	//for (int j = rect.top; j < rect.bottom; j++) {

	//	for (int i = rect.left; i < rect.right; i++) {

	//		//fn[j * nPitch + i] = rand() % 0xff;//100;
	//		if (fn[j * nPitch + i] > nTh) {
	//			nSumX += i;
	//			nSumY += j;
	//			nCount++;

	//		}
	//	}

	//	/*int x = rand() % nWidth;
	//	int y = rand() % nHeight;


	//	fn[y * nPitch + x] = rand() % 0xff;*/

	//}

	//double dCenterX = (double)nSumX / nCount;
	//double dCenterY = (double)nSumY / nCount;

	//cout << dCenterX << "\t" << dCenterY << endl;



	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMFC43Dlg::drawCircle(unsigned char* fn, int x, int y, int nRadius, int nGray)
{

	int nCenterX = x + nRadius;

	int nCenterY = y + nRadius;

	int dCenterX = x / 2;

	int dCenterY = y / 2;

	int nPitch = m_pDlgImage->m_image.GetPitch();//m_image.GetPitch();

	for (int j = y; j < y + nRadius * 2; j++) {
		for (int i = x; i < x + nRadius * 2; i++) {

			if (initCircle(i, j, nCenterX, nCenterY, nRadius))
				fn[j * nPitch + i] = nGray;
		}
	}

	cout << dCenterX << "\t" << dCenterY << endl;


}

bool CMFC43Dlg::initCircle(int i, int j, int nCenterX, int nCenterY, int nRadius)
{

	bool bRet = false;


	double dx = i - nCenterX;
	double dy = j - nCenterY;

	double dDist = dx * dx + dy * dy;

	if (dDist < nRadius * nRadius) {
		bRet = true;


	}


	return bRet;


}
