#include <bits/stdc++.h>
using namespace std;

// ====================
// Pricing Strategy
// ====================
class PricingStrategy {
public:
    virtual int getPrice(int basePrice) = 0;
};

class StandardPricingStrategy : public PricingStrategy {
public:
    int getPrice(int basePrice) override {
        return basePrice;
    }
};

class DiscountPricingStrategy : public PricingStrategy {
    int discountPercent;
public:
    DiscountPricingStrategy(int discount) {
        this->discountPercent = discount;
    }
    int getPrice(int basePrice) override {
        return basePrice - (basePrice * discountPercent / 100);
    }
};

class PremiumPricingStrategy : public PricingStrategy {
public:
    int getPrice(int basePrice) override {
        return basePrice + 200; // premium markup
    }
};

// ====================
// Product
// ====================
class Product {
protected:
    int id;
    string name;
    int basePrice;
    PricingStrategy* pricing;

public:
    Product(int id, string name, int price, PricingStrategy* strategy)
        : id(id), name(name), basePrice(price), pricing(strategy) {}

    virtual int getFinalPrice() {
        return pricing->getPrice(basePrice);
    }

    string getName() {
        return name;
    }
};

// ====================
// Store (Factory Method)
// ====================
class Store {
public:
    virtual Product* createProduct(int id, string name, int price) = 0;
};

class RegularStore : public Store {
public:
    Product* createProduct(int id, string name, int price) override {
        return new Product(id, name, price, new StandardPricingStrategy());
    }
};

class HolidayStore : public Store {
public:
    Product* createProduct(int id, string name, int price) override {
        return new Product(id, name, price, new DiscountPricingStrategy(15));
    }
};

class LuxuryStore : public Store {
public:
    Product* createProduct(int id, string name, int price) override {
        return new Product(id, name, price, new PremiumPricingStrategy());
    }
};

// ====================
// Main
// ====================
int main() {
    Store* holidayStore = new HolidayStore();
    Store* luxuryStore = new LuxuryStore();

    Product* p1 = holidayStore->createProduct(1, "Shoes", 500);
    Product* p2 = luxuryStore->createProduct(2, "Watch", 1500);

    cout << p1->getName() << " Final Price: " << p1->getFinalPrice() << endl;
    cout << p2->getName() << " Final Price: " << p2->getFinalPrice() << endl;

    // Clean up
    delete p1;
    delete p2;
    delete holidayStore;
    delete luxuryStore;

    return 0;
}

