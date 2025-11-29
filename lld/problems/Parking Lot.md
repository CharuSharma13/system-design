[PlantUml](https://kroki.io/plantuml/svg/eNq1WEuT2jgQvvtXqHJZUxlSu3skDBUHPISKeRQ4U5WjRmhAhZBYySZhN_PfV5JtIT-gksHRZazuVqvV_fVj-CATKJJ0Tz25I-wABdyDPWccbQXfY5CIFDuc9YGAv_7-0_P-APevWOpYaT2GnybDKFy9Vt0Boh3cYPDmEW8Joli-Af95WjFm6R7kxBX5F-dkvVbTIIrsbhqOJl-mdhsFy3Fodi-e-UNYgsUzRLjQ5miiBGEm8YLCBIMeWCWCsI3lSn1tzzXC1YsolBIMofgpfaVDU55wgU4_a0vpbCxStPuVY8Wr-z-6XW1unXg2p84z13kvbcFlESw_T2ZjsFrM49sxs4BC4XoDVgeeGOBUAp7zNdvxmFTbWbp_wkL5SwlbxjF_uA255RAZHCGh8Iliv6P4T5xTDJnlc4TSw8nPj3XOGiFSYfHPhA1OVvZ6o8o1QHMVygz9Our4XjnBqHKoS7xJKRQV6vyIhUby2tANw_VLBouKvppAVXVNoHxLa3jRCR0-htFr1WUuiPAR0xwBVH_Xwq8xIdU-IjLpO48beHlcAkoNykxs6lLqwdkl3e7AdU5LfhjOZ8Mvy2U4G3690RMc7aaQqewpyhZE_6REFBgVWOFa6l0LIbTJHi-DOBx_Bb79WgRxHC5nnfZKQCJUpm1ORfuoF4FcwCkEz4QZuPomniZ-g7si8XSc3UDWcnCGocDS5Eyh2-F-VKwHcon7oBr21kiIioZSdhUm93-8e3fxvkbhS9c3Cl-2pgUQPATL8LciQFmPr4RfsxtijyBFqe6Zmu_HBO1wokO-5ukTbai4H1VWuKoc1gLD3SeeClniG4HS5VlgmvTUxa7otAjCw_wN3B1BZCZMsC1nrorBKxxQuUpXuJJVbRZ7teLJ8HMY31bmsufkXknMZrIuT0fNzf7g9LV6_mOWiFNM9vqUqqSQjpQH9D7jfifJRaZ1d65zlCrvEc5MP6FcGaXcmJutPVwY5ZDabyt2jVVO3j6OjdXzZD0DNdkB6EFwhKX0nTqbPbKedKH2tz7u0pSXDcnQjG4zgJRlHXoh3x5Mi742DWbBOFzeBtU8qpWmXEybq3wumcJD35kI7-ojyMBFdcw1TR0qH70DtdGGOgNBzx0PPKeYnJxcKNUiiZMK3a_ss7Gi6LQPXOSm-FfarE7CBjEHJSlrktEhrrjTzZvC8gYR990toKQASDSPVcdTX1EYz2fgLRgNo04rcIn03N1fqS-KE84GA5t1MoEM4bNXo9ypZu61PSEbdrLhVmdtQdeZMnAr4RkbZbdlYS13hl6lVXjF8DzJrfI7dbuwrhPXo61G0iMuRPJOpWPNuEpyQTbbBPBnV-_I9LAu2mIluzYYV5ye55Fn4FsX3d8DllLayVwnT0z_YML0_zC-PtGxNavxlK1nZ58rDv7m2OF33numpL14mK2BNtcCVAfQIE8Hoko09apCq7i_wq06_oO6UP8i9D8o5jUS)

<img width="1873" height="606" alt="image" src="https://github.com/user-attachments/assets/c8ed244a-c44a-4fdb-9e54-29840595994d" />

<img width="1335" height="659" alt="image" src="https://github.com/user-attachments/assets/dfda966e-bddb-4b11-9586-d96e8c9f6082" />


# Parking Lot System – Requirements, Class Design & Design Patterns

## 🚗 Functional Requirements

1. The parking lot should have **multiple levels**, each with a configurable number of parking spots.  
2. Parking spots may be of different types:
   - **Compact**
   - **Regular**
   - **Oversized**
3. The system must support parking for:
   - **Motorcycles**
   - **Cars**
   - **Trucks**
4. Vehicles should be assigned a spot based on **vehicle size compatibility**.  
5. At the **entry gate**, the customer receives a **parking ticket** containing:
   - Vehicle details  
   - Entry timestamp  
6. At the **exit gate**, the customer pays a parking fee based on:
   - Duration of stay  
   - Vehicle type  
   - Time of day (peak/off-peak)  
7. Must support **multiple entry and exit points**.  
8. Must support **concurrent access** so multiple vehicles can enter/exit simultaneously.

---

## 🛡 Non-Functional Requirements

1. The system must **scale** to support very large parking lots.  
2. Must provide **reliable tracking** of:
   - Spot assignments  
   - Active tickets  
   - Fee calculations  
3. Must ensure **thread safety** during concurrent operations.  
4. Must maintain **data consistency** across levels and vehicle states.

---

## 🧱 Classes, Interfaces & Enums

### **ParkingLot (Singleton)**
- Only one instance for the entire system.  
- Maintains:
  - List of levels  
  - Global parking/unparking operations  
- Ensures **thread-safe** spot assignment.

### **Level**
- Represents a single parking floor.  
- Contains a list of parking spots.  
- Responsible for finding and assigning an appropriate spot.

### **ParkingSpot**
- Represents an individual spot.  
- Contains:
  - `spotId`  
  - `SpotType`  
  - Availability status  
  - Parked `Vehicle`  
- Exposes:
  - `isAvailable()`  
  - `park(vehicle)`  
  - `unpark()`

### **Vehicle (Abstract Class)**
- Base class for all vehicle types.  
- Contains:
  - Vehicle number  
  - VehicleType  
- Subclasses:
  - `Car`  
  - `Motorcycle`  
  - `Truck`

### **VehicleType (Enum)**
MOTORCYCLE
CAR
TRUCK


### **SpotType (Enum)**
COMPACT
REGULAR
OVERSIZED


### **Ticket**
- Contains:
  - Ticket ID  
  - Entry timestamp  
  - Vehicle details  
  - Assigned parking spot  

---

## 🔒 Thread Safety

- Parking/unparking is a **critical section**, requiring synchronization.  
- Using raw `lock()` / `unlock()` manually can cause **deadlocks** and is **not exception-safe**.  
- Prefer safer constructs:
  - `lock_guard` / `unique_lock` (C++)  
  - `ReentrantLock` in Java  
  - Synchronized blocks (carefully)  

These ensure the parking lot remains consistent even with multiple entries/exits.

---

## 🧩 Design Patterns Used

### **1. Singleton Pattern**
- Used by `ParkingLot`.  
- Guarantees only one instance of the parking lot exists globally.

### **2. Factory Method Pattern (Optional)**
- Can be used for creating vehicles dynamically based on input:
  - `"car"` → `Car`  
  - `"truck"` → `Truck`  
  - `"motorcycle"` → `Motorcycle`

### **3. Observer Pattern (Optional)**
- ParkingLot can notify subscribers:
  - When a spot becomes free  
  - When a level becomes full  
  - When wait time estimates change  

Useful for dashboards or mobile app updates.

---

## 🧪 Main Class (Demo)
- Shows:
  - Creating the parking lot  
  - Parking different vehicles  
  - Ticket generation  
  - Fee calculation  
  - Unparking flow  









