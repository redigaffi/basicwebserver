//
// Created by jordi on 16/08/18.
//

#include <sys/socket.h>

#include <iostream>
#include <unistd.h>
#include "SocketServer.h"

namespace Socket {
    SocketServer::SocketServer(int port, int maxConnections) {
        this->port = port;
        this->maxConnections = maxConnections;
    }

    int SocketServer::getPort() const {
        return port;
    }

    void SocketServer::startServer() {
        this->serverAddress.sin_family = AF_INET;
        this->serverAddress.sin_addr.s_addr = INADDR_ANY;
        this->serverAddress.sin_port = htons(this->port);
        int serverAddressSize = sizeof(this->serverAddress);

        int opt = 1;

        this->socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
        setsockopt(this->socketFileDescriptor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
        bind(this->socketFileDescriptor, (sockaddr *) &serverAddress, (socklen_t)serverAddressSize);
        listen(this->socketFileDescriptor, this->maxConnections);

    }

    void SocketServer::acceptConnections() {
        int serverAddressSize = sizeof(this->serverAddress);
        int new_socket;
        char buffer[2048] = {'\0'};
        int sizeBuffer = sizeof(buffer);

        while (true) {
            if ((new_socket = accept(this->socketFileDescriptor, (sockaddr*) &this->serverAddress, (socklen_t*) &serverAddressSize)) >= 0) {
                ::std::cout << "new connection " << new_socket << ::std::endl;


                int bytesRead = recv( new_socket , buffer, 2047, 0);
                ::std::cout << bytesRead << ::std::endl;

                ::std::cout << "end";

                ::std::cout << buffer;
            }
        }
    }


}