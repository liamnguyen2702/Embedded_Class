#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void saveAmountToFile(double amount);
double loadAmountFromFile();

class BankAccount{
    private: 
        int id;
        string name;
        double surplus; 
    public:
        BankAccount (int idnumber, string name, double surplus)
        : id(idnumber), name(name), surplus(surplus) {}

        double recharge(double amount){return surplus += amount;}

        double withdraw(double amount){return surplus -= amount;}

        double checkbalance(){return surplus;}

        ~BankAccount() {}
};

int main()
{
    double amount;
    amount = loadAmountFromFile();
    BankAccount* user = new BankAccount(19120147, "Lukaku", amount);
    
    int service;
    cout << "Chon dich vu: " << endl;
    cout << "1. Nap tien.\n2. Rut tien.\n3. Kiem tra so du." << endl;
    cin >> service;

    if (service == 1){
        cout << "Nhap so tien: ";
        cin >> amount;
        user -> recharge(amount);
        saveAmountToFile(user -> checkbalance());
        cout << "Da nap " << fixed << setprecision(0) << amount << " VND vao tai khoan" << endl;
    }
    else if (service == 2){
        cout << "Nhap so tien rut: ";
        cin >> amount;
        if (amount > user -> checkbalance())
            cout << "Khong du dau ma rut!";
        else {
            user -> withdraw(amount);
            saveAmountToFile(user -> checkbalance());
            cout << "Da rut " << fixed << setprecision(0) << amount << " VND tu tai khoan" << endl;
        }
    }
    else
        cout << "So du la: " << fixed << setprecision(0) << user -> checkbalance() << " VND";

    return 0;
}

    void saveAmountToFile(double amount) {
        ofstream file("amount.txt");
        if (file.is_open()) {
            file << fixed << setprecision(2) << amount;
            file.close();
        }
        else {
            cout << "Khong the mo file." << endl;
        }
    }

    double loadAmountFromFile() {
        double amount = 0;
        ifstream file("amount.txt");
        if (file.is_open()) {
            file >> amount;
            file.close();
        }
        return amount;
    }
