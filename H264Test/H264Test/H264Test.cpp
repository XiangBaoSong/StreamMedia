// H264Test.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//��� MbaffFrameFlag ���� 0
// 	fprintf(pFile,"<--��� MbaffFrameFlag ���� 0-->\n");
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
// 	fprintf(pFile,"<--��� MbaffFrameFlag ���� 0-->\n\n");

	//����MbaffFrameFlag ���� 1�����������й涨
// 	nXo = InverseRasterScan(((int)&nPicture)/2,16,32,729,0);
// 	nYo = InverseRasterScan(((int)&nPicture)/2,16,32,729,1);
// 
// 	//֡
// 	int nFrameYo_Y = nYo + (((int)&nPicture)%2)*16;
// 	//��
// 	int nFieldYo_Y = nYo + ((int)&nPicture)%2;
// 
// 	
// 	
// 
// 	//�����Ӻ��ָ�ɨ�����
// 	int nCount = 0;
// 	fprintf(pFile,"<--%d.�����Ӻ��ָ�ɨ����� -->\n",++nCount);
// 	for (int nIndex = 0;nIndex<4;nIndex++)
// 	{
// 		nX = InverseRasterScan(nIndex,4,4,8,0);
// 		nY = InverseRasterScan(nIndex,4,4,8,1);
// 
// 		fprintf(pFile,"x:%d,y:%d\n",nX,nY);
// 	}
// 	fprintf(pFile,"<--�����Ӻ��ָ�ɨ����� -->\n\n");
// 
// 	//����4��4���ȿ�ɨ�����
// 	fprintf(pFile,"<--%d.����4��4���ȿ�ɨ����� -->\n",++nCount);
// 	for (int nIndex = 0;nIndex<16;nIndex++)
// 	{
// 		nX = InverseRasterScan(nIndex/4,8,8,16,0)+InverseRasterScan(nIndex%4,8,8,16,0);
// 		nY = InverseRasterScan(nIndex/4,8,8,16,1)+InverseRasterScan(nIndex%4,8,8,16,1);
// 
// 		fprintf(pFile,"x:%d,y:%d\n",nX,nY);
// 	}
// 	fprintf(pFile,"<--����4��4���ȿ�ɨ����� -->\n\n");
// 
// 	fprintf(pFile,"<--%d.����8��8���ȿ�ɨ����� -->\n",++nCount);
// 	for (int nIndex = 0;nIndex<4;nIndex++)
// 	{
// 		nX = InverseRasterScan(nIndex,8,8,16,0);
// 		nY = InverseRasterScan(nIndex,8,8,16,1);
// 
// 		fprintf(pFile,"x:%d,y:%d\n",nX,nY);
// 	}
// 	fprintf(pFile,"<--����8��8���ȿ�ɨ����� -->\n");

	int nAddrA,nAddrB,nAddrC,nAddrD;
	bool bAddrA,bAddrB,bAddrC,bAddrD;

	fprintf(pFile,"<--%d.���ں���ַ��������Ե��Ƶ����� -->\n",++nCount);
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
	fprintf(pFile,"<--���ں���ַ��������Ե��Ƶ����� -->\n");


	if (pFile)
	{
		fclose(pFile);
	}

	return 0;
}

