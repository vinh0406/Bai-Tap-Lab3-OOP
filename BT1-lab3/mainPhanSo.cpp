#include <iostream>
#include "PhanSo.h"

int main() {
    PhanSo ps1, ps2;

    // Nhập hai phân số từ người dùng
    std::cout << "Nhap phan so thu nhat:\n";
    std::cin >> ps1;
    std::cout << "Nhap phan so thu hai:\n";
    std::cin >> ps2;

    // Hiển thị kết quả các phép toán
    std::cout << "Tong: " << ps1 + ps2 << '\n';
    std::cout << "Hieu: " << ps1 - ps2 << '\n';
    std::cout << "Tich: " << ps1 * ps2 << '\n';
    if (ps2 != PhanSo(0, 1)) {
        std::cout << "Thuong: " << ps1 / ps2 << '\n';
    }
    else {
        std::cout << "Khong the chia cho 0.\n";
    }

    // Kiểm tra các toán tử so sánh
    std::cout << "Phan so thu nhat == Phan so thu hai: ";
    if (ps1 == ps2)
        std::cout << "Dung\n";
    else std::cout << "Sai\n";

    std::cout << "Phan so thu nhat != Phan so thu hai: ";
    if (ps1 != ps2)
        std::cout << "Dung\n";
    else std::cout << "Sai\n";

    std::cout << "Phan so thu nhat >= Phan so thu hai: ";
    if (ps1 >= ps2)
        std::cout << "Dung\n";
    else std::cout << "Sai\n";

    std::cout << "Phan so thu nhat <= Phan so thu hai: ";
    if (ps1 <= ps2)
        std::cout << "Dung\n";
    else std::cout << "Sai\n";

    std::cout << "Phan so thu nhat > Phan so thu hai: ";
    if (ps1 > ps2)
        std::cout << "Dung\n";
    else std::cout << "Sai\n";

    std::cout << "Phan so thu nhat < Phan so thu hai: ";
    if (ps1 < ps2)
        std::cout << "Dung\n";
    else std::cout << "Sai\n";

    return 0;
}
