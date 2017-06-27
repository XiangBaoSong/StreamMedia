
//  
#ifdef WIN32 

#include "winsock2.h"  
#pragma comment(lib, "ws2_32.lib")  

#endif

enum enSocketType
{
	enClientSocket = 0,
	enListenSocket,
	enConnectedSocket
};

struct stNetPara
{
	SOCKET      sock;
	SOCKADDR_IN sockAdde_in;
	WSADATA     wsd;

	enSocketType enSocket;
};