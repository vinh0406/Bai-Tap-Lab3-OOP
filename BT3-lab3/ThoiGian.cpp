#include "ThoiGian.h"
#include <iostream>
using namespace std;

// Hàm khởi tạo mặc định
// Input: Không có tham số
// Output: Khởi tạo thời gian với iGio = 0, iPhut = 0, iGiay = 0
ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

// Hàm khởi tạo có tham số
// Input: Gio, Phut, Giay (int)
// Output: Khởi tạo thời gian với giá trị tương ứng, gọi hàm TinhLaiGio để tính lại
ThoiGian::ThoiGian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {
    TinhLaiGio(0); // Tính lại giờ, phút, giây
}

// Hàm tính giây
// Input: Không có tham số
// Output: Trả về tổng số giây tương ứng với thời gian hiện tại
// Giải thuật: Tính tổng giây từ giờ, phút và giây
int ThoiGian::TinhGiay() const {
    return iGio * 3600 + iPhut * 60 + iGiay; // Tính tổng giây
}

// Hàm tính lại giờ từ giây
// Input: Giay (int): số giây để cộng/trừ vào thời gian hiện tại
// Output: Cập nhật lại giá trị giờ, phút, giây tương ứng
// Giải thuật: Tính toán lại giờ, phút, giây từ tổng giây
void ThoiGian::TinhLaiGio(int Giay) {
    int tongGiay = TinhGiay() + Giay; // Tính tổng giây mới
    iGio = (tongGiay / 3600) % 24; // Lấy số giờ trong 24 giờ
    iPhut = (tongGiay % 3600) / 60; // Lấy số phút
    iGiay = tongGiay % 60; // Lấy số giây
}

// Toán tử cộng với giây (int)
// Input: Giay (int): số giây để cộng vào thời gian
// Output: Trả về một đối tượng ThoiGian mới với thời gian đã cộng
ThoiGian ThoiGian::operator+(int Giay) const {
    ThoiGian t(*this); // Tạo bản sao thời gian hiện tại
    t.TinhLaiGio(Giay); // Cộng giây vào thời gian
    return t; // Trả về thời gian mới
}

// Toán tử trừ với giây (int)
// Input: Giay (int): số giây để trừ khỏi thời gian
// Output: Trả về một đối tượng ThoiGian mới với thời gian đã trừ
ThoiGian ThoiGian::operator-(int Giay) const {
    ThoiGian t(*this); // Tạo bản sao thời gian hiện tại
    t.TinhLaiGio(-Giay); // Trừ giây khỏi thời gian
    return t; // Trả về thời gian mới
}

// Toán tử cộng với một đối tượng ThoiGian
// Input: a (ThoiGian): đối tượng thời gian để cộng
// Output: Trả về một đối tượng ThoiGian mới với thời gian đã cộng
ThoiGian ThoiGian::operator+(const ThoiGian& a) const {
    int totalGiay1 = TinhGiay(); // Thời gian hiện tại
    int totalGiay2 = a.TinhGiay(); // Thời gian a
    int totalGiayKq = totalGiay1 + totalGiay2; // Cộng tổng giây

    // Tạo đối tượng ThoiGian mới từ tổng giây
    return ThoiGian(totalGiayKq / 3600, (totalGiayKq % 3600) / 60, totalGiayKq % 60);
}

// Toán tử trừ với một đối tượng ThoiGian
// Input: a (ThoiGian): đối tượng thời gian để trừ
// Output: Trả về một đối tượng ThoiGian mới với thời gian đã trừ
ThoiGian ThoiGian::operator-(const ThoiGian& a) const {
    int totalGiay1 = TinhGiay(); // Thời gian hiện tại
    int totalGiay2 = a.TinhGiay(); // Thời gian a
    int totalGiayKq = totalGiay1 - totalGiay2; // Trừ tổng giây

    if (totalGiay1 < totalGiay2) {
        totalGiayKq += 86400; //Đảm bảo thời gian không âm
    }
    // Tạo đối tượng ThoiGian mới từ số giây kết quả
    return ThoiGian(totalGiayKq / 3600, (totalGiayKq % 3600) / 60, totalGiayKq % 60);
}

// operator++ tiền tố
// Input: Không có tham số đầu vào, nhưng thao tác trên thuộc tính của đối tượng `ThoiGian` hiện tại.
// Output: Trả về tham chiếu đến đối tượng `ThoiGian` đã được tăng giá trị giây thêm 1.
// Giải thuật: Tăng giá trị giây thêm 1, sau đó gọi hàm `TinhLaiGio` để đảm bảo giờ, phút, giây hợp lệ.
// Trả về đối tượng hiện tại sau khi đã cập nhật.
ThoiGian& ThoiGian::operator++() {
    iGiay++;
    TinhLaiGio(0); // Đảm bảo cập nhật giờ, phút, giây hợp lệ
    return *this;
}

// operator++ hậu tố
// Input: Có một tham số kiểu `int` (không sử dụng), thao tác trên thuộc tính của đối tượng `ThoiGian` hiện tại.
// Output: Trả về một bản sao của đối tượng `ThoiGian` trước khi tăng giá trị giây thêm 1.
// Giải thuật: Tạo bản sao tạm thời của đối tượng, tăng giá trị giây của đối tượng hiện tại,
// gọi `TinhLaiGio` để cập nhật giá trị, sau đó trả về bản sao ban đầu.
ThoiGian ThoiGian::operator++(int) {
    ThoiGian temp = *this;
    ++(*this); // Gọi operator++ tiền tố
    return temp;
}

// operator-- tiền tố
// Input: Không có tham số đầu vào, nhưng thao tác trên thuộc tính của đối tượng `ThoiGian` hiện tại.
// Output: Trả về tham chiếu đến đối tượng `ThoiGian` đã được giảm giá trị giây đi 1.
// Giải thuật: Giảm giá trị giây đi 1, sau đó gọi hàm `TinhLaiGio` để đảm bảo giờ, phút, giây hợp lệ.
// Trả về đối tượng hiện tại sau khi đã cập nhật.
ThoiGian& ThoiGian::operator--() {
    iGiay--;
    TinhLaiGio(0); // Đảm bảo cập nhật giờ, phút, giây hợp lệ
    return *this;
}

// operator-- hậu tố
// Input: Có một tham số kiểu `int` (không sử dụng), thao tác trên thuộc tính của đối tượng `ThoiGian` hiện tại.
// Output: Trả về một bản sao của đối tượng `ThoiGian` trước khi giảm giá trị giây đi 1.
// Giải thuật: Tạo bản sao tạm thời của đối tượng, giảm giá trị giây của đối tượng hiện tại,
// gọi `TinhLaiGio` để cập nhật giá trị, sau đó trả về bản sao ban đầu.
ThoiGian ThoiGian::operator--(int) {
    ThoiGian temp = *this;
    --(*this); 
    return temp;
}

// Toán tử so sánh bằng
// Input: a (ThoiGian): đối tượng thời gian để so sánh
// Output: Trả về true nếu hai thời gian bằng nhau, ngược lại false
bool ThoiGian::operator==(const ThoiGian& a) const {
    return iGio == a.iGio && iPhut == a.iPhut && iGiay == a.iGiay; // So sánh từng phần
}

// Toán tử so sánh khác
// Input: a (ThoiGian): đối tượng thời gian để so sánh
// Output: Trả về true nếu hai thời gian khác nhau, ngược lại false
bool ThoiGian::operator!=(const ThoiGian& a) const {
    return !(*this == a); // Ngược lại của so sánh bằng
}

// Toán tử so sánh lớn hơn hoặc bằng
// Input: a (ThoiGian): đối tượng thời gian để so sánh
// Output: Trả về true nếu thời gian hiện tại lớn hơn hoặc bằng a
bool ThoiGian::operator>=(const ThoiGian& a) const {
    return TinhGiay() >= a.TinhGiay(); // So sánh tổng giây
}

// Toán tử so sánh nhỏ hơn hoặc bằng
// Input: a (ThoiGian): đối tượng thời gian để so sánh
// Output: Trả về true nếu thời gian hiện tại nhỏ hơn hoặc bằng a
bool ThoiGian::operator<=(const ThoiGian& a) const {
    return TinhGiay() <= a.TinhGiay(); // So sánh tổng giây
}

// Toán tử so sánh lớn hơn
// Input: a (ThoiGian): đối tượng thời gian để so sánh
// Output: Trả về true nếu thời gian hiện tại lớn hơn a
bool ThoiGian::operator>(const ThoiGian& a) const {
    return TinhGiay() > a.TinhGiay(); // So sánh tổng giây
}

// Toán tử so sánh nhỏ hơn
// Input: a (ThoiGian): đối tượng thời gian để so sánh
// Output: Trả về true nếu thời gian hiện tại nhỏ hơn a
bool ThoiGian::operator<(const ThoiGian& a) const {
    return TinhGiay() < a.TinhGiay(); // So sánh tổng giây
}

// Toán tử nhập
// Input: istream is và thời gian t để nhập dữ liệu vào
// Output: Trả về đối tượng istream đã nhập dữ liệu
std::istream& operator>>(std::istream& is, ThoiGian& t) {
    cout << "Nhap gio: ";
    is >> t.iGio;
    cout << "Nhap phut: ";
    is >> t.iPhut;
    cout << "Nhap giay: ";
    is >> t.iGiay;
    t.TinhLaiGio(0); // Tính lại giờ, phút, giây
    return is; // Trả về luồng đã nhập
}

// Toán tử xuất
// Input: ostream os và thời gian t để xuất dữ liệu
// Output: Trả về đối tượng ostream đã xuất dữ liệu
std::ostream& operator<<(std::ostream& os, const ThoiGian& t) {
    os << t.iGio << ":" << t.iPhut << ":" << t.iGiay; // Xuất thời gian theo định dạng hh:mm:ss
    return os; // Trả về luồng đã xuất
}
