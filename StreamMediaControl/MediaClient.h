#pragma once


// CMediaClient �Ի���

class CMediaClient : public CDialogEx
{
	DECLARE_DYNAMIC(CMediaClient)

public:
	CMediaClient(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMediaClient();

// �Ի�������
	enum { IDD = IDD_MEDIA_CONTROL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSystemconfigButton();
};
