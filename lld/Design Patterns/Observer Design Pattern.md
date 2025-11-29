<img width="1131" height="616" alt="image" src="https://github.com/user-attachments/assets/11acd2ed-66f0-4669-a6d5-5177970fe690" />

# Observer Design Pattern

## What is the Observer Pattern?

The **Observer Pattern** is a design pattern where one object, called the **Subject**, maintains a list of other objects, called **Observers**, and automatically **notifies** them whenever its state changes.

This allows multiple components to react to the same event without tightly coupling them together.

In simple terms:

- **The Subject broadcasts updates**
- **Observers receive updates automatically**

This keeps the system flexible and loosely coupled.

---

## Components

### 1. Subject

The **Subject** is the object whose state or data changes.

It provides three main methods:

- **`registerObserver(observer)`**  
  Used by Observers to subscribe for updates.

- **`unregisterObserver(observer)`**  
  Used by Observers to unsubscribe when they no longer need updates.

- **`notify()`**  
  Called whenever the Subject’s state changes.  
  It loops through all registered Observers and calls their `update()` method.

**Subject = “I will notify all observers when something changes.”**

---

### 2. Observer (Interface)

The **Observer** is any object that wants to be notified of changes in the Subject.

Observers must implement a common interface, usually containing:

- **`update(data)`**  
  This method is called by the Subject when sending notifications.

Because all observers share the same interface, the Subject doesn’t care what type of objects the Observers are—it only knows that they have an `update()` method.

**Observer = “Tell me when something happens.”**

---

## How the Pattern Works (Simple Steps)

1. An Observer subscribes to the Subject using `registerObserver()`.
2. When the Subject’s state changes, it calls `notify()`.
3. `notify()` triggers the `update()` method on every subscribed Observer.
4. Each Observer reacts in its own way.

---

## One-Line Summary

**Observers subscribe to a Subject → Subject changes → Subject calls `notify()` → each Observer’s `update()` method is triggered automatically.**

