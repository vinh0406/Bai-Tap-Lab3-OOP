#include "PhanSo.h"
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

// Hàm khởi tạo mặc định
// Input: Không có tham số
// Output: Khởi tạo phân số với tử = 0, mẫu = 1
PhanSo::PhanSo() : iTu(0), iMau(1) {}

// Hàm khởi tạo có tham số
// Input: Tử số và mẫu số của phân số
// Output: Khởi tạo phân số và rút gọn nếu cần
PhanSo::PhanSo(int Tu, int Mau) : iTu(Tu), iMau(Mau) {
    RutGon();
}

// Hàm rút gọn phân số
// Input: Không có tham số
// Output: Rút gọn tử và mẫu của phân số
// Giải thuật: Sử dụng ước chung lớn nhất (GCD) để rút gọn phân số
void PhanSo::RutGon() {
    int a = iTu;
    int b = iMau;
    while (b != 0) {     // Tìm GCD của tử và mẫu, Sử dụng thuật toán Euclid để tính GCD.
        int temp = b;
        b = a % b;
        a = temp;
    } 

    iTu /= a; // Chia tử cho GCD
    iMau /= a; // Chia mẫu cho GCD
    if (iMau < 0) { // Đảm bảo mẫu số dương
        iTu = -iTu;
        iMau = -iMau;
    }
}

// Toán tử cộng
// Input: Phân số ps để cộng với phân số hiện tại
// Output: Trả về phân số tổng
PhanSo PhanSo::operator+(const PhanSo& ps) const {
    int tu = iTu * ps.iMau + ps.iTu * iMau;
    int mau = iMau * ps.iMau;
    return PhanSo(tu, mau);
}

// Toán tử trừ
// Input: Phân số ps để trừ với phân số hiện tại
// Output: Trả về phân số hiệu
PhanSo PhanSo::operator-(const PhanSo& ps) const {
    int tu = iTu * ps.iMau - ps.iTu * iMau;
    int mau = iMau * ps.iMau;
    return PhanSo(tu, mau);
}

// Toán tử nhân
// Input: Phân số ps để nhân với phân số hiện tại
// Output: Trả về phân số tích
PhanSo PhanSo::operator*(const PhanSo& ps) const {
    int tu = iTu * ps.iTu;
    int mau = iMau * ps.iMau;
    return PhanSo(tu, mau);
}

// Toán tử chia
// Input: Phân số ps để chia với phân số hiện tại
// Output: Trả về phân số thương
PhanSo PhanSo::operator/(const PhanSo& ps) const {
    int tu = iTu * ps.iMau;
    int mau = iMau * ps.iTu;
    return PhanSo(tu, mau);
}

// Toán tử so sánh bằng
// Input: Phân số ps để so sánh
// Output: Trả về true nếu hai phân số bằng nhau, ngược lại false
bool PhanSo::operator==(const PhanSo& ps) const {
    return iTu * ps.iMau == ps.iTu * iMau;
}

// Toán tử so sánh khác
// Input: Phân số ps để so sánh
// Output: Trả về true nếu hai phân số khác nhau, ngược lại false
bool PhanSo::operator!=(const PhanSo& ps) const {
    return !(*this == ps);
}

// Toán tử so sánh lớn hơn hoặc bằng
// Input: Phân số ps để so sánh
// Output: Trả về true nếu phân số hiện tại lớn hơn hoặc bằng ps, ngược lại false
bool PhanSo::operator>=(const PhanSo& ps) const {
    return iTu * ps.iMau >= ps.iTu * iMau;
}

// Toán tử so sánh nhỏ hơn hoặc bằng
// Input: Phân số ps để so sánh
// Output: Trả về true nếu phân số hiện tại nhỏ hơn hoặc bằng ps, ngược lại false
bool PhanSo::operator<=(const PhanSo& ps) const {
    return iTu * ps.iMau <= ps.iTu * iMau;
}

// Toán tử so sánh lớn hơn
// Input: Phân số ps để so sánh
// Output: Trả về true nếu phân số hiện tại lớn hơn ps, ngược lại false
bool PhanSo::operator>(const PhanSo& ps) const {
    return iTu * ps.iMau > ps.iTu * iMau;
}

// Toán tử so sánh nhỏ hơn
// Input: Phân số ps để so sánh
// Output: Trả về true nếu phân số hiện tại nhỏ hơn ps, ngược lại false
bool PhanSo::operator<(const PhanSo& ps) const {
    return iTu * ps.iMau < ps.iTu * iMau;
}

// Toán tử nhập
// Input: istream is và phân số ps để nhập dữ liệu vào
// Output: Trả về đối tượng istream đã nhập dữ liệu
// Giải thuật: Đọc tử số và mẫu số, gọi hàm rút gọn sau khi nhập
std::istream& operator>>(std::istream& is, PhanSo& ps) {
    cout << "Nhap tu so: ";
    is >> ps.iTu;
    cout << "Nhap mau so: ";
    is >> ps.iMau;
    while (ps.iMau == 0) {
        cout << "Mau so khong the la 0. Nhap lai!.\n";
        cout << "Nhap mau so: ";
        is >> ps.iMau;
    }
    ps.RutGon();
    return is;
}

// Toán tử xuất
// Input: ostream os và phân số ps để xuất dữ liệu
// Output: Trả về đối tượng ostream đã xuất dữ liệu
// Giải thuật: Xuất phân số theo định dạng tử/mẫu
std::ostream& operator<<(std::ostream& os, const PhanSo& ps) {
    if (ps.iTu == 0) os << "0";
    else if (ps.iMau == 1) os << ps.iTu;
    else os << ps.iTu << "/" << ps.iMau;
    return os;
}
