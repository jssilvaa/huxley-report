class MessageRouter {
private:
    std::map<std::string, ClientConnection*> activeClients;
    std::mutex clientsMutex;

public:
    void registerClient(const std::string& username, ClientConnection* handler) {
        std::lock_guard<std::mutex> lock(clientsMutex);  // Acquire lock
        activeClients[username] = handler;
        // Lock automatically released when lock_guard destructor runs
    }
    
    bool routeMessage(const std::string& sender, const std::string& recipient, 
                      const std::string& message) {
        std::lock_guard<std::mutex> lock(clientsMutex);
        
        auto it = activeClients.find(recipient);
        if (it != activeClients.end()) {
            // Recipient online—deliver immediately
            it->second->sendMessage(sender, message);
            return true;
        }
        
        // Recipient offline—queue in database
        return false;  // Caller will queue
    }
};