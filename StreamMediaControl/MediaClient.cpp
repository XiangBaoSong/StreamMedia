// MediaClient.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StreamMediaControl.h"
#include "MediaClient.h"
#include "afxdialogex.h"


// CMediaClient �Ի���

IMPLEMENT_DYNAMIC(CMediaClient, CDialogEx)

CMediaClient::CMediaClient(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMediaClient::IDD, pParent)
{

}

CMediaClient::~CMediaClient()
{
}

void CMediaClient::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMediaClient, CDialogEx)
	ON_BN_CLICKED(IDC_SystemConfig_BUTTON, &CMediaClient::OnBnClickedSystemconfigButton)
END_MESSAGE_MAP()


// CMediaClient ��Ϣ�������


void CMediaClient::OnBnClickedSystemconfigButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
