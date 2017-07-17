#include "StdAfx.h"
#include "Algorithm.h"


CAlgorithm::CAlgorithm(void)
{
}


CAlgorithm::~CAlgorithm(void)
{
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

bool MacroAddrInerence(enMicroAddrType eMicroAddrType, int nCurrentAddr,int& nResultAddr )
{
	int nPicWidthInMbs = MicrPicWidthInMbs;

	nResultAddr = nCurrentAddr%nPicWidthInMbs;
	if (0==nResultAddr)
	{
		return false;
	}

	switch(eMicroAddrType)
	{
	case mbAddrA:nResultAddr = nCurrentAddr-1;break;
	case mbAddrB:nResultAddr = nCurrentAddr - nPicWidthInMbs;break;
	case mbAddrC:nResultAddr = nCurrentAddr - nPicWidthInMbs + 1;break;
	case mbAddrD:nResultAddr = nCurrentAddr - nPicWidthInMbs - 1;break;
	}

	bool bRet = false;

	if (nResultAddr<0)
	{
		bRet = false;
	}
	else if (nResultAddr>nCurrentAddr)
	{
		bRet = false;
	}

	return bRet;
}

bool MacroAddrInerenceMBAFF( enMicroAddrType eMicroAddrType,int nCurrentAddr,int& nResultAddr )
{
	int nPicWidthInMbs = MicrPicWidthInMbs;

	nResultAddr = (nCurrentAddr/2)%nPicWidthInMbs;
	if (0==nResultAddr)
	{
		return false;
	}

	switch(eMicroAddrType)
	{
	case mbAddrA:nResultAddr = 2*(nCurrentAddr/2-1);break;
	case mbAddrB:nResultAddr = 2*(nCurrentAddr/2 - nPicWidthInMbs);break;
	case mbAddrC:nResultAddr = 2*(nCurrentAddr/2 - nPicWidthInMbs + 1);break;
	case mbAddrD:nResultAddr = 2*(nCurrentAddr/2 - nPicWidthInMbs - 1);break;
	}

	bool bRet = false;

	if (nResultAddr<0)
	{
		bRet = false;
	}
	else if (nResultAddr>nCurrentAddr)
	{
		bRet = false;
	}
	else if (0)//这里还有一种情况是地址不在同一条带还不知道怎么判断
	{

	}

	return bRet;
}

stInerrenceRes LumuniaInerrenceXn8x8( int nBlockIdx,int nXD )
{
	stInerrenceRes stRes;
	stRes.nIndex = (nBlockIdx%2)*8+nXD;

	return stRes;
}

stInerrenceRes LumuniaInerrenceYn8x8( int nBlockIdx,int nYD )
{
	stInerrenceRes stRes;
	stRes.nIndex= (nBlockIdx/2)*8+nYD;

	return stRes;
}

stInerrenceRes LumuniaInerrenceXn4x4( int nXPos,int nXD )
{
	stInerrenceRes stRes;
	stRes.nIndex = nXD + nXPos;

	return stRes;
}

stInerrenceRes LumuniaInerrenceYn4x4( int nYPos,int nYD )
{
	stInerrenceRes stRes;

	stRes.nIndex = nYPos + nYD;

	return stRes;
}

stInerrenceRes GetChromaInerrence4x4( enPosition enPos,int nChroma_format_idc,int nBlockIdx,int nDiference )
{
	int nX = -1,nY = -1;
	stInerrenceRes stRes;


	switch(nChroma_format_idc)
	{
	case 1:
	case 2:
		{
			nX = InverseRasterScan(nBlockIdx,4,4,8,0);
			nY = InverseRasterScan(nBlockIdx,4,4,8,1);
		}break;
	case 3:
		{
			nX = InverseRasterScan(nBlockIdx/4,8,8,16,0)
				+InverseRasterScan(nBlockIdx%4,8,8,16,0);
			nY = InverseRasterScan(nBlockIdx/4,8,8,16,1)
				+InverseRasterScan(nBlockIdx%4,8,8,16,1);
		}break;
	}

	int xN = nX + nDiference;
	int yN = nY + nDiference;

	if (enX==enPos)
	{
		stRes.nIndex = xN;
	}else if (enY==enPos)
	{
		stRes.nIndex = yN;
	}

	return stRes;
}
