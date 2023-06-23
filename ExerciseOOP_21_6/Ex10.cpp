#include <iostream>
#include <string>

using namespace std;

class Book{
    private: 
        string name;
        string author;
        int year;
        int quantity;

    public:
        
        Book (string name, string author, int publicyear, int quantity) : name(name), author(author), year(publicyear), quantity(quantity) {}

        void getInfor(){
            cout << "Ten sach: " << name << endl;
            cout << "Tac gia: " << author << endl;
            cout << "Nam xuat ban: " << year << endl;
            cout << "So luong: " << quantity << endl;
        }

        void borrow(){
            if (quantity > 0){
                quantity --;
                cout << "Da muon sach " << name << "." << endl;
            }
            else 
                cout << "Da het sach " << name << " trong thu vien." << endl;
        }

        void giveBack(){
            quantity ++;
            cout << "Da tra sach " << name << "." << endl;
        }

        int getQuantity(){return quantity;}
};

int main()
{
    Book* sach = new Book("Forrest Gump", "Winston Groom", 1994, 20);

    int op;
    cout << "Chon dich vu: " << endl;
    cout << "1. In thong tin sach.\n2. Muon sach.\n3. Tra sach." << endl;
    cin >> op;

    if (op == 1)
        sach -> getInfor();
    else if (op == 2){
        sach -> borrow();
        cout << "So luong con lai: " << sach -> getQuantity() << " cuon." << endl;
    }
    else   {
        sach -> giveBack();
        cout << "So luong con lai: " << sach -> getQuantity() << " cuon." << endl;
    }
    return 0;
}
