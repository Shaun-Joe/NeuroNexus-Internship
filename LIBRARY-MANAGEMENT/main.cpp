#include "library.h"

void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getIntegerInput()
{
    int number;
    while (!(cin >> number))
    {
        clearInputBuffer();
        cout << "Invalid input. Please enter an integer: ";
    }
    clearInputBuffer();
    return number;
}

string getStringInput()
{
    string input;
    getline(cin, input);
    return input;
}

void displayMenu()
{
    cout << "Library Management System" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Add Borrower" << endl;
    cout << "3. Checkout Book" << endl;
    cout << "4. Return Book" << endl;
    cout << "5. Search Books" << endl;
    cout << "6. View Transactions" << endl;
    cout << "7. Exit" << endl;
    cout << "Choose an option: ";
}

int main()
{
    Library library;
    int choice;

    while (true)
    {
        displayMenu();
        choice = getIntegerInput();

        switch (choice)
        {
        case 1:
        {
            cout << "Enter book title: ";
            string title = getStringInput();
            cout << "Enter book author: ";
            string author = getStringInput();
            cout << "Enter book ISBN: ";
            string isbn = getStringInput();
            library.addBook(Book(title, author, isbn));
            break;
        }
        case 2:
        {
            cout << "Enter borrower name: ";
            string name = getStringInput();
            cout << "Enter borrower ID: ";
            string id = getStringInput();
            library.addBorrower(Borrower(name, id));
            break;
        }
        case 3:
        {
            cout << "Enter book ISBN to checkout: ";
            string isbn = getStringInput();
            cout << "Enter borrower ID: ";
            string borrowerId = getStringInput();
            library.checkoutBook(isbn, borrowerId);
            break;
        }
        case 4:
        {
            cout << "Enter book ISBN to return: ";
            string isbn = getStringInput();
            library.returnBook(isbn);
            break;
        }
        case 5:
        {
            cout << "Enter search query (title, author, or ISBN): ";
            string query = getStringInput();
            library.searchBooks(query);
            break;
        }
        case 6:
        {
            library.viewTransactions();
            break;
        }
        case 7:
        {
            cout << "Exiting the program." << endl;
            return 0;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }

    return 0;
}
