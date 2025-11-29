[PlantUml](https://kroki.io/plantuml/svg/eNq1WEuT2jgQvvtXqHJZUxlSu3skDBUHPISKeRQ4U5WjRmhAhZBYySZhN_PfV5JtIT-gksHRZazuVqvV_fVj-CATKJJ0Tz25I-wABdyDPWccbQXfY5CIFDuc9YGAv_7-0_P-APevWOpYaT2GnybDKFy9Vt0Boh3cYPDmEW8Joli-Af95WjFm6R7kxBX5F-dkvVbTIIrsbhqOJl-mdhsFy3Fodi-e-UNYgsUzRLjQ5miiBGEm8YLCBIMeWCWCsI3lSn1tzzXC1YsolBIMofgpfaVDU55wgU4_a0vpbCxStPuVY8Wr-z-6XW1unXg2p84z13kvbcFlESw_T2ZjsFrM49sxs4BC4XoDVgeeGOBUAp7zNdvxmFTbWbp_wkL5SwlbxjF_uA255RAZHCGh8Iliv6P4T5xTDJnlc4TSw8nPj3XOGiFSYfHPhA1OVvZ6o8o1QHMVygz9Our4XjnBqHKoS7xJKRQV6vyIhUby2tANw_VLBouKvppAVXVNoHxLa3jRCR0-htFr1WUuiPAR0xwBVH_Xwq8xIdU-IjLpO48beHlcAkoNykxs6lLqwdkl3e7AdU5LfhjOZ8Mvy2U4G3690RMc7aaQqewpyhZE_6REFBgVWOFa6l0LIbTJHi-DOBx_Bb79WgRxHC5nnfZKQCJUpm1ORfuoF4FcwCkEz4QZuPomniZ-g7si8XSc3UDWcnCGocDS5Eyh2-F-VKwHcon7oBr21kiIioZSdhUm93-8e3fxvkbhS9c3Cl-2pgUQPATL8LciQFmPr4RfsxtijyBFqe6Zmu_HBO1wokO-5ukTbai4H1VWuKoc1gLD3SeeClniG4HS5VlgmvTUxa7otAjCw_wN3B1BZCZMsC1nrorBKxxQuUpXuJJVbRZ7teLJ8HMY31bmsufkXknMZrIuT0fNzf7g9LV6_mOWiFNM9vqUqqSQjpQH9D7jfifJRaZ1d65zlCrvEc5MP6FcGaXcmJutPVwY5ZDabyt2jVVO3j6OjdXzZD0DNdkB6EFwhKX0nTqbPbKedKH2tz7u0pSXDcnQjG4zgJRlHXoh3x5Mi742DWbBOFzeBtU8qpWmXEybq3wumcJD35kI7-ojyMBFdcw1TR0qH70DtdGGOgNBzx0PPKeYnJxcKNUiiZMK3a_ss7Gi6LQPXOSm-FfarE7CBjEHJSlrktEhrrjTzZvC8gYR990toKQASDSPVcdTX1EYz2fgLRgNo04rcIn03N1fqS-KE84GA5t1MoEM4bNXo9ypZu61PSEbdrLhVmdtQdeZMnAr4RkbZbdlYS13hl6lVXjF8DzJrfI7dbuwrhPXo61G0iMuRPJOpWPNuEpyQTbbBPBnV-_I9LAu2mIluzYYV5ye55Fn4FsX3d8DllLayVwnT0z_YML0_zC-PtGxNavxlK1nZ58rDv7m2OF33numpL14mK2BNtcCVAfQIE8Hoko09apCq7i_wq06_oO6UP8i9D8o5jUS)

<img width="1873" height="606" alt="image" src="https://github.com/user-attachments/assets/c8ed244a-c44a-4fdb-9e54-29840595994d" />

<img width="1335" height="659" alt="image" src="https://github.com/user-attachments/assets/dfda966e-bddb-4b11-9586-d96e8c9f6082" />


# Parking Lot System – Requirements & Design Overview

## ✅ Functional Requirements

Here are the key functional requirements we’ve identified:

- The parking lot should have **multiple levels**, each level containing a set of parking spots.  
- The parking lot should support different **parking spot types**: compact, regular, and oversized.  
- The parking lot should accommodate multiple **vehicle types** such as motorcycles, cars, and trucks.  
- The system must assign spots based on **vehicle size compatibility**.  
- At **entry**, customers should receive a **parking ticket** with vehicle details and entry time;  
  at **exit**, fees should be calculated based on duration, vehicle size, and fare strategy (base/peak hours).  
- The system must support **multiple entry and exit gates**, and handle **concurrent access**, ensuring consistent spot assignment.  
- The system should allow **pluggable parking strategies** (nearest, best-fit, farthest-first).  

---

## ✅ Non-Functional Requirements

- The system must **scale** to support large parking lots with many levels and spots.  
- The system should guarantee **data consistency**, especially with multiple gates operating in parallel.  
- The system should be **thread-safe**, preventing race conditions during spot allocation.  
- The architecture should be **extensible**, allowing new vehicle types, spot types, or strategies without breaking existing code.

---

## ✅ Classes, Interfaces, and Enumerations

Below is a concise explanation of the main components and their roles:

### ParkingLot (Singleton)
Acts as the central controller of the system, using DCL to manage levels, gates, parking operations, and fare calculation.

### Level
Represents a single floor and stores all parking spots available on that level.

### ParkingSpot (Interface)
Defines the structure and behavior of a parking space, including availability and assigned vehicle.

### CompactSpot / RegularSpot / OversizedSpot
Concrete spot types implementing ParkingSpot based on size compatibility.

### Vehicle (Interface)
Provides common vehicle attributes like license plate and size classification.

### Car / Motorcycle / Truck
Concrete vehicle types implementing the Vehicle interface.

### VehicleSize (Enum)
Defines standardized size categories: SMALL, MEDIUM, LARGE.

### ParkingStrategy (Strategy Pattern)
Defines how the system selects the most appropriate spot for a given vehicle.

### NearestSpotStrategy / BestFitSpotStrategy / FarthestFirstSpotStrategy
Different algorithms for choosing an optimal parking spot.

### FareStrategy (Strategy Pattern)
Defines how parking fare is computed for a given ticket.

### BaseFareStrategy / PeakHoursFareStrategy
Different billing calculations depending on time or conditions.

### FareCalculator
Applies one or more FareStrategy implementations to compute the final fare.

### Ticket
Stores details about the vehicle’s parking session, including spot, entry time, and exit time.

### ParkingManager
Handles the main parking logic, managing spot allocation, deallocation, and concurrency safety.

### LockManager
Ensures thread-safe operations by managing locks during concurrent spot allocation.


---

### ### **ParkingLot (Singleton)**
- Central controller of the system.  
- Ensures only one instance exists using **Double-Checked Locking (DCL)**.  
- Maintains:
  - Levels  
  - Gates  
  - ParkingManager  
  - FareCalculator  
- Provides:
  - `enterVehicle()`  
  - `leaveVehicle()`  

---

### **Level**
- Represents a **floor** in the parking lot.  
- Holds a list of **parking spots**.  
- Allows fetching all spots for searching or strategy evaluation.

---

### **ParkingSpot (Interface)**
Represents an individual parking space.

Tracks:
- `spotNumber`  
- `size`  
- whether it is **available**  
- the **parked vehicle**  

Implemented by:
- `CompactSpot`  
- `RegularSpot`  
- `OversizedSpot`

---

### **Vehicle (Interface)**
Abstracts common attributes of vehicles:
- license plate  
- size  

Implemented by:
- `Car`  
- `Motorcycle`  
- `Truck`

---

### **VehicleSize (Enum)**
- `small`  
- `medium`  
- `large`

- 
---

### **ParkingStrategy (Strategy Pattern)**  
Defines how to find the **best spot**.

Implementations:
- `NearestSpotStrategy`  
- `BestFitSpotStrategy`  
- `FarthestFirstSpotStrategy`

---

### **FareStrategy (Strategy Pattern)**
Defines how **fare is calculated**.

Implementations:
- `BaseFareStrategy`  
- `PeakHoursFareStrategy`  

Used by `FareCalculator`, which may apply one or multiple strategies.

---

### **Ticket**
Records:
- `ticketId`  
- `vehicle`  
- `assignedSpot`  
- `entryTime`  
- `exitTime`  

Used for billing on exit.

---

### **ParkingManager**
Core orchestrator of parking operations.

Maintains:
- map of **available spots**  
- **vehicle-to-spot** mapping  
- selected **ParkingStrategy**  
- **LockManager** for synchronization  

Responsible for:
- `parkVehicle()`  
- `unparkVehicle()`  

---

### **LockManager**
Handles thread synchronization to avoid **race conditions** during parallel gate operations.

---

## ✅ Design Patterns Used

### ✔ **Singleton Pattern**
- Used for `ParkingLot`.  
- Guarantees a single global instance.  
- Implements **Double-Checked Locking** for safe lazy initialization.

---

### ✔ **Strategy Pattern (Parking Strategy)**
Allows switching between:
- Nearest  
- Best-Fit  
- Farthest-First  

Makes spot allocation flexible and testable.

---

### ✔ **Strategy Pattern (Fare Strategy)**
Allows plugging in new billing mechanisms:
- Base fare  
- Peak hour surcharge  

---

### ✔ **(Optional) Factory Pattern**
- Can create vehicles dynamically based on input.

---

### ✔ **(Optional) Observer Pattern**
- Could notify subscribers about real-time spot availability or level status.

---

