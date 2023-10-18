// CDlgImage.cpp: 구현 파일
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
