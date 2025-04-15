#include <iostream>
using namespace std;

class TransaksiBensin
{
    friend istream &operator>>(istream &, TransaksiBensin &);
    friend ostream &operator<<(ostream &, const TransaksiBensin &);

private:
    string nama;
    string jenis;
    int liter;
    int total;
    int PERTALITE = 7000;
    int PERTAMAX = 9000;

public:
    void hitungTotal()
    {
        if (jenis == "Pertalite")
        {
            total = liter * PERTALITE;
        }
        else
        {
            total = liter * PERTAMAX;
        }
    }
};

istream &operator>>(istream &is, TransaksiBensin &transaksi)
{
    cout << "Masukkan nama pelanggan: ";
    getline(is, transaksi.nama);

    cout << "Pilih jenis bensin (1. Pertalite, 2. Pertamax): ";
    int pilihan;
    is >> pilihan;
    is.ignore();

    if (pilihan == 1)
    {
        transaksi.jenis = "Pertalite";
    }
    else
    {
        transaksi.jenis = "Pertamax";
    }

    cout << "Masukkan jumlah liter: ";
    is >> transaksi.liter;

    transaksi.hitungTotal();
    return is;
}

ostream &operator<<(ostream &os, const TransaksiBensin &transaksi)
{
    os << "\n===== STRUK PEMBELIAN =====" << endl;
    os << "Nama Pelanggan : " << transaksi.nama << endl;
    os << "Jenis Bensin   : " << transaksi.jenis << endl;
    os << "Jumlah Liter   : " << transaksi.liter << endl;
    os << "Total Harga    : Rp " << transaksi.total << endl;
    os << "===========================" << endl;
    return os;
}

int main()
{
    TransaksiBensin pembelian;
    cin >> pembelian;
    cout << pembelian;

    return 0;
}