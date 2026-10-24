#include<bits/stdc++.h>

using namespace std;


class Beverage{
public:

void prepareBeverage(){
    boilWate();
    addIngredients();
    pourIntoCup();
}

void boilWate(){
    cout << "Boiling Water\n";
}

virtual void addIngredients() = 0;

void pourIntoCup(){
    cout << "Pouring into cup\n";
}

virtual ~Beverage() = default;

};

class Tea:public Beverage{
public:
   void addIngredients() override{
    cout << "Adding tea leaves\n";
   }
};

class Coffee:public Beverage{
public:
   void addIngredients() override{
    cout << "Adding cofee powder\n";
   }
};


int main(){
    Tea* tea = new Tea();
    tea->prepareBeverage();

    cout << "\n";

    Coffee* coffee = new Coffee();
    coffee->prepareBeverage();

    cout << "\n";
}