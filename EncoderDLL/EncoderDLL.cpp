// EncoderDLL.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "EncoderDLL.h"


// ���ǵ���������һ��ʾ��
ENCODERDLL_API int nEncoderDLL=0;

// ���ǵ���������һ��ʾ����
ENCODERDLL_API int fnEncoderDLL(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� EncoderDLL.h
CEncoderDLL::CEncoderDLL()
{
	return;
}
