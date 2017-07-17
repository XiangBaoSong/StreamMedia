#pragma once

#ifndef BYTE
typedef    unsigned char BYTE;
#endif

#define MicrPicWidthInMbs 729/16

enum enDescribe
{
	enInvalid = 0
};

enum enMicroAddrType
{
	mbAddrA = 0,
	mbAddrB,
	mbAddrC,
	mbAddrD
};

enum enPosition\
{
	enX = 0,
	enY
};

struct stInerrenceRes
{
	bool bUse;
	int nIndex;
};

class CAlgorithm
{
public:
	CAlgorithm(void);
	~CAlgorithm(void);
};

//1.宏块反向扫描
int InverseRasterScan(int nAddr,int nWidth,int nHeight,int nTotalWidth,bool bFlag);

//2-1.相邻宏块地址及可用性推导
bool MacroAddrInerence(enMicroAddrType eMicroAddrType,int nCurrentAddr,int& nResultAddr);
//2-2.相邻宏块地址及可用性推导
bool MacroAddrInerenceMBAFF(enMicroAddrType eMicroAddrType,int nCurrentAddr,int& nResultAddr);

//6.4.8.2 相邻的8×8亮度块的推导过程 
stInerrenceRes LumuniaInerrenceXn8x8(int nBlockIdx,int nXD);
stInerrenceRes LumuniaInerrenceYn8x8(int nBlockIdx,int nYD);

int GetBlockIdx();

//6.4.8.3 相邻的4×4亮度块的推导过程
stInerrenceRes LumuniaInerrenceXn4x4(int nBlockIdx,int nXD);
stInerrenceRes LumuniaInerrenceYn4x4(int nBlockIdx,int nYD);

//6.4.8.4 相邻的4×4色度块的推导过程 
stInerrenceRes GetChromaInerrence4x4(enPosition enPos,int nChroma_format_idc,int nBlockIdx,int nDiference);
