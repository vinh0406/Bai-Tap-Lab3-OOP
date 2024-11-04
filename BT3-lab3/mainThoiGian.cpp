#include <iostream>
#include "ThoiGian.h"

int main() {
    ThoiGian tg1, tg2;

    // Nhập thời gian đầu tiên
    std::cout << "Nhap thoi gian 1:\n";
    std::cin >> tg1;

    // Nhập thời gian thứ hai
    std::cout << "Nhap thoi gian 2:\n";
    std::cin >> tg2;

    // Hiển thị thời gian đã nhập
    std::cout << "Thoi gian 1: " << tg1 << std::endl;
    std::cout << "Thoi gian 2: " << tg2 << std::endl;

    // Toán tử cộng với số giây
    ThoiGian tg3 = tg1 + 500;
    std::cout << "Thoi gian 1 + 500 giay = " << tg3 << std::endl;

    // Toán tử trừ với số giây
    ThoiGian tg4 = tg1 - 300;
    std::cout << "Thoi gian 1 - 300 giay = " << tg4 << std::endl;

    // Toán tử cộng với đối tượng ThoiGian khác
    ThoiGian tg5 = tg1 + tg2;
    std::cout << "Thoi gian 1 + Thoi gian 2 = " << tg5 << std::endl;

    // Toán tử trừ với đối tượng ThoiGian khác
    ThoiGian tg6 = tg1 - tg2;
    std::cout << "Thoi gian 1 - Thoi gian 2 = " << tg6 << std::endl;

    // Toán tử tăng tiền tố
    ++tg1;
    std::cout << "++Thoi gian 1 = " << tg1 << std::endl;

    // Toán tử tăng hậu tố
    tg1++;
    std::cout << "Thoi gian 1++ = " << tg1 << std::endl;

    // Toán tử giảm tiền tố
    --tg1;
    std::cout << "--Thoi gian 1 = " << tg1 << std::endl;

    // Toán tử giảm hậu tố
    tg1--;
    std::cout << "Thoi gian 1-- = " << tg1 << std::endl;

    // Các phép so sánh
    std::cout << "Thoi gian 1 bang thoi gian 2: " << (tg1 == tg2 ? "Dung" : "Sai") << std::endl;
    std::cout << "Thoi gian 1 khac thoi gian 2: " << (tg1 != tg2 ? "Dung" : "Sai") << std::endl;
    std::cout << "Thoi gian 1 lon hon hoac bang thoi gian 2: " << (tg1 >= tg2 ? "Dung" : "Sai") << std::endl;
    std::cout << "Thoi gian 1 nho hon hoac bang thoi gian 2: " << (tg1 <= tg2 ? "Dung" : "Sai") << std::endl;
    std::cout << "Thoi gian 1 lon hon thoi gian 2: " << (tg1 > tg2 ? "Dung" : "Sai") << std::endl;
    std::cout << "Thoi gian 1 nho hon thoi gian 2: " << (tg1 < tg2 ? "Dung" : "Sai") << std::endl;

    return 0;
}
