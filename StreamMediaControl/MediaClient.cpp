// MediaClient.cpp : 实现文件
//

#include "stdafx.h"
#include "StreamMediaControl.h"
#include "MediaClient.h"
#include "afxdialogex.h"


// CMediaClient 对话框

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


// CMediaClient 消息处理程序


void CMediaClient::OnBnClickedSystemconfigButton()
{
	// TODO: 在此添加控件通知处理程序代码
}
