#ifndef _DATAGRAMSOCKET_H_
#define _DATAGRAMSOCKET_H_

#include "SocketListener.h"
#include "Socket.h"
#include <winsock.h>
#pragma comment(lib, "wsock32.lib")

class CDatagramSocket
{
    public:
    CDatagramSocket();
    ~CDatagramSocket();
    void SetListener(ISocketListener *pListener);
    bool Open(int nPort);
    void Close(void);
    int GetPort(void);

    private:
    int m_nPort;
    SOCKET m_Socket;
    CSocket *m_pSocket;
    bool m_bClosed;
    ISocketListener *m_pListener;
};

#endif
