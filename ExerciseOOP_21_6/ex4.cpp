#include <iostream>
#include <string>

using namespace std;

class Animal{
    private:
        string name;
        int age;
        float weight;
        float height;
    public:
    
        Animal(string name, int age, float weight, float height)
        : name(name), age(age), weight(weight), height(height) {}

        float evaluateBMI(){return weight / (height * height);}

        bool compareAge(Animal a){return age > a.age;}

        bool compareWeight(Animal a){return weight > a.weight;}

        string getInfor(){
            return name;
        }
};

int main()
{
    Animal* dog = new Animal("Gaugau", 6, 15, 0.5);
    Animal* cat = new Animal("Meomeo", 3, 6, 0.3);

    cout << "Chi so BMI cua " << dog -> getInfor() << ": " << dog -> evaluateBMI() << endl;
    cout << "Chi so BMI cua " << cat -> getInfor() << ": " << cat -> evaluateBMI() << endl;

    cout << "So sanh tuoi: " << (dog -> compareAge(*cat) 
    ? dog -> getInfor() + " lon hon " + cat -> getInfor() 
    : cat -> getInfor() + " lon hon " + dog -> getInfor()) << endl;
    
    cout << "So sanh trong luong: " << (dog -> compareWeight(*cat) 
    ? dog -> getInfor() + " nang hon " + cat -> getInfor()
    : cat -> getInfor() + " nang hon " + dog -> getInfor()) << endl;

    return 0;
}