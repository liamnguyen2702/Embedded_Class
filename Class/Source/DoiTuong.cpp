#include "../Header/DoiTuong.h"

void DoiTuong::hienThi() {
    std::cout << "Day la class DoiTuong" << std::endl;
    std::cout << "Ten: " << TEN << std::endl;
    std::cout << "Tuoi: " << TUOI << std::endl;
}

void DoiTuong::setThongTin(std::string ten, int tuoi) {
    TEN = ten;
    TUOI = tuoi;
}
