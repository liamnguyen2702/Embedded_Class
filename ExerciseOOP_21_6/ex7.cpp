#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date{
    private: 
        int day;
        int month;
        int year;

    public:
        Date(int day, int month, int year) : day(day), month(month), year(year) {}

        int getAge(int thisyear) {return thisyear - year;}
    
        bool isHoliday(){
            vector < pair <int, int> > holidayList = {{1, 1}, {30, 4}, {1, 5}, {2, 9} };

            for (const auto& holiday : holidayList){
                if (holiday.first == day && holiday.second == month)
                    return true;
            }
            return false;
        }
};

int main()
{
    Date* hlDay = new Date(1, 9, 2000);

    int opt;
    cout << "Chon option: " << endl;
    cout << "1. Kiem tra ngay le\n2. Tinh tuoi\n";
    cin >> opt;
    
    if (opt == 1){
        if(hlDay -> isHoliday())
            cout << "Ngay nay la ngay le!";
        else 
            cout << "Ngay nay khong phai la ngay le!";
    }
    else
        cout << "Tuoi cua nguoi nay la: " << hlDay -> getAge(2023) << endl;
    
    return 0;
}