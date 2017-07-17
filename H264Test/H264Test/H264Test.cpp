// H264Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include "Algorithm.h"

int nPicture[576][729];

int _tmain(int argc, _TCHAR* argv[])
{
	int nX,nY;
	int nXo,nYo;
	int nValue = 0;
	int nCount = 0;

	for (int nXIndex = 0;nXIndex<576;nXIndex++)
	{
		for (int nYIndex = 0;nYIndex<729;nYIndex++)
		{
			nPicture[nXIndex][nYIndex] = nValue++;
		}
	}

	FILE* pFile = fopen("test.txt","w+");
	//如果 MbaffFrameFlag 等于 0
// 	fprintf(pFile,"<--如果 MbaffFrameFlag 等于 0-->\n");
// 	for (int nXIndex = 0;nXIndex<576/16+1;nXIndex++)
// 	{
// 		
// 		for(int nYIndex= 0;nYIndex<729/16+1;nYIndex++)
// 		{
// 			nX = InverseRasterScan(nXIndex,16,16,576,0);
// 			nY = InverseRasterScan(nYIndex,16,16,729,0);
// 
// 			fprintf(pFile,"x:%d,y:%d\n",nX,nY);
// 		}
// 	}
// 	fprintf(pFile,"<--如果 MbaffFrameFlag 等于 0-->\n\n");

	//否则（MbaffFrameFlag 等于 1），按照下列规定
// 	nXo = InverseRasterScan(((int)&nPicture)/2,16,32,729,0);
// 	nYo = InverseRasterScan(((int)&nPicture)/2,16,32,729,1);
// 
// 	//帧
// 	int nFrameYo_Y = nYo + (((int)&nPicture)%2)*16;
// 	//场
// 	int nFieldYo_Y = nYo + ((int)&nPicture)%2;
// 
// 	
// 	
// 
// 	//反向子宏块分割扫描过程
// 	int nCount = 0;
// 	fprintf(pFile,"<--%d.反向子宏块分割扫描过程 -->\n",++nCount);
// 	for (int nIndex = 0;nIndex<4;nIndex++)
// 	{
// 		nX = InverseRasterScan(nIndex,4,4,8,0);
// 		nY = InverseRasterScan(nIndex,4,4,8,1);
// 
// 		fprintf(pFile,"x:%d,y:%d\n",nX,nY);
// 	}
// 	fprintf(pFile,"<--反向子宏块分割扫描过程 -->\n\n");
// 
// 	//反向4×4亮度块扫描过程
// 	fprintf(pFile,"<--%d.反向4×4亮度块扫描过程 -->\n",++nCount);
// 	for (int nIndex = 0;nIndex<16;nIndex++)
// 	{
// 		nX = InverseRasterScan(nIndex/4,8,8,16,0)+InverseRasterScan(nIndex%4,8,8,16,0);
// 		nY = InverseRasterScan(nIndex/4,8,8,16,1)+InverseRasterScan(nIndex%4,8,8,16,1);
// 
// 		fprintf(pFile,"x:%d,y:%d\n",nX,nY);
// 	}
// 	fprintf(pFile,"<--反向4×4亮度块扫描过程 -->\n\n");
// 
// 	fprintf(pFile,"<--%d.反向8×8亮度块扫描过程 -->\n",++nCount);
// 	for (int nIndex = 0;nIndex<4;nIndex++)
// 	{
// 		nX = InverseRasterScan(nIndex,8,8,16,0);
// 		nY = InverseRasterScan(nIndex,8,8,16,1);
// 
// 		fprintf(pFile,"x:%d,y:%d\n",nX,nY);
// 	}
// 	fprintf(pFile,"<--反向8×8亮度块扫描过程 -->\n");

	int nAddrA,nAddrB,nAddrC,nAddrD;
	bool bAddrA,bAddrB,bAddrC,bAddrD;

	fprintf(pFile,"<--%d.相邻宏块地址及其可用性的推导过程 -->\n",++nCount);
	for (int nXIndex = 0;nXIndex<576/16+1;nXIndex++)
	{
		
		for(int nYIndex= 0;nYIndex<729/16+1;nYIndex++)
		{
			bAddrA = MacroAddrInerence(mbAddrA,nXIndex*(729/16+1)+nYIndex,nAddrA);
			bAddrB = MacroAddrInerence(mbAddrB,nXIndex*(729/16+1)+nYIndex,nAddrB);
			bAddrC = MacroAddrInerence(mbAddrC,nXIndex*(729/16+1)+nYIndex,nAddrC);
			bAddrD = MacroAddrInerence(mbAddrD,nXIndex*(729/16+1)+nYIndex,nAddrD);
	
			fprintf(pFile,"A:Addr=%d,b=%s B:Addr=%d,b=%s C:Addr=%d,b=%s D:Addr=%d,b=%s\n"
										  ,nAddrA,bAddrA?"Yes":"No"
										  ,nAddrB,bAddrB?"Yes":"No"
										  ,nAddrC,bAddrC?"Yes":"No"
										  ,nAddrD,bAddrD?"Yes":"No");
		}
	}
	fprintf(pFile,"<--相邻宏块地址及其可用性的推导过程 -->\n");


	if (pFile)
	{
		fclose(pFile);
	}

	return 0;
}

