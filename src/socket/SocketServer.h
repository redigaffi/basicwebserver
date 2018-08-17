//
// Created by jordi on 16/08/18.
//

#ifndef WEBSERVER_SOCKETSERVER_H
#define WEBSERVER_SOCKETSERVER_H
#include <netinet/in.h>

namespace Socket {
    class SocketServer {
        public:
            SocketServer(int port, int maxConnections);

            int getPort() const;
            void startServer();
            void acceptConnections();

    private:
            int port;
            int maxConnections;
            int socketFileDescriptor;
            sockaddr_in serverAddress;

    };
}


#endif //WEBSERVER_SOCKETSERVER_H
