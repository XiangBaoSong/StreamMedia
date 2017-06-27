// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� NETDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// NETDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef NETDLL_EXPORTS
#define NETDLL_API __declspec(dllexport)
#else
#define NETDLL_API __declspec(dllimport)
#endif

#include "NetDataDefine.h"

// �����Ǵ� NetDLL.dll ������
class NETDLL_API CMySocket {
public:
	CMySocket(void);
	~CMySocket(void);
	// TODO: �ڴ�������ķ�����
	bool InitClient(const char* pszIp,const short sPort);
	bool InitService(const short sPort);

	CMySocket* GetConnect();
	
	int RecMsg(char* pszRecvBuffer,int nRecvLength);
	int SendMsg(const char* pszSendBuffer,int nSendLength);

	void DisConnect();

	SOCKET GetSocket();
	const char* GetIP();
	//bool m_bService;
private:
	stNetPara m_stNetPara;
	bool Init(const short sPort,const char* pszIP=NULL);

	char szErr[256];
};

extern NETDLL_API int nNetDLL;

NETDLL_API int fnNetDLL(void);
