#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Circle{
    private: 

        float r;
        const float pi = 3.14159265359;

    public: 

        Circle (float radius) : r(radius) {}

        float evaluatePerimeter() {return (2 * pi * r);}

        float evaluateArea() {return (pow(r, 2) * pi);}

        ~Circle() {}
};

int main()
{
    float radius;
    
    cout << "Nhap ban kinh: " << endl;
    cin >> radius;

    Circle* hinhtron = new Circle(radius);

    cout << "Dien tich = " << fixed << setprecision(5) << hinhtron -> evaluatePerimeter() << endl;
    cout << "Chu vi = " << fixed << setprecision(5) << hinhtron -> evaluateArea() << endl;

    return 0;
}
