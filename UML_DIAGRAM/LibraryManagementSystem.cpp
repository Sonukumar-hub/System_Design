#include<iostream>
using namespace std;

class Book{
private:
    int bookId;
    string title;
    string author;
    bool available;
public:
    Book(int bookId,string title, string author,bool available){
        this->bookId = bookId;
        this->title = title;
        this->author = author;
        this->available = available;
    };

    void updateStatus(bool status){
        available = status;
    }

    void displayBook(){
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
    }
};




class Student{
private:
    int studentId;
    string name;

public:
    Student(int studentId,string name){
        this->studentId = studentId;
        this->name = name;
    }

    void searchBook(){
        cout << name << " is searching for a book." << endl;
    }

    void borrowBook(Book &book){
        cout << name << "is borrowed a book." << endl;
        book.updateStatus(false);
    }

    void returnBook(Book& book){
        book.updateStatus(true);
    }
};


class Librarian{
private:
    int librarianId;
    string name;
    
public:
    Librarian(int librarianId,string name){
        this->librarianId =librarianId;
        this->name = name;
    }

    void addBook(Book&book){
        cout << name << " added a book." << endl;
    }

    void removeBook(Book&book){
        cout << name << " removed a book." << endl;
    }

    void issueBook(Book & book){
        cout << name << " issude a book." << endl;
        book.updateStatus(false);
    }
};


class Fine{
private:
    int fineId;
    double amount;

public:
    Fine(int fineId,double amount){
        this->fineId = fineId;
        this->amount = amount;
    };

    void calculateFine(int lateDays){
        amount = lateDays*10;
    };

    void displayFine(){
        cout << "Fine: Rs. " << amount << endl;
    }
};



class Library {
private:
    int libraryId;
    string name;

public:
    Library(int id, string n) {
        libraryId = id;
        name = n;
    }

    void calculateFine(int lateDays) {
        double fine = lateDays * 10;

        cout << "Late days: " << lateDays << endl;
        cout << "Fine: Rs. " << fine << endl;
    }
};


int main(){
    Book* book1 = new Book(101,"clean code","Robert Martin",true);

    Student* student1 = new Student(1,"Sonu Kumar");

    Librarian *librarian1 = new Librarian(10, "Rahul");

    Fine *fine1 = new Fine(501, 0);

    cout << "----- Book -----" << endl;
    book1->displayBook();

    cout << "\n----- Student -----" << endl;
    student1->searchBook();
    student1->borrowBook(*book1);

    cout << "\n----- Librarian -----" << endl;
    librarian1->issueBook(*book1);

    cout << "\n----- Fine -----" << endl;
    fine1->calculateFine(5);
    fine1->displayFine();

    cout << "\n----- Library -----" << endl;
    Library *library1 = new Library(100, "Central Library");
    library1->calculateFine(7);

    return 0;
}