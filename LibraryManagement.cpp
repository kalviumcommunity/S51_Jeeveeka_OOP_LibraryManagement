#include <iostream>
#include <conio.h>
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

int main() {
    Book book1, book2;

    book1.setBookNumber("1");
    book1.setTitle("Dork Diaries");
    book1.setAuthor("Rachel");
    book1.setEdition("4th");
    book1.setPublication("Scholastic");

    book2.setBookNumber("2");
    book2.setTitle("Hunger Games");
    book2.setAuthor("Suzanne Collins");
    book2.setEdition("2nd");
    book2.setPublication("Scholastic Press");

    cout << "Book 1 Details:" << endl;
    book1.displayBook();
    cout << endl;

    cout << "Book 2 Details:" << endl;
    book2.displayBook();
    cout << endl;

    Member member1, member2;

    member1.setMemberId("M001");
    member1.setName("Jeevz");
    member1.setEmail("jeevz@example.com");

    member2.setMemberId("M002");
    member2.setName("Devz");
    member2.setEmail("devz@example.com");

    cout << "Member 1 Details:" << endl;
    member1.displayMember();
    cout << endl;

    cout << "Member 2 Details:" << endl;
    member2.displayMember();
    cout << endl;

    return 0;
}
