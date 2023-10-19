#pragma once

// CProcess 명령 대상

class CProcess : public CObject
{
public:
	CProcess();
	virtual ~CProcess();


	int getStartInfo(CImage *pimage,int nTh);
};


