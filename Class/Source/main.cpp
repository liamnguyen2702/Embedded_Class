#include <iostream>
#include <string>

#include "../Header/DoiTuong.h"
#include "../Header/SinhVien.h"

int main() {
    DoiTuong dt;

    dt.setThongTin("Hoang", 17);
    dt.hienThi();

    SinhVien sv;

    sv.setThongTin("Toan", 15, 1001);
    sv.hienThi();

    return 0;
}
