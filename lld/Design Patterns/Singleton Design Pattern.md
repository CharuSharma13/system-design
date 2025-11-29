# Step-by-Step Explanation of Singleton Pattern (Logger Example)

## Step 1: The Problem Without Singleton

Imagine a Logger class:

```cpp
class Logger {
public:
    Logger() {}
    void log(string msg) { cout << "[LOG]: " << msg << endl; }
};
```

### What happens?

```cpp
Logger l1;
Logger l2;

l1.log("Hello");
l2.log("World");
```

* Each `Logger` object is **separate**.
* If your program expects **only one logger**, this breaks the design.
* Multiple instances → inconsistent state → resource conflicts.

**Problem:** Multiple instances are created, which is undesirable.

---

## Step 2: Using Static for Single Instance

We can make a **single instance accessible globally**:

```cpp
class Logger {
private:
    static Logger* instance;  // only one instance

    Logger() {}

public:
    static Logger* getInstance() {
        if (instance == nullptr)
            instance = new Logger();
        return instance;
    }

    void log(string msg) { cout << "[LOG]: " << msg << endl; }
};

Logger* Logger::instance = nullptr;
```

### What this fixes:

* All parts of the program get the **same Logger object** using `Logger::getInstance()`.

---

## Step 3: Making It Thread-Safe with Lock

If multiple threads call `getInstance()` simultaneously, **multiple instances** may be created.

Solution: **Use a mutex**:

```cpp
static mutex mtx;

static Logger* getInstance() {
    mtx.lock();
    if (instance == nullptr)
        instance = new Logger();
    mtx.unlock();
    return instance;
}
```

### How it works:

* `mtx.lock()` ensures only **one thread** creates the instance.
* `mtx.unlock()` releases the lock.

### ⚠️ Problem:

* Manual `lock()`/`unlock()` is **not exception safe**.
* If an exception occurs between lock and unlock, mutex stays locked → deadlock.

**Better:** Use `lock_guard` or `unique_lock`:

```cpp
lock_guard<mutex> lock(mtx);  // automatically unlocks when going out of scope
```

* RAII principle ensures **automatic release**, even if exceptions occur.

---

## Step 4: Double-Checked Locking (Optimize)

Locking every time `getInstance()` is called is **slow**.

**Double-checked locking** reduces overhead:

```cpp
static Logger* getInstance() {
    if (instance == nullptr) {        // 1st check (no lock)
        mtx.lock();
        if (instance == nullptr) {    // 2nd check (inside lock)
            instance = new Logger();
        }
        mtx.unlock();
    }
    return instance;
}
```

### How it works:

1. **First check**: Avoid locking if instance is already created.
2. **Lock**: Only lock when instance might need to be created.
3. **Second check**: Ensure no other thread created the instance while waiting for the lock.
4. **Unlock**: Release mutex after creation.

✅ **Benefits**:

* Thread-safe
* Locking only happens **once**
* Efficient for multithreaded programs

---

## Step 5: Best Practices

* Use `lock_guard` or `unique_lock` instead of manual `lock()`/`unlock()` to **avoid deadlocks**.
* Or use **Meyers' Singleton** in C++11:

```cpp
static Logger& getInstance() {
    static Logger instance;  // thread-safe, lazy initialization
    return instance;
}
```

* Thread-safe without explicit mutex
* Simpler and safer than double-checked locking

---

### ✅ Summary

| Step | Solution               | Pros                    | Cons                              |
| ---- | ---------------------- | ----------------------- | --------------------------------- |
| 1    | No Singleton           | Simple                  | Multiple instances possible       |
| 2    | Static instance        | Single instance         | Not thread-safe                   |
| 3    | Lock/mutex             | Thread-safe             | Manual lock is not exception safe |
| 4    | Double-checked locking | Thread-safe + efficient | Still manual lock/unlock          |
| 5    | Meyers’ Singleton      | Thread-safe + simple    | C++11 or later only               |
