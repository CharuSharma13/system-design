#include <bits/stdc++.h>
#include <mutex>
using namespace std;

class Logger {
private:
    static Logger* instance;   // Single instance pointer
    static mutex mtx;          // Mutex for thread safety

    Logger() {}  // Private constructor

public:
    // Delete copy constructor and assignment operator
    Logger(const Logger&) = delete;
    void operator=(const Logger&) = delete;

    // Static method to get the singleton instance
    static Logger* getInstance() {
        // First check (without locking) for performance
        if (instance == nullptr) {
            mtx.lock();  // Acquire lock only if instance might be null

            // Second check (inside lock) to ensure no other thread created instance
            if (instance == nullptr) {
                instance = new Logger();
            }

            mtx.unlock();  // Release lock
        }

        return instance;
    }

    // Example method
    void log(const string& msg) {
        cout << "[LOG]: " << msg << endl;
    }
};

// Initialize static members
Logger* Logger::instance = nullptr;
mutex Logger::mtx;

int main() {
    Logger* a = Logger::getInstance();
    Logger* b = Logger::getInstance();

    a->log("Hello");
    b->log("World");

    cout << "Same instance? " << (a == b ? "YES" : "NO") << endl;

    return 0;
}
