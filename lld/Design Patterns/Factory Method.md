**Instead of calling a separate factory, you define a factory method inside a creator class (base class), which subclasses override to provide their own products.**

![image](https://github.com/user-attachments/assets/a7bfea58-2563-4baf-91c5-2264683c6601)

🎯 **Scenario**

You sell different **Product** types:

- `StandardProduct`
- `DiscountedProduct`
- `PremiumProduct`

You have **Stores** that decide which product to create:

- `RegularStore` always sells `StandardProduct`
- `HolidayStore` sells `DiscountedProduct`
- `LuxuryStore` sells `PremiumProduct`

`Store` defines the factory method:

---

Store defines the factory method createProduct().

Each Store subclass decides which concrete Product to create.

Client code uses only Store and Product abstractions.

