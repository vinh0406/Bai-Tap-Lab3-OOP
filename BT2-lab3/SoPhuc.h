#pragma once
#include <iostream>
using namespace std;

class SoPhuc {
private:
    double dThuc; // Phần thực của số phức
    double dAo;   // Phần ảo của số phức

public:
    // Hàm khởi tạo mặc định
    SoPhuc();

    // Hàm khởi tạo có tham số
    SoPhuc(double thuc, double ao);

    // Toán tử cộng
    SoPhuc operator+(const SoPhuc& sp) const;

    // Toán tử trừ
    SoPhuc operator-(const SoPhuc& sp) const;

    // Toán tử nhân
    SoPhuc operator*(const SoPhuc& sp) const;

    // Toán tử chia
    SoPhuc operator/(const SoPhuc& sp) const;

    // Toán tử so sánh bằng
    bool operator==(const SoPhuc& sp) const;

    // Toán tử so sánh khác
    bool operator!=(const SoPhuc& sp) const;

    // Toán tử nhập
    friend istream& operator>>(istream& is, SoPhuc& sp);

    // Toán tử xuất
    friend ostream& operator<<(ostream& os, const SoPhuc& sp);
};
