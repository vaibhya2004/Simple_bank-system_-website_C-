#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract base class for members of the library
class Member {
protected:
    string name;
    int memberID;

public:
    // Constructor to initialize member details
    Member(string n, int id) : name(n), memberID(id) {}

    // Pure virtual function to borrow a book (to be implemented by derived classes)
    virtual void borrowBook() = 0;

    // Pure virtual function to return a book (to be implemented by derived classes)
    virtual void returnBook() = 0;

    // Function to display member details
    void displayMemberDetails() {
        cout << "Name: " << name << endl;
        cout << "Member ID: " << memberID << endl;
    }
};

// Derived class RegularMember inherits from Member
class RegularMember : public Member {
public:
    RegularMember(string n, int id) : Member(n, id) {}

    // Implementation of borrowBook for RegularMember
    void borrowBook() override {
        cout << name << " can borrow up to 3 books." << endl;
    }

    // Implementation of returnBook for RegularMember
    void returnBook() override {
        cout << name << " is returning a book." << endl;
    }
};

// Derived class PremiumMember inherits from Member
class PremiumMember : public Member {
public:
    PremiumMember(string n, int id) : Member(n, id) {}

    // Implementation of borrowBook for PremiumMember
    void borrowBook() override {
        cout << name << " can borrow up to 10 books." << endl;
    }

    // Implementation of returnBook for PremiumMember
    void returnBook() override {
        cout << name << " is returning a book with priority." << endl;
    }
};

// Class for books in the library
class Book {
private:
    string title;
    string author;
    bool isAvailable;

public:
    // Constructor to initialize book details
    Book(string t, string a) : title(t), author(a), isAvailable(true) {}

    // Function to check out a book
    void borrow() {
        if (isAvailable) {
            isAvailable = false;
            cout << title << " has been borrowed." << endl;
        } else {
            cout << title << " is currently unavailable." << endl;
        }
    }

    // Function to return a book
    void returnBook() {
        isAvailable = true;
        cout << title << " has been returned." << endl;
    }

    // Function to display book details
    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
    }
};

// Library class that manages books and members
class Library {
private:
    vector<Book> books;
    vector<Member*> members; // Store pointers to Member objects (base class)

public:
    // Function to add a book to the library
    void addBook(Book b) {
        books.push_back(b);
    }

    // Function to add a member to the library
    void addMember(Member* m) {
        members.push_back(m);
    }

    // Function to display all books
    void displayBooks() {
        for (auto& book : books) {
            book.displayBookDetails();
            cout << "-----------------" << endl;
        }
    }

    // Function to display all members
    void displayMembers() {
        for (auto& member : members) {
            member->displayMemberDetails();
            cout << "-----------------" << endl;
        }
    }
};

// Main function to drive the program
int main() {
    // Create books
    Book book1("The C++ Programming Language", "Bjarne Stroustrup");
    Book book2("Clean Code", "Robert C. Martin");
    Book book3("Design Patterns", "Erich Gamma");

    // Create members
    RegularMember member1("rama", 1001);
    PremiumMember member2("mama", 1002);

    // Create library and add books and members
    Library myLibrary;
    myLibrary.addBook(book1);
    myLibrary.addBook(book2);
    myLibrary.addBook(book3);
    myLibrary.addMember(&member1);
    myLibrary.addMember(&member2);

    // Display all books and members
    cout << "Library Books: " << endl;
    myLibrary.displayBooks();

    cout << "\nLibrary Members: " << endl;
    myLibrary.displayMembers();

    // Simulate borrowing and returning books
    member1.borrowBook();
    book1.borrow();
    member1.returnBook();
    book1.returnBook();

    member2.borrowBook();
    book2.borrow();
    member2.returnBook();
    book2.returnBook();

    return 0;
}
