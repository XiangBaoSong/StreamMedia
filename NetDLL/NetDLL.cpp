// NetDLL.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "NetDLL.h"


// ���ǵ���������һ��ʾ��
NETDLL_API int nNetDLL=0;

// ���ǵ���������һ��ʾ����
NETDLL_API int fnNetDLL(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� NetDLL.h
CNetDLL::CNetDLL()
{
	return;
}
