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

//1.��鷴��ɨ��
int InverseRasterScan(int nAddr,int nWidth,int nHeight,int nTotalWidth,bool bFlag);

//2-1.���ں���ַ���������Ƶ�
bool MacroAddrInerence(enMicroAddrType eMicroAddrType,int nCurrentAddr,int& nResultAddr);
//2-2.���ں���ַ���������Ƶ�
bool MacroAddrInerenceMBAFF(enMicroAddrType eMicroAddrType,int nCurrentAddr,int& nResultAddr);

//6.4.8.2 ���ڵ�8��8���ȿ���Ƶ����� 
stInerrenceRes LumuniaInerrenceXn8x8(int nBlockIdx,int nXD);
stInerrenceRes LumuniaInerrenceYn8x8(int nBlockIdx,int nYD);

int GetBlockIdx();

//6.4.8.3 ���ڵ�4��4���ȿ���Ƶ�����
stInerrenceRes LumuniaInerrenceXn4x4(int nBlockIdx,int nXD);
stInerrenceRes LumuniaInerrenceYn4x4(int nBlockIdx,int nYD);

//6.4.8.4 ���ڵ�4��4ɫ�ȿ���Ƶ����� 
stInerrenceRes GetChromaInerrence4x4(enPosition enPos,int nChroma_format_idc,int nBlockIdx,int nDiference);
