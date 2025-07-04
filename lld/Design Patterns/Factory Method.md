**Instead of calling a separate factory, you define a factory method inside a creator class (base class), which subclasses override to provide their own products.**

![image](https://github.com/user-attachments/assets/8b5db29d-b649-441e-bd72-f0fd58104aae)



🎯 **Scenario**

You sell different **Product** types:

- `StandardProduct`
- `DiscountedProduct`
- `PremiumProduct`

You have **Stores** that decide which product to create:

- `RegularStore` always sells `StandardProduct`
- `HolidayStore` sells `DiscountedProduct`
- `LuxuryStore` sells `PremiumProduct`

---

Store defines the factory method createProduct().

Each Store subclass decides which concrete Product to create.

Client code uses only Store and Product abstractions.

