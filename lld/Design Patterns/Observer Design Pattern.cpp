#include <bits/stdc++.h>
using namespace std;

//
// Observer Interface
// Any class that wants to receive notifications must implement this
//
class ISubscriber {
public:
    // Called by the Subject (Group) when sending notifications
    virtual void notify(string message) = 0;
};


//
// Concrete Observer: User
//
class User : public ISubscriber {
    int id;

public:
    User(int id) {
        this->id = id;
    }

    int getId() {
        return id;
    }

    // Implementation of the observer's update/notify method
    void notify(string message) {
        cout << "User" + to_string(id) + " " + message << endl;
    }
};


//
// Subject: Group
// Maintains list of subscribers and notifies them
//
class Group {
    vector<ISubscriber*> users; // List of observers

public:

    // Subscribe a user (add observer)
    void subscribe(User* user) {
        users.push_back(user);
    }

    // Unsubscribe a user (remove observer)
    void unsubscribe(User* user) {
        // C++20 erase() removes all matching entries cleanly
        erase(users, user);
    }

    // Notify all subscribed observers
    void notify(string msg) {
        for (auto user : users) {
            user->notify(msg);
        }
    }
};


//
// Driver Code
//
int main() {
    Group* group = new Group();

    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3);

    // Subscribing users
    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    // First notification
    group->notify("msg");

    // Unsubscribing one user
    group->unsubscribe(user1);

    // Second notification
    group->notify("new msg");

    return 0;
}
