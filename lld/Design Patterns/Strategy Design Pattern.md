Problem -
Using inheritance for every combination of pricing, shipping, and tax creates too many subclasses (class explosion) and is hard to extend.
![image](https://github.com/user-attachments/assets/575d3be0-7f2a-4ebb-bdca-0d9a8807fe1f)


Solution -
Use the Strategy Pattern to separate each behavior into its own interface and compose them in Product, so you can mix and match strategies without creating new subclasses.
![image](https://github.com/user-attachments/assets/887ba778-1cda-4f52-a130-9d6686ab870b)
