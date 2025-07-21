//
// Created by sebas on 21-Jul-25.
//

#ifndef INPUT_HPP
#define INPUT_HPP
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
int MakeServerSocketV4(int port){
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    listen(serverSocket, 5);
    int clientSocket = accept(serverSocket, nullptr, nullptr);
    char buffer[1024] = {0};
    recv(clientSocket, buffer, sizeof(buffer), 0);
    cout << "Message from client: " << buffer << endl;
}

#endif //INPUT_HPP
