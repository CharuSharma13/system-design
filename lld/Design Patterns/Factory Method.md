**Instead of calling a separate factory, you define a factory method inside a creator class (base class), which subclasses override to provide their own products.**

![image](https://github.com/user-attachments/assets/b5bde8c4-2059-4dd7-902a-1648c055871a)


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

