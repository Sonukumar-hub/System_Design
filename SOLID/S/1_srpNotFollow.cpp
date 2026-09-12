//without follow single responseability principle
#include<iostream>
using namespace std;
#include <vector>

class Product {
public:
    string name;
    double price;
};

class ShoppingCart{
private:
   vector<Product*>products;
public:
   void addProduct(Product*p){
    products.push_back(p);
   }

   const vector<Product*>& getProducts(){
    return products;
   }

   // 1.Calculate total prices in cart
    double calculateTotal(){
    double total = 0;
    for(auto p : products){
        total += p->price;
    }
    return total;
   }

   // 2. violating srp - Prints invoice (should be in a separate class)
   void printInvoice(){
    cout << "Shopping Cart Invoice:\n";
    for(auto p : products){
        cout << p->name << "-$" << p->price << endl;
    }
    cout << "Total:$" << calculateTotal() << endl;
   }

   // 3. Voilating SRP - saves to DB (Should be in a separate class)
    void saveToDatabase(){
        cout << "Saving shopping cart to database..." << endl;
    }
};


int main(){
    ShoppingCart*cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop",1500));
    cart->addProduct(new Product("Mouse",50));

    cart->printInvoice();
    cart->saveToDatabase();
    return 0;
}