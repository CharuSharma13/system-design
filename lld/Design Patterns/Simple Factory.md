**A class (the factory) decides which concrete class to create, hiding the object creation logic from the client code.**
  
## For understanding

![image](https://github.com/user-attachments/assets/a3a6cf4a-03b4-4b0d-a389-52e3ba64dd47)

## Actual (in code) -

![image](https://github.com/user-attachments/assets/87bda3c5-502b-4a50-be2e-e3bf8735fdfa)


## Why do we use a Simple Factory?

**Without it:**

- Your code directly calls `new ConcreteClass()` everywhere.
- You scatter creation logic in many places.
- It’s harder to change how objects get built.

**With it:**

- You centralize all creation logic in one place.
- Your code depends on abstractions (e.g., `PricingStrategy`), not implementations.
- Adding new types is easier.


