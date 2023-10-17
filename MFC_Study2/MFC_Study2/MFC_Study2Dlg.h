
// MFC_Study2Dlg.h: 헤더 파일
//

#pragma once


// CMFCStudy2Dlg 대화 상자
class CMFCStudy2Dlg : public CDialogEx
{

private:
	CImage m_image;
	BOOL validImgPos(int x,int y);
	BOOL isInsideEllipse(int x, int y, int centerX, int centerY, int radiusX, int radiusY);
// 생성입니다.
public:
	CMFCStudy2Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_STUDY2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnImage();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	void UpdateDisplay();
	void moveRect();
	afx_msg void OnBnClickedBtnAct();
	void moveElipse();
};
