#pragma once
#include <iostream>

class PhanSo {
private:
    int iTu;  // Tử số của phân số
    int iMau; // Mẫu số của phân số

public:
    PhanSo();                    // Hàm khởi tạo mặc định
    PhanSo(int Tu, int Mau);      // Hàm khởi tạo với tử số và mẫu số

    // Hàm tính ước chung lớn nhất của hai số nguyên
   
    void RutGon(); // Hàm rút gọn phân số về dạng tối giản

    // Toán tử + để cộng hai phân số
    PhanSo operator+(const PhanSo& ps) const;

    // Toán tử - để trừ hai phân số
    PhanSo operator-(const PhanSo& ps) const;

    // Toán tử * để nhân hai phân số
    PhanSo operator*(const PhanSo& ps) const;

    // Toán tử / để chia hai phân số
    PhanSo operator/(const PhanSo& ps) const;

    // Toán tử so sánh bằng ==
    bool operator==(const PhanSo& ps) const;

    // Toán tử so sánh khác !=
    bool operator!=(const PhanSo& ps) const;

    // Toán tử so sánh lớn hơn hoặc bằng >=
    bool operator>=(const PhanSo& ps) const;

    // Toán tử so sánh nhỏ hơn hoặc bằng <=
    bool operator<=(const PhanSo& ps) const;

    // Toán tử so sánh lớn hơn >
    bool operator>(const PhanSo& ps) const;

    // Toán tử so sánh nhỏ hơn <
    bool operator<(const PhanSo& ps) const;

    // Toán tử nhập >>
    friend std::istream& operator>>(std::istream& is, PhanSo& ps);

    // Toán tử xuất <<
    friend std::ostream& operator<<(std::ostream& os, const PhanSo& ps);
};