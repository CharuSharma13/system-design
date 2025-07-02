Read uml from right to left - 

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
Definition: Subtypes must be substitutable for their base types.
Problem: If you treat every product as having a price, you’re forcing FreeProduct to pretend it has one. This means you either return 0 or throw an error, and any part of the program that expects a real price will break when it gets a FreeProduct.
Solution: Instead, you create separate types: one for products with prices, and one for products without prices. This way, anything that needs a price only works with priced products, and FreeProduct is never put into places where it doesn’t belong.

✅ I - Interface Segregation Principle (ISP)
Definition: Clients should not be forced to depend on methods they do not use.
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
