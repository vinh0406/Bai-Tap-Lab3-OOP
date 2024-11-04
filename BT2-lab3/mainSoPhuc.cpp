#include "SoPhuc.h"
#include <iostream>
using namespace std;

int main() {
    SoPhuc sp1, sp2;

    cout << "Nhap so phuc thu nhat:\n";
    cin >> sp1;

    cout << "Nhap so phuc thu hai:\n";
    cin >> sp2;

    SoPhuc tong = sp1 + sp2;
    SoPhuc hieu = sp1 - sp2;
    SoPhuc tich = sp1 * sp2;
    SoPhuc thuong = sp1 / sp2;

    cout << "\nTong: " << tong << endl;
    cout << "Hieu: " << hieu << endl;
    cout << "Tich: " << tich << endl;
    if (sp2 == SoPhuc(0, 0))
        cout << "Loi: Khong the chia cho 0";
    else cout << "Thuong: " << thuong << endl;

    if (sp1 == sp2) {
        cout << "\nHai so phuc bang nhau.\n";
    }
    else {
        cout << "\nHai so phuc khong bang nhau.\n";
    }

    return 0;
}