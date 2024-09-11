#include <iostream>
#include <string>
using namespace std;

class LibraryEntity {
public:
    virtual void displayEntity() const = 0;
    virtual ~LibraryEntity() {}
};

class Book : public LibraryEntity {
private:
    string bookNumber, title, author, edition, publication;
    static int totalBooks;

public:
    //default constructor
    Book() {
        totalBooks++;
    }

    //parameterised constructor
    Book(string bookNumber, string title, string author, string edition, string publication)
        : bookNumber(bookNumber), title(title), author(author), edition(edition), publication(publication) {
        totalBooks++;
    }

    //destructor
    ~Book() {
        totalBooks--;
    }

    string getBookNumber() { return this->bookNumber; }

    void displayEntity() const override {
        cout << "Book Number: " << this->bookNumber << endl;
        cout << "Title: " << this->title << endl;
        cout << "Author: " << this->author << endl;
        cout << "Edition: " << this->edition << endl;
        cout << "Publication: " << this->publication << endl;
    }

    static int getTotalBooks() {
        return totalBooks;
    }
};

int Book::totalBooks = 0;

class Member : public LibraryEntity {
private:
    string memberId, name, email;
    static int totalMembers;

public:
    //default constructor
    Member() {
        totalMembers++;
    }

    //parameterised constructor
    Member(string memberId, string name, string email)
        : memberId(memberId), name(name), email(email) {
        totalMembers++;
    }

    //destructor
    ~Member() {
        totalMembers--;
    }

    string getMemberId() { return this->memberId; }

    void displayEntity() const override {
        cout << "Member ID: " << this->memberId << endl;
        cout << "Name: " << this->name << endl;
        cout << "Email: " << this->email << endl;
    }

    static int getTotalMembers() {
        return totalMembers;
    }
};

int Member::totalMembers = 0;

//parameterised constructor
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

    // Createing a new book using the parameterized constructor
    books[bookCount] = Book(bookNumber, title, author, edition, publication);
    bookCount++;

    cout << "Book added successfully using parameterized constructor." << endl << endl;
}

//parameterised constructor
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

    // Createing a new member using the parameterized constructor
    members[memberCount] = Member(memberId, name, email);
    memberCount++;

    cout << "Member added successfully using parameterized constructor." << endl << endl;
}

void displayLibraryEntities(LibraryEntity** entities, int count) {
    cout << "Library Entity Details:" << endl;
    for (int i = 0; i < count; ++i) {
        entities[i]->displayEntity();
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
    int bookCapacity, memberCapacity;

    cout << "Enter initial capacity for books: ";
    cin >> bookCapacity;
    cout << "Enter initial capacity for members: ";
    cin >> memberCapacity;

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
                displayLibraryEntities((LibraryEntity**)books, bookCount);
                break;
            case 4:
                displayLibraryEntities((LibraryEntity**)members, memberCount);
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
