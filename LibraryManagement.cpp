#include<iostream> 
#include<conio.h>
#include<string>
using namespace std;

class Book {
    private:
        string bookNumber, title, author, edition, publication;
    
    public:
        void setBookNumber(string a) { bookNumber = a; }
        void setTitle(string b) { title = b; }
        void setAuthor(string c) { author = c; }
        void setEdition(string d) { edition = d; }
        void setPublication(string e) { publication = e; }

        string getBookNumber() { return bookNumber; }
        string getTitle() { return title; }
        string getAuthor() { return author; }
        string getEdition() { return edition; }
        string getPublication() { return publication; }

        void displayBook() {
            cout << "BookNumber: " << bookNumber << endl;
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Edition: " << edition << endl;
            cout << "Publication: " << publication << endl;
        }
};

class Member {
    private:
        string memberId, name, email;
    
    public:
        void setMemberId(string id) { memberId = id; }
        void setName(string n) { name = n; }
        void setEmail(string e) { email = e; }

        string getMemberId() { return memberId; }
        string getName() { return name; }
        string getEmail() { return email; }

        void displayMember() {
            cout << "Member ID: " << memberId << endl;
            cout << "Name: " << name << endl;
            cout << "Email: " << email << endl;
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
