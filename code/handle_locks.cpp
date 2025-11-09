void handleMessage(...) {
    {
        std::lock_guard<std::mutex> lock1(messageRouter->clientsMutex);
        // ... route message ...
    }  // Release clientsMutex
    
    {
        std::lock_guard<std::mutex> lock2(statusManager->ledMutex);
        // ... update LED ...
    }  // Release ledMutex
}