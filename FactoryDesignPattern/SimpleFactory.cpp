#include<iostream>
using namespace std;

class Burger{
public:
    virtual void prepare() = 0;

    virtual ~Burger(){}
};

class BasicBurger : public Burger{
public:
    void prepare() override{
        cout << "Preparing Basic Burger with bun, patty, and ketchup!" << endl;
    }
};

class StandardBurger : public Burger{
public:
    void prepare() override{
        cout << "Preparing Standard Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumBurger : public Burger{
public:
    void prepare() override{
        cout << "Preparing Premium Burger with gourmet bun, premium patty, cheese, lettuce and secret sauce!" << endl;
    }
};

class BurgerFactory{
public:
    Burger* createBurger(string &type){

        if(type == "basic"){
            return new BasicBurger();

        }else if(type == "standard"){
            return new StandardBurger();

        }else if(type == "premium"){
            return new PremiumBurger();

        }else{
            cout << "Invalid burger type!" << endl;
            return nullptr;
        }
    }
};

int main(){

    string type = "standard";

    BurgerFactory* myBurgerFactory = new BurgerFactory();

    Burger* burger = myBurgerFactory->createBurger(type);

    if(burger){
        burger->prepare();
        delete burger;
    }

    delete myBurgerFactory;

    return 0;
}