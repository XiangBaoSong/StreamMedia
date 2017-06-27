// NetDLL.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "NetDLL.h"


// 这是导出变量的一个示例
NETDLL_API int nNetDLL=0;

// 这是导出函数的一个示例。
NETDLL_API int fnNetDLL(void)
{
	return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 NetDLL.h
CNetDLL::CNetDLL()
{
	return;
}

bool CNetDLL::Init(const short sPort,const char* pszIP)
{
	if(WSAStartup(MAKEWORD(2,2), &m_stNetPara.wsd) != 0)
	{
		return false;
	}

	m_stNetPara.sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET==m_stNetPara.sock)
	{
		return false;
	}

	m_stNetPara.sockAdde_in.sin_family = AF_INET;
	m_stNetPara.sockAdde_in.sin_port = htons(sPort);
	if (NULL==pszIP)
	{
		m_stNetPara.sockAdde_in.sin_addr.s_addr  = INADDR_ANY;
	}
	else
	{
		m_stNetPara.sockAdde_in.sin_addr.s_addr  = inet_addr(pszIP);  
	}
}

bool CNetDLL::InitClient( const char* pszIp,const short sPort )
{
	if (NULL==pszIp)
	{
		return false;
	}

	bool bRet = Init(sPort,pszIp);
	if (!bRet)
	{
		return false;
	}

	if (SOCKET_ERROR == connect(m_stNetPara.sock,(LPSOCKADDR)&m_stNetPara.sockAdde_in, sizeof(m_stNetPara.sockAdde_in)))
	{
		return false;
	}

	return true;
}

bool CNetDLL::InitService( const short sPort )
{
	bool bRet = Init(sPort);
	if (!bRet)
	{
		return false;
	}

	int nRet = bind(m_stNetPara.sock, (LPSOCKADDR)&m_stNetPara.sockAdde_in, sizeof(m_stNetPara.sockAdde_in)); 
	if (SOCKET_ERROR==nRet)
	{
		return false;
	}

	nRet = listen(m_stNetPara.sock,20);
	if (SOCKET_ERROR==nRet)
	{
		return false;
	}

	return true;
}

CNetDLL* CNetDLL::GetConnect()
{
	if (true==m_stNetPara.bClient)
	{
		return NULL;
	}

	CNetDLL* pNetDLL = new CNetDLL();
	if (NULL==pNetDLL)
	{
		return false;
	}

	int nAddLen = sizeof(m_stNetPara.sockAdde_in);
	pNetDLL->m_stNetPara.sock = accept(pNetDLL->m_stNetPara.sock,
		(sockaddr FAR*)&m_stNetPara.sockAdde_in, &nAddLen); 

	if (INVALID_SOCKET==pNetDLL->m_stNetPara.sock)
	{
		delete pNetDLL;
		return NULL;
	}

	return pNetDLL;
}
