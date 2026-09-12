#include<iostream>
#include<vector>

using namespace std;

// Product class representing any item in eCommerce.

class Product{
public:
    string name;
    double price;

    Product(string name,double price){
        this->name = name;
        this->price = price;
    }
};

//1. ShoppingCart: only responsible for Cart related business layer.
class ShoppingCart{
private:
    vector<Product*>products; // store heap-allocation
public:
    void addProduct(Product*p){
        products.push_back(p);
    }

    const vector<Product*>&getProducts(){
        return products;
    }

    //calcculates total price in cart
    double calculateTotal(){
        double total = 0;
        for(auto p : products){
            total += p->price;
        }
        return total;
    }
};


// 2. ShoppingCartPrinter: only responsible for printing invoices
class ShoppingCartPrinter{
private:
    ShoppingCart*cart;

public:
    ShoppingCartPrinter(ShoppingCart*cart){
        this->cart = cart;
    }

    void printInvoice(){
    cout << "Shopping Cart Invoice\n";

    for(auto p : cart->getProducts()){
        cout << p->name << " : $" << p->price << endl;
    }
    cout << "Total: $" << cart->calculateTotal() << endl;
    
   }
};


//Abstract class 
class Persistence{
private:
    ShoppingCart* cart;
public: 
    virtual void save(ShoppingCart* cart) = 0; //pure virtual function
};

class SQLPersistance:public Persistence{
public:
    void save(ShoppingCart*cart) override {
        cout << "Saving shopping cart to SQL DB..." << endl;
    }
};

class MongoPersistance:public Persistence{
public: 
    void save(ShoppingCart*cart) override {
        cout << "Saving shopping cart to MongoDb..." << endl;
    }
};


class FilePersistance:public Persistence{
public: 
    void save(ShoppingCart*cart) override {
        cout << "Saving shopping cart to File..." << endl;
    }
};



int main(){
    ShoppingCart * cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop",1500));
    cart->addProduct(new Product("Mouse",50));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    Persistence * db = new SQLPersistance();
    Persistence * mongo = new MongoPersistance();
    Persistence * file = new FilePersistance();


    db->save(cart);  //save to sql db
    mongo->save(cart); // save to mongo db
    file->save(cart);  // save to file
    

    return 0;
}