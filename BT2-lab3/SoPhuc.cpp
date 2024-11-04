#include "SoPhuc.h"
#include <iostream>
using namespace std;

// Hàm khởi tạo mặc định
// Input: Không có tham số
// Output: Khởi tạo số phức với phần thực và phần ảo đều bằng 0
SoPhuc::SoPhuc() : dThuc(0), dAo(0) {}

// Hàm khởi tạo có tham số
// Input: Phần thực và phần ảo của số phức
// Output: Khởi tạo số phức với giá trị phần thực và phần ảo được cung cấp
SoPhuc::SoPhuc(double thuc, double ao) : dThuc(thuc), dAo(ao) {}

// Toán tử cộng
// Input: Số phức sp để cộng với số phức hiện tại
// Output: Trả về số phức tổng của hai số phức
// Giải thuật: Cộng từng phần thực và phần ảo của hai số phức
SoPhuc SoPhuc::operator+(const SoPhuc& sp) const {
    return SoPhuc(dThuc + sp.dThuc, dAo + sp.dAo);
}

// Toán tử trừ
// Input: Số phức sp để trừ với số phức hiện tại
// Output: Trả về số phức hiệu của hai số phức
// Giải thuật: Trừ từng phần thực và phần ảo của hai số phức
SoPhuc SoPhuc::operator-(const SoPhuc& sp) const {
    return SoPhuc(dThuc - sp.dThuc, dAo - sp.dAo);
}

// Toán tử nhân
// Input: Số phức sp để nhân với số phức hiện tại
// Output: Trả về số phức tích của hai số phức
// Giải thuật: Áp dụng công thức (a+bi)*(c+di) = (ac-bd) + (ad+bc)i
SoPhuc SoPhuc::operator*(const SoPhuc& sp) const {
    double thuc = dThuc * sp.dThuc - dAo * sp.dAo;
    double ao = dThuc * sp.dAo + dAo * sp.dThuc;
    return SoPhuc(thuc, ao);
}

// Toán tử chia
// Input: Số phức sp để chia với số phức hiện tại
// Output: Trả về số phức thương của hai số phức
// Giải thuật: Áp dụng công thức (a+bi)/(c+di) = [(ac+bd) + (bc-ad)i] / (c^2 + d^2)
SoPhuc SoPhuc::operator/(const SoPhuc& sp) const {
    double mau = sp.dThuc * sp.dThuc + sp.dAo * sp.dAo;
    double thuc = (dThuc * sp.dThuc + dAo * sp.dAo) / mau;
    double ao = (dAo * sp.dThuc - dThuc * sp.dAo) / mau;
    return SoPhuc(thuc, ao);
}

// Toán tử so sánh bằng
// Input: Số phức sp để so sánh
// Output: Trả về true nếu hai số phức bằng nhau, ngược lại false
bool SoPhuc::operator==(const SoPhuc& sp) const {
    return (dThuc == sp.dThuc) && (dAo == sp.dAo);
}

// Toán tử so sánh khác
// Input: Số phức sp để so sánh
// Output: Trả về true nếu hai số phức khác nhau, ngược lại false
bool SoPhuc::operator!=(const SoPhuc& sp) const {
    return !(*this == sp);
}

// Toán tử nhập
// Input: istream is và số phức sp để nhập dữ liệu vào
// Output: Trả về đối tượng istream đã nhập dữ liệu
// Giải thuật: Đọc phần thực và phần ảo từ người dùng hoặc luồng đầu vào
istream& operator>>(istream& is, SoPhuc& sp) {
    cout << "Nhap phan thuc: ";
    is >> sp.dThuc;
    cout << "Nhap phan ao: ";
    is >> sp.dAo;
    return is;
}

// Toán tử xuất
// Input: ostream os và số phức sp để xuất dữ liệu
// Output: Trả về đối tượng ostream đã xuất dữ liệu
// Giải thuật: Xuất số phức dưới dạng "phần thực + phần ảo i"
ostream& operator<<(ostream& os, const SoPhuc& sp) {
    os << sp.dThuc << " + (" << sp.dAo << "i)";
    return os;
}