
// MediaService.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMediaServiceApp:
// �йش����ʵ�֣������ MediaService.cpp
//

class CMediaServiceApp : public CWinApp
{
public:
	CMediaServiceApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMediaServiceApp theApp;