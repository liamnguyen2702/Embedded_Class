#include <iostream>
#include <list>
#include <string>

using namespace std;

class Manager
{
protected:
    int id;
    string tenMon;
    int soBan;
    int price;

public:
    list<Manager> listFood;

    Manager(int id, string tenMon, int price);

    Manager();

    void setTen(string tenMon);

    void setGia(int price);

    string getTenMon() const;

    int getGiaMon() const;

    void themMon();

    void suaTenMon(int ID);

    void suaGiaMon(int ID);

    void xoaMon();

    void displayMon();

    void thietlapSoBan(int soBan);

    int getSoBan();

    int getID() const;

    void setID(Manager a);
};

string Manager::getTenMon() const
{
    return tenMon;
}

int Manager::getGiaMon() const
{
    return price;
}

void Manager::setID(Manager a)
{
    static int id = 100;
    Manager::id = id;
    id++;
}

int Manager::getID() const
{
    return id;
}

Manager::Manager(int id, string tenMon, int price)
{
    Manager::id = id;
    Manager::tenMon = tenMon;
    Manager::price = price;
}

void Manager::themMon()
{
    string tenMon;
    cout << "Nhap ten mon can them: " << endl;
    cin >> tenMon;
    int price;
    cout << "Nhap gia: " << endl;
    cin >> price;

    Manager newFood{id, tenMon, price};
    newFood.setID(newFood);
    listFood.push_back(newFood);
}

void Manager::xoaMon()
{
    string tenMon;
    cout << "Nhap vao ten mon can xoa: " << endl;
    cin >> tenMon;
    for (auto it = listFood.begin(); it != listFood.end();)
    {
        if (it->tenMon == tenMon)
        {
            it = listFood.erase(it);
        }
        else
        {
            cout << "Khong co ten mon de xoa: " << endl;
            ++it;
        }
    }
}

void Manager::thietlapSoBan(int soBan)
{
    Manager::soBan = soBan;
}

int Manager::getSoBan()
{
    return soBan;
}

void Manager::displayMon()
{
    for (auto item : listFood)
    {
        cout << "ID: " << item.id << endl;
        cout << "Ten mon: " << item.tenMon << endl;
        cout << "Gia: " << item.price << endl;
    }
}

void Manager::setTen(string tenMon)
{
    Manager::tenMon = tenMon;
}

void Manager::setGia(int price)
{
    Manager::price = price;
}

void Manager::suaTenMon(int ID)
{
    for (auto it = listFood.begin(); it != listFood.end(); ++it)
    {
        if (it->id == ID)
        {
            it->displayMon();
            string name;
            cout << "Nhap ten can sua: " << endl;
            cin >> name;
            it->setTen(name);
            cout << "Sua thanh cong!" << endl;
            return;
        }
    }
    cout << "ID khong ton tai " << endl;
}

void Manager::suaGiaMon(int ID)
{
    for (auto it = listFood.begin(); it != listFood.end(); ++it)
    {
        if (it->id == ID)
        {
            it->displayMon();
            int price;
            cout << "Nhap gia can sua: " << endl;
            cin >> price;
            it->setGia(price);
            cout << "Sua gia thanh cong!" << endl;
            return;
        }
    }
    cout << "ID khong ton tai!" << endl;
}

class ThongTinBan : public Manager
{
protected:
    int id;
    int soluong;
    int soBan;
    bool trangThai;

public:
    list<ThongTinBan> orderList;

    ThongTinBan(int id, int soluong, int soBan, bool trangThai);
    ThongTinBan();
    int getIDMonTaiBan() const;
    int getSoLuong();
    bool getTrangThai(int soBan);
    void themMonTaiBan(int soBan);
    void suaMonTaiBan(int soBan);
    void xoaMonTaiBan(int soBan);
    void thanhToan(int soBan);
    void hienThiDanhSachMonTaiBan(int soBan);
    void setID(int ID);
    void setSoLuong(int soLuong);
    void setTrangThai(int soBan);
    int getSoBanDangGoiMon();
    void xoaMonSaiID(int id);
};

ThongTinBan::ThongTinBan()
{
}

ThongTinBan::ThongTinBan(int id, int soLuong, int soBan, bool trangThai)
{
    ThongTinBan::id = id;
    ThongTinBan::soluong = soLuong;
    ThongTinBan::soBan = soBan;
    ThongTinBan::trangThai = trangThai;
}

int ThongTinBan::getSoBanDangGoiMon()
{
    return ThongTinBan::soBan;
}

int ThongTinBan::getIDMonTaiBan() const
{
    return ThongTinBan::id;
}

int ThongTinBan::getSoLuong()
{
    return ThongTinBan::soluong;
}

void ThongTinBan::setTrangThai(int soBan)
{
    ThongTinBan::trangThai = true;
}

bool ThongTinBan::getTrangThai(int soBan)
{
    for (auto item : orderList)
    {
        if (item.getSoBanDangGoiMon() == soBan)
        {
            return item.trangThai;
        }
    }
    return false;
}

void ThongTinBan::setSoLuong(int soLuong)
{
    ThongTinBan::soluong = soLuong;
}

void ThongTinBan::setID(int ID)
{
    ThongTinBan::id = ID;
}

void ThongTinBan::themMonTaiBan(int soBan)
{
    int id;
    cout << "Nhap id mon: " << endl;
    cin >> id;
    int soLuong;
    cout << "Nhap so luong mon: " << endl;
    cin >> soLuong;
    bool trangThai2 = true;
    ThongTinBan newMonTaiBan{id, soLuong, soBan, trangThai2};
    orderList.push_back(newMonTaiBan);
}

void ThongTinBan::xoaMonSaiID(int id)
{
    for (auto it = orderList.begin(); it != orderList.end();)
    {
        if (it->id == id)
        {
            it = orderList.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
void ThongTinBan::suaMonTaiBan(int soBan)
{
    int id;
    int soLuong;
    cout << "Nhap id can sua: " << endl;
    cin >> id;
    cout << "Nhap so luong: " << endl;
    cin >> soLuong;
    for (auto &item : orderList)
    {
        if (item.soBan == soBan)
        {
            item.setID(id);
            item.setSoLuong(soLuong);
        }
    }
}

void ThongTinBan::xoaMonTaiBan(int soBan)
{
    int id;
    cout << "Nhap vao id mon can xoa: " << endl;
    cin >> id;
    for (auto it = orderList.begin(); it != orderList.end();)
    {
        if (it->getSoBanDangGoiMon() == soBan)
        {
            if (it->id == id)
            {
                it = orderList.erase(it);
                cout << "Da xoa thanh cong!" << endl;
                return;
            }
            else
            {
                cout << "Khong co Id da nhap tai ban!" << endl;
                ++it;
            }
        }
        else
        {
            cout << "Khong co so ban nhu tren!" << endl;
            ++it;
        }
    }
}

void ThongTinBan::hienThiDanhSachMonTaiBan(int soBan)
{
    for (auto &item : orderList)
    {
        if (item.soBan == soBan)
        {
            cout << "Id mon: " << item.getIDMonTaiBan() << endl;
            cout << "so luong: " << item.getSoLuong() << endl;
        }
    }
}

void ThongTinBan::thanhToan(int soBan)
{
    int tongTien = 0;
    for (auto &item : orderList)
    {
        if (item.soBan == soBan)
        {
            for (auto &food : listFood)
            {
                if (food.getID() == item.getIDMonTaiBan())
                {
                    tongTien += item.getSoLuong() * food.getGiaMon();
                }
            }
        }
    }
    cout << "Tong so tien ban " << soBan << " la: " << tongTien << " $" << endl;
}

int main(int argc, char const *argv[])
{
    int choice;
    Manager ql1;
    ThongTinBan order1;
    while (1)
    {
    L:
        cout << "1. Quan ly" << endl;
        cout << "2. Nhan vien" << endl;
        cout << "Nhap vao: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        B:
            int input2;
            cout << "1. Them mon" << endl;
            cout << "2. Sua mon" << endl;
            cout << "3. Xoa mon" << endl;
            cout << "4. Danh sach mon" << endl;
            cout << "5. Thiet lap so ban" << endl;
            cout << "0. Quay lai" << endl;
            cout << "Ban chon: " << endl;
            cin >> input2;
            switch (input2)
            {
            case 1:
            L:
                ql1.themMon();
                int inputTieptuc;
                cout << "1. Tiep tuc them mon" << endl;
                cout << "0. Quay lai" << endl;
                cout << "Ban chon: " << endl;
                cin >> inputTieptuc;
                switch (inputTieptuc)
                {
                case 1:
                    goto L;
                    break;
                case 2:
                    goto B;
                    break;
                default:
                    break;
                }
                break;
            case 2:
                int idInput;
                int selectionInput;
                cout << "Nhap vao id mon can sua" << endl;
                cin >> idInput;
                cout << "1. Sua ten" << endl;
                cout << "2. Sua gia" << endl;
                cout << "0. Quay lai" << endl;
                cout << "Ban chon: " << endl;
                cin >> selectionInput;
                switch (selectionInput)
                {
                case 1:
                    ql1.suaTenMon(idInput);
                    break;
                case 2:
                    ql1.suaGiaMon(idInput);
                    break;
                case 0:
                    goto L;
                    break;
                default:
                    break;
                }
                break;
            case 3:
                ql1.xoaMon();
                break;
            case 4:
                ql1.displayMon();
                break;
            case 5:
                int soBanInput;
                cout << "Nhap vao so ban:  " << endl;
                cin >> soBanInput;
                ql1.thietlapSoBan(soBanInput);
                break;
            case 0:
                goto L;
            default:
                break;
            }
            break;
        case 2:
            if (ql1.getSoBan() == 0)
            {
                cout << "Vui long thiet lap so ban truoc khi goi mon!" << endl;
                goto L;
            }
            else if (ql1.listFood.size() == 0)
            {
                cout << "Vui long bo sung danh sach mon an truoc khi goi mon!" << endl;
                goto L;
            }
            int soBan;
            cout << "------------------Thong tin------------------" << endl;
            cout << "So ban duoc thiet lap: " << ql1.getSoBan() << endl;
            for (int i = 0; i < ql1.getSoBan(); i++)
            {
                cout << "Ban " << i + 1 << " - Trang thai: " << order1.getTrangThai(i + 1) << endl;
            }
            cout << "Nhap vao so ban: " << endl;
            cout << "0. Quay lai" << endl;
            cout << "Nhap vao so ban: " << endl;
            cin >> soBan;
            switch (soBan)
            {
            case 1:
            K:
                int inputTaiBan;
                cout << "1. Them mon tai ban" << endl;
                cout << "2. Sua mon tai ban" << endl;
                cout << "3. Xoa mon tai ban" << endl;
                cout << "4. Danh sach mon tai ban" << endl;
                cout << "5. Thanh toan" << endl;
                cout << "0. Quay lai" << endl;
                cout << "Ban chon: " << endl;
                cin >> inputTaiBan;
                switch (inputTaiBan)
                {
                case 1:
                A:
                    ql1.displayMon();
                    order1.themMonTaiBan(soBan);
                    for (auto it = order1.orderList.begin(); it != order1.orderList.end();)
                    {
                        bool found = false;
                        for (auto &food : ql1.listFood)
                        {
                            if (food.getID() == it->getIDMonTaiBan())
                            {
                                found = true;
                                break;
                            }
                        }
                        if (!found)
                        {
                            cout << "Id nhap vao khong ton tai. Nhap lai: " << endl;
                            order1.xoaMonSaiID(it->getIDMonTaiBan());
                            cout << "Da xoa id mon: " << endl;
                            goto A;
                        }
                        ++it;
                    }
                B:
                    int inputTaiBan;
                    cout << "1.Tiep tuc" << endl;
                    cout << "0.Quay lai" << endl;
                    cout << "Enter: " << endl;
                    cin >> inputTaiBan;
                    switch (inputTaiBan)
                    {
                    case 1:
                        goto A;
                        break;
                    case 0:
                        goto K;
                        break;
                    default:
                        break;
                    }
                    break;
                case 2:
                    order1.hienThiDanhSachMonTaiBan(soBan);
                    order1.suaMonTaiBan(soBan);
                    break;
                case 3:
                    order1.hienThiDanhSachMonTaiBan(soBan);
                    order1.xoaMonTaiBan(soBan);
                    break;
                case 4:
                    order1.hienThiDanhSachMonTaiBan(soBan);
                    for (const auto &order : order1.orderList)
                    {
                        for (const auto &item : ql1.listFood)
                        {
                            if (item.getID() == order.getIDMonTaiBan())
                            {
                                cout << "Ten mon: " << item.getTenMon() << endl;
                                cout << "Gia tien: " << item.getGiaMon() << endl;
                                continue;
                            }
                        }
                    }
                    break;
                case 5:
                    order1.thanhToan(soBan);
                    break;
                case 0:
                    goto K;
                    break;
                default:
                    break;
                }
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                goto L;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    return 0;
}
