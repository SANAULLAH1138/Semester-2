#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

const string LOG_FILE = "log.txt";
const int MAX_SIZE = 1024 * 1024; // 1MB

int getNextLogNumber() {
    int i = 1;
    while (fs::exists("log" + to_string(i) + ".txt")) {
        i++;
    }
    return i;
}

void writeLog(const string& message) {
    if (fs::exists(LOG_FILE) && fs::file_size(LOG_FILE) >= MAX_SIZE) {
        int logNum = getNextLogNumber();
        fs::rename(LOG_FILE, "log" + to_string(logNum) + ".txt");
    }

    ofstream logFile(LOG_FILE, ios::app);
    logFile << message << endl;
    logFile.close();
}

int main() {
    for (int i = 0; i < 100000; i++) {
        writeLog("Log message #" + to_string(i));
    }
    cout << "Logs written. Check for rotated files." << endl;
    return 0;
}

