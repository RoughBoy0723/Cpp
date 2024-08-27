#include <iostream>
#include <cstring>

using namespace std;

class Book
{
private:
    char * title;
    char * isbn;
    int price;

public:
    Book(char* _title, char* _isbn, int _price):price(_price){
        title = new char[strlen(_title)+1];
        strcpy(title, _title);
        isbn = new char[strlen(_isbn)+1];
        strcpy(isbn, _isbn);
    };

    void ShowBookInfo(){
        cout << "제목: " << title <<endl;
        cout << "ISBN: " << isbn <<endl;
        cout << "가격: " << price <<endl;
    };

    ~Book(){
        delete []title;
        delete []isbn;
    };
};

class EBook : public Book
{
private:
    char * DRMKey;
public:
    EBook(char* _title, char* _isbn, int _price, char* _DRMKey):Book(_title, _isbn, _price){
        DRMKey = new char[strlen(_DRMKey)+1];
        strcpy(DRMKey, _DRMKey);
    };
    void ShowEBookInfo(){
        ShowBookInfo();
        cout << "DRMKey: " << DRMKey <<endl;
    };
    ~EBook(){
        delete []DRMKey;
    };
};

int main(void){
    Book book("좋은 C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout<<endl;
    EBook ebook("좋은 c++", "555-12345-890-1",10000,"fdx9w0i8kiw");
    ebook.ShowEBookInfo();

    return 0;
}
