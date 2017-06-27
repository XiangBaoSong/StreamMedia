#pragma once


// CMediaClient 对话框

class CMediaClient : public CDialogEx
{
	DECLARE_DYNAMIC(CMediaClient)

public:
	CMediaClient(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMediaClient();

// 对话框数据
	enum { IDD = IDD_MEDIA_CONTROL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSystemconfigButton();
};
