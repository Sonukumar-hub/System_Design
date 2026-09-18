#include <iostream>
using namespace std;

// Low-level module
class MySQLDatabase {
public:
    void save() {
        cout << "Saving data in MySQL" << endl;
    }
};


// High-level module
class OrderService {
private:
    MySQLDatabase* db;   // Directly depends on MySQL

public:
    OrderService(MySQLDatabase* database) {
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