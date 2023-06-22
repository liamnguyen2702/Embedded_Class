#include <iostream>
#include <cmath>

using namespace std;

class HinhChuNhat {
    private:
        float chieuDai;
        float chieuRong;

    public:
        HinhChuNhat(float dai, float rong) : chieuDai(dai), chieuRong(rong) {}

        float tinhChuVi() { return 2 * (chieuDai + chieuRong); }
        float tinhDienTich() { return chieuDai * chieuRong; }
        float tinhDuongCheo() { return sqrt(chieuDai * chieuDai + chieuRong * chieuRong); }
        bool laHinhVuong() { return chieuDai == chieuRong; }
};

int main() {

    float dai, rong;
    cout << "Nhap chieu dai: ";
    cin >> dai;
    if (dai <= 0) {
        cout << "Khong hop le" << endl;
        return 0;
    }
    cout << "Nhap chieu rong: ";
    cin >> rong;
      if (rong <= 0) {
        cout << "Khong hop le" << endl;
        return 0;
    }

    HinhChuNhat* hcn = new HinhChuNhat(dai, rong);

    cout << "Chu vi: " << hcn -> tinhChuVi() << endl;
    cout << "Dien tich: " << hcn -> tinhDienTich() << endl;
    cout << "Duong cheo: " << hcn -> tinhDuongCheo() << endl;
    cout << (hcn -> laHinhVuong() ? "La hinh vuong!" : "La hinh chu nhat!") << endl;

    delete hcn;
    return 0;
}
