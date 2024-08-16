#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string bookNumber, title, author, edition, publication;

public:
    void setBookNumber(string bookNumber) { this->bookNumber = bookNumber; }
    void setTitle(string title) { this->title = title; }
    void setAuthor(string author) { this->author = author; }
    void setEdition(string edition) { this->edition = edition; }
    void setPublication(string publication) { this->publication = publication; }

    string getBookNumber() { return this->bookNumber; }
    string getTitle() { return this->title; }
    string getAuthor() { return this->author; }
    string getEdition() { return this->edition; }
    string getPublication() { return this->publication; }

    void displayBook() {
        cout << "BookNumber: " << this->bookNumber << endl;
        cout << "Title: " << this->title << endl;
        cout << "Author: " << this->author << endl;
        cout << "Edition: " << this->edition << endl;
        cout << "Publication: " << this->publication << endl;
    }
};

class Member {
private:
    string memberId, name, email;

public:
    void setMemberId(string memberId) { this->memberId = memberId; }
    void setName(string name) { this->name = name; }
    void setEmail(string email) { this->email = email; }

    string getMemberId() { return this->memberId; }
    string getName() { return this->name; }
    string getEmail() { return this->email; }

    void displayMember() {
        cout << "Member ID: " << this->memberId << endl;
        cout << "Name: " << this->name << endl;
        cout << "Email: " << this->email << endl;
    }
};

void addBook(Book* &books, int &bookCount, int &capacity) {
    if (bookCount >= capacity) {
        cout << "Book storage is full. Expanding storage capacity..." << endl;
        capacity *= 2;
        Book* newBooks = new Book[capacity];
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

    books[bookCount].setBookNumber(bookNumber);
    books[bookCount].setTitle(title);
    books[bookCount].setAuthor(author);
    books[bookCount].setEdition(edition);
    books[bookCount].setPublication(publication);
    bookCount++;
    cout << "Book added successfully." << endl << endl;
}

void addMember(Member* &members, int &memberCount, int &capacity) {
    if (memberCount >= capacity) {
        cout << "Member storage is full. Expanding storage capacity..." << endl;
        capacity *= 2;
        Member* newMembers = new Member[capacity];
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

    members[memberCount].setMemberId(memberId);
    members[memberCount].setName(name);
    members[memberCount].setEmail(email);
    memberCount++;
    cout << "Member added successfully." << endl << endl;
}

void displayBooks(Book* books, int bookCount) {
    cout << "Book Details:" << endl;
    for (int i = 0; i < bookCount; ++i) {
        books[i].displayBook();
        cout << endl;
    }
}

void displayMembers(Member* members, int memberCount) {
    cout << "Member Details:" << endl;
    for (int i = 0; i < memberCount; ++i) {
        members[i].displayMember();
        cout << endl;
    }
}

void deleteBook(Book* &books, int &bookCount) {
    if (bookCount == 0) {
        cout << "No books to delete." << endl;
        return;
    }

    string bookNumber;
    cout << "Enter the book number of the book to delete: ";
    cin >> bookNumber;

    int index = -1;
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].getBookNumber() == bookNumber) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Book not found." << endl;
        return;
    }

    for (int i = index; i < bookCount - 1; ++i) {
        books[i] = books[i + 1];
    }

    bookCount--;
    cout << "Book deleted successfully." << endl;
}

int main() {
    int bookCapacity = 2;
    int memberCapacity = 2;

    Book* books = new Book[bookCapacity];
    Member* members = new Member[memberCapacity];

    int bookCount = 0;
    int memberCount = 0;

    while (true) {
        int choice;
        cout << "Menu:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Add Member" << endl;
        cout << "3. Display Books" << endl;
        cout << "4. Display Members" << endl;
        cout << "5. Delete Book" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books, bookCount, bookCapacity);
                break;
            case 2:
                addMember(members, memberCount, memberCapacity);
                break;
            case 3:
                displayBooks(books, bookCount);
                break;
            case 4:
                displayMembers(members, memberCount);
                break;
            case 5:
                deleteBook(books, bookCount);
                break;
            case 6:
                cout << "Exiting program..." << endl;
                delete[] books;
                delete[] members;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
