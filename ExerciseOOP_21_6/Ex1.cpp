#include <iostream>
#include <cmath>

using namespace std;

class Point{
    private: 
        float x;
        float y;

    public:
        Point() : x(0.0), y(0.0) {}
        
        Point(float xValue, float yValue) : x(xValue), y(yValue) {}

        void getPoints(){
            cout << "Enter x value: ";
            cin >> x;
            cout << "Enter y value: ";
            cin >> y;
        }

        float evaluate(Point p){
            float delX = p.x - x;
            float delY = p.y - y;
            return sqrt(pow(delX, 2) + pow(delY, 2));
        }

        float evaluate(Point p2, Point p3){
            float c1 = evaluate(p2);
            float c2 = p2.evaluate(p3);
            float c3 = evaluate(p3);
            float n = (c1 + c2 + c3) / 2;
            return sqrt(n * (n - c1) * (n - c2) * (n - c3));
        }

        ~Point() {}
};

int main()
{
    Point* p1 = new Point;
    Point* p2 = new Point;
    Point* p3 = new Point;

    int t;

    cout << "Chon yeu cau: " << endl;
    cout << "1. Tinh khoang cach" << endl << "2. Tinh dien tich" << endl;
    cin >> t;

    if (t == 1){
        cout << "Nhap toa do diem thu nhat: " << endl;
        p1 -> getPoints();

        cout << "Nhap toa do diem thu hai: " << endl;
        p2 -> getPoints();

        float distance = p1 -> evaluate(*p2);

        cout << "Khoang cach giua 2 diem: " << distance << endl;
    }
    else {
        
        cout << "Nhap toa do diem thu nhat: " << endl;
        p1 -> getPoints();

        cout << "Nhap toa do diem thu hai: " << endl;
        p2 -> getPoints();
        
        cout << "Nhap toa do diem thu ba: " << endl;
        p3 -> getPoints();

        float area = p1 -> evaluate(*p2, *p3);

        cout << "Dien tich tam giac: " << area << endl;
    }

    return 0;
}
