// H264Test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

enum enDescribe
{
	enInvalid = 0
};

//1.��鷴��ɨ��
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