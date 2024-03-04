#include <iostream>
using namespace std;
class Book
{
public:
    string title;
    string author;
    string genre;
    double price;
    bool availability;
    Book() : title(""), author(""), genre(""), price(0.0), availability(false) {}
    Book(string t, string a, string g, double p, bool av) : title(t), author(a), genre(g), price(p), availability(av) {}
};

int book_count = 0;

class Node {
public:
    Book data;
    Node* next;

    Node(const Book& book) : data(book), next(nullptr) {}
};

class BookStack {
private:
    Node* top;
public:
    BookStack() : top(nullptr) {}

    void push(const Book& book) {
        Node* newNode = new Node(book);
        newNode->next = top;
        top = newNode;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    Book pop() {
        if (isEmpty()) {
            cout << "Error: Stack is empty." << endl;
        }

        Node* temp = top;
        top = top->next;
        Book poppedBook = temp->data;
        delete temp;

        return poppedBook;
    }

    void sortBooksByLatestAdded() {
        BookStack tempStack;

        while (!isEmpty()) {
            tempStack.push(pop());
        }

        while (!tempStack.isEmpty()) {
            push(tempStack.pop());
        }
    }
};


class OnlineBookstore
{
public:
    static const int MAX_BOOKS = 100;
    Book book_list[MAX_BOOKS];
    int order_count = 0;
    static const int MAX_ORDERS= 100;
    Book recently_viewed_stack[MAX_BOOKS];
    int recently_viewed_count = 0;
    Book order_queue[MAX_ORDERS];
    int orderFront = 0;
    int orderRear = 0;
    BookStack bookStack;


    // Default constructor
    OnlineBookstore() {}

    void addBook()
    {
        string title, author, genre;
        double price;
        bool availability;
        getline(cin, title);

        cout << "Enter the title of the book: \n" ;
        getline(cin, title);
        cout << "Enter the author of the book: \n";
        getline(cin, author);
        cout << "Enter the genre of the book: \n";
        getline(cin, genre);
        cout << "Enter the price of the book: \n";
        cin >> price;
        cout << "Is the book available? (1 for Yes, 0 for No): ";
        cin >> availability;




        if (book_count < MAX_BOOKS)
        {
            Book newBook(title, author, genre, price, availability);
            book_list[book_count++] = newBook;
        }
        else
        {
            cout << "Maximum number of books reached. Cannot add more books." << endl;
        }
    }

    Book* searchBook(string title)
    {
        for (int i = 0; i < book_count; ++i)
        {
            if (book_list[i].title == title)
            {
                return &book_list[i];
            }
        }
        return nullptr;
    }

    Book* viewRecentlyViewed()
    {
        if (recently_viewed_count > 0)
        {
            return &recently_viewed_stack[recently_viewed_count - 1];
        }
        else
        {
            return nullptr;
        }
    }


    void addToOrderQueue()
    {   if(book_count == 0){
        cout << "no books ; add some books first  " << endl;
        }
        else {
        string bookTitle;
        getline(cin,bookTitle);
        cout << "Enter the title of the book to add to the order queue: ";
        getline(cin,bookTitle);

        Book* bookToAdd = searchBook(bookTitle);
        if (bookToAdd != nullptr)
        {
            if (order_count < MAX_BOOKS)
            {
                order_queue[order_count++] = *bookToAdd;
                cout << "Book added to the order queue." << endl;
            }
            else
            {
                cout << "Order queue is full. Cannot add more books." << endl;
            }
        }
        else
        {
            cout << "Book not found." << endl;
        }
        orderRear ++ ;
        }

    }

    void sortBooksByAuthor()
    { //insertion sort

    for (int i = 1; i < book_count; ++i) {
        Book key = book_list[i];
        int j = i - 1;

        while (j >= 0 && key.author < book_list[j].author) {
            book_list[j + 1] = book_list[j];
            j--;
        }
        book_list[j + 1] = key;
    }
}


    void sortBooksByTitle()
    {

    for (int i = 1; i < book_count; ++i) {
        Book key = book_list[i];
        int j = i - 1;

        while (j >= 0 && key.title < book_list[j].title) {
            book_list[j + 1] = book_list[j];
            j--;
        }
        book_list[j + 1] = key;
    }
    }

    void sortBooksByPrice()
    {
  for (int i = 1; i < book_count; ++i) {
        Book key = book_list[i];
        int j = i - 1;

        while (j >= 0 && key.price < book_list[j].price) {
            book_list[j + 1] = book_list[j];
            j--;
        }
        book_list[j + 1] = key;
    }    }

    void viewBooksByGenre()
    {    if(book_count == 0){
        cout << "no books ; add some books first  " << endl;
        }
        else {
        string genreChoice;
        getline(cin ,  genreChoice );
        cout << "Enter a genre to view books from that genre: ";
        getline(cin ,  genreChoice );
        for (int i = 0; i < book_count; ++i)
        {
            if (book_list[i].genre == genreChoice)
            {
                cout << book_list[i].title << " by " << book_list[i].author << " - $" << book_list[i].price << endl;
            }
        }
    }
    }

    void viewBookAvailability()
    {    if(book_count == 0){
        cout << "no books ; add some books first  " << endl;
        }
        else {
        string bookToView;
        getline(cin ,  bookToView);
        cout << "Enter the title of the book to view availability: ";
        getline(cin ,  bookToView);
        Book* book = searchBook(bookToView);
        if (book != nullptr)
        {
            cout << "Availability of " << book->title << ": " << (book->availability ? "Available" : "Not Available") << endl;
        }
        else
        {
            cout << "Book not found." << endl;
        }
    }
    }
    void display()
    {
        for (int i = 0; i < book_count; ++i)
        {
            cout << book_list[i].title << " by " << book_list[i].author << " - $"
                 << book_list[i].price << endl;
        }
    }
    void Booksunderx( )
    {    if(book_count == 0){
        cout << "no books ; add some books first  " << endl;
        }
        else {
        double maxPrice ;
        cout<< "max price?" << endl;
        cin >> maxPrice;

        for (int i = 0 ; i < book_count ; i ++)
        {
            if (book_list[i].price <= maxPrice)
            {
                cout << i+1 << ". " << book_list[i].title << " - " <<  book_list[i].author << endl;
            }
        }
    }
    }

        void processOrderQueue() {
        cout << "Processing orders from the queue:" << endl;

        while (orderFront != orderRear) {
            Book orderedBook = order_queue[orderFront];
            orderFront = (orderFront + 1) % MAX_ORDERS;

            cout << "Book Title: " << orderedBook.title << " by " << orderedBook.author << " - $" << orderedBook.price << endl;
        }

        cout << "All orders processed." << endl;
    }

    void checkout() {
        processOrderQueue();

        cout << "Thank you for your purchase. Your order details are:" << endl;
        cout << "==============================================" << endl;
        double sum = 0;
        for (int i = 0; i < order_count; ++i) {
            cout << i + 1 << ". " << order_queue[i].title << " by " << order_queue[i].author << " - $" << order_queue[i].price << endl;
            sum += order_queue[i].price;
        }
        cout << "==============================================" << endl;
        cout << "Total: $" << sum << endl;
        cout << "Have a great day!" << endl;

        orderFront = 0;
        orderRear = 0;
        order_count = 0;
    }

        void sortBooksByLatestAdded() {
        bookStack.sortBooksByLatestAdded();
    }

    void undoAddBook() {
    if (book_count > 0) {
        Book lastAdded = book_list[--book_count];
        cout << "Undoing addition of book: " << lastAdded.title << " by " << lastAdded.author << endl;
        bookStack.pop(); // Pop the latest book from the stack
    } else {
        cout << "No books to undo." << endl;
    }
}


};

int main()
{
    OnlineBookstore onlineBookstore;
    int choice ;
    do
    {   cout << "press 1 to add new book to the bookstore " << endl;
        cout << "press 2 to sort the books " << endl ;
        cout << "press 3 to view books by genre "<< endl;
        cout << "press 4 to check if the book is available " << endl;
        cout << "press 5 to view books under specified price " << endl;
        cout << "press 6 to add books to queue" << endl;
        cout << "press 7 to undo add books to queue" << endl;
        cout << "press 0 to checkout" << endl;

        cin >> choice ;
         if (choice != 0) {
        switch (choice)
        {

        case 1:
            onlineBookstore.addBook();
            break;
        case 2:
        {    if(book_count == 0){
                cout << "no books ; add some books first  " << endl;
                break;
            }
                else {
            int sortPreference;
            cout << "How would you like to sort the books? (1author, 2title, 3price): ";
            cin >> sortPreference;

            switch (sortPreference)
            {
            case 1 :
                onlineBookstore.sortBooksByAuthor();
                onlineBookstore.display();
                break;
            case 2 :
                onlineBookstore.sortBooksByTitle();
                onlineBookstore.display();
                break;
            case 3 :
                onlineBookstore.sortBooksByPrice();
                onlineBookstore.display();
                break;
            case 4 :
                onlineBookstore.sortBooksByLatestAdded();
                onlineBookstore.display();
                break;
            default :
                cout << "Invalid sorting preference. Books will remain unsorted." << endl;
                break;
            }
            break;
                }
        }
        case 3:
        {
            onlineBookstore.viewBooksByGenre();
            break;
        }
        case 4 :
        {
            onlineBookstore.viewBookAvailability();
            break;
        }
        case 5 :
        { onlineBookstore.Booksunderx();
            break;
        }
        case 6 :
        {
            onlineBookstore.addToOrderQueue();
            break;
        }
        case 7 : {
            onlineBookstore.undoAddBook();
            break;
        }


        default :
        {   if (choice != 0){
            cout <<"enter valid number " << endl;
            break;
            }
        }

        }
    } }
    while (choice!=0);

    onlineBookstore.checkout();




}
