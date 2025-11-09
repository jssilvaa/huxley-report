void HuxleyServer::start(int port) {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    bind(serverSocket, ...);
    listen(serverSocket, 25);  // Backlog = max concurrent connections
    
    while (running) {
        int clientSocket = accept(serverSocket, ...);
        
        // Spawn thread for this client
        ClientConnection* client = new ClientConnection(clientSocket, authManager, messageRouter);
        pthread_t thread_id;
        pthread_create(&thread_id, nullptr, ClientConnection::threadEntry, client);
        pthread_detach(thread_id);  // Auto-cleanup on exit
        
        clients.push_back(client);
    }
}