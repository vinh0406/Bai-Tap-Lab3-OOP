#include "NgayThangNam.h"
#include <iostream>
using namespace std;

// Hàm khởi tạo mặc định
// Input: Không có
// Output: Khởi tạo đối tượng với ngày, tháng, năm là 1/1/1970
NgayThangNam::NgayThangNam() : iNgay(1), iThang(1), iNam(1970) {}

// Hàm khởi tạo có tham số
// Input: Nam, Thang, Ngay (int)
// Output: Khởi tạo đối tượng với giá trị ngày, tháng, năm tương ứng
NgayThangNam::NgayThangNam(int Nam, int Thang, int Ngay) : iNgay(Ngay), iThang(Thang), iNam(Nam) {
    TinhNgay(); // Kiểm tra và chuẩn hóa giá trị ngày, tháng, năm
}

// Hàm tính tổng số ngày kể từ năm 0 đến ngày hiện tại
// Input: Không có
// Output: Trả về tổng số ngày tương ứng
// Giải thuật: Dùng công thức để chuyển ngày, tháng, năm thành tổng số ngày
int NgayThangNam::TinhNgay() const {
    int tongNgay = 0;

    // Tính tổng số ngày cho các năm đầy đủ trước năm hiện tại
    for (int nam = 0; nam < iNam; nam++) {
        tongNgay += 365; // Thêm 365 ngày cho mỗi năm
        // Kiểm tra năm nhuận
        if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) {
            tongNgay++; // Thêm 1 ngày cho năm nhuận
        }
    }

    // Tính tổng số ngày cho các tháng đầy đủ trước tháng hiện tại
    for (int thang = 1; thang < iThang; thang++) {
        tongNgay += SoNgayTrongThang(thang, iNam); // Thêm số ngày của tháng
    }

    // Thêm số ngày hiện tại
    tongNgay += iNgay;

    return tongNgay;
}

// Hàm tính số ngày trong tháng
// Input: Thang (int), Nam (int)
// Output: Trả về số ngày trong tháng
// Giải thuật: Xác định tháng có 31, 30 hay 28/29 ngày dựa vào năm nhuận
int NgayThangNam::SoNgayTrongThang(int Thang, int Nam) const {
    static const int ngayTrongThang[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (Thang == 2 && ((Nam % 4 == 0 && Nam % 100 != 0) || (Nam % 400 == 0))) {
        return 29;
    }
    return ngayTrongThang[Thang - 1];
}

// Toán tử cộng với số ngày
// Input: ngay (int) - số ngày cần cộng
// Output: Trả về đối tượng NgayThangNam mới với ngày tháng năm đã cộng
// Giải thuật: Cộng số ngày và chuẩn hóa lại ngày, tháng, năm
NgayThangNam NgayThangNam::operator+(int ngay) const {
    NgayThangNam kq = *this;
    kq.iNgay += ngay;
    kq.ChuanHoa();
    return kq;
}

// Toán tử trừ với số ngày
// Input: ngay (int) - số ngày cần trừ
// Output: Trả về đối tượng NgayThangNam mới với ngày tháng năm đã trừ
// Giải thuật: Trừ số ngày và chuẩn hóa lại ngày, tháng, năm
NgayThangNam NgayThangNam::operator-(int ngay) const {
    NgayThangNam kq = *this;
    kq.iNgay -= ngay;
    kq.ChuanHoa();
    return kq;
}

// Toán tử trừ giữa hai đối tượng NgayThangNam
// Input: a (NgayThangNam) - đối tượng ngày tháng năm để trừ
// Output: Trả về số ngày giữa hai ngày
// Giải thuật: Tính tổng số ngày của từng đối tượng và lấy hiệu
int NgayThangNam::operator-(const NgayThangNam& a) const {
    int t1 = TinhNgay();
    int t2 = a.TinhNgay();
    if (t1 >= t2)
        return t1 - t2;
    else
        return t2 - t1;
}

// Hàm chuẩn hóa ngày tháng năm
// Input: Không có
// Output: Cập nhật giá trị ngày tháng năm hợp lệ
// Giải thuật: Điều chỉnh lại ngày, tháng, năm nếu vượt quá giới hạn
void NgayThangNam::ChuanHoa() {
    while (iNgay > SoNgayTrongThang(iThang, iNam)) {
        iNgay -= SoNgayTrongThang(iThang, iNam);
        iThang++;
        if (iThang > 12) {
            iThang = 1;
            iNam++;
        }
    }
    while (iNgay <= 0) {
        iThang--;
        if (iThang <= 0) {
            iThang = 12;
            iNam--;
        }
        iNgay += SoNgayTrongThang(iThang, iNam);
    }
}

// operator==
bool NgayThangNam::operator==(const NgayThangNam& a) const {
    return (iNgay == a.iNgay && iThang == a.iThang && iNam == a.iNam);
}

// operator!=
bool NgayThangNam::operator!=(const NgayThangNam& a) const {
    return !(*this == a);
}

// operator>=
bool NgayThangNam::operator>=(const NgayThangNam& a) const {
    return TinhNgay() >= a.TinhNgay();
}

// operator<=
bool NgayThangNam::operator<=(const NgayThangNam& a) const {
    return TinhNgay() <= a.TinhNgay();
}

// operator>
bool NgayThangNam::operator>(const NgayThangNam& a) const {
    return TinhNgay() > a.TinhNgay();
}

// operator<
bool NgayThangNam::operator<(const NgayThangNam& a) const {
    return TinhNgay() < a.TinhNgay();
}

// operator++
NgayThangNam& NgayThangNam::operator++() {
    *this = *this + 1;
    return *this;
}

// operator--
NgayThangNam& NgayThangNam::operator--() {
    *this = *this - 1;
    return *this;
}

// operator>>
istream& operator>>(istream& is, NgayThangNam& nt) {
    cout << "Nhap ngay: ";
    is >> nt.iNgay;
    cout << "Nhap thang: ";
    is >> nt.iThang;
    cout << "Nhap nam: ";
    is >> nt.iNam;
    nt.ChuanHoa();
    return is;
}

// operator<<
ostream& operator<<(ostream& os, const NgayThangNam& nt) {
    os << nt.iNgay << "/" << nt.iThang << "/" << nt.iNam;
    return os;
}
