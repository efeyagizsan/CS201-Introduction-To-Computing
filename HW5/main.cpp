#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;


struct Book {
    string title;
    string author;
    int publicationYear;
};


bool compareByLastName(const Book& book1, const Book& book2) {
    string lastName1 = book1.author.substr(book1.author.find_last_of(' ') + 1);
    string lastName2 = book2.author.substr(book2.author.find_last_of(' ') + 1);

    transform(lastName1.begin(), lastName1.end(), lastName1.begin(), [](unsigned char c) { return std::toupper(c); });
    transform(lastName2.begin(), lastName2.end(), lastName2.begin(), [](unsigned char c) { return std::toupper(c); });

    if (lastName1 != lastName2) {
        return lastName1 < lastName2;
    } else {
        string title1 = book1.title;
        string title2 = book2.title;
        transform(title1.begin(), title1.end(), title1.begin(), [](unsigned char c) { return std::toupper(c); });
        transform(title2.begin(), title2.end(), title2.begin(), [](unsigned char c) { return std::toupper(c); });
        return title1 < title2;
    }
}




void addBook(vector<Book>& library) {
    string title, author;
    int publicationYear;

    cin.ignore();
    cout<<"Enter the new book details:"<<endl;
    cout << "Enter book's title: ";
    getline(cin, title);
    cout << "Enter book's author: ";
    getline(cin, author);
    cout << "Enter book's publication year: ";
    cin >> publicationYear;

    Book newBook = {title, author, publicationYear};


    auto it = upper_bound(library.begin(), library.end(), newBook, compareByLastName);


    library.insert(it, newBook);


}


void searchByAuthor(const vector<Book>& books) {
    string searchAuthor;
    cout << "Enter the author of the book you want to search for: ";
    cin.ignore();
    getline(cin, searchAuthor);
    string lastname;
    stringstream ss(searchAuthor);
    while (getline(ss, lastname, ' ')) {

    }

    transform(searchAuthor.begin(), searchAuthor.end(), searchAuthor.begin(), [](unsigned char c) { return std::tolower(c); });

    bool found = false;
    bool firsttime = true;
    for (size_t i = 0; i < books.size(); i++) {
        string bookAuthor = books[i].author;

        transform(bookAuthor.begin(), bookAuthor.end(), bookAuthor.begin(), [](unsigned char c) { return std::tolower(c); });

        if (bookAuthor == searchAuthor) {
            if (firsttime){
                cout << "Books by " << lastname <<":"<< endl;
                firsttime = false;
            }

            found = true;
            cout << "Title: " << books[i].title << ", Publication Year: " << books[i].publicationYear << ", Position: " << (i + 1) << endl;
        }
    }

    if (!found) {
        cout << "No books were found." << endl;
    }
}




void searchByTitle(const vector<Book>& books) {
    string searchTitle;
    cout << "Enter the title of the book you want to search for: ";
    cin.ignore();
    getline(cin, searchTitle);

    cout << "Books matching the title \"" << searchTitle << "\":" << endl;
    transform(searchTitle.begin(), searchTitle.end(), searchTitle.begin(), [](unsigned char c) { return std::toupper(c); });

    bool found = false;

    for (size_t i = 0; i < books.size(); i++) {
        string bookTitle = books[i].title;

        transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(), [](unsigned char c) { return std::toupper(c); });

        if (bookTitle == searchTitle) {
            found = true;

            cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Publication Year: " << books[i].publicationYear << ", Position: " << (i + 1) << endl;
        }
    }

    if (!found) {
        cout << "No books were found." << endl;
    }
}






void displayBooks(const vector<Book>& library) {
    vector<Book> sortedLibrary = library;
    sort(sortedLibrary.begin(), sortedLibrary.end(), compareByLastName);

    cout << "Sorted books by author's last name:" << endl;
    int position = 1;
    for (const Book& book : sortedLibrary) {
        cout << position << ". " << book.title << ", " << book.author << ", " << book.publicationYear << endl;
        position++;
    }
}


int main() {
    vector<Book> library = {
            {"The Great Gatsby", "F Scott Fitzgerald", 1925},
            {"Moby Dick", "Herman Melville", 1851},
            {"To Kill a Mockingbird", "Harper Lee", 1960},
            {"Pride and Prejudice", "Jane Austen", 1813},
            {"Burmese Days", "George Orwell", 1934},
            {"Brave New World", "Aldous Huxley", 1932},
            {"Animal Farm", "George Orwell", 1945}
    };
    vector<Book> sortedLibrary = library;
    sort(sortedLibrary.begin(), sortedLibrary.end(), compareByLastName);



    int choice;

    do {

        cout << "Library System Menu:" << endl;
        cout << "1. Add books" << endl;
        cout << "2. Search for an author" << endl;
        cout << "3. Search for by book title" << endl;
        cout << "4. Display books" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(sortedLibrary);
                break;
            case 2:
                searchByAuthor(sortedLibrary);
                break;
            case 3:
                searchByTitle(sortedLibrary);
                break;
            case 4:
                displayBooks(sortedLibrary);
                cout<<endl;
                break;
            case 5:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice, please try again."<<endl;
        }
    } while (choice != 5);

    return 0;
}
