<img width="807" height="755" alt="image" src="https://github.com/user-attachments/assets/4bb3bd9b-0b65-4bca-824c-9145877e5c7b" />

<img width="1503" height="670" alt="image" src="https://github.com/user-attachments/assets/244c30f7-5317-4446-b4b9-b9ae8c95375a" />

Functional Requirements:
1. Product Selection and Dispensing:
Users should be able to select a product from the available inventory.
The machine should dispense the selected product after payment is successfully processed.

2. Payment Processing:
Support multiple payment methods (coins, cards, etc.).
Validate and process the payment using the appropriate strategy (e.g., coin validation, card transaction).
Provide feedback to the user if the payment fails.

3. Change Dispensing:
Calculate the correct amount of change to return based on the amount paid and the product price.
Dispense change in the form of coins.

4. Inventory Management:
Maintain a list of products with their attributes (e.g., ID, name, price, quantity, category).
Allow the operator to restock products when inventory is low.
Notify users if a selected product is out of stock.

5. User Interaction:
Display a list of available products with their prices.
Show appropriate messages for user actions (e.g., "Payment Successful", "Out of Stock").
Indicate the current machine state (e.g., "Waiting for Payment", "Dispensing Product").

6. State Management:
Operate in different states: Idle, Waiting for Payment, and Dispensing Product.
Transition between states based on user actions and system conditions.

7. Maintenance and Monitoring:
Allow operators to check the inventory status and cash levels.
Support restocking of inventory and refilling of change.

Non- Functional Requirements:
Scalability:
The system should allow easy addition of new payment methods (e.g., mobile payment) by extending the payment strategy.

2. Modularity:
Components like inventory, payment processing, and change dispensing should be modular for ease of maintenance and extension.

3. Reliability:
Ensure robust handling of edge cases, such as:
Insufficient funds.
Incorrect product selection.
Insufficient change availability.

4. Usability:
Provide a clear and user-friendly interface for users and operators.

5. Performance:
Ensure fast response times for dispensing products and returning change.

<img width="868" height="543" alt="image" src="https://github.com/user-attachments/assets/fcf0fafd-580e-47af-96f4-9aff05f4f731" />
