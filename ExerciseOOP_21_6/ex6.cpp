#include <iostream>

using namespace std;

class Fraction{
    private: 
        int nume; // numerator
        int deno; // denominator

    public:

        Fraction(int tu, int mau) : nume(tu), deno(mau) {}

        Fraction plus(Fraction ft){
            int tu = nume * ft.deno + deno * ft.nume;
            int mau = deno * ft.deno;
            return Fraction(tu, mau);
        }
        
        Fraction exception(Fraction ft){
            int tu = nume * ft.deno - deno * ft.nume;
            int mau = deno * ft.deno;
            return Fraction(tu, mau);
        }

        Fraction multiplication(Fraction ft){
            int tu = nume * ft.nume;
            int mau = deno * ft.deno;
            return Fraction(tu, mau);
        }

        Fraction split(Fraction ft){
            int tu = nume * ft.deno;
            int mau = deno * ft.nume;
            return Fraction(tu, mau);
        }

        int getnume(){
            return nume;
        }

        int getdeno(){
            return deno;
        }

        int findGCD(int a, int b) {
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }


        void simplify() {
            int gcd = findGCD(nume, deno);
            nume /= gcd;
            deno /= gcd;
        }
};



int main()
{
    Fraction ft1(1, 2);
    Fraction ft2(3, 4);

    Fraction sum = ft1.plus(ft2);
    Fraction difference = ft1.exception(ft2);
    Fraction product = ft1.multiplication(ft2);
    Fraction quotient = ft1.split(ft2);

    sum.simplify();         difference.simplify();
    product.simplify();     quotient.simplify(); 

    cout << "Tong:   " << sum.getnume() << "/" << sum.getdeno() << endl;
    cout << "Hieu:   " << difference.getnume() << "/" << difference.getdeno() << endl;
    cout << "Tich:   " << product.getnume() << "/" << product.getdeno() << endl;
    cout << "Thuong: " << quotient.getnume() << "/" << quotient.getdeno();

    return 0;
}