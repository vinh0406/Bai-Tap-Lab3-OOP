#pragma once
#include <iostream>

class NgayThangNam {
private:
    int iNgay;   // Ngày
    int iThang;  // Tháng
    int iNam;    // Năm

public:
    // Constructor mặc định
    NgayThangNam();

    // Constructor có tham số
    NgayThangNam(int Nam, int Thang, int Ngay);

    // Hàm tính số ngày từ ngày 1/1/0000
    int TinhNgay() const; // Trả về số ngày tính từ 1/1/0000

    // Hàm tính số ngày trong tháng
    int SoNgayTrongThang(int Thang, int Nam) const; // Trả về số ngày trong tháng

    // Toán tử cộng ngày
    NgayThangNam operator+(int ngay) const; // Cộng thêm số ngày vào đối tượng hiện tại

    // Toán tử trừ ngày
    NgayThangNam operator-(int ngay) const; // Trừ đi số ngày từ đối tượng hiện tại

    // Toán tử trừ với một đối tượng NgayThangNam
    int operator-(const NgayThangNam& a) const; // Trả về số ngày giữa hai đối tượng

    // Hàm chuẩn hóa ngày tháng năm
    void ChuanHoa(); // Điều chỉnh ngày, tháng, năm cho hợp lệ

    // Toán tử so sánh
    bool operator==(const NgayThangNam& a) const; // So sánh hai đối tượng
    bool operator!=(const NgayThangNam& a) const; // So sánh khác nhau
    bool operator>=(const NgayThangNam& a) const; // So sánh lớn hơn hoặc bằng
    bool operator<=(const NgayThangNam& a) const; // So sánh nhỏ hơn hoặc bằng
    bool operator>(const NgayThangNam& a) const;  // So sánh lớn hơn
    bool operator<(const NgayThangNam& a) const;   // So sánh nhỏ hơn

    // Toán tử tiền tố và hậu tố ++, --
    NgayThangNam& operator++();    // Tiền tố: Tăng ngày lên 1
    NgayThangNam operator++(int);  // Hậu tố: Tăng ngày lên 1
    NgayThangNam& operator--();     // Tiền tố: Giảm ngày xuống 1
    NgayThangNam operator--(int);   // Hậu tố: Giảm ngày xuống 1

    // Toán tử nhập và xuất
    friend std::istream& operator>>(std::istream& is, NgayThangNam& t); // Nhập ngày tháng năm
    friend std::ostream& operator<<(std::ostream& os, const NgayThangNam& t); // Xuất ngày tháng năm
};
