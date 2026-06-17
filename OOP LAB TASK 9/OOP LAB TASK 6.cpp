#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Logger {
private:
    vector<string> logs;
    const size_t MAX_LOGS = 1000;

    string getCurrentTime() {
        time_t now = time(0);
        tm* localTime = localtime(&now);
        char buf[80];
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localTime);
        return string(buf);
    }

    void addLog(const string& severity, const string& message) {
        if (logs.size() >= MAX_LOGS) {
            logs.erase(logs.begin()); 
        }
        string logEntry = "[" + getCurrentTime() + "] [" + severity + "] " + message;
        logs.push_back(logEntry);
    }

public:
    void logInfo(const string& message) {
        addLog("INFO", message);
    }

    void logWarning(const string& message) {
        addLog("WARNING", message);
    }

    void logError(const string& message) {
        addLog("ERROR", message);
    }

    friend class Auditor;
};

class Auditor {
private:
    string password;

public:
    Auditor(const string& pwd) : password(pwd) {}

    vector<string> retrieveLogs(const Logger& logger, const string& inputPassword) {
        if (inputPassword == password) {
            return logger.logs; // safe copy
        }
        return {};
    }
};

int main() {
    Logger systemLogger;

    systemLogger.logInfo("Network module initialized");
    systemLogger.logWarning("Database module connection slow");
    systemLogger.logError("Authentication module failure");

    for (int i = 0; i < 1005; ++i) {
        systemLogger.logInfo("Filler log " + to_string(i));
    }

    Auditor authAuditor("secure123");
    vector<string> logs = authAuditor.retrieveLogs(systemLogger, "secure123");

    for (const auto& log : logs) {
        cout << log << endl;
    }

    return 0;
}

