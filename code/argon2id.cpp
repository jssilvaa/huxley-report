#include <sodium.h>

std::string AuthManager::hashPassword(const std::string& password) {
    char hashed[crypto_pwhash_STRBYTES];
    
    if (crypto_pwhash_str(
        hashed,
        password.c_str(),
        password.length(),
        crypto_pwhash_OPSLIMIT_INTERACTIVE,  // 2 iterations
        crypto_pwhash_MEMLIMIT_INTERACTIVE   // 64 MB memory
    ) != 0) {
        throw std::runtime_error("Out of memory during hashing");
    }
    
    return std::string(hashed);
}

bool AuthManager::verifyPassword(const std::string& password, 
                                  const std::string& hash) {
    return crypto_pwhash_str_verify(
        hash.c_str(),
        password.c_str(),
        password.length()
    ) == 0;
}