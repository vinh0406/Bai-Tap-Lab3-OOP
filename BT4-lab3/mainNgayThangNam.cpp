#include "NgayThangNam.h"
#include <iostream>
using namespace std;

int main() {
    NgayThangNam date1, date2;

    // Nhap 2 ngay
    cout << "Nhap ngay thu nhat:\n";
    cin >> date1;
    cout << "Nhap ngay thu hai:\n";
    cin >> date2;

    // In hai ngay
    cout << "Ngay thu nhat: " << date1 << endl;
    cout << "Ngay thu hai: " << date2 << endl;

    // So sanh
    cout << "Hai ngay bang nhau: " << (date1 == date2 ? "Dung" : "Sai") << endl;
    cout << "Hai ngay khac nhau: " << (date1 != date2 ? "Dung" : "Sai") << endl;
    cout << "Ngay thu nhat lon hon ngay thu hai: " << (date1 > date2 ? "Dung" : "Sai") << endl;
    cout << "Ngay thu nhat nho hon ngay thu hai: " << (date1 < date2 ? "Dung" : "Sai") << endl;
    cout << "Ngay thu nhat lon hon hoac bang ngay thu hai: " << (date1 >= date2 ? "Dung" : "Sai") << endl;
    cout << "Ngay thu nhat nho hon hoac bang ngay thu hai: " << (date1 <= date2 ? "Dung" : "Sai") << endl;

    // Toan tu cong va tru ngay
    cout << "Ngay thu nhat cong 5 ngay: " << (date1 + 5) << endl;
    cout << "Ngay thu nhat tru 5 ngay: " << (date1 - 5) << endl;
    cout << "Khoang cach giua hai ngay (so ngay): " << (date1 - date2) << endl;

    // Toan tu ++ va --
    cout << "Ngay thu nhat sau khi ++: " << ++date1 << endl;
    cout << "Ngay thu hai sau khi --: " << --date2 << endl;

    return 0;
}
