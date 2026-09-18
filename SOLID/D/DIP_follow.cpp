#include <iostream> 
using namespace std; 
 
// Abstraction 
class Database { 
public: 
    virtual void save() = 0; 
}; 
 
 
// Low-level module 
class MySQLDatabase : public Database { 
public: 
    void save() override { 
        cout << "Saving data in MySQL" << endl; 
    } 
}; 
 
 
// Another low-level module 
class MongoDB : public Database { 
public: 
    void save() override { 
        cout << "Saving data in MongoDB" << endl; 
    } 
}; 
 
 
// High-level module 
class OrderService { 
private: 
    Database* db; 
 
public: 
    OrderService(Database* database) { 
        db = database; 
    } 
 
    void placeOrder() { 
        cout << "Order placed" << endl; 
        db->save(); 
    } 
}; 
 
 
int main() { 
 
    MySQLDatabase mysql; 
 
    OrderService order(&mysql); 
    order.placeOrder(); 
 
    return 0; 
} 