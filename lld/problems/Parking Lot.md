[Detailed Explanation](https://bytebytego.com/courses/object-oriented-design-interview/design-a-parking-lot)

[PlantUml](https://kroki.io/plantuml/svg/eNq1WEuT2jgQvvtXqHJZUxlSu3skDBUHPISKeRQ4U5WjRmhAhZBYySZhN_PfV5JtIT-gksHRZazuVqvV_fVj-CATKJJ0Tz25I-wABdyDPWccbQXfY5CIFDuc9YGAv_7-0_P-APevWOpYaT2GnybDKFy9Vt0Boh3cYPDmEW8Joli-Af95WjFm6R7kxBX5F-dkvVbTIIrsbhqOJl-mdhsFy3Fodi-e-UNYgsUzRLjQ5miiBGEm8YLCBIMeWCWCsI3lSn1tzzXC1YsolBIMofgpfaVDU55wgU4_a0vpbCxStPuVY8Wr-z-6XW1unXg2p84z13kvbcFlESw_T2ZjsFrM49sxs4BC4XoDVgeeGOBUAp7zNdvxmFTbWbp_wkL5SwlbxjF_uA255RAZHCGh8Iliv6P4T5xTDJnlc4TSw8nPj3XOGiFSYfHPhA1OVvZ6o8o1QHMVygz9Our4XjnBqHKoS7xJKRQV6vyIhUby2tANw_VLBouKvppAVXVNoHxLa3jRCR0-htFr1WUuiPAR0xwBVH_Xwq8xIdU-IjLpO48beHlcAkoNykxs6lLqwdkl3e7AdU5LfhjOZ8Mvy2U4G3690RMc7aaQqewpyhZE_6REFBgVWOFa6l0LIbTJHi-DOBx_Bb79WgRxHC5nnfZKQCJUpm1ORfuoF4FcwCkEz4QZuPomniZ-g7si8XSc3UDWcnCGocDS5Eyh2-F-VKwHcon7oBr21kiIioZSdhUm93-8e3fxvkbhS9c3Cl-2pgUQPATL8LciQFmPr4RfsxtijyBFqe6Zmu_HBO1wokO-5ukTbai4H1VWuKoc1gLD3SeeClniG4HS5VlgmvTUxa7otAjCw_wN3B1BZCZMsC1nrorBKxxQuUpXuJJVbRZ7teLJ8HMY31bmsufkXknMZrIuT0fNzf7g9LV6_mOWiFNM9vqUqqSQjpQH9D7jfifJRaZ1d65zlCrvEc5MP6FcGaXcmJutPVwY5ZDabyt2jVVO3j6OjdXzZD0DNdkB6EFwhKX0nTqbPbKedKH2tz7u0pSXDcnQjG4zgJRlHXoh3x5Mi742DWbBOFzeBtU8qpWmXEybq3wumcJD35kI7-ojyMBFdcw1TR0qH70DtdGGOgNBzx0PPKeYnJxcKNUiiZMK3a_ss7Gi6LQPXOSm-FfarE7CBjEHJSlrktEhrrjTzZvC8gYR990toKQASDSPVcdTX1EYz2fgLRgNo04rcIn03N1fqS-KE84GA5t1MoEM4bNXo9ypZu61PSEbdrLhVmdtQdeZMnAr4RkbZbdlYS13hl6lVXjF8DzJrfI7dbuwrhPXo61G0iMuRPJOpWPNuEpyQTbbBPBnV-_I9LAu2mIluzYYV5ye55Fn4FsX3d8DllLayVwnT0z_YML0_zC-PtGxNavxlK1nZ58rDv7m2OF33numpL14mK2BNtcCVAfQIE8Hoko09apCq7i_wq06_oO6UP8i9D8o5jUS)

<img width="1335" height="659" alt="image" src="https://github.com/user-attachments/assets/dfda966e-bddb-4b11-9586-d96e8c9f6082" />

In-depth -
<img width="1873" height="606" alt="image" src="https://github.com/user-attachments/assets/c8ed244a-c44a-4fdb-9e54-29840595994d" />
add relationship
<img width="1488" height="638" alt="image" src="https://github.com/user-attachments/assets/b4953481-ca6b-4f68-a78c-0e87fcc20192" />

add observers
<img width="1857" height="558" alt="image" src="https://github.com/user-attachments/assets/34fa2815-0480-432a-b993-144e2af3d95c" />

add payment
<img width="1701" height="436" alt="image" src="https://github.com/user-attachments/assets/6fca44b1-865c-43ea-831e-6c01429b52b8" />







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

## ✅ Exception Handling & Failure Scenarios

Interviewer wants to see if you can handle:

- Spot is full
- No spot for this vehicle type
- Ticket mismatch
- Lost ticket scenario
- Gate system failure
- Payment decline

A “robust system” discussion is a huge plus.

---

## ✅ API Layer

Add if asked about integration:

- REST APIs:
- POST /enter
- POST /exit
- GET /availability
- POST /pay


---

## ✅ Classes, Interfaces, and Enumerations

Below is a concise explanation of the main components and their roles:

ParkingLot (Singleton) – Single global controller managing levels, gates, parking manager, and fare calculation using thread-safe double-checked locking.

Level – Represents one parking floor and contains all parking spots available on that level.

ParkingSpot (Interface) – Blueprint for a parking space defining its size, availability, and the parked vehicle, implemented by CompactSpot, RegularSpot, and OversizedSpot.

Vehicle (Interface) – Defines common vehicle properties like license plate and size, implemented by Car, Motorcycle, and Truck.

VehicleSize (Enum) – Represents supported vehicle sizes: SMALL, MEDIUM, and LARGE.

ParkingStrategy (Strategy Pattern) – Determines how to pick the best available spot, with NearestSpotStrategy, BestFitSpotStrategy, and FarthestFirstSpotStrategy as algorithms.

FareStrategy (Strategy Pattern) – Defines how parking fees are calculated, with BaseFareStrategy and PeakHoursFareStrategy providing normal-hour and peak-hour billing rules.

Ticket – Holds ticket ID, assigned spot, vehicle reference, and entry/exit timestamps for billing.

ParkingManager – Coordinates spot assignment, maintains mappings and available spots, applies parking strategy, and enforces concurrency via LockManager.

LockManager – Provides thread-safe locking to prevent race conditions when multiple gates attempt spot allocation simultaneously.



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

🔥 ParkingManager → Display Board / Mobile App
Whenever a spot becomes free or occupied, ParkingManager notifies:

Electronic Display Board
- Mobile App
- Dashboard Screen
- Monitoring System

Why Observer?
Because many displays depend on spot availability, and they must update automatically whenever state changes.

Interview one-liner:
We use observer pattern so all display boards automatically update whenever ParkingManager changes available spot count.
---



### Extra points -

## Logging & Audit Trail

Production systems log EVERYTHING.

Add class:
- AuditLogger

Events logged:

- Vehicle entry
- Spot assignment
- Payment
- Vehicle exit
- Spot released

This is great to mention for maintainability & debuggability.

## EV Charging Spots (Modern Interviews Love This)

Some companies test if you think beyond basics.

Add:
- ChargingSpot (extends ParkingSpot)
- ChargingRateStrategy
- ChargeSession


 ## Caching Frequent Data

For performance:
- Cache available spots per level
- Cache number of free spots per vehicle size

Mention:
“Since querying spot lists repeatedly is expensive, ParkingManager caches availability and invalidates cache on occupy/vacate.”

This shows performance awareness.

