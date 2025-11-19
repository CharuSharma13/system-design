Read uml from right to left - 

[plantUml link](//www.plantuml.com/plantuml/png/ZPFDYjim4CVlUeh1bzefNkZLbB2cQMWEJGDk3prEv8cZuaX66WTAstUl58jW6JRa5e_-7xyCqgjZj3nUUj7JYO4DMDMT6LfbIR8oMWYbcUm99S71cdQK37y4mFkEUDVc1LJW1N6mnmlTHewjqftubxgLf7QPSPlUOxpX7UoQiXQfkYp_hY5-225xT0xsnbwmd-ULghtZbDgpt4d2O0Y9yVmv_hSGa-R85d4JmgqbUfBlUQ31-kEy21mX_z66chCP1c_xX3O239F0-SGhIJRsOmA-MeS6REDtg8ahYBvf8B6NOuzCD_F4WaUFY99XgZvOSienQabJiqJBtuw_e4geLZ7V_uvbpaF5oFWdy4hVpGOPZ-Xys0FHLlMfO7QVqfXfNJD8CKjOdlcCT9LVwWQ-rlkVYokTrrrdgSFmR0gHEB8F6PYoX6oLBKmLIACPbNQ-9bdRZ-Ppa_Rc6nf8jwJbxqBCfIylwrHPmUZ89xvwUNZS_m40)

<img width="1296" height="338" alt="image" src="https://github.com/user-attachments/assets/1d516d2d-8998-4edc-83d3-cf026a83aa56" />




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
