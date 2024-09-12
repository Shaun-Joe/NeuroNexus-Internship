#include "library.h"

Book::Book(const string &title, const string &author, const string &isbn)
    : title(title), author(author), isbn(isbn), available(true) {}

string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::isAvailable() const { return available; }
void Book::setAvailable(bool available) { this->available = available; }

Borrower::Borrower(const string &name, const string &id)
    : name(name), id(id) {}

string Borrower::getName() const { return name; }
string Borrower::getId() const { return id; }

Transaction::Transaction(const Book &book, const Borrower &borrower, time_t checkoutDate)
    : book(book), borrower(borrower), checkoutDate(checkoutDate), returnDate(0) {}

const Book &Transaction::getBook() const { return book; }
const Borrower &Transaction::getBorrower() const { return borrower; }
time_t Transaction::getCheckoutDate() const { return checkoutDate; }
time_t Transaction::getReturnDate() const { return returnDate; }
void Transaction::setReturnDate(time_t returnDate) { this->returnDate = returnDate; }

void Library::addBook(const Book &book)
{
    books.push_back(book);
}

void Library::addBorrower(const Borrower &borrower)
{
    borrowers.push_back(borrower);
}

Book *Library::findBookByISBN(const string &isbn)
{
    for (auto &book : books)
    {
        if (book.getISBN() == isbn)
        {
            return &book;
        }
    }
    return nullptr;
}

Borrower *Library::findBorrowerById(const string &id)
{
    for (auto &borrower : borrowers)
    {
        if (borrower.getId() == id)
        {
            return &borrower;
        }
    }
    return nullptr;
}

Transaction *Library::findTransactionByISBN(const string &isbn)
{
    for (auto &transaction : transactions)
    {
        if (transaction.getBook().getISBN() == isbn && transaction.getReturnDate() == 0)
        {
            return &transaction;
        }
    }
    return nullptr;
}

void Library::checkoutBook(const string &isbn, const string &borrowerId)
{
    Book *book = findBookByISBN(isbn);
    Borrower *borrower = findBorrowerById(borrowerId);

    if (book && borrower && book->isAvailable())
    {
        book->setAvailable(false);
        time_t now = time(nullptr);
        transactions.emplace_back(*book, *borrower, now);
        cout << "Book checked out successfully." << endl;
    }
    else
    {
        cout << "Error: Book is not available or borrower not found." << endl;
    }
}

void Library::returnBook(const string &isbn)
{
    Transaction *transaction = findTransactionByISBN(isbn);

    if (transaction)
    {
        time_t now = time(nullptr);
        transaction->setReturnDate(now);
        Book *book = findBookByISBN(isbn);
        if (book)
        {
            book->setAvailable(true);
        }
        double fine = calculateFine(transaction->getCheckoutDate(), transaction->getReturnDate());
        if (fine > 0)
        {
            cout << "Book returned. Fine: $" << fine << endl;
        }
        else
        {
            cout << "Book returned with no fine." << endl;
        }
    }
    else
    {
        cout << "Error: No active transaction found for this book." << endl;
    }
}

void Library::searchBooks(const string &query) const
{
    cout << "Search results:" << endl;
    for (const auto &book : books)
    {
        if (book.getTitle().find(query) != string::npos ||
            book.getAuthor().find(query) != string::npos ||
            book.getISBN().find(query) != string::npos)
        {
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << endl;
        }
    }
}

void Library::viewTransactions() const
{
    cout << "Current transactions:" << endl;

    for (const auto &transaction : transactions)
    {
        time_t checkoutDate = transaction.getCheckoutDate();
        time_t returnDate = transaction.getReturnDate();

        tm *checkoutTm = localtime(&checkoutDate);
        tm *returnTm = (returnDate != 0) ? localtime(&returnDate) : nullptr;

        cout << "Book: " << transaction.getBook().getTitle()
             << ", Borrower: " << transaction.getBorrower().getName()
             << ", Checkout Date: " << put_time(checkoutTm, "%c");

        if (returnTm)
        {
            cout << ", Return Date: " << put_time(returnTm, "%c") << endl;
        }
        else
        {
            cout << ", Status: Checked out" << endl;
        }
    }
}

double Library::calculateFine(time_t checkoutDate, time_t returnDate) const
{
    const int DAYS_OVERDUE = 14;
    double finePerDay = 0.50;
    tm *checkoutTm = localtime(&checkoutDate);
    tm *returnTm = localtime(&returnDate);

    time_t checkoutTime = mktime(checkoutTm);
    time_t returnTime = mktime(returnTm);

    double daysOverdue = difftime(returnTime, checkoutTime) / (60 * 60 * 24) - DAYS_OVERDUE;
    if (daysOverdue > 0)
    {
        return daysOverdue * finePerDay;
    }
    return 0.0;
}
