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


// 3. ShoppingCartStorage: only responsible for saving cart to db
class ShoppingCartStorage{
private:
    ShoppingCart*cart;

public:
    ShoppingCartStorage(ShoppingCart*cart){
        this->cart = cart;
    }

    void saveToDatabase(){
        cout << "Saving shopping cart to database..." << endl;
    }

    void saveToSQlDatabase(){
        cout << "Saving shopping cart to SQL DB..." << endl;
    }

    void saveToMongoDatabase(){
        cout << "Saving shopping cart to File..." << endl;
    }
};


int main(){
    ShoppingCart * cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop",1500));
    cart->addProduct(new Product("Mouse",50));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage * db = new ShoppingCartStorage(cart);
    db->saveToDatabase();

    return 0;
}