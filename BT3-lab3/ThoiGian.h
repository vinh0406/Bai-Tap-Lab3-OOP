#pragma once
#include <iostream>

class ThoiGian {
private:
    int iGio;   // Lưu giờ
    int iPhut;  // Lưu phút
    int iGiay;  // Lưu giây

public:
    // Hàm khởi tạo mặc định
    ThoiGian();

    // Hàm khởi tạo có tham số
    ThoiGian(int Gio, int Phut, int Giay);

    // Phương thức tính tổng giây
    int TinhGiay() const;

    // Phương thức tính lại giờ từ số giây
    void TinhLaiGio(int Giay);

    // Toán tử cộng với giây
    ThoiGian operator+(int Giay) const;

    // Toán tử trừ với giây
    ThoiGian operator-(int Giay) const;

    // Toán tử cộng với một đối tượng ThoiGian
    ThoiGian operator+(const ThoiGian& a) const;

    // Toán tử trừ với một đối tượng ThoiGian
    ThoiGian operator-(const ThoiGian& a) const;

    // Toán tử tăng tiền tố (++a)
    ThoiGian& operator++();

    // Toán tử tăng hậu tố (a++)
    ThoiGian operator++(int);

    // Toán tử giảm tiền tố (--a)
    ThoiGian& operator--();

    // Toán tử giảm hậu tố (a--)
    ThoiGian operator--(int);

    // Toán tử so sánh bằng
    bool operator==(const ThoiGian& a) const;

    // Toán tử so sánh khác
    bool operator!=(const ThoiGian& a) const;

    // Toán tử so sánh lớn hơn hoặc bằng
    bool operator>=(const ThoiGian& a) const;

    // Toán tử so sánh nhỏ hơn hoặc bằng
    bool operator<=(const ThoiGian& a) const;

    // Toán tử so sánh lớn hơn
    bool operator>(const ThoiGian& a) const;

    // Toán tử so sánh nhỏ hơn
    bool operator<(const ThoiGian& a) const;

    // Toán tử nhập
    friend std::istream& operator>>(std::istream& is, ThoiGian& tg);

    // Toán tử xuất
    friend std::ostream& operator<<(std::ostream& os, const ThoiGian& tg);
};