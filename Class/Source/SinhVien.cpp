#include "../Header/SinhVien.h"

void SinhVien::hienThi() {
    std::cout << "Day la class SinhVien" << std::endl;
    std::cout << "Ten: " << TEN << std::endl;
    std::cout << "Tuoi: " << TUOI << std::endl;
    std::cout << "MSSV: " << MSSV << std::endl;
}

void SinhVien::setThongTin(std::string ten, int tuoi, int mssv) {
    TEN = ten;
    TUOI = tuoi;
    MSSV = mssv;
}
