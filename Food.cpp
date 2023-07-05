#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Food
{
private:
    int id;
    string name;
    double price;

public:
    Food(int id, string name, double price)
    {
        this->id = id;
        this->name = name;
        this->price = price;
    }
    void setAll(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
    int getId()
    {
        return this->id;
    }
    string getName()
    {
        return this->name;
    }
    double getPrice()
    {
        return this->price;
    }
};

class Table {
    vector<Food> foods;
    char status;
    int no;
    public:
    Table(int no, char status){
        this->no = no;
        this->status = status;
    }
    int getNo() { return this->no;}
    char getStatus() { return this->status;}

    void addFood(int id) {
    }
};

class Employee
{
private:
    int noTable;
    std::vector<int> tables;
    std::vector<char> status;
    vector<Table> tablesMain;
    // Menu menu;

public:
    void setNoTableEmp(int no)
    {
        for (int i = 0; i <= no ; i++)
        {
            Table t(i+1, 'o');
            this->tablesMain.push_back(t);
        }
    }
    void displayFoodMenu()
    {

        // for (Food f : this->manager.getlfood()) {
        //     cout << f.getId() << " - " << f.getName() << " - " << f.getPrice() << endl;
        // }
    }
    void addFoodToTable(int idBan) {
        displayFoodMenu();
    }
    void menuEmployee()
    {
        printTable();
        int idBan;
        cout << "nhap so ban: ";
        cin >> idBan;
        do
        {
            cout << "Table " << idBan << ":" << endl;
            cout << "1. Add Food to table" << endl;
            cout << "2. Edit food" << endl;
            cout << "3. delete food" << endl;
            cout << "4. Display menu" << endl;
            cout << "5. Thanh Toan" << endl;
            cout << "6. Back" << endl;

            int input = 0;
            cin >> input;
            switch (input)
            {
            case 1:
                addFoodToTable(idBan);
                break;
            case 2:
                // editFoodFromMenu();
                break;
            case 3:
                // deleteFoodFromMenu();
                break;
            case 4:
                // displayFoodMenu();
                break;
            case 5:
                // setNoTable(e);
                break;
            default:
                goto OUT1;
            }
        } while (true);
    OUT1:;
    }
    void printTable()
    {
        int n = this->tablesMain.size();
        cout << n << endl;

        int columnWidth = 5;

        std::string horizontalLine((columnWidth + 1) * (n + 1) + 2, '-');

        std::cout << "+";
        std::cout << horizontalLine;
        std::cout << "+" << std::endl;

        for (int i = 0; i < 2; i++)
        {
            std::cout << "|";
            std::cout.width(columnWidth);
            std::cout << (i == 0 ? " Tables " : " Status ");

            for (int j = 0; j < n; j++)
            {
                std::cout << "|";
                if (i == 0)
                {
                    std::cout.width(columnWidth);
                    std::cout << this->tablesMain[j].getNo(); // this->tables[j];
                }
                else
                {
                    std::cout.width(columnWidth);
                    std::cout << this->tablesMain[j].getStatus(); //this->status[j];
                }
            }
            std::cout << "|" << std::endl;

            std::cout << "+";
            std::cout << horizontalLine;
            std::cout << "+" << std::endl;
        }
    }
};
int countid = 1;
class Menu {
    vector<Food>* lFood;
    public:
    Menu() {
        Food f1(countid++, "coca", 10);
        Food f2(countid++, "pepsi", 20);
        Food f3(countid++, "com tam", 50);
        lFood->push_back(f1);
        lFood->push_back(f2);
        lFood->push_back(f3);
    }
    vector<Food>* getLFood() { return this->lFood; }
};



class Manager
{
private:
    // vector<Food> lFood;
    Menu* menu;

public:
    // vector<Food> getlfood() { return this->lFood;}
    Manager(Menu* menu)
    {
        this->menu = menu;
        // lFood = menu.getLFood();
        // Food f1(countid++, "coca", 10);
        // Food f2(countid++, "pepsi", 20);
        // Food f3(countid++, "com tam", 50);
        // lFood.push_back(f1);
        // lFood.push_back(f2);
        // lFood.push_back(f3);
    }
    void displayFoodMenu()
    {
        for (Food f : *(menu->getLFood()))
        {
            cout << f.getId() << " - " << f.getName() << " - " << f.getPrice() << endl;
        }
    }
    void displayLastFoodFromMenu()
    {
        Food f = (*(menu->getLFood()))[countid - 2];
        cout << f.getId() << " - " << f.getName() << " - " << f.getPrice() << endl;
    }
    void displayFoodAtIdxFromMenu(int idx)
    {
        Food f = (*(menu->getLFood()))[idx];
        cout << f.getId() << " - " << f.getName() << " - " << f.getPrice() << endl;
    }

    void addFoodToMenu()
    {
        cout << "nhap ten mon: ";
        string name;
        cin >> name;
        cout << "nhap gia mon: ";
        double price;
        cin >> price;
        Food f(countid++, name, price);
        (this->menu->getLFood())->push_back(f);
        displayLastFoodFromMenu();
    }
    int searchIdInList(int id)
    {
        for (int i = 0; i < menu->getLFood()->size(); i++)
        {
            if (id == (*(this->menu->getLFood()))[i].getId())
            {
                return i;
            }
        }
        return -1;
    }
    void editFoodFromMenu()
    {
        displayFoodMenu();
        int id = 0;
        cout << "nhap id: ";
        cin >> id;
        int idx = searchIdInList(id);
        if (idx == -1)
        {
            cout << "id khong ton tai\n";
            return;
        }
        string name;
        double price;
        cout << "nhap ten mon an moi: ";
        cin >> name;
        cout << "nhap gia mon an moi: ";
        cin >> price;

        // (*(this->menu->getLFood())[idx]).setAll(name, price);
        // cout << "da sua thanh: ";
        // displayFoodAtIdxFromMenu(idx);
    }
    void deleteFoodFromMenu()
    {
        displayFoodMenu();
        int id = 0;
        cout << "nhap id mon an muon xoa: ";
        cin >> id;
        int idx = searchIdInList(id);
        if (idx == -1)
        {
            cout << "id khong ton tai\n";
            return;
        }
        // vector<Food>::iterator it = this->menu->getLFood().begin();
        // for (int i = 0; i < idx; i++, it++)
        //     ;
        // this->menu->getLFood().erase(it);
        // // remove(lFood.begin(),lFood.end(),lFood[idx]);
        // displayFoodMenu();
    }
    void setNoTable()
    {
        // cout << "nhap tong so ban: ";
        // int no;
        // cin >> no;
        // e->setNoTableEmp(no);
    }
    void menuManager()
    {
        do
        {
            cout << "Manager Menu: " << endl;
            cout << "1. Add Food to Menu" << endl;
            cout << "2. Edit food" << endl;
            cout << "3. delete food" << endl;
            cout << "4. Display menu" << endl;
            cout << "5. Edit no Table" << endl;
            cout << "6. Back" << endl;

            int input = 0;
            cin >> input;
            switch (input)
            {
            case 1:
                addFoodToMenu();
                continue;
            case 2:
                editFoodFromMenu();
                continue;
            case 3:
                deleteFoodFromMenu();
                continue;
            case 4:
                displayFoodMenu();
                continue;
            case 5:
                setNoTable();
                continue;
            default:
                break;
            }
            break;
        } while (true);
    }
};

int main()
{
    Menu* menu = new Menu();
    Manager* manager = new Manager(menu);
    Employee* employee = new Employee();
    do
    {
        int input = 0;
        cout << "1 - manager\n2 - employee\n";
        cin >> input;
        switch (input)
        {
        case 1:
            manager->menuManager();
            continue;
        default: 
            employee->menuEmployee();
            continue;
        }

    } while (true);

}
