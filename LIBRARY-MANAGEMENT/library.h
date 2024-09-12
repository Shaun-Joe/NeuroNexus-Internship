#ifndef LIBRARY_H
#define LIBRARY_H

    #include <string>
    #include <vector>
    #include <ctime>
    #include <limits>
    #include <iostream>
    #include <iomanip>
    #include <sstream>

    using namespace std;

    class Book
    {
    public:
        Book(const string &title, const string &author, const string &isbn);

        string getTitle() const;
        string getAuthor() const;
        string getISBN() const;
        bool isAvailable() const;
        void setAvailable(bool available);

    private:
        string title;
        string author;
        string isbn;
        bool available;
    };

    class Borrower
    {
    public:
        Borrower(const string &name, const string &id);

        string getName() const;
        string getId() const;

    private:
        string name;
        string id;
    };

    class Transaction
    {
    public:
        Transaction(const Book &book, const Borrower &borrower, time_t checkoutDate);

        const Book &getBook() const;
        const Borrower &getBorrower() const;
        time_t getCheckoutDate() const;
        time_t getReturnDate() const;
        void setReturnDate(time_t returnDate);

    private:
        Book book;
        Borrower borrower;
        time_t checkoutDate;
        time_t returnDate;
    };

    class Library
    {
    public:
        void addBook(const Book &book);
        void addBorrower(const Borrower &borrower);
        void checkoutBook(const string &isbn, const string &borrowerId);
        void returnBook(const string &isbn);
        void searchBooks(const string &query) const;
        void viewTransactions() const;

    private:
        vector<Book> books;
        vector<Borrower> borrowers;
        vector<Transaction> transactions;

        Book *findBookByISBN(const string &isbn);
        Borrower *findBorrowerById(const string &id);
        Transaction *findTransactionByISBN(const string &isbn);
        double calculateFine(time_t checkoutDate, time_t returnDate) const;
    };

#endif