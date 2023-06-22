#include <iostream>
#include <string>
using namespace std;

class People{
    private: 
        string name;
        int age;
        string address;
        int year;
    public: 
        People (string name, string address, int year) 
        : name(name), address(address), year(year) {}

        int howOld(int thisyear) {
            age = thisyear - year;
        }

        void getInfor(){
            cout << "Ten: " << name << endl;
            cout << "Nam sinh: " << year << endl;
            cout << "Tuoi: " << age << endl;
            cout << "Dia chi: " << address << endl;
        }
};

int main()
{
    People* man = new People ("Lukaku", "89 Cong Hoa Street", 1993);
    man -> howOld(2023);
    man -> getInfor();

    return 0;
}
