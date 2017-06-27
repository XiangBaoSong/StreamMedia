// NetDLL.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "NetDLL.h"


// ���ǵ���������һ��ʾ��
NETDLL_API int nNetDLL=0;

// ���ǵ���������һ��ʾ����
NETDLL_API int fnNetDLL(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� NetDLL.h
CMySocket::CMySocket()
{
	memset(&m_stNetPara,0,sizeof m_stNetPara);

	return;
}

bool CMySocket::Init(const short sPort,const char* pszIP)
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

bool CMySocket::InitClient( const char* pszIp,const short sPort )
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

	m_stNetPara.enSocket = enClientSocket;

	return true;
}

bool CMySocket::InitService( const short sPort )
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

	m_stNetPara.enSocket = enListenSocket;

	return true;
}

CMySocket* CMySocket::GetConnect()
{
	if (true==m_stNetPara.enSocket)
	{
		return NULL;
	}

	CMySocket* pNetDLL = new CMySocket();
	if (NULL==pNetDLL)
	{
		return false;
	}

	pNetDLL->m_stNetPara.enSocket = enConnectedSocket;

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

CMySocket::~CMySocket( void )
{
	closesocket(m_stNetPara.sock);

	if (enConnectedSocket!=m_stNetPara.enSocket)
	{
		clear();
	}
}

int CMySocket::RecMsg(char* pszRecvBuffer,int nRecvLength)
{
	int nRecLen = recv(m_stNetPara.sock, pszRecvBuffer, nRecvLength, 0);

	return nRecLen;
}

int CMySocket::SendMsg(const char* pszSendBuffer,int nSendLength)
{
	int nSendLen = send(m_stNetPara.sock, pszSendBuffer, nSendLength, 0);

	return nSendLen;
}
