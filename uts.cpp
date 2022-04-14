#include<iostream>
#include<unistd.h>
using namespace std;

class PaketMakanan{
    public:
        string namaPaket;
        double harga;

        //CONSTRUCTOR
        PaketMakanan(string namaPaket = "", double harga = 0){
            this->namaPaket = namaPaket;
            this->harga = harga;
        }

        //METHOD
        void tampilkanPaket(){
            cout << "Nama Paket : " << this->namaPaket << endl;
            cout << "Harga      : Rp" << this->harga << endl;
        }

        void setHarga(double harga){
            this->harga = harga;
        }

        //DESTRUCTOR
        ~PaketMakanan(){
            cout << "Destructor Paket Makanan Called" << endl;
        }

};

class MenuMakanan : public PaketMakanan{
    public:
        string makanan;
        string minuman;

        //CONSTRUCTOR
        MenuMakanan(string namaPaket = "", double harga = 0, string makanan = "", string minuman = "") : PaketMakanan(namaPaket, harga){
            this->makanan = makanan;
            this->minuman = minuman;
        }

        //METHOD
        void tampilkanMenu(){
            this->tampilkanPaket();
            cout << "Makanan    : " << this->makanan << endl;
            cout << "Minuman    : " << this->minuman << endl << endl;
        }

        void setMakanan(string makanan){
            this->makanan = makanan;
        }

        void setMinuman(string minuman){
            this->minuman = minuman;
        }

        //DESTRUCTOR
        ~MenuMakanan(){
            cout << "Destructor Menu Makanan Called" << endl;
        }
};

class Transaksi{
    public:
        string namaPembeli;
        int jumlah;
        string NamaPaket[100];
        double harga[100];
        double total;

        //CONSTRUCTOR
        Transaksi(string namaPembeli = "", int jumlah = 0){
            this->namaPembeli = namaPembeli;
            this->jumlah = jumlah;
        }

        //METHOD
        void PemesananMenu(double paket1, double paket2, double paket3, double paket4, double paket5){
            this->total = 0;
            int pilihan;
            for(int i = 0; i < this->jumlah; i++){
                cout << "Pilih Paket Makanan (1-5) : ";
                cin >> pilihan;

                if(pilihan == 1){
                    this->NamaPaket[i] = "Paket 1";
                    this->harga[i] = paket1;
                    this->total += this->harga[i];
                }
                else if(pilihan == 2){
                    this->NamaPaket[i] = "Paket 2";
                    this->harga[i] = paket2;
                    this->total += this->harga[i];
                }
                else if(pilihan == 3){
                    this->NamaPaket[i] = "Paket 3";
                    this->harga[i] = paket3;
                    this->total += this->harga[i];
                }
                else if(pilihan == 4){
                    this->NamaPaket[i] = "Paket 4";
                    this->harga[i] = paket4;
                    this->total += this->harga[i];
                }
                else if(pilihan == 5){
                    this->NamaPaket[i] = "Paket 5";
                    this->harga[i] = paket5;
                    this->total += this->harga[i];
                }
                else{
                    i--;
                    cout << "Pilihan tidak ada" << endl;
                }
            }
        }

        void tampilkanTransaksi(){
            double uang;
            do{
                system("cls");
                cout << "===========================================================" << endl;
                cout << "                       STRUK PEMBELIAN" << endl;
                cout << "                      RESTORAN KUY COBA" << endl;
                cout << "           Jl. Ambarawa Barat Nomor 53 Ciamis, Jawa Barat" << endl;
                cout << "===========================================================" << endl;
                cout << "Nama Pembeli   : " << this->namaPembeli << endl;
                cout << "Jumlah Pesanan : " << this->jumlah << endl;
                for(int i = 0; i < this->jumlah; i++){
                    cout << "Paket Makanan  : " << this->NamaPaket[i] << endl;
                    cout << "Harga Paket    : Rp" << this->harga[i] << endl << endl;
                }
                cout << "===========================================================" << endl;
                cout << "Total Pembayaran   : Rp" << this->total << endl;
                cout << "Masukkan Uang Anda : Rp";
                cin >> uang;
                if(uang < this->total){
                    cout << "Mohon Maaf Uang Anda Kurang Rp" << this->total-uang << endl;
                    sleep(2);
                }
                else{
                    cout << "Kembalian Anda     : Rp" << uang - this->total << endl;
                }
            }while(uang < this->total);
            cout << "===========================================================" << endl;
            cout << "                 Terima Kasih Atas Kunjungannya" << endl;
        }

        ~Transaksi(){
            cout << "Destructor Transaksi Called" << endl;
        }
};

int main(){
    int pilih, pilihmenu;
    string u_makanan, u_minuman;
    double u_harga;
    MenuMakanan menu1("Paket 1", 15000, "Nasi Goreng 69", "Es Teh");
    MenuMakanan menu2("Paket 2", 20000, "Nasi Soto Ayam", "Es Teh");
    MenuMakanan menu3("Paket 3", 25000, "Nasi Soto Daging", "Es Teh");
    MenuMakanan menu4("Paket 4", 30000, "Nasi Rawon Setan", "Es Teh");
    MenuMakanan menu5("Paket 5", 35000, "Nasi Ayam Kentucky", "Es Teh");

    do{
        system("cls");
        string namapembeli;
        int jumlahpesanan;
        double totalharga;

        cout << "Nama  : Imam Maskuri" << endl;
        cout << "NPM   : 20081010074" << endl;
        cout << "Kelas : Pemrograman Berorientasi Objek A" << endl << endl;
        cout << "===========================================================" << endl;
        cout << "                        RESTORAN KUY COBA"<<endl;
        cout << "============================================================" <<endl;
        cout << "1. Lihat Paket Menu"<<endl;
        cout << "2. Update Paket Menu"<<endl;
        cout << "3. Beli Paket Menu"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Masukkan Pilihan : ";
        cin >> pilih;
        switch(pilih){
            default:
                cout<<"Pilihan Tidak Tersedia!"<<endl;
                sleep(2);
                break;

            case 1:
                system("cls");
                cout << "======================== PAKET MENU =======================" << endl << endl;
                menu1.tampilkanMenu();
                menu2.tampilkanMenu();
                menu3.tampilkanMenu();
                menu4.tampilkanMenu();
                menu5.tampilkanMenu();
                system("pause");  
                break;

            case 2:
                system("cls");
                cout << "======================== PAKET MENU =======================" << endl << endl;
                cout << "Pilih Paket Menu Yang Akan di Update (1-5) : ";
                cin >> pilihmenu;

                if(pilihmenu == 1){
                    cout << "Masukkan Harga Paket 1 : ";
                    cin >> u_harga;
                    menu1.setHarga(u_harga);

                    fflush(stdin);
                    cout << "Masukkan Makanan Paket 1  : ";
                    getline(cin, u_makanan);
                    menu1.setMakanan(u_makanan);

                    cout << "Masukkan Minuman Paket 1  : ";
                    getline(cin, u_minuman);
                    menu1.setMinuman(u_minuman);

                    cout << "Paket Menu 1 Berhasil Di Update" << endl;
                }

                else if(pilihmenu == 2){
                    cout << "Masukkan Harga Paket 2 : ";
                    cin >> u_harga;
                    menu2.setHarga(u_harga);

                    fflush(stdin);
                    cout << "Masukkan Makanan Paket 2  : ";
                    getline(cin, u_makanan);
                    menu2.setMakanan(u_makanan);

                    cout << "Masukkan Minuman Paket 2  : ";
                    getline(cin, u_minuman);
                    menu2.setMinuman(u_minuman);

                    cout << "Paket Menu 2 Berhasil Di Update" << endl;
                }

                else if(pilihmenu == 3){
                    cout << "Masukkan Harga Paket 3 : ";
                    cin >> u_harga;
                    menu3.setHarga(u_harga);

                    fflush(stdin);
                    cout << "Masukkan Makanan Paket 3  : ";
                    getline(cin, u_makanan);
                    menu3.setMakanan(u_makanan);

                    cout << "Masukkan Minuman Paket 3  : ";
                    getline(cin, u_minuman);
                    menu3.setMinuman(u_minuman);

                    cout << "Paket Menu 3 Berhasil Di Update" << endl;
                }

                else if(pilihmenu == 4){
                    cout << "Masukkan Harga Paket 4 : ";
                    cin >> u_harga;
                    menu4.setHarga(u_harga);

                    fflush(stdin);
                    cout << "Masukkan Makanan Paket 4  : ";
                    getline(cin, u_makanan);
                    menu4.setMakanan(u_makanan);

                    cout << "Masukkan Minuman Paket 4  : ";
                    getline(cin, u_minuman);
                    menu4.setMinuman(u_minuman);

                    cout << "Paket Menu 4 Berhasil Di Update" << endl;
                }

                else if(pilihmenu == 5){
                    cout << "Masukkan Harga Paket 5 : ";
                    cin >> u_harga;
                    menu5.setHarga(u_harga);

                    fflush(stdin);
                    cout << "Masukkan Makanan Paket 5  : ";
                    getline(cin, u_makanan);
                    menu5.setMakanan(u_makanan);

                    cout << "Masukkan Minuman Paket 5  : ";
                    getline(cin, u_minuman);
                    menu5.setMinuman(u_minuman);

                    cout << "Paket Menu 5 Berhasil Di Update" << endl;
                }

                else{
                    cout << "Pilihan Menu Tidak Tersedia" << endl;
                }
                sleep(1);
                break;

            case 3:
                system("cls");
                fflush(stdin);
                cout << "======================== PAKET MENU =======================" << endl << endl;
                menu1.tampilkanMenu();
                menu2.tampilkanMenu();
                menu3.tampilkanMenu();
                menu4.tampilkanMenu();
                menu5.tampilkanMenu();
                cout << endl;
                cout << "Masukkan Nama Pembeli   : ";
                getline(cin, namapembeli);
                cout << "Masukkan Jumlah Pesanan : ";
                cin >> jumlahpesanan;
                Transaksi pesan(namapembeli, jumlahpesanan);
                pesan.PemesananMenu(menu1.harga, menu2.harga, menu3.harga, menu4.harga, menu5.harga);
                pesan.tampilkanTransaksi();
                system("pause");
                break;
        }

    }while (pilih != 0);
    cout << "Terima Kasih Telah Menggunakan Program Ini" << endl;
    return 0;
    

}
