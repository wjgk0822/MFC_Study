// CProcess.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_4-3.h"
#include "CProcess.h"


// CProcess

CProcess::CProcess()
{
}

CProcess::~CProcess()
{
}

int CProcess::getStartInfo(CImage *pimage,int nTh)
{
	unsigned char* fn = (unsigned char*)pimage->GetBits();

	int nWidth = pimage->GetWidth();
	int nHeight = pimage->GetHeight();
	int nPitch = pimage->GetPitch();

	int nSum = 0;

	for (int k = 0; k < nWidth * nHeight; k++) {
		if (fn[k] > nTh)
			nSum++;
	}

	return nSum;
}


// CProcess 멤버 함수
