# Object-Oriented Relationships in C++

### IS-A / HAS-A / USES with ShoppingCart Example

------------------------------------------------------------------------

## 1️⃣ IS-A (Inheritance)

**Definition:**\
A child class *IS-A* type of its parent class.

``` cpp
class Product {
public:
    virtual void print() = 0;
};

class PricedProduct : public Product {   // IS-A
private:
    int price;
public:
    void print() override { }
};
```

✔️ `PricedProduct` **IS-A** `Product`\
✔️ LSP applies\
✔️ Standard inheritance

------------------------------------------------------------------------

## 2️⃣ HAS-A (Composition / Aggregation)

**Definition:**\
One class *contains* another class inside it.

### Example: `ShoppingCart HAS-A PricedProduct`

``` cpp
class PricedProduct { };

class ShoppingCart {
private:
    std::vector<PricedProduct*> products;   // HAS-A
public:
    void addProduct(PricedProduct* p) {
        products.push_back(p);
    }
};
```

✔️ ShoppingCart **HAS-A list of** PricedProduct\
✔️ Composition/Aggregation depending on ownership

------------------------------------------------------------------------

## 3️⃣ USES (Dependency)

**Definition:**\
One class *temporarily uses* another class (usually via function
arguments).

### Example: `Persistence USES ShoppingCart`

``` cpp
class ShoppingCart { };

class IPersistence {
public:
    virtual void save(const ShoppingCart& cart) = 0; // USES
};
```

✔️ Persistence **USES** ShoppingCart\
✔️ Does NOT own it\
✔️ No long-term relationship\
✔️ Dependency injection friendly

------------------------------------------------------------------------

## Summary Table

  ---------------------------------------------------------------------------------------------------
  Relationship                     Meaning                Code
  -------------------------------- ---------------------- -------------------------------------------
  **IS-A**                         Inheritance            `class Child : public Parent`

  **HAS-A**                        Composition /          `ShoppingCart { vector<PricedProduct*> }`
                                   Aggregation            

  **USES**                         Temporary dependency   `save(ShoppingCart cart)`
  ---------------------------------------------------------------------------------------------------

------------------------------------------------------------------------

# Full ShoppingCart Example With All 3

``` cpp
// IS-A
class Product {
public:
    virtual int getPrice() = 0;
};

class PricedProduct : public Product {   // IS-A
private:
    int price;
public:
    int getPrice() override { return price; }
};

// HAS-A
class ShoppingCart {
private:
    std::vector<PricedProduct*> items;   // HAS-A
public:
    void add(PricedProduct* p) {
        items.push_back(p);
    }
};

// USES
class IPersistence {
public:
    virtual void save(const ShoppingCart& cart) = 0;   // USES
};

class SaveToFile : public IPersistence {   // IS-A
public:
    void save(const ShoppingCart& cart) override {
        // write cart to file
    }
};
```

✔️ `PricedProduct IS-A Product`\
✔️ `ShoppingCart HAS-A PricedProduct`\
✔️ `Persistence USES ShoppingCart`\
✔️ `SaveToFile IS-A Persistence`
