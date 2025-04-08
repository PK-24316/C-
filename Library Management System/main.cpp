#include <iostream>
#include <string>

using namespace std;

//Book class
class Book
{
    private:
        int id;
        string title;
        string author;
        bool isIssued;

    public:
        Book() //Constructor
        {
            id = 0;
            isIssued = false;
        }

        void inputDetails(int newID)
        {
            id = newID;
            cin.ignore(); //Clear input buffer

            cout << "Enter a book title: ";
            getline(cin, title);

            cout << "Enter author name: ";
            getline(cin, author);

            isIssued = false;
        }

        void displayDetails() const
        {
            cout << "Book ID: " << id << "\n" 
                 << "Title: " << title << "\n"
                 << "Author: " << author << "\n"
                 << "Status: " << (isIssued ? "Issued" : "Available") << "\n";
            cout << "-----------------------------------\n"; 
        }

        int getID() const
        {
            return id;
        }

        string getTitle() const
        {
            return title;
        }

        bool checkIssued() const
        {
            return isIssued;
        }

        void issueBook()
        {
            if (!isIssued)
            {
                isIssued = true;
                cout << "Book issued successfully.\n";
            }
            else cout << "Book is already issued.\n";
        }

        void returnBook()
        {
            if (isIssued)
            {
                isIssued = false;
                cout << "Book returned successfully.\n";
            }
            else cout << "This book was not issued.\n";
        }
};

//Library Class
class Library
{
    private:
        Book books[100];
        int bookCount = 0;
        int nextID = 1001;

    public:
        void addBook()
        {
            if (bookCount >= 100)
            {
                cout << "Library is Full!\n";
                return;
            }
            books[bookCount].inputDetails(nextID);
            bookCount++;
            cout << "Book added successfully. Book ID: " << nextID << endl;
            nextID++;
        }

        void showAllBooks() const
        {
            if (bookCount == 0)
            {
                cout << "No books in the library.\n";
                return;
            }
            cout << "\n--- Book List ---\n";
            for (int i = 0; i < bookCount; i++)
                books[i].displayDetails();
        }

        Book* searchBookById(int id)
        {
            for (int i = 0; i < bookCount; i++)
            {
                if (books[i].getID() == id)
                    return &books[i];
            }

            return nullptr;
        }

        void issueBook()
        {
            int id;

            cout << "Enter Book ID to issue: ";
            cin >> id;

            Book* book = searchBookById(id);

            if (book != nullptr)
                book->issueBook();
            else
                cout << "Book not found!\n";
        }

        void returnBook()
        {
            int id;

            cout << "Enter Book ID to return: ";
            cin >> id;

            Book* book = searchBookById(id);

            if (book != nullptr)
                book->returnBook();
            else
                cout << "Book not found!\n";
        }

};


int main()
{
    Library lib;
    int choice;

    do
    {
        cout << "\n======= LIBRARY MENU ======\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice)
        {
            case 1: lib.addBook(); break;
            case 2: lib.showAllBooks(); break;
            case 3: lib.issueBook(); break;
            case 4: lib.returnBook(); break;
            case 5: cout << "Goodbye!\n"; break;
            default: cerr << "Invalid choice. Try again.\n";
        }


    } while (choice != 5);

    return 0;
}