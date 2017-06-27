
//  
#ifdef WIN32 

#include "winsock2.h"  
#pragma comment(lib, "ws2_32.lib")  

#endif

struct stNetPara
{
	SOCKET      sock;
	SOCKADDR_IN sockAdde_in;
	WSADATA     wsd;

	bool bClient;
};