#ifndef SINH_VIEN_H
#define SINH_VIEN_H

#include "DoiTuong.h"

class SinhVien : public DoiTuong {
public:
    void setThongTin(std::string ten, int tuoi, int mssv);
    void hienThi();
private:
    int MSSV;
};

#endif  // SINH_VIEN_H
