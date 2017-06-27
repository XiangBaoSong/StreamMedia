// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 NETDLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// NETDLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef NETDLL_EXPORTS
#define NETDLL_API __declspec(dllexport)
#else
#define NETDLL_API __declspec(dllimport)
#endif

#include "NetDataDefine.h"

// 此类是从 NetDLL.dll 导出的
class NETDLL_API CMySocket {
public:
	CMySocket(void);
	~CMySocket(void);
	// TODO: 在此添加您的方法。
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
