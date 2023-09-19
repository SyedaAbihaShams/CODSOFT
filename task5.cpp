#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <cmath>
using namespace std;

class Date{
private:
    time_t t;
public:
    struct tm date;
    int day , month , year;
    
    Date(){
        time_t t = time(NULL);
        struct tm* localDate = localtime(&t);
        
        day = localDate->tm_mday;
        month = localDate->tm_mon + 1;
        year = localDate->tm_year + 1900;
        
        date = *localDate;
    }
    
    Date(int d, int m, int y){
        day = d; month = m ; year = y;
        
        struct tm localDate = {};
        localDate.tm_mday = d;
        localDate.tm_mon = m - 1;
        localDate.tm_year = y - 1900;
        
        t = mktime(&localDate);
        date = *localtime(&t);
    }

    double calculateDifferenceInDays(Date& otherDate) {
        time_t thisTime = mktime(&date);
        time_t otherTime = mktime(&otherDate.date);
        double differenceInSeconds = difftime(thisTime, otherTime);
        return std::floor(std::abs(differenceInSeconds / (60 * 60 * 24)));
    }
};

class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;
    bool isAvailable;

    Book(const std::string& t, const std::string& a, const std::string& i)
        : title(t), author(a), isbn(i), isAvailable(true) {}
};

class Library {
private:
    std::vector<Book> books;
    std::map<std::string, Book*> isbnToBook;

public:
    void addBook(const std::string& title, const std::string& author, const std::string& isbn) {
        Book newBook(title, author, isbn);
        books.push_back(newBook);
        isbnToBook[isbn] = &newBook;
    }

    Book* searchBook(const std::string& keyword) {
        for (int i=0 ; i<books.size() ; i++) {
            if (books[i].title == keyword || books[i].author == keyword || books[i].isbn == keyword) {
                return &books[i];
            }
        }
        return NULL;
    }

    bool checkoutBook(const std::string& isbn) {
        Book* book = searchBook(isbn);
        if(!book) return false;
        if (book->isAvailable) {
            book->isAvailable = false;
            return true;
        }
        return false;
    }

    void returnBook(const std::string& isbn) {
        if (isbnToBook.find(isbn) != isbnToBook.end()) {
            Book* book = isbnToBook[isbn];
            if (!book->isAvailable) {
                book->isAvailable = true;
            }
        }
    }
    
    void printAvailableBooks(){
        std::cout<<endl<<"These are the available books:"<<endl;
        
        for(int i=0 ; i<books.size() ; i++){
            if(books[i].isAvailable){
                cout<<books[i].title<<" by "<<books[i].author<< " [ISBN: "<<books[i].isbn<<" ]"<<endl;
            }
        }
    }
};

int main() {
    Library library;

    // Add books to the library
    library.addBook("The Sharp Objects", "Gillian Flynn", "123-0-01-09876-0");
    library.addBook("An Unwanted Guest", "Shari Lapena", "123-0-01-09876-1");
    library.addBook("The A.B.C Murders","Agatha Christie","123-0-01-09876-2");
    library.addBook("The Silent Patient","Alex Michaelides","123-0-01-09876-3");
    library.addBook("One of us is Lying","Karen M. McManus","123-0-01-09876-4");
    library.addBook("Rebecca","Daphne du Maurier","123-0-01-09876-5");

    while (true) {
        cout<<"\n\n--------------------------------"<<endl;
        std::cout << "1. Search for a book\n2. Checkout a book\n3. Return a book\n4. Exit\n";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter title, author, or ISBN to search: ";
            std::string keyword;
            std::cin >> keyword;
            Book* foundBook = library.searchBook(keyword);
            if (foundBook) {
                std::cout << "Book Found: " << foundBook->title << " by " << foundBook->author << " ISBN: " << foundBook->isbn << std::endl;
            } else {
                std::cout << "Book not found." << std::endl;
            }
        } else if (choice == 2) {
            library.printAvailableBooks();
            std::cout << "Enter ISBN to checkout: ";
            std::string isbn;
            std::cin >> isbn;
            if (library.checkoutBook(isbn)) {
                Date today;
                
                Book* book = library.searchBook(isbn);
                cout<<"You choose: ";
                cout<<book->title<<" by "<<book->author<<" [ISBN: "<<isbn<<"]"<<endl;
                std::cout << "Book checked out successfully on date: " << today.day<<"-"<<today.month<<"-"<<today.year<<std::endl;
            } else {
                std::cout << "Book not available or not found." << std::endl;
            }
        } else if (choice == 3) {
            std::cout << "Enter ISBN to return: ";
            std::string isbn;
            std::cin >> isbn;
            
            Book* book = library.searchBook(isbn);
            
            if(book->isAvailable){
                cout<<book->title<<" by "<<book->author<<" [ISBN: "<<isbn<<"]"<<endl;
                cout<<"The book can't be returned it is already present.";
            }
            else{
                cout<<"Enter day of return: ";
                int d;cin>>d;
                cout<<"Enter month of return: ";
                int m; cin>>m;
                cout<<"Enter year of return: ";
                int y; cin>>y;
                
                Date retDate(d,m,y);
                Date curr;
                
                if(curr.calculateDifferenceInDays(retDate) > 7){
                    cout<<"You have to pay the fine of 2$ to the next counter because you are late."<<endl;
                }
                
                library.returnBook(isbn);
                cout<<book->title<<" by "<<book->author<<" [ISBN: "<<isbn<<"]"<<endl;
                std::cout << "Book returned." << std::endl;
            }
        } else if (choice == 4) {
            cout<<" THE END "<<endl;
            break;
        }
    }

    return 0;
}
