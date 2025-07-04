**Instead of calling a separate factory, you define a factory method inside a creator class (base class), which subclasses override to provide their own products.**

![image](https://github.com/user-attachments/assets/dcae81a2-e43b-4eb3-a89a-983387db6a38)

Product is an abstract creator and has createPricingStrategy() (factory method).

Each subclass (StandardProduct, DiscountProduct) decides which pricing strategy to create.

Client code just calls getFinalPrice() without worrying about the specific strategy.
