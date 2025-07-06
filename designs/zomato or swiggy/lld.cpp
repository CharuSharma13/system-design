#include <bits/stdc++.h>
using namespace std;


class MenuItem{
    private:
        int id;
        string name;
        double price;
    public:
        MenuItem(int id, string name, int price){
            this->id=id;
            this->name=name;
            this->price=price;
        }
        
        int getId(){
            return id;
        }
        
        string getName(){
            return name;
        }
        
        double getPrice(){
            return price;
        }
};

class Resturant{
    private:
        vector<MenuItem*> menuItems;
        static int nextResturantId;
        int resturantId;
        string name;
        string location;
    public:
        Resturant(string name, string location){
            this->location=location;
            this->name=name;
            this->resturantId=++nextResturantId;
        };
        
        string getName(){
            return name;
        }
        
         string getLocation(){
            return location;
        }
        
        void addMenuItem(MenuItem* item){
            menuItems.push_back(item);
        }
        vector<MenuItem*> getMenuItems(){
            for(auto item : menuItems) {
                cout<<item->getName();
            }
            return menuItems;
        }
        
};

int Resturant::nextResturantId = 0;

class ResturantManager{
    private:
        vector<Resturant*> resturants;
        static ResturantManager* instance;
        ResturantManager(){
            
        }
    public:
        static ResturantManager* getInstance(){
            if(instance==nullptr){
                instance=new ResturantManager();
            }
            return instance;
        }
        void addResturant(Resturant* resturant){
            resturants.push_back(resturant);
        }
        void removeResturant(Resturant* resturant){
            resturants.erase(remove(resturants.begin(),resturants.end(), resturant), resturants.end());
        }
        void getResturants(){
            for(auto resturant : resturants) {
                cout<<resturant->getName();
            }
        }
        
        vector<Resturant*> searchByLocation(string location) {
            vector<Resturant*> resturantListBasedLocation;
             for(auto resturant : resturants) {
                 if(resturant->getLocation()==location){
                     resturantListBasedLocation.push_back(resturant);
                 }
            }
            return resturantListBasedLocation;
        }
        
};

ResturantManager* ResturantManager :: instance= nullptr;

class Cart{
    private:
        Resturant* resturant;
        vector<MenuItem*> menuItems;
    public:
        Cart(){
            resturant=nullptr;
        }
        
        void addToCart(MenuItem* menuItem){
            menuItems.push_back(menuItem);
        }
        
        double getTotalPrice(){
            double sum = 0;
            for(auto item : menuItems){
                sum+=item->getPrice();
            }
            return sum;
        }

        vector<MenuItem*> getCartMenuItems() {
            for(auto item : menuItems){
                cout<< item->getName();
            }
            return menuItems;
        }
        
        Resturant* getResturant(){
            return resturant;
        }
        
        void setResturant(Resturant* resturant) {
            this->resturant = resturant;
        }
        
        void clear() {
            menuItems.clear();
            resturant = nullptr;
        }
};

class User {
    private:
        int id;
        string address;
        Cart* cart;
    public:
        User(int id, string address){
            this->id = id;
            this->address = address;
            cart = new Cart();
        }
        Cart* getCart(){
            return cart;
        }
};

class PaymentStrategy{
    public:
        virtual void pay(double total) = 0;
};

class UPIPayment : public PaymentStrategy{
    string contactNumber;
    public:
        UPIPayment(string contactNumber){
            this->contactNumber = contactNumber;
        }
        void pay(double total){
           cout<<"payment using UPI"<<total<<endl;
        }
};

class CardPayment : public PaymentStrategy{
    public:
        void pay(double total){
           cout<<"payment using Card"<<endl;
        }
    
};


class Order{
    Resturant* resturant;
    vector<MenuItem*> menuItems;
    PaymentStrategy* paymentStrategy;
    static int nextOrderId;
    int orderId;
    User* user;
    double total;
    public: 
        Order(){
            user = nullptr;
            resturant = nullptr;
            paymentStrategy = nullptr;
            total=0.0;
            orderId=++nextOrderId;
        }
        
        void setUser(User* user){
            this->user=user;
        }
        
        void setResturant(Resturant* resturant){
            this->resturant=resturant;
        }
        
        void setOrderedMenuItems(vector<MenuItem*> menuItems){
            this->menuItems = menuItems;
        }
        
        void setPaymentStrategy(PaymentStrategy* paymentStrategy) {
            this->paymentStrategy= paymentStrategy;
        }
        
        void setTotalCost(double total){
            this->total = total;
        }

        bool processPayment(){
            if(paymentStrategy){
                paymentStrategy->pay(total);
                return true;
            }
            else {
                cout<<"Please choose payment mode first"<<endl;
                return false;
            }
        }
        virtual string getType() = 0;
};

int Order::nextOrderId = 0;

class PickupOrder : public Order {
    private:
        string resturantAddress;
    public:
        string getType() {
            return "pickup";
        }
};

class DeliveryOrder : public Order {
    private:
        string userAddress;
    public:
        string getType() {
            return "delivery";
        }
};

class OrderManager {
    vector<Order*> orders;
    static OrderManager* instance;
    public:
        static OrderManager* getInstance(){
            if(instance==nullptr){
                instance= new OrderManager();
            }
            return instance;
        }
        
        void addOrders(Order* order){
            orders.push_back(order);
        }
        
        void getOrders(){
            cout<<"all orders"<<endl;
        }
};


 OrderManager* OrderManager::instance = nullptr;


class OrderFactory{
    public:
        virtual Order* createOrder(User* user, PaymentStrategy* paymentStrategy, string type) = 0;
};

class OrderNow : public OrderFactory {
    public:
        Order* createOrder(User* user, PaymentStrategy* paymentStrategy,string type){
              Order* order= nullptr;
              if(type=="pickup"){
                 order = new PickupOrder();
            }
            else if(type=="delivery") {
                order = new DeliveryOrder();
            }
            order->setUser(user);
            order->setResturant(user->getCart()->getResturant());
            order->setPaymentStrategy(paymentStrategy);
            order->setOrderedMenuItems(user->getCart()->getCartMenuItems());
            order->setTotalCost(user->getCart()->getTotalPrice());
            return order;
        }
};

class ScheduledOrder : public OrderFactory {
    public:
        Order* createOrder(User* user, PaymentStrategy* paymentStrategy, string type){
            Order* order= nullptr;
              if(type=="pickup"){
                return new PickupOrder();
            }
            else if(type=="delivery") {
                return new DeliveryOrder();
            }
            order->setUser(user);
            order->setResturant(user->getCart()->getResturant());
            order->setPaymentStrategy(paymentStrategy);
            order->setOrderedMenuItems(user->getCart()->getCartMenuItems());
            order->setTotalCost(user->getCart()->getTotalPrice());
            return order;
        }
};

class NotificationService {
    public:
        void notify(Order *order){
            cout<<"notification"<<endl;
        }
};

class Zomato {
    
    public:
        Zomato(){
            ResturantManager* resturant = ResturantManager::getInstance();
            Resturant* resturant1 = new Resturant("Res1","delhi");
            resturant->addResturant(resturant1);
            resturant1->addMenuItem(new MenuItem(1,"menu1",100));
            resturant1->addMenuItem(new MenuItem(2,"menu2",50));
            // resturant1->getMenuItems();
            
            Resturant* resturant2 = new Resturant("Res2","near delhi");
            resturant->addResturant(resturant2);
            resturant2->addMenuItem(new MenuItem(3,"menu3",300));
            resturant2->addMenuItem(new MenuItem(4,"menu4",350));
            
           // resturant2->getMenuItems();
            
        }
        
        vector<Resturant*> searchResturants(string location){
            return ResturantManager::getInstance()->searchByLocation(location);
        }
        
        void selectRestaurant(User* user, Resturant* resturant) {
            user->getCart()->setResturant(resturant);
        }
        
        void addToCart(User* user, int id){
            Resturant* resturant = user->getCart()->getResturant();
            cout<<resturant->getName();
            for (auto item : resturant->getMenuItems()){
                if(item->getId() == id) {
                    user->getCart()->addToCart(item);
                    return;
                }
            }
        }
        
        Order* checkoutNow(User* user, string orderType, PaymentStrategy* paymentStrategy) {
        return checkout(user, orderType, paymentStrategy, new OrderNow());
        }
        
        Order* checkout(User* user, string orderType, 
        PaymentStrategy* paymentStrategy, OrderFactory* orderFactory) {
            // if (user->getCart()->isEmpty()) return nullptr;

            Order* order = orderFactory->createOrder(user, paymentStrategy, orderType);
            OrderManager::getInstance()->addOrders(order);
            return order;
        }
        
        void payForOrder(User* user, Order* order) {
            bool isPaymentSuccess = order->processPayment();
    
            if(isPaymentSuccess) {
                NotificationService* notification = new NotificationService();
                notification->notify(order);
                user->getCart()->clear();
            }  
        }
        
        
};

int main(){
    
    Zomato* zomato = new Zomato();
    
    User* user = new User(101, "Delhi");
    vector<Resturant*> resturants = zomato->searchResturants("near delhi");
    zomato->selectRestaurant(user, resturants[0]);
    zomato->addToCart(user,4);
    
    user->getCart()->getCartMenuItems();
    
    Order* order = zomato->checkoutNow(user, "delivery", new UPIPayment("1234567890"));
    
    zomato->payForOrder(user, order);
    
    delete zomato;
    delete user;
    
}
