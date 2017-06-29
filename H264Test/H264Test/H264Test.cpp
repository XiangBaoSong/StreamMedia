// H264Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

enum enDescribe
{
	enInvalid = 0
};

//1.宏块反向扫描
int InverseRasterScan(int nAddr,int nWidth,int nHeight,int nTotalWidth,bool bFlag);

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

int InverseRasterScan(int nAddr,int nWidth,int nHeight,int nTotalWidth,bool bFlag)
{
	if(0==nWidth)
	{
		return enInvalid;
	}

	int nRet = 0;

	if (!bFlag)
	{
		nRet = (nAddr%(nTotalWidth/nWidth))*nWidth;
	}
	else
	{
		nRet = (nAddr/(nTotalWidth/nWidth))*nHeight;
	}

	return nRet;
}