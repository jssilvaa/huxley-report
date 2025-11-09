Database::Database(const std::string& filename) {
    sqlite3_open(filename.c_str(), &dbHandle);
    
    // Enable WAL mode
    char* errMsg;
    sqlite3_exec(dbHandle, "PRAGMA journal_mode=WAL;", nullptr, nullptr, &errMsg);
    sqlite3_exec(dbHandle, "PRAGMA synchronous=NORMAL;", nullptr, nullptr, &errMsg);
    // NORMAL: fsync() only at checkpoints (balance safety vs speed)
}