#ifndef DOI_TUONG_H
#define DOI_TUONG_H

#include <iostream>
#include <string>

class DoiTuong {
public:
    void setThongTin(std::string ten, int tuoi);
    void hienThi();
protected:
    int TUOI;
    std::string TEN;
};

#endif  // DOI_TUONG_H
