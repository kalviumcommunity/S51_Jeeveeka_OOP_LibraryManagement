#include <iostream>
#include <string>
using namespace std;

class LibraryEntity {
public:
    virtual void displayEntity() const = 0; 
    virtual ~LibraryEntity() {}
};

// Single responsibility principle
class Book : public LibraryEntity {
private:
    string bookNumber, title, author, edition, publication;
    static int totalBooks;

public:
    Book() { totalBooks++; }

    Book(string bookNumber, string title, string author, string edition, string publication)
        : bookNumber(bookNumber), title(title), author(author), edition(edition), publication(publication) {
        totalBooks++;
    }

    ~Book() { totalBooks--; }

    void displayEntity() const override {
        cout << "Book Number: " << bookNumber << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Edition: " << edition << endl;
        cout << "Publication: " << publication << endl;
    }

    static int getTotalBooks() { return totalBooks; }
};

int Book::totalBooks = 0;

// Single responsibility principle
class Member : public LibraryEntity {
private:
    string memberId, name, email;
    static int totalMembers;

public:
    Member() { totalMembers++; }

    Member(string memberId, string name, string email)
        : memberId(memberId), name(name), email(email) {
        totalMembers++;
    }

    ~Member() { totalMembers--; }

    void displayEntity() const override {
        cout << "Member ID: " << memberId << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
    }

    static int getTotalMembers() { return totalMembers; }
};

int Member::totalMembers = 0;

// open closed principle
class DigitalBook : public Book {
private:
    string fileSize, format;

public:
    DigitalBook(string bookNumber, string title, string author, string edition, string publication, string fileSize, string format)
        : Book(bookNumber, title, author, edition, publication), fileSize(fileSize), format(format) {}

    void displayEntity() const override {
        Book::displayEntity();  
        cout << "File Size: " << fileSize << endl;
        cout << "Format: " << format << endl;
    }
};

// open closed principle
class PremiumMember : public Member, public Book {
private:
    string subscriptionType;

public:
    PremiumMember(string memberId, string name, string email, string bookNumber, string title, string author, string edition, string publication, string subscriptionType)
        : Member(memberId, name, email), Book(bookNumber, title, author, edition, publication), subscriptionType(subscriptionType) {}

    void displayEntity() const override {
        Member::displayEntity();  
        Book::displayEntity();   
        cout << "Subscription Type: " << subscriptionType << endl;
    }
};

void addBook(LibraryEntity** &books, int &bookCount, int &capacity) {
    if (bookCount >= capacity) {
        capacity *= 2;
        LibraryEntity** newBooks = new LibraryEntity*[capacity];
        for (int i = 0; i < bookCount; i++) {
            newBooks[i] = books[i];
        }
        delete[] books;
        books = newBooks;
    }

    string bookNumber, title, author, edition, publication;
    cout << "Enter details for Book " << bookCount + 1 << endl;
    cout << "Book Number: "; cin >> bookNumber; cin.ignore();
    cout << "Title: "; getline(cin, title);
    cout << "Author: "; getline(cin, author);
    cout << "Edition: "; getline(cin, edition);
    cout << "Publication: "; getline(cin, publication);

    books[bookCount] = new Book(bookNumber, title, author, edition, publication);
    bookCount++;

    cout << "Book added successfully." << endl << endl;
}

void addDigitalBook(LibraryEntity** &books, int &bookCount, int &capacity) {
    if (bookCount >= capacity) {
        capacity *= 2;
        LibraryEntity** newBooks = new LibraryEntity*[capacity];
        for (int i = 0; i < bookCount; i++) {
            newBooks[i] = books[i];
        }
        delete[] books;
        books = newBooks;
    }

    string bookNumber, title, author, edition, publication, fileSize, format;
    cout << "Enter details for Digital Book " << bookCount + 1 << endl;
    cout << "Book Number: "; cin >> bookNumber; cin.ignore();
    cout << "Title: "; getline(cin, title);
    cout << "Author: "; getline(cin, author);
    cout << "Edition: "; getline(cin, edition);
    cout << "Publication: "; getline(cin, publication);
    cout << "File Size: "; cin >> fileSize;
    cout << "Format: "; cin >> format;

    books[bookCount] = new DigitalBook(bookNumber, title, author, edition, publication, fileSize, format);
    bookCount++;

    cout << "Digital Book added successfully." << endl << endl;
}

void addMember(LibraryEntity** &members, int &memberCount, int &capacity) {
    if (memberCount >= capacity) {
        capacity *= 2;
        LibraryEntity** newMembers = new LibraryEntity*[capacity];
        for (int i = 0; i < memberCount; i++) {
            newMembers[i] = members[i];
        }
        delete[] members;
        members = newMembers;
    }

    string memberId, name, email;
    cout << "Enter details for Member " << memberCount + 1 << endl;
    cout << "Member ID: "; cin >> memberId; cin.ignore();
    cout << "Name: "; getline(cin, name);
    cout << "Email: "; getline(cin, email);

    members[memberCount] = new Member(memberId, name, email);
    memberCount++;

    cout << "Member added successfully." << endl << endl;
}

void displayBooks(LibraryEntity** books, int bookCount) {
    if (bookCount == 0) {
        cout << "No books to display!" << endl;
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        cout << "Book " << i + 1 << " details:" << endl;
        books[i]->displayEntity();  
        cout << endl;
    }
}

void displayMembers(LibraryEntity** members, int memberCount) {
    if (memberCount == 0) {
        cout << "No members to display!" << endl;
        return;
    }

    for (int i = 0; i < memberCount; i++) {
        cout << "Member " << i + 1 << " details:" << endl;
        members[i]->displayEntity();  
        cout << endl;
    }
}

int main() {
    int bookCapacity = 2;
    LibraryEntity** books = new LibraryEntity*[bookCapacity];
    int bookCount = 0;

    int memberCapacity = 2;
    LibraryEntity** members = new LibraryEntity*[memberCapacity];
    int memberCount = 0;

    while (true) {
        int choice;
        cout << "Menu:\n1. Add Book\n2. Add Digital Book\n3. Add Member\n4. Display Books\n5. Display Members\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books, bookCount, bookCapacity);
                break;
            case 2:
                addDigitalBook(books, bookCount, bookCapacity);
                break;
            case 3:
                addMember(members, memberCount, memberCapacity);
                break;
            case 4:
                displayBooks(books, bookCount);
                break;
            case 5:
                displayMembers(members, memberCount);
                break;
            case 6:
                cout << "Exiting..." << endl;
                for (int i = 0; i < bookCount; i++) delete books[i];
                for (int i = 0; i < memberCount; i++) delete members[i];
                delete[] books;
                delete[] members;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
