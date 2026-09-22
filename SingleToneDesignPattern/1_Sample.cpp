

// what if we do constuctor private


#include <iostream>
using namespace std;

class Singleton {

private:

    // It must be static
    static Singleton* instance;

    Singleton() {
        cout << "Singleton Constructor called. New Object Created" << endl;
    }

public:

    static Singleton* getInstance() {

        if (instance == nullptr) {
            instance = new Singleton();
        }

        return instance;
    }
};

// Define the static member outside the class
Singleton* Singleton::instance = nullptr;


int main() {

    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;

    return 0;
}