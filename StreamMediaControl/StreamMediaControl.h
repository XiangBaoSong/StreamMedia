
// StreamMediaControl.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CStreamMediaControlApp:
// �йش����ʵ�֣������ StreamMediaControl.cpp
//

class CStreamMediaControlApp : public CWinApp
{
public:
	CStreamMediaControlApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CStreamMediaControlApp theApp;