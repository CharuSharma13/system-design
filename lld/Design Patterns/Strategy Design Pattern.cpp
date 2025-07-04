#include <bits/stdc++.h>
using namespace std;

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
        this->discountPercent= discount;
    }
    int getPrice(int basePrice) override {
        return basePrice - (basePrice * discountPercent / 100);
    }
};


class ShippingStrategy {
public:
    virtual int getShippingCost() = 0;
};

class StandardShippingStrategy : public ShippingStrategy {
public:
    int getShippingCost() override {
        return 50;
    }
};

class FreeShippingStrategy : public ShippingStrategy {
public:
    int getShippingCost() override {
        return 0;
    }
};

class TaxStrategy {
public:
    virtual int calculateTax(int price) = 0;
};

class NoTaxStrategy : public TaxStrategy {
public:
    int calculateTax(int price) override {
        return 0;
    }
};

class VATTaxStrategy : public TaxStrategy {
public:
    int calculateTax(int price) override {
        return price * 15 / 100;
    }
};

class Product {
    int id;
    string name;
    int basePrice;
    PricingStrategy* pricing;
    ShippingStrategy* shipping;
    TaxStrategy* tax;

public:
    Product(int id,
            string name,
            int basePrice,
            PricingStrategy* pricing,
            ShippingStrategy* shipping,
            TaxStrategy* tax){
                this->id=id;
                this->name=name;
                this->basePrice=basePrice;
                this->pricing=pricing;
                this->shipping=shipping;
                this->tax=tax;
            }

    int getFinalPrice() {
        int price = pricing->getPrice(basePrice);
        int shippingCost = shipping->getShippingCost();
        int taxAmount = tax->calculateTax(price);
        return price + shippingCost + taxAmount;
    }

    string getName() {
        return name;
    }
};

int main() {
    Product p1(
        1,
        "Laptop",
        1000,
        new StandardPricingStrategy(),
        new StandardShippingStrategy(),
        new NoTaxStrategy()
    );

    Product p2(
        2,
        "Phone",
        800,
        new DiscountPricingStrategy(10),  // 10% off
        new FreeShippingStrategy(),
        new VATTaxStrategy()
    );

    cout << p1.getName() << " Final Price: " << p1.getFinalPrice() << endl;
    cout << p2.getName() << " Final Price: " << p2.getFinalPrice() << endl;

    return 0;
}

