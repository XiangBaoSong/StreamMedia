// VideoDLL.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "VideoDLL.h"


// ���ǵ���������һ��ʾ��
VIDEODLL_API int nVideoDLL=0;

// ���ǵ���������һ��ʾ����
VIDEODLL_API int fnVideoDLL(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� VideoDLL.h
CVideoDLL::CVideoDLL()
{
	return;
}
