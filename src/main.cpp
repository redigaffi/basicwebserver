#include <iostream>
#include "socket/SocketServer.h"

using std::cout;
using std::endl;

int main() {
    Socket::SocketServer socketServer(8080, 5);
    cout << socketServer.getPort() << endl;
    socketServer.startServer();
    socketServer.acceptConnections();

    std::cout << "Hello, World!" << endl;
    return 0;
}