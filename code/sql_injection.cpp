bool Database::findUser(const std::string& username, std::string& outHash) {
    const char* sql = "SELECT password_hash FROM users WHERE username = ?;";
    sqlite3_stmt* stmt = nullptr;
    
    sqlite3_prepare_v2(dbHandle, sql, -1, &stmt, nullptr);  // Compile SQL
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_TRANSIENT);  // Bind data
    
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        outHash = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        sqlite3_finalize(stmt);
        return true;
    }
    
    sqlite3_finalize(stmt);
    return false;
}