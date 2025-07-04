#include <bits/stdc++.h>
using namespace std;

// =============================
// Pricing Strategy and Factory
// =============================
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

class PricingStrategyFactory {
public:
    // No static keyword here
    PricingStrategy* createStrategy(string type, int discount = 0) {
        if (type == "standard") {
            return new StandardPricingStrategy();
        } else if (type == "discount") {
            return new DiscountPricingStrategy(discount);
        } else {
            throw invalid_argument("Unknown pricing strategy type");
        }
    }
};

// =============================
// Product Class
// =============================
class Product {
    int id;
    string name;
    int basePrice;
    PricingStrategy* pricing;

public:
    Product(int id,
            string name,
            int basePrice,
            PricingStrategy* pricing) {
        this->id = id;
        this->name = name;
        this->basePrice = basePrice;
        this->pricing = pricing;
    }

    int getFinalPrice() {
        return pricing->getPrice(basePrice);
    }

    string getName() {
        return name;
    }
};


int main() {
    PricingStrategyFactory* factory = new PricingStrategyFactory();
    
    Product p1(
        1,
        "Laptop",
        1000,
        factory->createStrategy("standard")
    );
    
    Product p2(
        2,
        "Phone",
        800,
        factory->createStrategy("discount", 10)
    );
    
    cout << p1.getName() << " Final Price: " << p1.getFinalPrice() << endl;
    cout << p2.getName() << " Final Price: " << p2.getFinalPrice() << endl;
    
    delete factory; // clean up


    return 0;
}
