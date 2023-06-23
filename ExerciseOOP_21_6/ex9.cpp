#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Vehicle{
    private: 
        string color;
        string type;
        float counter;
        float fee;
    public:
        Vehicle(string color, string type, float km) : color(color), type(type), counter(km) {}

        float Counter(){return counter;}

        float Fee(float km){return fee = 1000000 + (km - 15000) * 10;}

        void getInfor(){
            cout << "     Loai xe:         " << type << endl;
            cout << "     Mau sac:         " << color << endl;
            cout << "     So km da di:     " << counter << endl;
            cout << "     Chi phi bao tri: " << fixed << setprecision(0) << Fee(counter) << " VND" << endl;
        }
};

int main()
{
    Vehicle* car = new Vehicle("Xanh Navi", "Audi A6", 236547);
    int op;
    cout << "Chon yeu cau: " << endl;
    cout << "1. Thong tin xe\n2. So km da di\n3. Phi bao tri\n";
    cin >> op;
    if (op == 1){
        cout << "Thong tin xe: " << endl;
        car -> getInfor();
    }
    else if(op == 2){
        cout << "So km da di la: ";
        cout << car -> Counter();
    }
    else 
        cout << "Phi bao tri la: "  << fixed << setprecision(0) << car -> Fee(car -> Counter()) << " VND" << endl;

    return 0;
}