Read uml from right to left - 
[plantUml link](https://www.plantuml.com/plantuml/uml/ZP4zR_8m4CTtVmehomCyoj0LLGZK5hL30n9TEXxE0QuSEx8lB6s_Uo_4ZM9G4LEIy__bvyiy47XgAYCCxaYIarxl3oHBxL6HTbO8RGdz3XJAjNTbeqX-2Yd_xv5Uoj5OJYKBug202a-ZG5xRlVXEtLfXUPvnclOnR4XbUVur--qLGXa8GHRELs26GRakUuxSCaIFq0xgDZ6UtmR-5rlI7DaYRaAuz8WtyzqAL7i-7erRZZR_seOs1rVNR7i07m7gJX0uyOYAdBzFm2UpjW7A-Cqr_GewNpTGO5HZWF1axbXWouZ085trscFGWS0gx9eLCwos7tAQK4rYFh_7ii1GCJ9U0exuvXw1O0k1mww8bjfS2b9_jwS1dHXOByx4ltI7pukDV5qKxsU_Ez5aTna7pMGsoL8PNrqvIw1juE1aGstkgdXAoiH0q8VoCn5nvW62cACjcyhy0000)

![image](https://github.com/user-attachments/assets/c04e7078-4f30-4e94-872c-f58229238817)



✅ S - Single Responsibility Principle (SRP)
Definition: A class should have only one reason to change.
Problem: If ShoppingCart handled saving to database and calculating totals, any change in saving logic would force you to modify cart logic.
Solution: You split responsibilities—ShoppingCart only manages products, while Presistance and its subclasses handle storage.
How to solve via code: Split ShoppingCart and persistence into separate classes so each has exactly one job.

✅ O - Open/Closed Principle (OCP)
Definition: Software entities should be open for extension but closed for modification.
Problem: If you had only SaveToDatabase, adding new class SaveToFile would require editing existing classes, risking bugs.
Solution: You made Presistance abstract, so you can add SaveToFile or SaveToCloud by extending, without changing existing code.
How to solve via code: Make Presistance abstract/interface and create subclasses for each storage type, so you can add new ones without changing existing code.

✅ L - Liskov Substitution Principle (LSP)
Definition: Subclass must be substitutable for their base class.
Problem: If you treat every product as having a price, you’re forcing FreeProduct to pretend it has one. This means you either return 0 or throw an error, and any part of the program that expects a real price will break when it gets a FreeProduct.
Solution: Instead, you create separate types: one for products with prices, and one for products without prices. This way, anything that needs a price only works with priced products, and FreeProduct is never put into places where it doesn’t belong.

✅ I - Interface Segregation Principle (ISP)
Definition: Clients should not be forced to depend on methods they do not use. Split large interfaces into smaller, specific ones.
Problem: If Product interface had getPrice(), FreeProduct would be forced to implement it unnecessarily.
Solution: You split Product and PricedProduct, so FreeProduct only depends on getId() and getName(), and NormalProduct adds getPrice().

✅ D - Dependency Inversion Principle (DIP)
Definition: High-level modules should depend on abstractions, not concrete implementations.
Problem: If main() directly created SaveToDatabase, switching to another storage type would require code changes everywhere.
Solution: main() depends on Presistance abstraction and can inject any subclass without knowing the details.




✅ Summary :
Each class has one clear job (SRP) and uses small interfaces (ISP).
New behaviors are added by extending, not modifying (OCP), and all subclasses are safely substitutable (LSP).
High-level code relies on abstractions (DIP) to stay decoupled.
