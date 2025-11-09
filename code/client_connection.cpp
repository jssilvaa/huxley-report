void ClientConnection::run() {
    while (true) {
        char buffer[4096];
        int bytesRead = recv(socketFd, buffer, sizeof(buffer), 0);
        
        if (bytesRead <= 0) break;  // Disconnect
        
        std::string command(buffer, bytesRead);
        std::string response = processCommand(command);  // Calls AuthManager/MessageRouter
        
        send(socketFd, response.c_str(), response.length(), 0);
    }
    
    // Cleanup on exit
    messageRouter->unregisterClient(username);
}