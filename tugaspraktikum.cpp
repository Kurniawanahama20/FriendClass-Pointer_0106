#include <iostream>
using namespace std;

class BelahKetupat; // forward declaration

class LayangLayang {
private:
    double d1, d2; // diagonal
    double a, b;   // sisi

public:
    void input() {
        cout << "Input Layang-Layang\n";
        cout << "Diagonal 1: "; cin >> d1;
        cout << "Diagonal 2: "; cin >> d2;
        cout << "Sisi a: "; cin >> a;
        cout << "Sisi b: "; cin >> b;
    }

    double luas() {
        return 0.5 * d1 * d2;
    }

    double keliling() {
        return 2 * (a + b);
    }

    void output() {
        cout << "\nLayang-Layang\n";
        cout << "Luas: " << luas() << endl;
        cout << "Keliling: " << keliling() << endl;
    }

    // friend function (keliling Belah Ketupat boleh akses private LayangLayang)
    friend double kelilingBelahKetupat(BelahKetupat bk, LayangLayang ll);
};

class BelahKetupat {
private:
    double d1, d2; // diagonal
    double s;      // sisi

public:
    void input() {
        cout << "\nInput Belah Ketupat\n";
        cout << "Diagonal 1: "; cin >> d1;
        cout << "Diagonal 2: "; cin >> d2;
        cout << "Sisi: "; cin >> s;
    }

    double luas() {
        return 0.5 * d1 * d2;
    }

    double keliling() {
        return 4 * s;
    }

    void output() {
        cout << "\nBelah Ketupat\n";
        cout << "Luas: " << luas() << endl;
        cout << "Keliling: " << keliling() << endl;
    }

    // kasih akses ke fungsi friend
    friend double kelilingBelahKetupat(BelahKetupat bk, LayangLayang ll);
};

// friend function
double kelilingBelahKetupat(BelahKetupat bk, LayangLayang ll) {
    cout << "\n[Friend Function Dipanggil]\n";
    cout << "Keliling Belah Ketupat: " << bk.keliling() << endl;

    // akses data private Layang-Layang (karena friend)
    cout << "Akses sisi Layang-Layang (a + b): " << ll.a + ll.b << endl;

    return bk.keliling();
}

int main() {
    LayangLayang ll;
    BelahKetupat bk;

    ll.input();
    bk.input();

    ll.output();
    bk.output();

    kelilingBelahKetupat(bk, ll);

    return 0;
}